#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static void display_date_tm(const struct tm*);
static int compare_date_old(uint16_t , uint16_t);
static int compare_date_verbose(uint16_t , uint16_t);
static void summary_date(uint16_t, uint16_t);
static void display_16bits_date(uint16_t);

static void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

static void print_info(uint16_t date_1, uint8_t index_date_1, uint16_t date_2, uint8_t index_date_2)
{
    printf("date_1 [%2d] :", index_date_1);
    print_binary((date_1 >> index_date_1) & 1);
    puts("");
    printf("date_2 [%2d] :", index_date_2);
    print_binary((date_2 >> index_date_2) & 1);
    puts("");
}

/**
 * OLD
 * @brief compare deux dates
 * 
 * @param date_1 
 * @param date_2 
 * @return int 0 date_1 et date_2 sont identiques
 *             1 date_1 est APRES date_2
 *            -1 date_1 est AVANT date_2
 */
static int compare_date_old(uint16_t date_1, uint16_t date_2) 
{
    if (date_1 == date_2)
    {
        return 0;
    }

    if (((date_2 >> 12) & 1) == ((date_1 >> 12) & 1))
    {
        if (((date_2 >> 13) & 1) == ((date_1 >> 13) & 1))
        {
            return (date_2 << 4) < (date_1 << 4);
        } 
        else
        {
            if (((date_1 >> 13) & 1) != ((date_1 >> 15) & 1))
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }        
    }
    else
    {
        if (((date_1 >> 12) & 1) != ((date_1 >> 14) & 1))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

/**
 * @brief compare deux dates
 * 
 * @param date_1 
 * @param date_2 
 * @return int 0 date_1 et date_2 sont identiques
 *             1 date_1 est APRES date_2
 *            -1 date_1 est AVANT date_2
 */
static int compare_date_verbose(uint16_t date_1, uint16_t date_2) 
{
    int ret = 0;

    // B pour date_1
    uint16_t B12 = (date_1 >> 12) & 1;
    uint16_t B13 = (date_1 >> 13) & 1;
    uint16_t B14 = (date_1 >> 14) & 1;
    uint16_t B15 = (date_1 >> 15) & 1;
    uint16_t B11_0 = date_1 & 0x0FFF;

    // b pour date_2
    uint16_t b12 = (date_2 >> 12) & 1;
    uint16_t b13 = (date_2 >> 13) & 1;
    uint16_t b11_0 = date_2 & 0x0FFF;

    if (B12 != b12)
    {
        printf("(B12 != b12)\n");
        print_info(date_1, 12, date_2, 12);

        if (B12 != B14)
        {
            printf("(B12 != B14)\n");
            print_info(date_1, 12, date_1, 14);

            return 1;
        }
        else
        {
            printf("(B12 (==) B14)\n");
            print_info(date_1, 12, date_1, 14);

            return -1;
        }
    }
    else
    {
        printf("(B12 (==) b12)\n");
        print_info(date_1, 12, date_2, 12);
        
        if (B13 == b13)
        {
            printf("(B13 == b13)\n");
            print_info(date_1, 13, date_2, 13);

            if (B11_0 < b11_0)
            {
                printf("(B11_0 < b11_0)\n");
                
                return -1;
            }
            else
            {
                printf("(B11_0 (>=) b11_0)\n");

                if (B11_0 == b11_0)
                {
                    printf("(B11_0 == b11_0)\n");
                    
                    return 0;
                }

                return 1;
            }
        }

        if (B13 != B15)
        {
            printf("(B13 != B15)\n");
            print_info(date_1, 13, date_1, 15);

            return 1;
        }
        else
        {
            printf("(B13 == B15)\n");
            print_info(date_1, 13, date_1, 15);

            return -1;
        }
    }

    return ret;
}

static void summary_date(uint16_t date_1, uint16_t date_2)
{
    printf("\n%s\n", __func__);

    printf("date_1\n");
    display_16bits_date(date_1);

    printf("date_2\n");
    display_16bits_date(date_2);

    // int ret = compare_date_old(date_1, date_2);
    int ret = compare_date_verbose(date_1, date_2);
    if (ret > 0) 
    {
        printf("GREATER\n");
        return;
    }    
    if (ret < 0) 
    {
        printf("LESS\n");
        return;
    }

    printf("EQUAL\n");    
}

static bool is_expired(uint16_t date_1, uint16_t date_2)
{
    int ret = compare_date_verbose(date_1, date_2);
    if (ret > 0) 
    {
        printf("date not expired\n");
        return false;
    }    
    if (ret < 0) 
    {
        printf("!! date expired !!\n");
        return true;
    }

    printf("date not expired\n");
    return false;
}

static uint16_t compute_expiration_date(uint16_t offset)
{
    uint16_t b_expiration_date = 0;

    time_t timestamp = time(NULL);
    struct tm *current_time = gmtime(&timestamp);

    display_date_tm(current_time);

    // [15]            <1-bit-parité-mois-init>
    // [14]            <1-bit-parité-jour-init>

    // Parité du mois de la date courante
    b_expiration_date |= (current_time->tm_mon & 1) << 15;

    // Parité du jour de la date courante
    b_expiration_date |= (current_time->tm_mday & 1) << 14;

    // [13]            <1-bit-parité-mois>
    // [12]            <1-bit-parité-jour>
    // [11 10 9 8 7]   <5-bits-heure>
    // [6  5  4 3 2 1] <6-bits-min>
    // [0]             <1-bit-sec>

    timestamp += offset;
    struct tm *expiration_date = gmtime(&timestamp);
    
    display_date_tm(expiration_date);

    // Parité du mois
    b_expiration_date |= (expiration_date->tm_mon & 1) << 13;

    // Parité du jour
    b_expiration_date |= (expiration_date->tm_mday & 1) << 12;    

    // Heure
    b_expiration_date |= expiration_date->tm_hour << 7;

    // Minute
    b_expiration_date |= expiration_date->tm_min << 1;

    // Secondes pas de 30 secondes
    // [0-29] => 0
    // [30-59] => 1
    b_expiration_date |= (expiration_date->tm_sec / 30);

    display_16bits_date(b_expiration_date);

    return b_expiration_date;
}

static uint16_t compute_current_date()
{
    return compute_expiration_date(0);
}

static void display_16bits_date(uint16_t date_16)
{
    print_binary(date_16);
    printf("\n");

    printf("%2d:%2d", (date_16 >> 7) & 0x1F, (date_16 >> 1) & 0x3F);
    const char *sec = (date_16 & 1) ? "30-59" : "0-29";
    printf(":%s\n", sec);
}

static void display_date_tm(const struct tm* s_date)
{
    char buffer[26] = {0};

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", s_date);
    puts(buffer);
}

int main()
{
    uint16_t current_date = compute_current_date();
    // uint16_t expiration_date = compute_expiration_date(46800);
    uint16_t expiration_date = compute_expiration_date(30);
    

    // summary_date(expiration_date, current_date);
    // summary_date(current_date, expiration_date);
    // summary_date(current_date, current_date);

    // is_expired(expiration_date, current_date);
    is_expired(current_date, expiration_date);
    
    return 0;
}

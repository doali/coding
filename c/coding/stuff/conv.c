#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

static void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

static uint16_t convert_time_now()
{
    time_t timestamp = time( NULL );
    struct tm * current_time = localtime(&timestamp);

    // Détermination des deca-secondes
    uint16_t btime = (current_time->tm_hour * 3600 + current_time->tm_min * 60 + current_time->tm_sec) / 10;

    // Mois pair alors bit d'indice 15 positionné à 1
    btime |= (current_time->tm_mon & 1) << 15;

    // Jour pair alors bit d'indice 14 positionné à 1
    btime |= (current_time->tm_mday & 1) << 14;

    return btime;
}

static void display_bit(uint16_t digit_16b)
{
    printf("%u\n", digit_16b);
    printf("%d\n", digit_16b);
    printf("%X\n", digit_16b);
    printf("%x\n", digit_16b);
    printf("%o\n", digit_16b);
    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(digit_16b >> 8));
    printf("\n");
    printf("Leading text "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(digit_16b));
    printf("\n");
    print_binary(digit_16b);
    printf("\n");
}

static void display_one_by_one(const char* str)
{
    if (strlen(str) == 0)
    {
        return;
    }

    for (; *str != '\0'; str++)
    {
        putc(*str, stdout);
    }

    printf("\n");
}

static void reverse_str(const char* str)
{
    if (*str == '\0')
    {
        return;
    }
    else
    {
        reverse_str(str + 1);
        putc(*str, stdout);
    }
}

int main()
{
    uint16_t res = convert_time_now();
    display_bit(35);

    display_one_by_one("titi");
    reverse_str("titi");

    return 0;
}
#ifndef _EXP_IOCTL_
#define _EXP_IOCTL_

#include <stdlib.h>
#include <stdio.h>

void display_command_line(int argc, char *argv[])
{
    for(u_int16_t curr_arg = 0; curr_arg < argc; ++curr_arg)
    {
        printf("[%3u]:%s\n", curr_arg, argv[curr_arg]);
    }
}

int main(int argc, char *argv[])
{
    display_command_line(argc, argv);

    return EXIT_SUCCESS;
}

#endif // _EXP_IOCTL_
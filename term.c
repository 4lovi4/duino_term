#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "term.h"

extern int sio_fd;

int init_sio()
{

        return 0;
}

int close_sio()
{

        return 0;
}

int write_sio()
{

        return 0;
}

int read_sio()
{

        return 0;
}

void term_usage(char *pr_str)
{
        fprintf(stderr, "usage: \n"
                        "\t%s [-f <sio name>] [-h]\n"
                        "\t-f - Enter sio device name like /dev/ttyX\n"
                        "\t-h - print this message \n",
                        pr_str);
}

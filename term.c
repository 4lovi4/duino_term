#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>

#include "term.h"

extern int sio_fd;

int init_sio(char *str)
{
        int res;
        struct termios old_tio, new_tio;

#ifdef DEBUG_DUINO
        fprintf(stderr, "In %s\n", __PRETTY_FUNCTION__);
#endif

        if ((res = open((const char*)str, O_RDWR|O_NOCTTY)) < 0) {
                perror("open()");
                return(-1);
        }
        sio_fd = res;
        tcgetattr(sio_fd, &old_tio);
        new_tio = old_tio;
        return res;
}

int close_sio()
{
        int res;

        if ((res = close(sio_fd) < 0)) {
                        perror("close()");
                        return(-1);
                        }
        return res;
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

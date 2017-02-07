#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>

#include "term.h"

extern int sio_fd; // Переменная sio_fd объявлена в main.c

int init_sio(char *str, int baudrate)
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
        // 8N1
        new_tio.c_cflag &= ~PARENB;
        new_tio.c_cflag &= ~CSTOPB;
        new_tio.c_cflag &= ~CSIZE;
        new_tio.c_cflag |= CS8;
        // no flow control
        new_tio.c_cflag &= ~CRTSCTS;

        new_tio.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines
        new_tio.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl

        new_tio.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
        new_tio.c_oflag &= ~OPOST; // make raw

        // see: http://unixwiz.net/techtips/termios-vmin-vtime.html
        new_tio.c_cc[VMIN]  = 0;
        new_tio.c_cc[VTIME] = 20;

        if( tcsetattr(sio_fd, TCSANOW, &new_tio) < 0) {
                perror("init_serialport: Couldn't set term attributes");
                return -2;
        }
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

int write_sio(char *msg_buf)
{

        return 0;
}

int read_sio(char *in_buf)
{

        return 0;
}

void term_usage(char *pr_str)
{
        fprintf(stderr, "usage: \n"
                        "\t%s [-f <sio name>] [-r <baudrate>] [-h]\n"
                        "\t-f - Enter sio device name like /dev/ttyX\n"
                        "\t-r - Enter sio device baudrate like 19200 or 38400\n"
                        "\t-h - print this message \n",
                        pr_str);
}

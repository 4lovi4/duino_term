#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>

#include "term.h"

#define DEV_NAME "/dev/ttyACM0" //Имя COM-порта по умолчанию

extern char *optarg;
extern int optind, opterr, optopt;
int sio_fd;
static char *sio_name;

int main (int argc, char **argv)
{
        int opt,
            baudrate;
        
        sio_name = strdup(DEV_NAME);
        baudrate = B9600;
#ifdef DEBUG_DUINO
        fprintf(stderr, "In %s()\n", __PRETTY_FUNCTION__);
        fprintf(stderr, "default sio_name = %s\n", sio_name);
#endif
        while ((opt = getopt(argc, argv, "f:r:h")) != -1) {
                switch (opt) {
                        case 'f': // Определяется новое имя COM-порта, заданное как аргумент команды в CLI
                                if (!strncmp(optarg, "/dev/tty", 8)) {
                                        sio_name = (char *)realloc(sio_name, (strlen(optarg) * sizeof(char) + 1));
                                        memset(sio_name, 0, sizeof(sio_name));
                                        strncpy(sio_name, optarg, strlen(optarg));
#ifdef DEBUG_DUINO
                                        fprintf(stderr, "current sio_name = %s\n", sio_name);
#endif
                                        break;
                                }
                        case 'r':
                                switch (atol(optarg)) {
                                        case 9600:
                                                break;
                                        case 19200:
                                                baudrate = B19200;
                                                break;
                                        case 38400:
                                                baudrate = B38400;
                                                break;
                                        case 57600:
                                                baudrate = B57600;
                                                break;
                                        default:
                                                break;
                                }
                                break;
                        case 'h':
                                term_usage(argv[0]);
                                break;
                        default:
                                break;
                }
        }
#ifdef DEBUG_DUINO
        fprintf(stderr, "current baudrate = %d\n", baudrate);
#endif
        if ( init_sio(sio_name, baudrate) < 0) {
                free(sio_name);
                exit(1);
        }
        close_sio();
        free(sio_name);
        return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

#include "term.h"

#define DEV_NAME "/dev/ttyACM0"

extern char *optarg;
extern int optind, opterr, optopt;
extern int sio_fd;
static char *sio_name;

int main (int argc, char **argv)
{
        int opt;

        sio_name = strdup(DEV_NAME);
#ifdef DEBUG_DUINO
        fprintf(stderr, "In %s()\n", __PRETTY_FUNCTION__);
        fprintf(stderr, "default sio_name = %s\n", sio_name);
#endif
        while ((opt = getopt(argc, argv, "f:h")) != -1) {
                switch (opt) {
                        case 'f':
                                if (!strncmp(optarg, "/dev/tty", 8)) {
                                        sio_name = (char *)realloc(sio_name, (strlen(optarg) * sizeof(char) + 1));
                                        memset(sio_name, 0, sizeof(sio_name));
                                        strncpy(sio_name, optarg, strlen(optarg));
#ifdef DEBUG_DUINO
                                        fprintf(stderr, "current sio_name = %s\n", sio_name);
#endif
                                        break;
                                }
                        case 'h':
                                term_usage(argv[0]);
                                break;
                        default:
                                break;
                }
        }
        free(sio_name);
        return 0;
}

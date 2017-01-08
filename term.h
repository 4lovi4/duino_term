#ifndef __TERM_DUINO__
#define __TERM_DUINO__
int init_sio();
int close_sio();
int write_sio();
int read_sio();
void term_usage(char *);

int sio_fd;
#endif //__TERM_DUINO__

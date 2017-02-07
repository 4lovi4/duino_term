#ifndef __TERM_DUINO__
#define __TERM_DUINO__
int init_sio(char *str, int baudrate);
int close_sio();
int write_sio(char *msg_buf);
int read_sio(char *in_buf);
void term_usage(char *);

#endif //__TERM_DUINO__

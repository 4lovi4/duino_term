#ifndef __TERM_DUINO__
#define __TERM_DUINO__
int init_sio(char *str);
int close_sio();
int write_sio();
int read_sio();
void term_usage(char *);

#endif //__TERM_DUINO__

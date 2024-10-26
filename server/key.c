#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#include "key.h"


void *th_key_handler(void *arg) {
    volatile char *c = (volatile char *)arg;

    set_noncanon();
    while(*c != SERV_EXIT) *c = getchar();
    set_canon();

    return NULL;
}


void set_noncanon(void) {
    struct termios tm;

    tcgetattr(STDIN_FILENO, &tm);
    tm.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &tm);
}


void set_canon(void) {
    struct termios tm;

    tcgetattr(STDIN_FILENO, &tm);
    tm.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tm);
}

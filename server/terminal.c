#include <unistd.h>
#include <termios.h>


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

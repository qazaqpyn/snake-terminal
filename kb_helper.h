//: KB_HELPER.h
#ifndef KB_HELPER_H
#define KB_HELPER_H

#include <iostream>
#include <sys/select.h>
#include <unistd.h>
#include <termios.h>

void delay_ms(int milisec) { usleep(useconds_t(milisec * 1000)); }
void clear_src(void) { system("clear"); }

// replicate kbhit() from windows <cohio.h>
int khbit(void)
{
    struct timeval tv;
    fd_set read_fd;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&read_fd);
    FD_SET(0, &read_fd);
    if (select(1, &read_fd, NULL, NULL, &tv) == -1)
        return 0;
    if (FD_ISSET(0, &read_fd))
        return 1;
    return 0;
}

// replicate khbit() from windows <cohio.h>
char getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int __khbit(void) { return khbit(); }
char __getch(void) { return getch(); }

#endif //: KB_HELPER_H

#ifndef LINUX_KBHIT_H_
#define LINUX_KBHIT_H_

#include <stdio.h>
#include <termios.h> 	/* struct terminos, tcgetattr(), TCSANOW */
#include <unistd.h> 	/* STDIN_FILENO */

/* STDIN_FILENO : file descriptor for standard input. Mainly 0. */

int linux_kbhit(void)
{
    struct termios oldt, newt;

    /* 	struct termios {
		tcflag_t c_iflag; //
		tcflag_t c_oflag;
		tcflag_t c_cflag;
		tcflag_t c_lflag;
		cc_t c_cc[NCCS];
		speed_t c_ispeed;
		speed_t c_ospeed;
	};
     */

    int ch;

    tcgetattr( STDIN_FILENO, &oldt );

    /* tcgetattr() function
      
       int tcgetattr(int fd, struct termios *termios_p);
     
       int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
     */

    printf("STDIN_FILENO: %d", STDIN_FILENO);
    newt = oldt;

    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

    ch = getchar();

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );

    return ch;
}

#endif

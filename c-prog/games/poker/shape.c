#include <stdio.h>

/*
 *  Made by Jeanseong Baik. 
 *  jsbaik@hanyang.ac.kr
 *
 *  WARNING: USE ONLY FOR HANYANG UNIV. CLASS SYSTEM PROGRAMMING INTRODUCTION.
 *           OTHER COMMERCIAL OR EDUCATIONAL PURPOSES ARE NOT ALLOWED.
 */

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main (void)
{
	printf(
		BOLDMAGENTA
		"┏━━━━━┓\n"
		"┃"SPADE"    ┃\n"
		"┃  K  ┃\n"
		"┃    "SPADE"┃\n"
		"┗━━━━━┛\n"
		RESET
     	);
		
	printf(
		BOLDRED
		"┏━━━━━┓\n"
		"┃"HEART"    ┃\n"
		"┃  6  ┃\n"
		"┃    "HEART"┃\n"
		"┗━━━━━┛\n"
		RESET
	);

	return 0;
}



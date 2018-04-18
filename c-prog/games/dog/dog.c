#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <inttypes.h>
#include <math.h>

static time_t prev_time = 0;

void print_current_time_with_ms (void)
{
	long            ms; // Milliseconds
	time_t          s;  // Seconds
	struct timespec spec;

	clock_gettime(CLOCK_REALTIME, &spec);

	s  = spec.tv_sec;
	ms = round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
	if (ms > 999) {
	s++;
	ms = 0;
	}

	printf("Current time: %"PRIdMAX".%03ld seconds since the Epoch\n",
	   (intmax_t)s, ms);
	}

int breathe(void)
{
	long            ms; // Milliseconds
	time_t          s;  // Seconds
	struct timespec spec;
	clock_gettime(CLOCK_REALTIME, &spec);


	time 
	//time_t curr_time = time(NULL);
	//if(prev_time == 0) prev_time = curr_time;
	int diff = curr_time - prev_time;
	printf("curr : %ld\nprev : %ld\ndiff : %d\n", curr_time, prev_time, diff);
	prev_time = curr_time;
	if(diff > 1) printf("Dog is dead!\n");
	else printf("Dog is alive\n");
	usleep(2000000);
	return diff;
	// struct tm tm = *localtime(&curr_time_t);
	// printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main(int argc, const char* argv[]) 
{
	for(;;) {
		print_current_time_with_ms();
		breathe();
	}
	return 0;
}

// Nastasja radulovic
//Turney Lab 9
// pmod.c

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(int argc, char* argv[]) 
{
    // Reduce process priority by 10
    if (nice(10) == -1 && errno != 0) {
        perror("Error setting process priority");
        return 1;
    }

    // Sleep for 1,837,272,638 nanoseconds (or approximately 1.837 seconds)
    struct timespec sleep_time;
    sleep_time.tv_sec = 1;               // 1 second
    sleep_time.tv_nsec = 837272638;      // 837,272,638 nanoseconds

    if (nanosleep(&sleep_time, NULL) == -1) {
        perror("Error during nanosleep");
        return 1;
    }

    printf("Goodbye!\n");

    return 0;
}

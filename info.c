// Nastasja Radulovic
//Turney Lab 9

// info.c

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <time.h>

int main(int argc, char* argv[])
{
    struct utsname sys_info;         // For system name, OS, etc.
    struct sysinfo mem_info;         // For memory information
    struct timespec current_time;    // For current time
    long num_cpus;                   // For number of CPUs

    // 1. Get the current time in nanoseconds
    if (clock_gettime(CLOCK_REALTIME, &current_time) == -1) {
        perror("clock_gettime");
        return 1;
    }
    printf("Current Time (nanoseconds): %ld\n", current_time.tv_nsec);

    // 2. Get system information (network name, OS name, OS release, OS version, hardware type)
    if (uname(&sys_info) != -1) {
        printf("Network Name: %s\n", sys_info.nodename);
        printf("Operating System: %s\n", sys_info.sysname);
        printf("OS Release: %s\n", sys_info.release);
        printf("OS Version: %s\n", sys_info.version);
        printf("Hardware Type: %s\n", sys_info.machine);
    } else {
        perror("uname");
    }

    // 3. Get the number of CPUs
    num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    if (num_cpus != -1) {
        printf("Number of CPUs: %ld\n", num_cpus);
    } else {
        perror("sysconf (CPU count)");
    }

    // 4. Get memory information
    if (sysinfo(&mem_info) != -1) {
        printf("Total Physical Memory (bytes): %ld\n", mem_info.totalram);
        printf("Total Free Memory (bytes): %ld\n", mem_info.freeram);
    } else {
        perror("sysinfo");
    }

    return 0;
}

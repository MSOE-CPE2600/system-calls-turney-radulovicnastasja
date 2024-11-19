//Nastasja Radulovic
//Turney Lab 9 

#define _GNU_SOURCE  // Enable GNU extensions for sched.h compatibility
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>

/**
 * Function to print the scheduling policy in a human-readable format.
 */
void print_scheduler(int policy) {
    switch (policy) {
        case SCHED_OTHER: printf("Scheduling policy: SCHED_OTHER\n"); break;
        case SCHED_FIFO: printf("Scheduling policy: SCHED_FIFO\n"); break;
        case SCHED_RR: printf("Scheduling policy: SCHED_RR\n"); break;
        case SCHED_BATCH: printf("Scheduling policy: SCHED_BATCH\n"); break;
        case SCHED_IDLE: printf("Scheduling policy: SCHED_IDLE\n"); break;
        case SCHED_DEADLINE: printf("Scheduling policy: SCHED_DEADLINE\n"); break;
        default: printf("Unknown scheduling policy\n"); break;
    }
}

int main(int argc, char *argv[]) {
    // Determine if a process ID (PID) was provided as a command-line argument
    // If no argument is provided, default to the current process ID
    pid_t pid = (argc > 1) ? atoi(argv[1]) : getpid();

    // Retrieve the priority of the specified process
    int priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {  // Check if getting priority failed
        perror("Error getting priority");
        return 1;
    }

    // Retrieve the scheduling policy of the specified process
    int policy = sched_getscheduler(pid);
    if (policy == -1) {  // Check if getting scheduler failed
        perror("Error getting scheduler");
        return 1;
    }

    // Output the process ID
    printf("Process ID: %d\n", pid);
    
    // Output the process priority
    printf("Process priority: %d\n", priority);
    
    // Print the scheduling policy in a readable format
    print_scheduler(policy);

    return 0;
}

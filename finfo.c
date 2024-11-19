// nastasja radulovuc
// turney Lab 9 System Calls
// Section:111

// finfo.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) printf("File Type: Regular file\n");
    else if (S_ISDIR(mode)) printf("File Type: Directory\n");
    else if (S_ISCHR(mode)) printf("File Type: Character device\n");
    else if (S_ISBLK(mode)) printf("File Type: Block device\n");
    else if (S_ISFIFO(mode)) printf("File Type: FIFO/pipe\n");
    else if (S_ISLNK(mode)) printf("File Type: Symbolic link\n");
    else if (S_ISSOCK(mode)) printf("File Type: Socket\n");
    else printf("File Type: Unknown\n");
}

void print_permissions(mode_t mode) {
    printf("Permissions: ");
    printf( (mode & S_IRUSR) ? "r" : "-");
    printf( (mode & S_IWUSR) ? "w" : "-");
    printf( (mode & S_IXUSR) ? "x" : "-");
    printf( (mode & S_IRGRP) ? "r" : "-");
    printf( (mode & S_IWGRP) ? "w" : "-");
    printf( (mode & S_IXGRP) ? "x" : "-");
    printf( (mode & S_IROTH) ? "r" : "-");
    printf( (mode & S_IWOTH) ? "w" : "-");
    printf( (mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == -1) {
        perror("Error retrieving file information");
        return 1;
    }

    // Print file type
    print_file_type(file_stat.st_mode);

    // Print permissions
    print_permissions(file_stat.st_mode);

    // Print file owner
    struct passwd *pwd = getpwuid(file_stat.st_uid);
    if (pwd) {
        printf("Owner: %s (UID: %d)\n", pwd->pw_name, file_stat.st_uid);
    } else {
        printf("Owner UID: %d\n", file_stat.st_uid);
    }

    // Print file size
    printf("File Size: %ld bytes\n", file_stat.st_size);

    // Print last modification time
    char mod_time[20];
    strftime(mod_time, sizeof(mod_time), "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_mtime));
    printf("Last Modified: %s\n", mod_time);

    return 0;
}

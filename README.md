# Lab 9 - System Calls

## Overview

This project is part of the CPE-2600 Systems Programming course and involves working with POSIX system calls on a Linux operating system. The purpose of this lab is to gain familiarity with commonly used system calls in the following categories:
- Information Maintenance
- Process Control
- File Management

### Programs

This project includes the following four programs:

1. **info.c** - Displays general system information such as system uptime, memory usage, and CPU information.
2. **pinfo.c** - Displays process information for a specified or current process, including its priority and scheduling policy.
3. **pmod.c** - Modifies its own process priority and pauses execution for a set amount of time.
4. **finfo.c** - Displays file information, including file type, permissions, owner, size, and last modification date.

### Files

- **info.c**: Program to display various system information like uptime, memory usage, and CPU statistics.
- **pinfo.c**: Program to retrieve and display process information for a specified process (PID), including its priority and scheduling policy.
- **pmod.c**: Program that changes the priority of its own process and then sleeps for a specified duration.
- **finfo.c**: Program that displays detailed information about a specified file, such as its type, permissions, owner, and last modification date.
- **Makefile**: A Makefile to compile all the programs.
- **README.md**: Documentation for the project.

## Compilation

To compile all the programs, run:

```bash
make

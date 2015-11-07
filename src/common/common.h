#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdbool.h>

/* Default server port */
#define TG_SERVER_PORT 5001
/* Default number of backlogged connections for listen() */
#define TG_SERVER_BACKLOG_CONN SOMAXCONN
/* Maximum amount of data to write in a 'send' system call */
#define TG_MAX_WRITE 1048576 //1MB
/* Minimum amount of data to write in a 'send' system call (used with rate limiting) */
#define TG_MIN_WRITE 65536   //64KB
/* Default number of TCP connections per pair */
#define TG_PAIR_CONN 3


/* I borrow following three functions from https://github.com/datacenter/empirical-traffic-gen. Thanks Mohammod! */
unsigned int read_exact(int fd, char *buf, size_t count,
    size_t max_per_read, bool dummy_buf);

unsigned int write_exact(int fd, char *buf, size_t count, size_t max_per_write,
    unsigned int rate_mbps, unsigned int tos, unsigned int usleep_overhead_us, bool dummy_buf);

/* Print error information and terminate the program */
void error(char *msg);

/* Remove \r \n from a string */
void remove_newline(char *str);

/* Generate poission process arrival interval */
double poission_gen_interval(double avg_rate);

#endif

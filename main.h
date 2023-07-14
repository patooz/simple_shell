#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

/** c_data functions */
void cdata_t(data_t *);
void sdata_t(data_t *, char **);
void fdata_t(data_t *, int);

/** our_strings.c functions */
int our_putchar(char);
void our_puts(char *);
char *our_strdup(const char *);
char *our_strcpy(char *, char *);

/** our_string.c functions */
int our_strcmp(char *, char *);
char *first_char(const char *, const char *);
int our_strlen(char *);
char *our_strcat(char *, char *);

/** our_errors.c functions */
int our_putnode(char, int);
void our_eputs(char *);
int our_putnodes(char *, int);
int our_eputchar(char);


#endif /** MAIN_H */

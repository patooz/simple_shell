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

/** our_error.c functions */
int strip_c(char *);
int show_fig(int, int);
void show_emsg(data_t *, char *);
char *novit_char(long int, int, int);
void novit_words(char *);

/** our_list.c functions */
node_t *a_listn(node_t **, const char *, int);
node_t *a_listn_last(node_t **, const char *, int)
size_t show_listn_s(const node_t *);
int rm_listn(node_t **, unsigned int);
void claim_list_mem(node_t **);

/** final.c function */
char street(char *, char *);
char street2(char *, char);

/** local.c function */
char * our_memset(char *, char, unsigned int);
void_free(char *);
void * alloc(void *, unsigned int, unsigned int);

/** think.c function */
int free_all(void **);

/** get.c function */
int active(d_t *);
int denim(char, char *);
int our_isalpha(int);
int stoi(char *);

/** pass.c function */
int pass(data_t *, char *);
char *new_char(char *, int, int);
char *our_path(data_t *, char *, char *);

/** geo.c function */
char *geo file(data_t *i);
int geo write(data_t *i);
int geo read(data_t *i);
int geo list(data_t *i, char *buf, int linecount);
int geo renumber(data_t *i);

/** ariel.c function */
char get(data_t *, const char *);
int env(data_t *);
int my set(data_t *);
int my unset(data_t *);
int my list(data_t *);

/** general.c function */
char general(data_t *);
int micro(data_t *, char *);
int mini(data_t *, char *, char *);

/** our_lists.c functions */
size_t show_l(const node_t *);
size_t size_l(const node_t *);
char **convert_s(node_t *);
node_t *init_form(node_t *, char *, char);
ssize_t node_i(node_t *, node_t *);

/** inherited.c functions */
int our_quit(data_t *);
int our_dir(data_t *);
int our_help(data_t *);


#endif /** MAIN_H */

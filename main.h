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

/** BUFFERS */
#define BUFF_READ 1024
#define BUFF_WRITE 1024
#define FLUSH -1

/** CHAINING COMMANDS */
#define C_NORM  0
#define C_O 1
#define C_A 2
#define C_C 3

/** for novit_char in our_sec_errors.c */
#define NOVIT_LOWER 1
#define NOVIT_UNSIGNED 2

/** for inbuilt getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE   ".shell_history"
#define HIST_MAX    4096


extern char **environ;


/**
 * struct list_struct - linked list
 * @num: number
 * @s: string
 * @in: node pointer
 */
typedef struct list_struct
{
	int num;
	char *s;
	struct list_struct *in;
} node_t;

/**
 * struct inf_P - function arguments
 * @d_buff_t: CMD type
 * @d_buff: address to the d_buff pointer
 * @_file: filename
 * @hist: node to the history
 * @env: local environment
 * @otherwise: aliase node
 * @argc: argument count
 * @p: command path
 * @envi_shift: environment shift
 * @environ: customed environment
 * @emblem_ln: line of input
 * @condition: status of the lst command
 * @argv: argument array
 * @char_fail: exit error code
 * @arg: string from find_line
 * @command_t: for error count
 * @fd_read: read line fd
 * @c_line: address pointer
 * @hist_c: history count
 * @ren_counter: error counter
 */

typedef struct inf_P
{
	int d_buff_t;
	char **d_buff;
	char *_file;
	node_t *hist;
	node_t *env;
	node_t *otherwise;
	int argc;
	char *p;
	int envi_shift;
	char **environ;
	int emblem_ln;
	int condition;
	char **argv;
	int char_fail;
	char *arg;
	int command_t;
	int fd_read;
	int c_line;
	int hist_c;
	unsigned int ren_counter;
} data_t;

#define DATA_IT \
{0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, NULL, 0, 0, \
NULL, 0, NULL, 0, 0, 0, 0, 0}

/**
 * struct sysd - for builtin string
 * @func: function
 * @type: command flag
 */
typedef struct sysd
{
	char *type;
	int (*func)(data_t *);
} sys_data;


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
node_t *a_listn_last(node_t **, const char *, int);
size_t show_listn_s(const node_t *);
int rm_listn(node_t **, unsigned int);
void claim_list_mem(node_t **);

/** final.c function */
char **street(char *, char *);
char **street2(char *, char);

/** local.c function */
char *our_memset(char *, char, unsigned int);
void _free(char **);
void *alloc(void *, unsigned int, unsigned int);

/** think.c function */
int free_all(void **);

/** get.c function */
int active(data_t *);
int denim(char, char *);
int our_isalpha(int);
int stoi(char *);

/** pass.c function */
int pass(data_t *, char *);
char *new_char(char *, int, int);
char *our_path(data_t *, char *, char *);

/** geo.c function */
char *geofile(data_t *i);
int geowrite(data_t *i);
int georead(data_t *i);
int geolist(data_t *i, char *buf, int linecount);
int georenumber(data_t *i);

/** ariel.c function */
char * get(data_t *, const char *);
int our_env(data_t *);
int our_set(data_t *);
int our_unset(data_t *);
int our_list(data_t *);

/** general.c function */
char **general(data_t *);
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

/** inherits.c functions */
int our_hist(data_t *);
int remove_otherwise(data_t *, char *);
int add_otherwise(data_t *, char *);
int show_otherwise(node_t *);
int our_otherwise(data_t *);

/** find_line.c functions */
ssize_t find_input(data_t *);
int find_ln(data_t *, char **, size_t *);
ssize_t b_read(data_t *, char *, size_t *);
ssize_t b_input(data_t *, char **, size_t *);
void sig_h(__attribute__((unused)) int);

/** toka.c functions */
char *our_strchr(char *, char);
char *our_strncat(char *, char *, int);
char *our_strncpy(char *, char *, int);

/** commands.c functions */
int is_c_command(data_t *, char *, size_t *);
void find_command(data_t *, char *, size_t *, size_t, size_t);
int r_command(data_t *);
int other_wise_command(data_t *);
int rs_command(char **, char *);

/** loop.c functions */
int loop(data_t *, char **);
int get_inherent(data_t *);
void get_d(data_t *);
void hook_c(data_t *);



#endif /** MAIN_H */

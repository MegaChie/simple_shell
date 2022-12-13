#ifndef someShell
#define someShell

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* values commenly used*/
#define bufFlush -1 
#define infoStart {NULL, NULL, NULL, 0, 0, 0, 0,
 NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0, 0}
#define writeBufferSize 1024
#define cmdOr 1
#define cmdAnd 2
#define cmdChain 3
#define cmdNormal
#define useGetLine 0
#define readBufferSize 1024

/* functions */
void _eputs(char *str);
int interactive(info_t *info);
void sigintHandler(__attribute__((unused))int sig_num);
int _getline(info_t *info, char **ptr, size_t *length);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
ssize_t get_input(info_t *info);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
int replace_string(char **old, char *new);
int replace_vars(info_t *info);
int replace_alias(info_t *info);
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int is_chain(info_t *info, char *buf, size_t *p);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);
int _eputchar (char c);
int _putfd(char c, int fileDire);
int _putsfd(char *str, int fileDire);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **headPointer);
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);
int bfree(void **ptr);
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif

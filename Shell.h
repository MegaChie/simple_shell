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

/* functions */
void _eputs(char *str);
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
#endif

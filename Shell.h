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
#endif

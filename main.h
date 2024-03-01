#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
extern char **environ;

char** split_string(char *string, size_t nbr_char);
int f_strcmp(const char *str1, const char *str2);

#endif

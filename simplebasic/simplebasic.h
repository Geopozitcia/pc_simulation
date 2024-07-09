#pragma once
#include "../include/mySimpleComputer.h"
#include "../mySimpleComputer/sc.h"
#include "sb_variables.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

char sb_getVarName (int varAddr, int offset);
int sb_getGotoAddr (int gotoLine);
void sb_clearBackspace (char *str);
int sb_getVarAddr (char varName, int offset);
int sa_memorySet (int address, int value);
int sa_commandValidate (char *command);
int basicToAss (FILE *file_sb, FILE *file_sa, char **argv, int flag);
int basicToAssembler (FILE *file_sb, FILE *file_sa, char **argv, int flag);
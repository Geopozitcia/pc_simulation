#include "../include/mySimpleComputer.h"
#include "../mySimpleComputer/sc.h"
#include "sb_variables.h"
#include "simplebasic.h"
// 10 REM коммент
// 20 INPUT A
// 30 INPUT B
// 40 LET C = A - B
// 50 IF C < 0 GOTO 20
// 60 PRINT C
// 70 END
int
main (int argc, char **argv)
{
  FILE *file_sb, *file_sa;

  if ((file_sb = fopen (argv[1], "rb")) <= 0)
    {
      printf ("Can`t open '%s' file.\n", argv[1]);
      return -1;
    }
  if ((file_sa = fopen (argv[2], "wb")) <= 0)
    {
      printf ("Can`t create '%s' file.\n", argv[2]);
      return -1;
    }

  if (argc != 4)
    {
      printf ("Usage: sbt file.sb file.sa -a/file.o\n ");
      return -1;
    }
  printf ("Basic file is open\n");
  if (strcmp (argv[3], "-a") == 0)
    {
      basicToAssembler (file_sb, file_sa, argv, 1);
    }
  else
    {
      basicToAssembler (file_sb, file_sa, argv, 2);
      fclose (file_sa);
      exit (0);
    }
  return 0;
}
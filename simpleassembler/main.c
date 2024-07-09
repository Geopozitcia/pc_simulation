#include "../include/mySimpleComputer.h"
#include "../mySimpleComputer/sc.h"
#include "simpleassembler.h"

int
main (int argc, char **argv)
{
  FILE *file_sa, *file_o;
  if (argc != 3)
    {
      printf ("Формат: ./sat file.sa file.o\n ");
      return -1;
    }
  if ((file_sa = fopen (argv[1], "rb")) <= 0)
    {
      printf ("Не удалось открыть '%s'.\n", argv[1]);
      return -1;
    }
  printf ("Файл открыт\n");
  sc_memoryInit ();
  char line[100], ch, comment[10], operandLine[10], commentLine[100] = "\0";
  int value, address, command, operand;
  do
    {
      fgets (line, sizeof (line), file_sa);
      if (feof (file_sa))
        {
          break;
        }
      if (sscanf (line, "%d %s %s ;%s", &address, comment, operandLine,
                  commentLine)
          < 3)
        {
          printf ("Проверьте ввод\n");
          return -1;
        }
      command = sa_commandValidate (comment);
      printf ("%d %d %s\n", address, command, operandLine);
      if (command != -1)
        {
          if (command != 1)
            {
              if (sscanf (operandLine, "%d", &operand) != 1
                  || sc_commandEncode (command, operand, &value) == -1
                  || sa_memorySet (address, value) == -1)
                {
                  printf ("Проверьте ввод\n");
                  return -1;
                }
            }
          else
            {
              if (sscanf (operandLine, "%c%04X", &ch, &value) != 2)
                {
                  printf ("Проверьте ввод\n");
                  return -1;
                }
              if (ch == '-')
                {
                  value = -value;
                }
              if (sa_memorySet (address, value) == -1)
                {
                  printf ("Проверьте ввод\n");
                  return -1;
                }
            }
        }
      else
        {
          printf ("Проверьте ввод\n");
          return -1;
        }
    }
  while (!feof (file_sa));
  fclose (file_sa);
  if (sc_memorySave (argv[2]) == -1)
    {
      printf ("Не удалось создать '%s'.\n", argv[2]);
      return -1;
    }
  return 0;
}
#include "../include/console.h"

int
font (char *filename)
{
  FILE *file;
  file = fopen (filename, "wb");
  if (file == NULL)
    {
      printf ("Че не открывается?.\n");
      return -1;
    }

  if (fwrite (bc, sizeof (int), 19, file) != 19)
    {
      fprintf (stderr, "Ошибка записи в файл\n");
      fclose (file);
      return -1;
    }
  fclose (file);
  return 0;
}
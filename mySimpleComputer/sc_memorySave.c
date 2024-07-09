#include <mySimpleComputer.h>
#include <sc.h>

int
sc_memorySave (char *filename)
{
  FILE *addressData = fopen (filename, "wb");
  if (addressData == NULL)
    {
      perror ("Не удалось открыть файл");
      return -1;
    }

  if (fwrite (memory, sizeof (int), 128, addressData) != 128)
    {
      fprintf (stderr, "Ошибка записи в файл\n");
      fclose (addressData);
      return -1;
    }

  fclose (addressData);

  return 0;
}
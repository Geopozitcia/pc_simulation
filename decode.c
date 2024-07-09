#include <stdio.h>

#define SC_COMMAND_SIGN_MASK 0x8000
#define SC_COMMAND_MASK 0x7F00
#define SC_COMMAND_OPERAND_MASK 0xFF

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if (value < 0 || value > 0xFFFF)
    {
      return -1; // Некорректное значение
    }

  *sign = (value & SC_COMMAND_SIGN_MASK) ? -1 : 1;
  *command = (value & SC_COMMAND_MASK) >> 8;
  *operand = value & SC_COMMAND_OPERAND_MASK;

  return 0; // Успешное декодирование
}

int
main ()
{
  int value = 0xA123; // Пример значения в ячейке памяти

  int sign, command, operand;
  if (sc_commandDecode (value, &sign, &command, &operand) == 0)
    {
      printf ("Sign: %d\n", sign);
      printf ("Command: %d\n", command);
      printf ("Operand: %d\n", operand);
    }
  else
    {
      printf ("Ошибка при декодировании\n");
    }

  return 0;
}
#include "../include/mySimpleComputer.h"
#include "../mySimpleComputer/sc.h"
#include "simplebasic.h"

int
sa_memorySet (int address, int value)
{
  if ((address < 0 || address > 128) || (value < 0 || value > 65535))
    {
      sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
      printf ("ОШИБКА: ВЫХОД ЗА ГРАНИЦЫ ПАМЯТИ, address: %x\n", address);
      return -1;
    }
  memory[address] = value;
  return 0;
}
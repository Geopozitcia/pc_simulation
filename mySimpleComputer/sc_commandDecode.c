#include <mySimpleComputer.h>
#include <sc.h>

int
sc_commandDecode (int value, int *command, int *operand)
{
  int tmpCom = 0, tmpOp = 0;
  if ((value >> 14) & 1)
    {
      sc_regSet (INCORRECT_COMMAND_RECEIVED, 4);
      return -1;
    }

  for (int i = 0; i < 7; i++)
    {
      int bit = (value >> i) & 1;
      tmpOp |= (bit << i);
    }

  for (int i = 0; i < 7; i++)
    {
      int bit = (value >> (i + 7)) & 1;
      tmpCom |= (bit << i);
    }

  *command = tmpCom;
  *operand = tmpOp;
  return 0;
}
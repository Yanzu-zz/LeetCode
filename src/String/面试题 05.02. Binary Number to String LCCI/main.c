#include <stdio.h>
#include <string.h>

#define ESP 1e-32

char *printBin(double num)
{
  int idx = 2;
  double tmp;
  char *res = (char *)malloc(33 * sizeof(char));
  res[0] = '0';
  res[1] = '.';

  while (fabs(num) >= ESP && idx < 33)
  {
    tmp = num * 2;
    if (tmp >= 1)
    {
      res[idx] = '1';
      tmp -= 1;
    }
    else
    {
      res[idx] = '0';
    }

    idx++;
    num = tmp;
  }

  if (idx >= 33)
  {
    res = "ERROR";
  }
  else
  {
    res[idx] = '\0';
  }

  return res;
}

int main(int argc, char *argv[])
{

  return 0;
}
#include <stdio.h>
#include <assert.h>
#include <limits.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **mergeSimilarItems(int **items1, int items1Size, int *items1ColSize, int **items2, int items2Size, int *items2ColSize, int *returnSize, int **returnColumnSizes)
{
  int **tmp = (int **)malloc(1001 * sizeof(int *)); // Dynamically malloc 2D-Array

  if (tmp == NULL)
  {
    exit(0);
  }

  for (int i = 0; i < 1001; i++)
  {
    tmp[i] = (int *)malloc(2 * sizeof(int));
    if (tmp[i] == NULL)
    {
      exit(0);
    }

    tmp[i][0] = i;
    tmp[i][1] = 0;
  }

  int len = 1;
  for (int i = 0; i < items1Size; i++)
  {
    if (tmp[items1[i][0]][1] == 0)
      len++;
    tmp[items1[i][0]][1] += items1[i][1];
  }

  for (int i = 0; i < items2Size; i++)
  {
    if (tmp[items2[i][0]][1] == 0)
      len++;
    tmp[items2[i][0]][1] += items2[i][1];
  }

  int **ret = (int **)malloc(len * sizeof(int *));
  for (int i = 0; i < len; i++)
  {
    ret[i] = (int *)malloc(2 * sizeof(int));

    if (ret[i] == NULL)
    {
      exit(0);
    }
  }

  int idx = 0;
  for (int i = 1; i < 1001 && idx < len; i++)
  {
    if (tmp[i][1] != 0)
    {
      ret[idx][0] = i;
      ret[idx][1] = tmp[i][1];
      idx++;
    }
  }

  *returnSize = len - 1;
  *returnColumnSizes = (int *)malloc(sizeof(int) * len);
  for (int i = 0; i < len; i++)
  {
    (*returnColumnSizes)[i] = 2;
  }

  return ret;
}

int main(int argc, char *argv[])
{

  return 0;
}
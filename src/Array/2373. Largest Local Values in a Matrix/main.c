int maxVal(int **grid, int curI, int curJ)
{
  int i, j, res = -1;

  for (i = curI; i <= curI + 2; i++)
  {
    for (j = curJ; j <= curJ + 2; j++)
      if (grid[i][j] > res)
        res = grid[i][j];
  }

  return res;
}

int **largestLocal(int **grid, int gridSize, int *gridColSize, int *returnSize, int **returnColumnSizes)
{
  int len = gridSize - 2;
  int **res = (int **)calloc(len, sizeof(int *));
  if (res == NULL)
    exit(0);

  for (int i = 0; i < len; i++)
  {
    res[i] = (int *)calloc(len, sizeof(int));
    if (res[i] == NULL)
      exit(0);
  }

  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len; j++)
      res[i][j] = maxVal(grid, i, j);
  }

  *returnSize = len;
  *returnColumnSizes = (int *)calloc(len, sizeof(int));
  for (int i = 0; i < len; i++)
  {
    (*returnColumnSizes)[i] = len;
  }

  return res;
}
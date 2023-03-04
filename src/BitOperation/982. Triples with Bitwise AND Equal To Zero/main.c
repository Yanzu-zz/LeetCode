#include <stdio.h>
#include <assert.h>
#include <limits.h>

int countTriplets(int *nums, int numsSize)
{
  int i, j, cnt = 0, len = 1 << 16;
  int x, maxVal = -1;
  int *mark = (int *)calloc(sizeof(int), len);

  for (i = 0; i < numsSize; i++)
  {
    x = nums[i];
    // 由于相同索引也算，故 i,j 可以相等
    for (j = 0; j < numsSize; j++)
    {
      mark[x & nums[j]]++;
    }

    if (x > maxVal)
      maxVal = x;
  }

  // 然后就是用 nums 中的每个元素与上面的 mark 数组中存储的结果作 and&
  // 相当于上面的两层循环是 i&j，这里就是 (i&j) & k
  for (i = 0; i < numsSize; i++)
  {
    j = 0;
    x = nums[i];
    for (; j <= maxVal; j++)
      if (!(x & j))
        cnt += mark[j];
  }

  return cnt;
}

int main(int argc, char *argv[])
{
  int arr1[] = {2, 1, 3}, arr2[] = {0, 0, 0};
  int res1 = countTriplets(arr1, 3);
  int res2 = countTriplets(arr2, 3);
  printf("%d---%d\n", res1, res2);

  return 0;
}
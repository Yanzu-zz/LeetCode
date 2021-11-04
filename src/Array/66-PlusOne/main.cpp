#include <iostream>
#include <vector>

using namespace std;

class Solution66
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int len = digits.size() - 1;

    // 当没遇到 9 时，游标从后往前走，且把 9 置零
    // 到遇到不是 9 的元素就停下，+1 即可（当然要考虑 9999 这种需要扩容情况）
    int curIndex = len;
    while (curIndex >= 0 && digits[curIndex] == 9)
      digits[curIndex--] = 0;

    if (curIndex >= 0)
    {
      digits[curIndex]++;
      return digits;
    }
    else
    {
      vector<int> ret(len + 2, 0);
      ret[0] = 1;
      return ret;
    }
  }
};

int main(void)
{
  vector<int> arr1 = {1, 2, 3};
  vector<int> arr2 = {6, 9, 9};
  vector<int> arr3 = {9, 9, 9, 9};

  Solution66 so;
  vector<int> ret1 = so.plusOne(arr1);
  for (int i = 0; i < arr1.size(); i++)
    cout << ret1[i];
  cout << endl;

  vector<int> ret2 = so.plusOne(arr2);
  for (int i = 0; i < arr2.size(); i++)
    cout << ret2[i];
  cout << endl;

  vector<int> ret3 = so.plusOne(arr3);
  for (int i = 0; i < arr3.size(); i++)
    cout << ret3[i];
  cout << endl;

  return 0;
}

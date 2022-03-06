#include <iostream>
#include <vector>

using namespace std;

class Solution534
{
private:
  void swap(vector<char> &s, int i, int j)
  {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }

public:
  void reverseString(vector<char> &s)
  {
    int n = s.size();
    int l = 0, r = n - 1;

    // 边界条件是左指针小于右指针的位置索引
    while (l < r)
      swap(s, l++, r--);
  }
};

int main(void)
{

  return 0;
}

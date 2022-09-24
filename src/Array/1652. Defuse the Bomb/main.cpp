#include <iostream>
#include <vector>

using namespace std;

class Solution1652
{
public:
  vector<int> decrypt(vector<int> &code, int k)
  {
    int n = code.size();
    vector<int> res(n, 0);
    if (k == 0)
      return res;

    int n2 = n << 1;
    vector<int> s(n2 + 1, 0);
    // 计算前缀和
    for (int i = 0; i < n2; i++)
      s[i + 1] = s[i] + code[i % n];

    if (k > 0)
    {
      for (int i = 0; i < n; i++)
        res[i] = s[i + k + 1] - s[i + 1];
    }
    else
    {
      for (int i = 0; i < n; i++)
        res[i] = s[i + n] - s[i + k + n];
    }

    return res;
  }
};

int main(void)
{

  return 0;
}

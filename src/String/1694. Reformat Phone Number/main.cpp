#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string reformatNumber(string number)
  {
    int n = number.size(), cnt = 0;
    string res = "";

    // 将非数字都去掉，然后每三个字母字符就加个 -
    for (char ch : number)
    {
      if (ch >= '0' && ch <= '9')
      {
        res += ch;
        cnt++;
      }

      if (cnt == 3)
      {
        res += '-';
        cnt = 0;
      }
    }

    if (res[res.size() - 1] == '-')
      res.erase(n - 1, 1);

    n = res.size();
    if (res[n - 2] == '-')
      swap(res, n - 2, n - 3);

    return res;
  }

  void swap(string &str, int a, int b)
  {
    char ch = str[a];
    str[a] = str[b];
    str[b] = ch;
  }
};

int main(void)
{

  return 0;
}

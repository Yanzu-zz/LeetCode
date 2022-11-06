#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string interpret(string command)
  {
    int n = command.size();
    string res = "";

    int i = 0;
    while (i < n)
    {
      int j = i;
      // 没遇到括号的情况直接入返回值
      if (command[i] != '(')
      {
        res += command[i++];
      }
      else
      {
        // 遇到了则将中间的字符串提取
        j = i + 1;
        while (j < n && command[j] != ')')
          res += command[j++];

        // 空的话就加 o
        if (j == i + 1)
          res += 'o';
      }
      i = j + 1;
    }

    return res;
  }
};

int main(void)
{
  string s1 = "G()(al)";
  Solution().interpret(s1);

  return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

class Solution1816
{
public:
  string truncateSentence(string s, int k)
  {
    int n = s.size();
    int i = 0;

    // 开始走过空格数量
    for (; i < n && k > 0; i++)
      if (s[i] == ' ')
        k--;

    return k == 0 ? s.substr(0, i - 1) : s;
  }
};

int main(void)
{
  string s1 = "this is a happ world!";
  int k1 = 3;
  cout << Solution1816().truncateSentence(s1, k1) << endl;

  string s2 = "this is asnadfn dsgf world!";
  int k2 = 10;
  cout << Solution1816().truncateSentence(s2, k2) << endl;

  return 0;
}

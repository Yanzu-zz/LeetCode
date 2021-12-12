#include <iostream>
#include <vector>

using namespace std;

class Solution709
{
public:
  string toLowerCase(string s)
  {
    // 只处理大写字母
    for (auto &ch : s)
      if (ch >= 'A' && ch <= 'Z')
        ch += 32;

    return s;
  }
};

int main(void)
{

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution1108
{
public:
  string defangIPaddr(string address)
  {
    int n = address.size();
    string res = "";

    for (int i = 0; i < n; i++)
    {
      char ch = address[i];
      if (ch != '.')
        res += ch;
      else
        res += "[.]";
    }

    return res;
  }
};

int main()
{

  return 0;
}
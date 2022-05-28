#include <iostream>
#include <stack>

using namespace std;

class Solution1021
{
public:
  string removeOuterParentheses(string s)
  {
    int n = s.size();
    stack<char> st;
    string res = "";

    // 也就是找到外层对应的 ( 的 )
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ')')
        st.pop();

      if (st.empty())
      {
        res += s.substr(prev, i - prev);
        prev = i + 1;
      }

      if (s[i] == '(')
        st.emplace('(');
    }

    return res;
  }
};

int main()
{

  return 0;
}
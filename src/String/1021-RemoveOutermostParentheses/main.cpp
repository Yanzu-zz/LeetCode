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

    for (char &ch : s)
    {
      if (ch == ')')
        st.pop();

      if (!st.empty())
        res += ch;
      if (ch == '(')
        st.emplace(ch);
    }

    return res;
  }
};

int main()
{

  return 0;
}
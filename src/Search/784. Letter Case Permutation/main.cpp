#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<string> letterCasePermutation(string s)
  {
    vector<string> ans;
    queue<string> qu;
    qu.emplace("");
    while (!qu.empty())
    {
      string &curr = qu.front();
      if (curr.size() == s.size())
      {
        ans.emplace_back(curr);
        qu.pop();
      }
      else
      {
        int pos = curr.size();
        if (isalpha(s[pos]))
        {
          string next = curr;
          next.push_back(s[pos] ^ 32);
          qu.emplace(next);
        }
        curr.push_back(s[pos]);
      }
    }
    return ans;
  }
};

int main(void)
{
  string str1 = "a1b2c34";
  Solution().letterCasePermutation(str1);

  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution804
{
public:
  int uniqueMorseRepresentations(vector<string> &words)
  {
    int n = words.size();
    unordered_set<string> set;
    vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    for (string &word : words)
    {
      // 拼接每一个单词对应的摩尔斯密码
      string tmp = "";
      for (char &ch : word)
        tmp.append(morse[ch - 'a']);

      // 然后去重加入哈希表
      set.insert(tmp);
    }

    // 最后的哈希表长度就是答案
    return set.size();
  }
};

int main(void)
{

  return 0;
}

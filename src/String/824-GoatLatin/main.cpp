#include <iostream>
#include <vector>

using namespace std;

class Solution824
{
private:
  bool isVowel(char ch)
  {
    if (ch >= 'A' && ch <= 'Z')
      ch += 32;
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
  }

public:
  string toGoatLatin(string sentence)
  {
    int n = sentence.size(), aCnt = 1;
    string res = "";

    for (int i = 0; i < n; i++)
    {
      // 寻找当前 word 开头结尾
      int j = i + 1;
      for (; j < n && sentence[j] != ' '; j++)
        ;

      // 截取当前 word，然后下面进行题目要求的处理
      string tmp = sentence.substr(i, j - i);
      // 非元音开头字符串需要将开头结尾字符挪到结尾
      if (!isVowel(tmp[0]))
      {
        char headCh = tmp[0];
        tmp.erase(0, 1);
        tmp += headCh;
      }

      // 接着就是加上 ma 字符串
      tmp.append("ma");
      // 然后加上相应数字的 a 字符
      tmp.insert(tmp.size() - 1, aCnt++, 'a');

      // 然后就是加入 res 中
      res.append(tmp + ' ');

      // 到下个单词开头去
      i = j;
    }

    // 去掉结尾空格
    return res.substr(0, res.size() - 1);
  }
};

int main(void)
{
  string str1 = "I speak Goat Latin";
  cout << Solution824().toGoatLatin(str1) << endl;

  return 0;
}

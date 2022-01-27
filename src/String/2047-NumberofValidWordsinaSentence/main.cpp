#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

class Solution2047
{
public:
  int countValidWords(string sentence)
  {
    /**
     * 写一个正则表达式去匹配题目要求的式子，即下面的情况是错误的
     * 单词中包含数字；
     * 单词中包含两个以上连字符；
     * 连字符在单词头部或者单词末尾；
     * 连字符的左/右边字符不是小写字母；
     * 单词中的标点符号不在单词的末尾。
     */
    // 这个正则的意思是：开头必须是字母字符，中间可以是字母和连字符，末尾可以是字母字符和三个标点
    regex ex("[a-z]*([a-z]-[a-z])?[a-z]*[!,.]?");

    istringstream ss(sentence);
    string token;
    int res = 0;

    // 将 ss 以空格为分隔，逐个逐个 word 传给 ss
    while (ss >> token)
      // 如果正则正确匹配上了，则表示当前 word 是个合法的，总合法 word 个数+1
      if (regex_match(token, ex))
        res++;

    return res;
  }
};

int main(void)
{

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution937
{
public:
  vector<string> reorderLogFiles(vector<string> &logs)
  {
    // 用稳定排序可以解决 digit-log 类型原先顺序要求
    stable_sort(logs.begin(), logs.end(),
      [&](const string &log1, const string &log2)
      {
        // 获取真正 log 内容下标前一个空格索引
        int pos1 = log1.find_first_of(" ");
        int pos2 = log2.find_first_of(" ");
        // 判断是 letter-log 还是 digit-log 类型
        bool isDigit1 = isdigit(log1[pos1 + 1]);
        bool isDigit2 = isdigit(log2[pos2 + 1]);

        // 如果是 digit-log 类型则简单按照原先顺序
        if (isDigit1 && isDigit2)
          return false;

        // 如果两个都是 letter-log 类型则按照字典序排序
        if (!isDigit1 && !isDigit2)
        {
          string s1 = log1.substr(pos1);
          string s2 = log2.substr(pos2);
          // 字典序
          if (s1 != s2)
            return s1 < s2;

          // 若相等则比较 Letter 里面的数字
          return log1 < log2;
        }

        // 如果是两个类型比较则 letter-log 优先
        return isDigit1 ? false : true;
      });

    return logs;
  }
};

int main(void)
{

  return 0;
}

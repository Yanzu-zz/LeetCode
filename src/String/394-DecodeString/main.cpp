#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution394
{
public:
  string decodeString(string s)
  {
    int n = s.size();
    int currRepeatedNum = 0;     // 记录当前需要重复多少次的数字
    string currRepeatedStr = ""; // 纪律当前需要重复的字符（串）
    //  用栈是因为可能出现括号嵌套的情况，比如 2[a2[bc]]，这样必须要用栈解决里面的重复再弄外面的
    stack<int> numStk;    // 存放当前需要重复多少次的数字的栈
    stack<string> strStk; // 存放当前需要重复的字符串（串）的栈

    string retStr = "";
    for (int i = 0; i < n; i++)
    {
      // 下面判断四种情况
      if (s[i] >= '0' && s[i] <= '9') // 数字情况，有可能为三位数字 123，出现 123次
      {
        currRepeatedNum = currRepeatedNum * 10 + s[i] - '0';
      }
      else if (s[i] == '[') // 左括号情况，这时就要将‘[’前的数字压入nums栈内， （到这个位置前面已经重复好的）字母字符串压入strs栈内
      {
        // 入栈重复次数数字
        numStk.push(currRepeatedNum);
        currRepeatedNum = 0;

        // 入栈需要重复字符串
        strStk.push(currRepeatedStr);
        currRepeatedStr = "";
      }
      else if (s[i] == ']') // 右括号情况，这时就要进行字符串重复拼接操作了
      {
        int repeatedTimes = numStk.top();
        numStk.pop();

        for (int j = 0; j < repeatedTimes; j++) // 重复 times 次
        {
          // 这里的 strStk.top() 是上层 [] 里面的待重复字符串，和上层合并后最终是要和它再和上上层重复数字一起重复的
          strStk.top() += currRepeatedStr;
        }
        
        currRepeatedStr = strStk.top();
        strStk.pop();
      }
      else // 这个就是 字符 情况，上面的字符串重复拼接就是靠这里累加起来的
      {
        currRepeatedStr += s[i];
      }
    }

    return currRepeatedStr;
  }
};

int main()
{

  return 0;
}
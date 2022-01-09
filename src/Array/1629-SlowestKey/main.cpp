#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution1629
{
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed)
  {
    // 初始化
    int n = releaseTimes.size();
    char res = keysPressed[0];
    int longestTime = releaseTimes[0];

    for (int i = 1; i < n; i++)
    {
      // 注意了，是查看单次按键持续时间最长，不是总共按键持续时间！！
      int curNewAddTime = releaseTimes[i] - releaseTimes[i - 1];
      // 当按键时长最长一样的话选字母 ASCII 大的那个
      if (curNewAddTime == longestTime && keysPressed[i] > res)
      {
        res = keysPressed[i];
      }
      // 但如果是时间长度最长，就不需要看 ASCII 大小了
      else if (curNewAddTime > longestTime)
      {
        longestTime = curNewAddTime;
        res = keysPressed[i];
      }
    }

    return res;
  }
};

int main(void)
{
  vector<int> releaseTimes = {12, 23, 36, 46, 62};
  string keysPressed = "spuda";
  cout << Solution1629().slowestKey(releaseTimes, keysPressed) << endl;

  vector<int> releaseTimes2{1, 2, 3, 4, 5, 6, 7, 8};
  string keysPressed2 = "abcdefga";
  cout << Solution1629().slowestKey(releaseTimes2, keysPressed2) << endl;
  ;

  return 0;
}

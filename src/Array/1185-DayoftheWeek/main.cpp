#include <iostream>
#include <vector>

using namespace std;

class Solution1185
{
private:
  int dayOfYear(int day, int month, int year)
  {
    // 每个月有多少天， 0 - 11月
    const int presum[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    // 计算今天是当年的第几天
    int res = 0;
    res += presum[month - 1];
    // 是闰年的话需要额外加一天，前提是当前月份是超过 2 月的
    if (month > 2)
      if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        res += 1;
    res += day;

    return res;
  }

public:
  string dayOfTheWeek(int day, int month, int year)
  {
    int res = 4; // 1970年最后一天为星期四
    string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // 计算中间年份经过的天数，核心就是判断是否闰年
    for (int i = 1971; i < year; i++)
    {
      // 平年为 365天，闰年为 366，这是常识
      // 四年一闰，百年不闰，四百年再闰
      res += ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) ? 366 : 365;
    }

    // 接下来就是计算今年的天数了，可以复用 1154 题的代码
    res += dayOfYear(day, month, year);

    // 接下来就是简单的计算一下余数就能知道答案了
    return week[res % 7];
  }
};

int main(void)
{

  return 0;
}

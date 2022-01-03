#include <iostream>
#include <vector>

using namespace std;

class Solution1154
{
private:
  // 每个月有多少天， 0 - 11月，注意这里的2月是按照平年的数据写的
  const int presum[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

public:
  int dayOfYear(string date)
  {
    // 获取年月日
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    // 计算今天是当年的第几天
    int res = 0;
    res += presum[month - 1];
    // 是闰年的话需要额外加一天，前提是当前月份是超过 2 月的
    if (month > 2)
      // 四年一闰，百年不闰，四百年再闰
      if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        res += 1;
    res += day;

    return res;
  }
};

int main(void)
{

  return 0;
}

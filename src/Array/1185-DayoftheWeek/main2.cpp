#include <iostream>
#include <vector>

using namespace std;

class Solution1185
{
public:
  string dayOfTheWeek(int day, int month, int year)
  {
    vector<string> week = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int m = month, y = year;
    if (month < 3)
    {
      m = month + 12;
      y = year - 1;
    }

    int index = 0;
    // 蔡勒公式
    index = (day + 13 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    
    return week[index];
  }
};

int main(void)
{

  return 0;
}

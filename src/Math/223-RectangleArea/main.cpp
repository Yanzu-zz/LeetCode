#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution223
{
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
  {
    int rect1Area = (ax2 - ax1) * (ay2 - ay1);
    int rect2Area = (bx2 - bx1) * (by2 - by1);
    int coincidenceX = max(min(ax2, bx2) - max(ax1, bx1), 0);
    int coincidenceY = max(min(ay2, by2) - max(ay1, by1), 0);

    return rect1Area + rect2Area - (coincidenceX * coincidenceY);
  }
};

int main(void)
{

  return 0;
}

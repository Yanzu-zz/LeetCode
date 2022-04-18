#include <iostream>
#include <vector>

using namespace std;

class Solution386
{
public:
  vector<int> lexicalOrder(int n)
  {
    vector<int> res(n);

    int curr = 1;
    for (int i = 0; i < n; i++)
    {
      // 先赋值当前位置的字典序数字
      res[i] = curr;

      // 然后确定下个字典序数字
      if (curr * 10 <= n)
      {
        // 优先肯定是先 *10（即在后面加个0
        curr *= 10;
      }
      else
      {
        while (curr % 10 == 9 || curr + 1 > n)
        {
          curr /= 10;
        }
        // 然后就是 +1，上面的就是判断是否靠近时越界
        curr++;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution682
{
public:
  int calPoints(vector<string> &ops)
  {
    vector<int> arr;
    int res = 0;

    // 按照题目意思模拟即可
    // 这里我们用数组来存储每个步骤的结果
    for (string &op : ops)
    {
      int n = arr.size();
      switch (op[0])
      {
      case '+':
        res += arr[n - 1] + arr[n - 2];
        arr.emplace_back(arr[n - 1] + arr[n - 2]);
        break;
      case 'D':
        res += 2 * arr[n - 1];
        arr.emplace_back(2 * arr[n - 1]);
        break;
      case 'C':
        res -= arr[n - 1];
        arr.pop_back();
        break;
      default:
        res += stoi(op);
        arr.emplace_back(stoi(op));
        break;
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}

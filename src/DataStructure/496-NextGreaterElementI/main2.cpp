#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution496
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size(), n2 = nums2.size();
    stack<int> stk;
    unordered_map<int, int> hashMap;

    // 先初始化单调栈和哈希表对应位置上下个比当前元素大的值
    for (int i = n2 - 1; i >= 0; i++)
    {
      int currNum = nums2[i];
      while (!stk.empty() && currNum > stk.top()) // 即将入栈的元素比当前栈顶元素大，就将其出栈
        stk.pop();

      // 出栈后就表明当前下个比当前位置元素大的元素就是栈顶值
      hashMap[currNum] = stk.empty() ? -1 : stk.top();
      stk.push(currNum);
    }

    // 接下来就用 哈希表 里存好的值赋值即可
    vector<int> res(n1);
    for (int i = 0; i < n1; i++)
      res[i] = hashMap[nums1[i]]; // 表中就存着 nums2 对应元素中下个比这个元素大的值

    return res;
  }
};

int main()
{

  return 0;
}
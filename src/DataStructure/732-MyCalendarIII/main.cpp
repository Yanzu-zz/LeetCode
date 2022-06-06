#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class MyCalendarThree
{
public:
  // 线段树
  unordered_map<int, pair<int, int>> tree;

  MyCalendarThree()
  {
  }

  // 线段树更新区间元素
  void update(int start, int end, int l, int r, int idx)
  {
    // 超出线段树范围，直接返回即可
    if (r < start || end < l)
      return;

    // 找到了需要更新的区间，将其值 +1 即可，因为这里一次 update 只能加一次 book 的次数
    if (start <= l && r <= end)
    {
      tree[idx].first++;
      tree[idx].second++;
    }
    // 要不就是还没找到正确的区间，往下递归寻找
    else
    {
      int mid = l + (r - l >> 1);
      update(start, end, l, mid, idx << 1);
      update(start, end, mid + 1, r, (idx << 1) + 1);
      // 往下递归的同时，当前节点需要更新值，因为子节点改变了它上面的所有父节点都要改变
      tree[idx].first = tree[idx].second + max(tree[idx << 1].first, tree[(idx << 1) + 1].first);
    }
  }

  int book(int start, int end)
  {
    // 新数据来了，更新一下区间
    update(start, end - 1, 0, 1e9, 1);

    // 因为只是求当前 overlap 的 book 次数，故根节点的值就是所求次数
    return tree[1].first;
  }
};

int main()
{

  return 0;
}
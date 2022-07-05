#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class MyCalendar
{
public:
  unordered_set<int> tree, lazy; // 懒标记线段树

  bool query(int start, int end, int l, int r, int idx)
  {
    if (r < start || end < l)
      return false;

    // 如果该区间已被预订，则直接返回
    if (lazy.count(idx))
      return true;

    // 遇到交错区间
    if (start <= l && r <= end)
      return tree.count(idx);

    int mid = l + (r - l >> 1);
    return query(start, end, l, mid, idx << 1) || query(start, end, mid + 1, r, (idx << 1) + 1);
  }

  void update(int start, int end, int l, int r, int idx)
  {
    if (r < start || end < l)
      return;

    // 找到想要的区间了
    if (start <= l && r <= end)
    {
      tree.emplace(idx);
      lazy.emplace(idx);
    }
    // 没找到，继续递归
    else
    {
      int mid = l + (r - l >> 1);
      // 没找到的话继续查看左右子树
      update(start, end, l, mid, 2 * idx);
      update(start, end, mid + 1, r, 2 * idx + 1);
      tree.emplace(idx); // 标记该节点

      // 如果发现左右子树都变成 booked 状态了，该节点也变成 booked 状态
      if (lazy.count(idx << 1) && lazy.count((idx << 1) + 1))
        lazy.emplace(idx);
    }
  }

  bool book(int start, int end)
  {
    // 如果发现有交错区间，则直接报错
    if (query(start, end - 1, 0, 1e9, 1))
      return false;

    // 否则就更新区间
    update(start, end - 1, 0, 1e9, 1);
    return true;
  }
};

int main(void)
{

  return 0;
}

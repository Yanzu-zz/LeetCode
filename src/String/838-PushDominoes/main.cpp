#include <iostream>
#include <vector>

using namespace std;

class Solution838
{
private:
  void replace(string &dominoes, int start, int end)
  {
    // 如果两头都是R，全部替换成R
    // 如果左边是R，右边是边界，全部替换成R
    // 如果两头都是L，全部替换成L
    // 如果左边是边界，右边是L，全部替换成L
    // 如果左边是R，右边是L，除了最中间那个.，其他的都需要替换
    // 其他情况保持不变
    if (start - 1 >= 0 && dominoes[start - 1] == 'R' && (end + 1 >= dominoes.size() || dominoes[end + 1] == 'R'))
    {
      while (start <= end)
      {
        dominoes[start++] = 'R';
        dominoes[end--] = 'R';
      }
    }
    else if (end + 1 < dominoes.size() && dominoes[end + 1] == 'L' && (start - 1 < 0 || dominoes[start - 1] == 'L'))
    {
      while (start <= end)
      {
        dominoes[start++] = 'L';
        dominoes[end--] = 'L';
      }
    }
    else if (start - 1 >= 0 && end + 1 < dominoes.size() && dominoes[start - 1] == 'R' && dominoes[end + 1] == 'L')
    {
      while (start < end)
      {
        dominoes[start++] = 'R';
        dominoes[end--] = 'L';
      }
    }
  }

public:
  string pushDominoes(string dominoes)
  {
    int n = dominoes.size();
    int l = 0; // 左右指针，在连续的 . 区间中操作（一个 . 也算连续）

    while (l < n)
    {
      // 只处理 . 即没被施加方向力的多米诺牌子
      // 跳过非 . 字符
      while (l < n && dominoes[l] != '.')
        l++;

      int r = l;
      // 寻找连续 . 区间的右区间
      while (r < n && dominoes[r] == '.')
        r++;

      // 知道左右区间后就是替换中间牌子的状态了（笔记里分析了只有 5 种情形
      replace(dominoes, l, r - 1);
      // 然后就是继续寻找下个连续 . 区间
      l = r;
    }

    return dominoes;
  }
};

int main(void)
{

  return 0;
}

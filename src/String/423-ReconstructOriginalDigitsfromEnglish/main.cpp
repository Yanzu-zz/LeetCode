#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution423
{
public:
  string originalDigits(string s)
  {
    int n = s.size();
    unordered_map<char, int> map;
    for (const auto &ch : s)
      map[ch]++;

    string res = "";
    vector<int> cnt(10);

    // 按照笔记上分析的图表来确定个数
    // 下面是出现特定字母的数字
    cnt[8] = map['g'];
    cnt[4] = map['u'];
    cnt[2] = map['w'];
    cnt[6] = map['x'];
    cnt[0] = map['z'];

    // 下面是出现两个字母，但是有一个字母和上面一致，故可以通过减掉上面的个数来获得
    cnt[5] = map['f'] - cnt[4];
    cnt[3] = map['h'] - cnt[8];
    cnt[7] = map['s'] - cnt[6];

    // 下面就差 1和9了
    cnt[1] = map['o'] - cnt[0] - cnt[2] - cnt[4];
    cnt[9] = map['i'] - cnt[5] - cnt[6] - cnt[8];

    // 最后就是按照个数添加到结果字符串中了
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < cnt[i]; j++)
        res += char(i + '0');

    return res;
  }
};

int main()
{

  return 0;
}
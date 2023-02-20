#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string bestHand(vector<int> &ranks, vector<char> &suits)
  {
    vector<string> res = {"Flush", "Three of a Kind", "Pair", "High Card"};
    unordered_map<int, int> card;
    unordered_map<char, int> color;
    int idx = 3;

    for (int i = 0; i < 5; i++)
    {
      card[ranks[i]]++;
      color[suits[i]]++;

      if (color[suits[i]] == 5)
        idx = 0;
      else if (card[ranks[i]] >= 2)
      {
        if (card[ranks[i]] >= 3)
          idx = 1;

        if (idx < 2)
          break;
        idx = 2;
      }
    }

    return res[idx];
  }
};

int main(void)
{

  return 0;
}

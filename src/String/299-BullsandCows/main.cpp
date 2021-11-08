#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution299
{
public:
  string getHint(string secret, string guess)
  {
    int n = secret.size();
    int bulls = 0, cows = 0;
    int seCnt[10], guCnt[10];
    memset(seCnt, 0, sizeof(seCnt));
    memset(guCnt, 0, sizeof(guCnt));

    for (int i = 0; i < n; i++)
    {
      // 要是对应的位置相等的话 bulls 的值就+1
      if (secret[i] == guess[i])
      {
        bulls++;
      }
      else // 要是对应位置不相等就把该位置的值的个数存下来
      {
        seCnt[secret[i] - '0']++;
        guCnt[guess[i] - '0']++;
      }
    }

    // 然后 cows 的值就是两者之间的最小值
    for (int i = 0; i <= 9; i++)
      cows += min(seCnt[i], guCnt[i]);

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};

int main()
{
  string secret1 = "1807", guess1 = "7810";
  cout << Solution299().getHint(secret1, guess1);

  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution942
{
public:
  vector<int> diStringMatch(string s)
  {
    int n = s.size();
    int low = 0, high = n;
    vector<int> res(n + 1);

    /**
     * 	如果 s[i]=‘I’，那么令 perm[i]=low，则无论 perm[i+1] 为何值都满足 perm[i]<perm[i+1]；
     *  如果 s[i]=‘D’，那么令 perm[i]=high，则无论 perm[i+1] 为何值都满足 perm[i]>perm[i+1]；
     */
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'I')
        res[i] = low++;
      else
        res[i] = high--;
    }
    res[n] = low; // 还有一个数，此时 low==high

    return res;
  }
};

int main(void)
{

  return 0;
}

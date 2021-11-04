#include <iostream>
#include <vector>
#include <map>
#include <hash_map>

using namespace std;

class Solution167
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int n = numbers.size();
    hash_map<int, int> numsMap;
    int i;
    for (i = 0; i < n; i++)
      numsMap.insert(make_pair(numbers[i], i));

    vector<int> ret;
    for (i = 0; i < n; i++)
    {
      if (numsMap.find(target - numbers[i]))
      {
        ret.emplace_back(i + 1);
        ret.emplace_back(numsMap[target - numbers[i]] + 1);
      }
    }

    return ret;
  }
};

int main(void)
{
  vector<int> arr1 = {2, 7, 11, 15};
  int target1 = 9;

  cout << Solution167().twoSum(arr1, target1) << endl;

  return 0;
}

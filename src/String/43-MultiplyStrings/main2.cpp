#include <iostream>
#include <vector>

using namespace std;

class Solution43_2
{
public:
  string multiply(string num1, string num2)
  {
    if (num1 == "0" || num2 == "0")
      return "0";

    int n = num1.size(), m = num2.size();
    vector<int> indices(n + m, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      int num1Val = num1[i] - '0';
      for (int j = m - 1; j >= 0; j--)
      {
        int num2Val = num2[j] - '0';
        int sum = indices[i + j + 1] + num1Val * num2Val;
        indices[i + j + 1] = sum % 10;
        indices[i + j] += sum / 10;
      }
    }

    string result = "";
    for (int i = 0; i < m + n; i++)
    {
      if (i == 0 && indices[i] == 0)
        continue;
      result.push_back('0' + indices[i]);
    }

    return result;
  }
};

int main()
{
  string a1 = "6", b1 = "10";
  cout << Solution43_2().multiply(a1, b1) << endl;

  string a2 = "0", b2 = "0";
  cout << Solution43_2().multiply(a2, b2) << endl;

  string a3 = "8", b3 = "9";
  cout << Solution43_2().multiply(a3, b3) << endl;

  return 0;
}
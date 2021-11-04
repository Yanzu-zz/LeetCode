#include <iostream>
#include <vector>

using namespace std;

class Solution273
{
public:
  // 各值的位置都是按照顺序放的，到时候 nums%n，num/xxx 就能直接拿到数据
  vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  // 处理小于 1000 的值的英文转化
  string comma(int n)
  {
    string ans = "";

    // 处理百位数
    int hundred = n / 100;
    if (hundred)
      ans += singles[hundred] + " Hundred ";

    n %= 100;
    // 添加 10-19 单词
    if (n < 20 && n >= 10)
    {
      ans += teens[n % 10] + " ";
      return ans;
    }
    else if (n >= 20) // 否则就添加 [2-9]0 的英文
    {
      ans += tens[n / 10] + " ";
    }
    n %= 10;
    // 查看是否是整十数，是的话后面就没东西加了
    if (n == 0)
      return ans;
    ans += singles[n % 10] + " "; // 否则加上个位数的值

    return ans;
  }

  // 递归处理数字转英文
  string recur(int n)
  {
    // 获取各单位的数值
    int billion = n / 1000000000;
    n %= 1000000000; // 如果小于这个值就不会改变它
    int million = n / 1000000;
    n %= 1000000;
    int thousand = n / 1000;
    n %= 1000;
    string ans = "";

    // 下面就是给各单位（如果有）加上单位
    if (billion)
      // 这里用 recur 不直接用 comma 原因是有可能数值非常大，还能再分一次 billion 等
      // 而就算数值变到几十几百了，也不会影响到执行，因为下面会执行 comma，无非就是让系统多压一次栈，多存几个寄存器的值
      ans += recur(billion) + "Billion ";
    if (million)
      ans += recur(million) + "Million ";
    if (thousand)
      ans += recur(thousand) + "Thousand ";

    ans += comma(n);

    return ans;
  }

  string numberToWords(int num)
  {
    if (num == 0)
      return "Zero";
    string ret = recur(num);
    ret.pop_back();
    return ret;
  }
};

int main(void)
{

  return 0;
}

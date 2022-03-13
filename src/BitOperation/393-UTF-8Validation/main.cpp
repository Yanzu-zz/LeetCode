#include <iostream>
#include <vector>

using namespace std;

class Solution393
{
public:
  /**
   * UTF-8 中的一个字符可能的长度为 1 到 4 字节,因此只判断编码中的前1-5bits value.
   * 简单的来说可以分为4种情况
   *    1. 0xxxxxxx
   *    2. 110xxxxx
   *    3. 1110xxxx
   *    4. 11110xxx
   * 只需要对这4种情况分别进行讨论我们便知道所给的编码是否合法.
   */
  bool validUtf8(vector<int> &data)
  {
    // bytesCharcter 如果为 0，则表示上一个 UTF-8 编码以及处理完毕，需要进行下一轮的编码解析
    int bytesCharacter = 0;
    for (int num : data)
    {
      // 如果是到了下一轮的 UTF-8 编码开头判断解析
      if (bytesCharacter == 0)
      {
        // 后面 3 个情况不再写注释，和情况2注释意思一样只不过 continuation byte 数量不同而已
        if ((num >> 5) == 0b110)       // 如果是情况 2（上面注释）
          bytesCharacter = 1;          // 则表明后面还有一个 continuation byte
        else if ((num >> 4) == 0b1110) // 情况 3
          bytesCharacter = 2;
        else if ((num >> 3) == 0b11110) // 情况 4
          bytesCharacter = 3;
        else if (num >> 7) // 通过了上述验证，如果是在新一轮解析的情况下，开头第一个 bit 不为 0，那么就不可能符合解析条件
          return false;
      }
      else
      {
        // 如果不是开头编码，而是它的后续
        if ((num >> 6) != 0b10)
          return false;
        --bytesCharacter; // 根据不同情形查找他后面几个 contination byte
      }
    }

    return bytesCharacter == 0;
  }
};

int main(void)
{

  return 0;
}

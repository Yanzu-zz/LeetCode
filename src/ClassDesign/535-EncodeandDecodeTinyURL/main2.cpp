#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
  unordered_map<int, string> db;

public:
  Solution()
  {
    // 生成随机种子
    srand(time(0));
  }

  // Encodes a URL to a shortened URL.
  string encode(string longUrl)
  {
    // 这里就是不维护一个全局 id ，而是随机生成 id
    // 此时撞库的几率还是很小滴
    int id;
    while (true)
    {
      id = rand();
      if (db.count(id) == 0)
        break;
    }

    db[id] = longUrl;
    return string("http://tinyurl.com/") + to_string(id);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl)
  {
    // 解码就是获取 url 里面的 id，然后双射回原本的真正的 url 去
    // 找到对应 / 的索引位置
    int p = shortUrl.rfind('/') + 1;
    // 获取 id
    int key = stoi(shortUrl.substr(p, int(shortUrl.size()) - p));
    return db[key];
  }
};

int main(void)
{

  return 0;
}

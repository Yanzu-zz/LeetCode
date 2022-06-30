#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution535
{
private:
  int id = 0;
  unordered_map<int, string> db;

public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl)
  {
    // 每次新来一个需要编码的 URL 就将全局 id 自增1
    id++;
    // 映射到对应 url
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

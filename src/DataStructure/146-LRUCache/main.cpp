#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef class Nodea Node;

class Nodea
{
public:
  int key, val;
  Node *prev, *next;

  Nodea(int key, int val)
  {
    this->key = key;
    this->val = val;
  }
};

class DoubleList
{
private:
  int size;
  Node *head = nullptr, *tail = nullptr;

public:
  DoubleList()
  {
    this->size = 0;
  }

  // add element node to the first place of DoubleList
  void addFirst(Node *node)
  {
    if (this->head == nullptr)
    {
      this->head = this->tail = node;
    }
    else
    {
      Node *tmp = this->head;
      tmp->prev = node;
      node->next = tmp;
      this->head = node;
    }

    // Don't forget to increace the size of the list
    this->size++;
  }

  // Remove an element from the list
  void remove(Node *node)
  {
    if (this->head == node && this->tail == node)
    {
      this->head = this->tail = nullptr;
    }
    else if (this->tail == node)
    {
      node->prev->next = nullptr;
      this->tail = node->prev;
      // free(node);
    }
    else if (this->head == node)
    {
      node->next->prev = nullptr;
      this->head = node->next;
      // free(node);
    }
    else
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      // free(node);
    }

    this->size--;
  }

  Node *removeLast()
  {
    Node *tmp = this->tail;
    remove(this->tail);
    return tmp;
  }

  int getSize()
  {
    return this->size;
  }
};

class LRUCache
{
private:
  int capacity;
  DoubleList *list;
  unordered_map<int, Node *> mp;

public:
  LRUCache(int capacity)
  {
    this->capacity = capacity;
    list = new DoubleList();
  }

  // 获取 key 对应的 value 值，并且将该 key 位置提到最新
  int get(int key)
  {
    // 如果哈希表中没有记录则直接返回 -1
    if (mp.count(key) == 0)
      return -1;

    // 记得更新一下它的最新位置
    put(key, mp[key]->val);
    return mp[key]->val;
  }

  // 加入新的 key-value，如果存储元素数量超过 capacity，则将 least recently used 的元素删除
  void put(int key, int value)
  {
    // 先创建新的结点
    Node *x = new Node(key, value);

    // 如果是 put 存在的元素，则只是更新它的值且移到最新位置上
    if (mp.count(key) > 0)
    {
      list->remove(mp[key]);
    }
    else
    {
      // 如果列表数量超了就删除最后的元素
      if (list->getSize() == this->capacity)
        mp.erase(list->removeLast()->key);
    }

    // 然后就正常添加
    list->addFirst(x);
    mp[key] = x; // 记得哈希表也要记录
  }
};

int main(void)
{

  return 0;
}

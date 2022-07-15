#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node()
  {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution558
{
public:
  Node *intersect(Node *quadTree1, Node *quadTree2)
  {
    // quadTree1 是叶子节点
    if (quadTree1->isLeaf)
    {
      if (quadTree1->val)
        return new Node(true, true, nullptr, nullptr, nullptr, nullptr);

      return quadTree2;
    }

    // quadTree2 是叶子节点
    if (quadTree2->isLeaf)
    {
      if (quadTree2->val)
        return new Node(true, true, nullptr, nullptr, nullptr, nullptr);

      return quadTree1;
    }

    // 都不是叶子节点，递归下去找到叶子节点
    Node *topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
    Node *topRight = intersect(quadTree1->topRight, quadTree2->topRight);
    Node *bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
    Node *bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

    if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val)
      return new Node(topLeft->val, true, nullptr, nullptr, nullptr, nullptr);

    return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
  }
};

int main(void)
{

  return 0;
}

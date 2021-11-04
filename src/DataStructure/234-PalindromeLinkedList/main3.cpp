#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution234
{
private:
    // leetcode 206 题做过的翻转链表
    ListNode *reverseLinkedList(ListNode *curr)
    {
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        // 快慢指针
        ListNode *slow = head, *fast = head;

        // 利用快慢指针一次遍历找到链表中间位置
        // 原理是快指针一次走两步，慢指针一次一步
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 此时 slow 的位置就是在前半个链表的末尾
        ListNode *rearLinkedPos = reverseLinkedList(slow->next);

        ListNode *t1 = head, *t2 = rearLinkedPos;
        // 前后对比判断是否回文链表
        while (t2 != nullptr)
        {
            if (t1->val != t2->val)
                return false;

            t1 = t1->next;
            t2 = t2->next;
        }

        // 还原（还原最好，这样不影响原链表）
        slow->next = reverseLinkedList(rearLinkedPos);

        return true;
    }
};

int main(void)
{

    return 0;
}

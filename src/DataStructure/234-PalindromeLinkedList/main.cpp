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
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> arr;
        int n = 0;
        // 先将链表中的所有元素加进来
        while (head != nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
            n++;
        }

        // 然后头尾对比，直至相遇
        int left = 0, right = n - 1;
        while (left < right)
            if (arr[left++] != arr[right--])
                return false;

        return true;
    }
};

int main(void)
{

    return 0;
}

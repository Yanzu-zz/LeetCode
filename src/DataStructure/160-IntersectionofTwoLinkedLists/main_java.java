import java.util.LinkedList;
import java.util.List;

/**
 * 解题思路一：先遍历长度，再从头移动
 * 先遍历一遍链表获取长度，接着利用两个链表的 gap 来对比，由于题目说明
 * intersectVal == listA[skipA + 1] == listB[skipB + 1] if listA and listB intersect.
 * 然后我们简单遍历判断即可
 */
class Solution160 {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int aLen = 0, bLen = 0;
        ListNode aTemp = headA, bTemp = headB;
        while (aTemp != null || bTemp != null) {
            if (aTemp != null) {
                aLen++;
                aTemp = aTemp.next;
            }
            if (bTemp != null) {
                bLen++;
                bTemp = bTemp.next;
            }
        }

        int gap = aLen - bLen;
        aTemp = headA;
        bTemp = headB;

        while (gap > 0) {
            aTemp = aTemp.next;
            gap--;
        }
        while (gap < 0) {
            bTemp = bTemp.next;
            gap++;
        }

        while (aTemp != null || bTemp != null) {
            while (aTemp != null) {
                if (aTemp == bTemp)
                    return aTemp;
                aTemp = aTemp.next;
                bTemp = bTemp.next;
            }
        }

        return null;
    }
}
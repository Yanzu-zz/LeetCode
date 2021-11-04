import java.util.LinkedList;
import java.util.List;

/**
 * 解题思路：走到尽头时不见你，于是走你来时的路，等到相遇才发现，你也走过我来时的路~
 */
class Solution160_2_ {
    class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;

        ListNode pA = headA, pB = headB;
        while (pA != pB) {
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }

        return pA;
    }
}
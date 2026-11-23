/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *slow = headA, *fast = headB;

        while (slow != fast) {
            if (!slow)
                slow = headB;
            else
                slow = slow->next;
            if (!fast)
                fast = headA;
            else
                fast = fast->next;
        }
        return slow;
    }
};
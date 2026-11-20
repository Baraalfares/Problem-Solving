/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* fast = head,* slow = head;
        while(fast && fast -> next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* node = reverse(slow);
        ListNode* curr = head;
        int maxi = 0;
        while(curr != slow){
            maxi = max(maxi, curr->val + node->val);
            curr = curr->next;
            node = node->next;
        }
        return maxi;
    }
};
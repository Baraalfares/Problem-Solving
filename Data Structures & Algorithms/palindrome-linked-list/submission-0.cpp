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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = head -> next;

        while(curr){
            ListNode* temp = curr;
            curr -> next = prev;
            prev = temp;
            curr = nxt;
            nxt = nxt -> next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head,* slow = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* node = reverse(slow);

        ListNode* left = head,* right = node;
        while(right){
            if(left -> val != right -> val)
                return false;
            left = left -> next;
            right = right -> next;
        }
        return true;
    }
};
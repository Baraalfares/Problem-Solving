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
    ListNode* reverseList(ListNode* head) {
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
};

// 1 -> 2 -> 3 -> 4 -> 5 

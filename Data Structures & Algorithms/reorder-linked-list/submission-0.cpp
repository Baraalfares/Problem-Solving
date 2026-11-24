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
        while(head){
            ListNode* next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        ListNode* fast = head, *slow = head;

        while(fast->next && fast -> next->next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* second = reverse(slow -> next);
        ListNode* first = head;

        slow -> next = nullptr;
        while(second){
            ListNode* fst = first -> next;
            ListNode* scnd = second -> next;

            first -> next = second;
            second -> next = fst;
            first = fst;
            second = scnd;
        }
    }
};

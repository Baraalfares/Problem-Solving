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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = new ListNode(0, list1);
        for(int i = 0; i <= a - 1; i++){
            curr = curr -> next;
        }
        ListNode* pred = curr;
        for(int i = a; i <= b + 1 ; i++){
            curr = curr -> next;
        }
        ListNode* tail = list2;
        while(tail->next){
            tail = tail -> next;
        }
        ListNode* succ = curr;
        pred->next = list2;
        tail->next = succ;
        return list1;
    }
};

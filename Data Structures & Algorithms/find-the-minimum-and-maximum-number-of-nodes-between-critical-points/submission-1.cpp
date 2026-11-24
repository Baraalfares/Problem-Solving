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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        int fst = -1;
        int scnd  = -1;
        int i = 1;
        int mini = INT_MAX;
        while(curr && curr -> next){
            int a = prev -> val, b = curr -> val, c = curr -> next -> val;
            if((b > a && b > c) || (b < a && b < c)){
                if(fst == -1){
                    fst = i;
                }
                else{
                    mini = min(mini, i - scnd);
                }
                scnd = i;
            }
            prev = curr;
            curr = curr -> next;
            i++;
        }
        if(fst == scnd)
            return {-1, -1};
        return {mini, scnd - fst};
    }
};

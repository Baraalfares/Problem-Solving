class BrowserHistory {
public:
    struct ListNode {
    public:
        string val;
        ListNode* next;
        ListNode* prev;
        ListNode(string val, ListNode* prev = nullptr, ListNode* next = nullptr)
            : val(val), prev(prev), next(next) {}
    };
    ListNode* curr;
    BrowserHistory(string homepage) {
        curr = new ListNode(homepage); 
    }
    
    void visit(string url) {
        curr -> next = new ListNode(url, curr, nullptr);
        curr = curr -> next;
    }
    
    string back(int steps) {
        while(curr-> prev && steps--){
            curr = curr -> prev;
        }
        return curr -> val;
    }
    
    string forward(int steps) {
        while(curr -> next && steps--){
            curr = curr -> next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
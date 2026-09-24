class MyLinkedList {

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val) : val(val), next(nullptr) {}
    };
public:
    ListNode* head;
    int size;
    MyLinkedList() {
        head = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1;
        ListNode* curr = head -> next;
        for(int i = 0 ; i < index ; i++){
            curr = curr -> next;
        }
        return curr -> val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node -> next = head -> next;
        head -> next = node;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* curr = head;
        while(curr->next){
            curr = curr -> next;
        }
        ListNode* node = new ListNode(val);
        curr->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        ListNode* node = new ListNode(val);
        ListNode* curr = head;
        for(int i = 0 ; i < index ; i++){
            curr = curr -> next;
        }
        node -> next = curr->next;
        curr -> next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        ListNode* curr = head;
        for(int i = 0 ; i < index ; i++){
            curr = curr -> next;
        }
        ListNode* temp = curr -> next;
        curr -> next = curr -> next -> next;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
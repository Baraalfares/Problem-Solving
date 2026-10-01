class MyHashSet {
public:
    vector<int>vec;
    MyHashSet() {
        vec = vector(10000001, -1);
    }
    
    void add(int key) {
        vec[key] = key;
    }
    
    void remove(int key) {
        vec[key] = -1;
    }
    
    bool contains(int key) {
        if(vec[key] == -1)
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
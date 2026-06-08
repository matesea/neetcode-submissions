class MyCircularQueue {
    vector<int> q;
    int rp, wp;
public:
    MyCircularQueue(int k) {
        q.resize(k + 1, 0);
        rp = wp = 0;
    }
    
    bool enQueue(int value) {
       if (isFull()) return false;
       q[wp] = value;
       wp = (wp+1) % q.size();
       return true;
    }
    
    bool deQueue() {
       if (isEmpty()) return false;
       rp = (rp + 1) % q.size();
       return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[rp];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int i = (q.size() + wp - 1) % q.size();
        return q[i];
    }
    
    bool isEmpty() {
        return rp == wp;
    }
    
    bool isFull() {
       return (wp + 1) % q.size() == rp; 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
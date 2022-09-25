class MyCircularDeque {
public:
    int *arr;
    int k, front, rear;
    
    MyCircularDeque(int k) {
        arr = new int[k];
        front = rear = -1;
        this->k = k;
    }
    
    bool insertFront(int value) {
        if(front == rear && rear == -1){
            front ++;
            rear ++;
            arr[front] = value;
            return true;
        }
        
        if( ( rear + 1) % k == front){
            return false;
        }
        
        front = front - 1;
        if(front < 0){
            front = k - 1;
        }
        
        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(front == rear && rear == -1){
            front ++;
            rear ++;
            arr[front] = value;
            return true;
        }
        
        if( ( rear + 1) % k == front){
            return false;
        }
        
        rear = (rear + 1) % k;        
        arr[rear] = value;
        
        return true;
    }
    
    bool deleteFront() {
        if(front == -1 && front == rear){
            return false;
        }
        
        if(front == rear){
            front = rear = -1;
            return true;
        }
        
        front = (front + 1) % k;
        return true;
    }
    
    bool deleteLast() {
        if(front == -1 && front == rear){
            return false;
        }
        
        if(front == rear){
            front = rear = -1;
            return true;
        }
        
        rear = rear - 1;
        if(rear < 0){
            rear = k - 1;
        }

        return true;
    }
    
    int getFront() {
        if(front == -1)
            return -1;

        return arr[front];
    }
    
    int getRear() {
        if(rear == -1)
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % k == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
class MyCircularQueue {
public:
    int *arr;
    int front, rear, k;
    
    MyCircularQueue(int k) {
        arr = new int[k];
        front = rear = -1;
        this->k = k;
    }
    
    bool enQueue(int value) {
        if( (rear + 1) % k == front){
            return false;
        }
        
        if(front == -1 && front == rear){
            arr[0] = value;
            front ++;
            rear ++;
        }
        else{
            rear = (rear + 1) % k;
            arr[rear] = value;
        }
        
        return true;
    }
    
    bool deQueue() {
        if(front == -1){
            return false;
        }
        
        if(front == rear){
            front = rear = -1;
            return true;
        }
        
        front = (front+1) % k;
        return true;
    }
    
    int Front() {
        if(front != -1)
            return arr[front];
        return -1;
    }
    
    int Rear() {
        if(rear != -1)
            return arr[rear];
        return -1;        
    }
    
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    
    bool isFull() {
        return (rear+1)%k == front;
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
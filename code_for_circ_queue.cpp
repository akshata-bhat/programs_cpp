class MyCircularQueue {
public:
    int* arr = NULL;
    int head;
    int tail;
    int size;
    

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr = new int[k];
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(head == -1 && tail == -1){
            head = 0;
            tail = 0;
            arr[tail] = value;
            return true;
        }
        else if(head == 0 && tail == size-1 || head == tail+1){
            cout << "Queue full" << endl;
            return false;
        }
        else if(tail == size-1 && head != 0){
            tail = 0;
            arr[tail] = value;
            return true;
        }
        else{
            tail++;
            arr[tail] = value;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(head == -1 && tail == -1){
            return false;
        }
        else if((head == 0 && tail == size -1) || (head == tail+1)){
            head++;
            return true;
        }
        else if(head == size-1){
            if(tail == 0)
                return false;
            else{
                head = 0;
                return true;
            }
        }
        else{
            head++;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(head == -1)
            return -1;
        else
            return arr[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(head == -1)
            return -1;
        else 
            return arr[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if((head == size-1 && tail == 0) || (head == 0 && tail == size-1) || (tail == head+1))
           return true;
        else 
           return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return !(isEmpty());
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

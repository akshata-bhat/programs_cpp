#include<iostream>
#include<vector>
using namespace std;

class MyQueue{
	private:
	vector<int> q;
	int q_start;
	
	public:
	MyQueue(){q_start = 0;}

	bool enQueue(int value){
		q.push_back(value);
		return true;
	}

	bool isEmpty(){
		return q_start >= q.size(); 
	}
	
	bool deQueue(){
		if(isEmpty()) {
			return false;
		}
		q_start++;
		return true;
	}
	
	int getFront(){
		return q[q_start];
	}
};

int main(){
	MyQueue q_obj;
	q_obj.enQueue(3);
	q_obj.enQueue(4);
	q_obj.enQueue(10);
	cout << "Is the queue empty? " << q_obj.isEmpty() << endl;
	if(!q_obj.isEmpty()){
		cout << "Front element: " << q_obj.getFront() << endl;
	}  
	q_obj.deQueue();
	q_obj.deQueue();
	q_obj.deQueue();

	cout << "Is the queue empty? " << q_obj.isEmpty() << endl;
	return 0;
}

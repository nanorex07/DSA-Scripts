// Circular Queue
// Date: 4/25/2022


#include <iostream>
#include <vector>

using namespace std;

template <class T>
class CirQueue {
private:
	vector<T> queue;
	int front, rear, maxSize;
public:
	CirQueue(int s) {
		queue.resize(s);
		front = -1;
		rear = -1;
		maxSize = s;
	}
	void enqueue(T data){
		if( (rear + 1 ) % maxSize  == front){
			cout << "Overflow" << endl;
			return;
		}
		if(front == -1 ){
			front = 0;
			rear = 0;
		}
		else
			rear = (rear+1)%maxSize;
		queue[rear] = data;
	}
	void deque() {
		if(front == -1 && rear == -1){
			cout << "Underflow" << endl;
			return;
		}
		if(front == rear){
			front = -1;
			rear = -1;
			return;
		}
		front = (front+1)%maxSize;
	}
	void show() {
		int k = front;
		while (k != rear){
			cout << queue[k] << " ";
			k = (k+1)%maxSize;
		}
		cout << queue[rear] << endl;
	}
};

int main () {
	int ch;
	CirQueue<char> q(5);
	while(true){
		cin >> ch;
		if (ch == 1 ){
			char data;
			cout << "+: ";
			cin >> data;
			q.enqueue(data);
		}
		else if (ch == 2){
			q.deque();
		}
		else if (ch == 3){
			q.show();
		}
		else{
			break;
		}
	}

}
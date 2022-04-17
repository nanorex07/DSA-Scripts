/*
Add two integers with link list
Date: 4/17/2022
*/

#include <iostream>
using namespace std;


class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val, ListNode* next){
		this->val = val;
		this->next = next;
	}
	ListNode(int val){
		this->val = val;
		this->next = nullptr;
	}
};

class LinkedListAdder {
private:
	ListNode* list1;
	ListNode* list2;

	void initList(int x, int y){
		ListNode* p;
		while(x){
			if(list1==nullptr){
				list1 = new ListNode(x%10);
				p = list1;
			}
			else{
				p->next = new ListNode(x%10);
				p = p->next;
			}
			x /= 10;
		}

		while(y){
			if(list2 == nullptr){
				list2 = new ListNode(y%10);
				p = list2;
			}
			else{
				p->next = new ListNode(y%10);
				p = p->next;
			}
			y /= 10;
		}
	}

public:
	void traverse(){
		cout << "List 1: ";
		ListNode* p = list1;
		while(p){
			cout << p->val << " -> ";
			p = p->next;
		}
		cout << "null" << endl;
		cout << "List 2: ";
		p = list2;
		while(p){
			cout << p->val << " -> ";
			p = p->next;
		}
		cout << "null" << endl;

	}

	int add(int x, int y){
		initList(x,y);
		int sum = 0;
		int carry = 0;
		int mul = 1;
		ListNode* p1 = list1;
		ListNode* p2 = list2;

		while(p1 && p2){
			int a = (p1->val+p2->val+carry);
			sum += (a%10)*mul;
				carry = a/10;
			mul *= 10;
			p1 = p1->next;
			p2 = p2->next;
		}
		while(p1){
			int a = (p1->val+carry);
			sum += (a%10)*mul;
			carry = a/10;
			mul*=10;
			p1 = p1->next;
		}
		while(p2){
			int a = (p2->val+carry);
			sum += (a%10)*mul;
			carry = a/10;
			mul*=10;
			p2 = p2->next;
		}
		if(carry) sum += carry*mul;

		return sum;
	}
	LinkedListAdder() {
		list1 = nullptr;
		list2 = nullptr;
	}
};

int main(){
	int x,y;
	cin >> x >> y;
	LinkedListAdder adder = LinkedListAdder();
	cout << adder.add(x,y) << endl;
}
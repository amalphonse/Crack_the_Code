#include<iostream>
#include<vector>

using namespace std;

int top= 0;

vector<int> s;

void push(int item) {
	s.push_back(item);
	top++;

}

void pop() {
	if (top == 0)
		cout << "The stack is empty." << endl;
	top = top - 1;
}

int peek() {
	if (top == -1)
		return -1;
	int item = s[top];
	return item;
}

bool isEmpty() {
	if (top == -1)
		return true;
	else {
		return false;
	}
}

void print() {
	for (int i = 0; i < top; i++)
		cout << s[i] << endl;

}

int main() {
	push(1);
	push(20);
	push(15);
	print();

	return 0;
}
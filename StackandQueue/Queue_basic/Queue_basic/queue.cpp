#include<iostream>
#include<vector>

using namespace std;

int front = 0;
int back = 0;

vector<int> q;

void add(int item) {
	back = back + 1;
	q.push_back(item);
}

void remove() {
	
	front = front + 1;
}

bool isEmpty() {
	if (front == back)
		return true;
	return false;
}






#include<iostream>


using namespace std;

struct Node {
	int data;
	struct Node* next;
};

class LinkedList {
private:
public:
	void reverse_linkedlist(Node* head) {

	}
	Node* Insert_at_end(Node* head, int data) {
		Node* new_node = new Node();
		new_node->data = data;
		new_node->next = NULL;
		Node* node = head;
		node->next = new_node;
		return node;
	}

	Node* Insert_at_beginning(Node *head, int data) {

	}
	void remove_dups(Node* head) {
		if (head == NULL) {
			return;
		}
		Node *current = head;
		Node *runner = current;

		while (runner->next != NULL) {
			if (current->data == runner->next->data) {
				runner->next = runner->next->next;
			}
			else { runner = runner->next; }
			current = current->next;
		}

	}
};
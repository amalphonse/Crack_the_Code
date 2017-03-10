#include<iostream>


using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void print(Node* node);
	Node* new_node(int data) {
		Node* newnode = new Node();
		newnode->data = data;
		newnode->next = NULL;
		return newnode;
	}

	Node* Insert_in_front(Node* node, int data) {
		if (node == NULL) {
			return new_node(data);
		}
	
		Node* nnode = new_node(data);
		nnode->next = node;
		cout << nnode->data << endl;
		return nnode;
	}

	Node* reverse(Node* node) {
		if (node == NULL)
			return NULL;
		Node* next;
		Node* curr = node;
		Node *prev = NULL;
		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			//cout << prev->data << curr->data << next->data << endl;
		}
		node = prev;
		return  node;
	}
	Node* remove_dups(Node* node) {
		if (node == NULL)
			return NULL;
		Node *curr = node;
		
		while (curr != NULL) {
			Node *runner = curr;
			while (runner->next != NULL) {
				if (runner->next->data == curr->data) {
					runner->next = runner->next->next;
				}
				else {
					runner = runner->next;
				}
			}
			curr = curr->next;
		}
		return node;
	}

	Node* get_knode(Node* node,int k) {
		Node *knode = node;
		int i = 0;
		while (i != k && knode->next != NULL) {
			knode = knode->next;
			i++;
		}
		while (knode->next != NULL) {
			node = node->next;
			knode = knode->next;
		}
		return node;
	}

	bool isPalindrome(Node* node) {
		if (node == NULL)
			return false;
		Node *rev = reverse(node);
		cout << "The reverse node is:" << endl;
		print(rev);
		Node *curr = node;
		cout << "The node is:" << endl;
		print(curr);
		while (curr->next != NULL && rev->next != NULL) {
			if (rev->data != curr->data) {
				return false;
			}
			curr = curr->next;
			rev = rev->next;
		}
		return true;
	}
	void print(Node* node) {
		Node *curr = node;
		//cout << curr->data << endl;
		while (curr != NULL) {
			cout << curr->data << endl;
			curr = curr->next;
			
		}
	}

int main() {
	Node *head = new Node();
	/*head = Insert_in_front(head, 10);
	head = Insert_in_front(head, 20);
	head = Insert_in_front(head, 30);
	head = Insert_in_front(head, 40);
	*/
	head = Insert_in_front(head, 1);
	head = Insert_in_front(head, 2);
	head = Insert_in_front(head, 1);
	head = Insert_in_front(head, 1);
	print(head);
	cout << "The reverse is:" << endl;
	head = reverse(head);
	print(head);
	
	//cout << isPalindrome(head) << endl;
	//head = reverse(head);
	//print(head);
	//head = remove_dups(head);

	//Node* node = get_knode(head, 2);
	//cout << node->data << endl;
	//print(head);
	

	return 0;
}
#include <iostream>
using namespace std;

struct Node{
    int num;
    Node *next;
};

Node *head = nullptr;

void sortData(Node *head){
	bool swapped;
	do {
		swapped = false;
		Node *current = head;
		while(current != nullptr && current -> next != nullptr){
			if(current -> num > current -> next -> num){
				int temp = current -> num;
				current -> num = current -> next -> num;
				current -> next -> num = temp;
				swapped = true;
			} current = current -> next;
		}
	}while(swapped);
}

int main(){
int node_size = 0;
int num = 0;
cout << "Number of nodes: ";
cin >> node_size;

for (int i = 1; i<=node_size;i++){
	cout << "Enter integer for node " << i << ": ";
	cin >> num;
	Node *newNode = new Node;
    newNode -> num = num;
    newNode ->next = nullptr;
    if (head == nullptr){
    	head = newNode;}
    else {
	    Node *temp = head;
	    while(temp -> next != nullptr){
	    temp = temp -> next;}
	    temp -> next = newNode;
	}
}

Node *current = head;
    while (current != nullptr){
        cout << current -> num << " ";
        current = current->next;
    }
cout << "\n";
sortData(head);
current = head;
    while (current != nullptr){
        cout << current -> num << " ";
        current = current->next;
    }
return 0;
}


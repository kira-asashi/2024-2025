#include <iostream>
using namespace std;
struct Node {
int data;
Node *next;
};
Node *head = NULL, *tail = NULL;
void addNodeAtLast(int data) {
Node *node = new Node;
node->data = data;
node->next = NULL;
if(head == NULL) {
head = tail = node;
} else {
tail->next = node;
tail = node;
}
}
void head_recursion(Node *node){
if (node == NULL) return;
head_recursion(node->next);
cout << node->data << endl;
}
void tail_recursion(Node *node){
if (node != NULL) {
cout << node->data << endl;
tail_recursion(node->next);
}
}

int main(int argc, char const *argv[])
{   
addNodeAtLast(1);
addNodeAtLast(2);
addNodeAtLast(3);
addNodeAtLast(4);
addNodeAtLast(5);
cout << "Acedera, Kruschev Hadriel B." << endl;
cout << "Head Recursion:" << endl;
head_recursion(head);
cout << "Tail Recursion:" << endl;
tail_recursion(head);
return 0;
}

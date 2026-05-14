#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;
Node *newNode = NULL;


void add_NodeTail(){
int num;
cout << "Enter integer: ";
cin >> num;

if (head == NULL){
    newNode = new Node;
    newNode -> data = num;
    newNode -> next = NULL;

    head = tail = newNode;
}
else {
    newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;

    tail -> next = newNode;
    tail = newNode;
    newNode = NULL;
}


}

void add_NodeHead(){
int num;
cout << "Enter integer: ";
cin >> num;

if (head == NULL){
    newNode = new Node;
    newNode -> data = num;
    newNode -> next = NULL;

    head = tail = newNode;
}
else {
    newNode = new Node;
	newNode->data = num;
	newNode->next = head;
    head = newNode;
}


}

void add_NodeMid(){
int position = 0, num, node_size = 0;
cout << "Enter the data to insert: ";
cin >> num;
cout << "Input the place to add your node in (1 being the 1st place): ";
cin >> position;


Node *temp = head;
while(temp != NULL){
    node_size++;
    temp = temp->next;}

if (position < 1 || position > node_size + 1){
    cout << "Error! Invalid position" << endl;
    return;}

newNode = new Node;
newNode -> data = num;
newNode -> next = NULL;

if (position == 1){
if (head == NULL){
    head = tail = newNode;}
else {
	newNode->next = head;
    head = newNode;}
return;}

Node* prev = head;
for (int i = 1; i < position - 1; i++) {
    prev = prev->next;
}

newNode->next = prev->next;
prev->next = newNode;

if (newNode->next == NULL) {
    tail = newNode;
}
}

void display_Node(){
int node_size = 0;

if (head == NULL){
    cout << "\nNode is Empty!" << endl;
    return;}

cout << "Node Contents:" << endl;

Node *temp = head;
while(temp != NULL) {
    node_size++;
    cout << temp->data << " ";
    temp = temp->next;}

cout << "\n\nNode contains " << node_size << " data in it." << endl << endl;
}

void delete_NodebyValue(){

if (head == NULL){
    cout << "\nNode is Empty!" << endl;
    return;}

int data;
cout << "\nInput data to be deleted: ";
cin >> data;
cout << "\nFIRST node consisting of input data will be deleted" << endl;

    if (head -> data == data){
        Node *temp = head;
        head = head -> next;
        cout << data << " is deleted" << endl;
        delete temp;
        cout << endl;
        display_Node();
        return;}
    
    Node *prev = head;
    newNode = head ->next;
    while(newNode != NULL) {
        if (newNode -> data == data){          
            prev ->next = newNode -> next;
            cout << newNode -> data << " is deleted" << endl;
            delete newNode;
            display_Node();
            return;}
        prev = newNode;
        newNode = newNode->next;}
}

void delete_NodebyPosition(){
int position = 0, node_size = 0;

if (head == NULL){
    cout << "\nNode is Empty!" << endl;
    return;}

cout << "Input the nth node to be deleted: ";
cin >> position;

Node *temp = head;
while(temp != NULL){
    node_size++;
    temp = temp->next;
    }

if (position < 1 || position > node_size){
    cout << "Error! Invalid position" << endl;
    return;}

if (position == 1){
    temp = head;
    head = head -> next;
    cout << position << "st node is deleted" << endl;
    if (head == NULL) tail = NULL;
    delete temp;
    cout << endl;
    display_Node();
    return;}

Node *prev = head;
temp = head -> next;
for (int i = 1; i < position - 1; i++){
    prev = prev -> next;
    temp = temp -> next;
}

prev -> next = temp -> next;
cout << "Node with data " << temp->data << " at position " << position << " is deleted." << endl;
delete temp;
display_Node();
cout << endl;
}

void edit_Node(){
int position = 0, node_size = 0, num;

if (head == NULL){
    cout << "\nNode is Empty!" << endl;
    return;}

cout << "Enter the new data: ";
cin >> num;
cout << "Input the nth node to be edited: ";
cin >> position;

Node *temp = head;
while(temp != NULL){
    node_size++;
    temp = temp->next;
    }

if (position < 1 || position > node_size){
    cout << "Error! Invalid position" << endl;
    return;}

temp = head;
for (int i = 1; i < position; i++){
    temp = temp -> next;
}

temp -> data = num;
cout << "Data Successfully Edited" << endl;
display_Node();
}

int main(){
    int data;
    int choice;
    int option;
    do {
        cout << endl;
        cout << "[1] - Add/Create a linked list" << endl;
        cout << "[2] - Display Linked List" << endl;
        cout << "[3] - Delete Node" << endl;
        cout << "[4] - Edit Node" << endl;
        cout << "[5] - Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: {
                    cout << "Where do you want to add your data? " << endl;
                    cout << "[1] - Last Place" << endl;
                    cout << "[2] - First Place" << endl;
                    cout << "[3] - In-between" << endl;
                    cout << "Type your selection: ";
                    cin >> option;
                    if (option == 1) add_NodeTail();
                    else if (option == 2) add_NodeHead();
                    else if (option == 3) add_NodeMid();
                    else cout << "Invalid Input!" << endl;
                    break;}
            case 2: display_Node();
                    break;
            case 3: {
                    cout << "Do you wish to delete by value or by position? " << endl;
                    cout << "[1] - By Value" << endl;
                    cout << "[2] - By Position" << endl;
                    cout << "Type your selection: ";
                    cin >> option;
                    if (option == 1) { delete_NodebyValue(); }
                    else if (option == 2) { delete_NodebyPosition();}
                    else { cout << "\nInvalid Input!" << endl;}
                    break;}
            case 4: 
                    cout << "Input the Position for The Node You Wish To Edit: " << endl;
                    edit_Node();
                    break;
            case 5: cout << "Exiting Program!";
                    return 0;
        }
    } while (choice != 5);
}
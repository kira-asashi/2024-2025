#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void add_node(Node *&head, Node *&tail);
void edit_node(Node *&head, Node *&tail);
void delete_node(Node *&head, Node *&tail);
void display_node(Node *head, Node *tail);

int main(){
Node *head = NULL;
Node *tail = NULL;

int choice;
do {
cout << "[1] - Add Node" << endl;
cout << "[2] - Edit Node" << endl;
cout << "[3] - Delete Node" << endl;
cout << "[4] - Display Node" << endl;
cout << "[5] - Exit" << endl;
cout << "Enter your choice(1-5): ";
if (!(cin >> choice) || choice < 1 || choice > 5){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "\nError!Please Enter Within Valid Input Only.\n\n";
        continue;}
switch (choice){
    case 1:
        add_node(head, tail);
        break;
    case 2:
        edit_node(head, tail);
        break;
    case 3:
        delete_node(head, tail);
        break;
    case 4:
        display_node(head, tail);
        break;
    case 5:
        cout << "\nExiting Program..." << endl;
        break;
    }
}while (choice !=5);
return 0;
}

void add_node(Node *&head, Node *&tail){
    int choice;
    int num;
    cout <<"\nEnter integer: ";
    cin >> num;

    Node *newNode = new Node;
    newNode -> data = num;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    int nodeSize = 0;

    Node *temp = head;
    while(temp!=NULL){
    nodeSize++;
    temp = temp ->next;
    }

    if (head == NULL){
    cout << "\nNode is Empty!" << endl;
    cout << num << " will be used to create the first node." << endl;
    head = tail = newNode;
    display_node(head,tail);
    return;}

    int position = 0;
    cout << "Enter position: ";
    while (!(cin >> position) || position < 1){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Position! Position must be atleast 1." << endl;
    cout << "Enter Valid Position: ";}
    
  
    if (position >= nodeSize){
    cout << "Node only contains " << nodeSize << "nodes." << endl;
    cout << num << " will be used to create the last node instead." << endl;
    newNode ->prev = tail;
    newNode ->next = NULL;
    tail -> next = newNode;
    tail = newNode;
    display_node(head,tail);
    return;}


    temp = head;
    for (int i = 0 ; i < position - 1; i++){
    temp = temp ->next;
    }

    newNode ->next = temp;
    newNode ->prev = temp ->prev;
    temp -> prev = newNode;

    if(position == 1)
    head = newNode;
    

    display_node(head,tail);
} 

void edit_node(Node *&head, Node *&tail){
    if (head == NULL){
    cout << "\nNode is Empty!" << endl;
    cout << endl;
    return;}

    int choice;
    int num;
    cout <<"\nEnter integer: ";
    cin >> num;

    Node *newNode = new Node;
    newNode -> data = num;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    int nodeSize = 0;

    Node *temp = head;
    while(temp!=NULL){
    nodeSize++;
    temp = temp ->next;
    }

    int position = 0;
    cout << "Enter position: ";
    while (!(cin >> position) || position < 1 || position > nodeSize){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Position! Must be within valid range(1 - " << nodeSize << ")." << endl;
    cout << "Enter Valid Position: ";}
    
    temp = head;
    for (int i = 0; i < position - 1; i++){
    temp = temp ->next;
    }
    temp -> data = num;
    display_node(head,tail);
}

void delete_node(Node *&head, Node *&tail){
    if (head == NULL){
    cout << "\nNode is Empty!" << endl;
    cout << endl;
    return;}
    
    Node *temp = head;
    int nodeSize = 0;
    while(temp!=NULL){
    nodeSize++;
    temp = temp ->next;
    }

    int position = 0;
    cout << "Enter position: ";
    while (!(cin >> position) || position < 1 || position > nodeSize){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Position! Must be within valid range(1 - " << nodeSize << ")." << endl;
    cout << "Enter Valid Position: ";}
    
    temp = head;
    if (position == 1){
        head = head -> next;
        if (head != NULL)
            head -> prev = NULL;
        delete temp;
        display_node(head,tail);
        return;
    }
    //0 1
    for (int i = 0; i < position - 1; i++){
    temp = temp ->next;
    }
    //_123_
    temp -> prev ->next = temp ->next;
    if (temp ->next != NULL){
    temp ->next ->prev = temp ->prev;   
    }else{
    tail = temp -> prev;}
    delete temp;
    display_node(head,tail);
}

void display_node(Node *head, Node *tail){
    if (head == NULL){
        cout << "\nNode is Empty!" << endl;
        cout << endl;
        return;
    }
    
    cout << "\n\n";
    cout << "Data Contents: " << endl;

    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;}
    cout << endl;
    temp = tail;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;}
    cout << endl << endl;
}

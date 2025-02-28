#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

//Write List::remove() here
void List::remove(int idx) {
    if (root == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    // If we want to remove the first node (root)
    if (idx == 0) {
        Node* temp = root;
        root = root->next;  // Move the root to the next node
        delete temp;        // Delete the old root node
        return;
    }

    // Traverse the list to find the node to be deleted
    Node* current = root;
    for (int i = 0; current != NULL && i < idx - 1; i++) {
        current = current->next;
    }

    // If the index is out of range (either list is too short or the index is invalid)
    if (current == NULL || current->next == NULL) {
        cout << "Position out of range." << endl;
        return;
    }

    // Node current->next is the node to be deleted
    Node* temp = current->next;
    current->next = current->next->next;  // Unlink the node from the list
    delete temp;  // Delete the node
}


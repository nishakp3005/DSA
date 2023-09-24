#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    //constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" " ;
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void insert(Node* &head, int position, int data){
    Node* new_node = new Node(data);
    if(head == NULL){
        head = new_node;
    }
    Node* temp = head;
    if(position == 0){
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else if(position == -1){
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next=new_node;
        new_node->prev = temp;
    }
    else{
        int count = 1;
        Node* temp2 = head->next;
        while(count < position){
            temp = temp->next;
            temp2 = temp2->next;
            count++;
        }
        new_node->next = temp2;
        new_node->prev = temp;
        temp->next = new_node;
        temp2->prev = new_node;
    }
}

void deleteNode(Node* &head, int position){
    Node* temp = head;
    if(position == 0){
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position == -1){
        Node* temp1 = head->next;
        while(temp1->next != NULL){
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp->next = NULL;
        temp1->prev = NULL;
        delete temp1;
    }
    else{
        Node* temp1 = NULL;

        int cnt = 1;
        while(cnt < position) {
            temp1 = temp;
            temp = temp -> next;
            cnt++;
        }

        temp1 -> next = temp -> next;
        temp -> next  = NULL;
        delete temp;

    }
}

int main(){
    Node* node1 = new Node(50);
    Node* head = node1;
    print(head);
    cout<<"length is "<<getLength(head)<<endl;
    cout<<endl<<"insertion starts here"<<endl;
    insert(head, 0, 49);
    print(head);
    cout<<"length is "<<getLength(head)<<endl;
    insert(head, -1, 69);
    print(head);
    cout<<"length is "<<getLength(head)<<endl;
    insert(head, 2, 54);
    insert(head, 2, 53);
    insert(head, 2, 52);
    insert(head, 2, 51);
    print(head);
    cout<<"length is "<<getLength(head)<<endl;
    cout<<endl<<"deletion starts here"<<endl;
    deleteNode(head, 0);
    print(head);
    cout<<"length is "<<getLength(head)<<endl;
    deleteNode(head, -1);
    print(head);
    cout<<"length is "<<getLength(head)<<endl;
    deleteNode(head, 2);
    print(head);
    cout<<"length is "<<getLength(head)<<endl;
    return 0;
}
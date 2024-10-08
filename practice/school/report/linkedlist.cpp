#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* newNode(int x){
    Node *tmp = new Node();
    tmp->next = NULL;
    tmp->data = x;
    return tmp;
}

struct Singly_linkedlist{
    // datatype elements
    Node *head; 

    // some prototypes
    void initiation(){
        head = NULL;
    }
    void INSERT_Tail(int x){
        if(isEmpty()){
            head = newNode(x);
            return;
        }
        Node *p = head;
        while(p != NULL){
            p = p->next; 
        }
        p->next = newNode(x);
    }
    void DELETE_head(int x){
        if(isEmpty()){
            cout << "can not delete";
            return;
        }
        Node *tmp = head; 
        head = head->next;
        delete tmp;
    }
    int FIND(int x){
        Node* p = head;
        while(p->next != NULL){
            if(p->data == x)
                return p->data;
            p = p->next;
        }
        return -1;
    }
    void UPDATE(int x, int y){
        Node* p = head;
        while(p->next != NULL){
            if(p->data == x)
                p->data = y;
            p = p->next;
        }
    }
    void Traversal(){
        Node *p = head; 
        while(p->next != NULL){
            cout << p->data;
            p = p->next;
        }
    }
    int size(){
        int cnt = 0;
        Node *p = head; 
        while(p->next != NULL){
            cnt++;
            p = p->next;
        }
    }
    bool isEmpty(){
        return head == NULL;
    }
};

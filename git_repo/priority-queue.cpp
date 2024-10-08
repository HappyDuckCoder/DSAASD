#include<iostream>
#include<string>

using namespace std;

struct Node{
    string data;
    Node *next;
};

typedef Node* node;

node makeNode(string x){
    node tmp = new Node();
    tmp->next = NULL;
    tmp->data = x;
    return tmp;
}

class Queue{
private:
    node head;

    void pushQu(node &head, string x){
        node tmp = makeNode(x);
        if(head == NULL){
            head = tmp;
        } else {
            node p = head;
            
            while(p->next != NULL && p->data <= x) p = p->next;
            
            tmp->next = p->next;
            p->next = tmp;
        }
    }

    void popQu(node &head){
        if(head == NULL) return;
        node tmp = head;
        head = head->next;
        delete tmp;
    }

    bool emptyQu(node head){
        return head == NULL;
    }

    string frontQu(node head){
        if(head == NULL) return "emptyQu";
        return head->data;
    }

public:
    Queue() { head = NULL; }

    void push(string x){
        pushQu(head, x);
    }

    void pop(){
        popQu(head);
    }

    bool empty(){
        return emptyQu(head);
    }

    string front(){
        return frontQu(head);
    }
};

int main(){
    string Names[7] = {"toi", "ten", "la", "tran", "hai", "duc", "ne"};
    int n = 7;

    Queue qu;
    for(int i = 0; i < n; i++){
        qu.push(Names[i]);
    }

    qu.pop();
    qu.pop();

    while(!qu.empty()){
        cout << qu.front() << "\n";
        qu.pop();
    }

    return 0;
}

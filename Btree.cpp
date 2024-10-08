#include<iostream> 
using namespace std;

//3-ways tree

struct Node{
    int key[3]; 
    int *ways[3];
};

struct Btree{
    Node* root = NULL;
};

Node* insert(int data);
Node* _delete(int data);

Node* insert(Node* root, int data){
    if(root == NULL){
        Node* tmp = new Node();
        tmp->key[0] = data;
        tmp->key[1] = tmp->key[2] = 0; 
        tmp->ways[0] = tmp->ways[1] = tmp->ways[2] = NULL; 
        return tmp; 
    } else {
        int cnt = 0;
        int emp = 0;
        for(int i = 0; i < 3; i++){
            if(root->key != 0){
                cnt++;
                emp = i;
            }
        }
        if(cnt == 2){
            int j = 0; 
            while(root->key[j] > data) j++; 
            if(j == 2) root = insert(root->ways[2], data); 
            else if(j == 1) root = insert(root->ways[1], data);
            else if(j == 0) root = insert(root->ways[0], data); 
        } else {
            root->key[emp] = data;
        }
    }
}

int main(){

    return 0;
}
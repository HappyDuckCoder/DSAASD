#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data){
    Node *tmp = new Node();
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

Node *insert(Node *root, int data){
    if(!root) return newNode(data);
    if(data < root->data) root->left = insert(root->left, data);
    else if(data > root->data) root->right = insert(root->right, data);
    // else return root;

    return root;
}

void inorder(Node *root){
    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    int n; cin >> n;

    Node* root = NULL;

    for(int i = 0; i < n; i++){
        int data; cin >> data;
        inorder(root);
        root = insert(root, data);        
    }


    return 0;
}
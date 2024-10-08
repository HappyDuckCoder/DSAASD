#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};

typedef Node* node;

node newNode(int data){
    node tmp = new Node();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->key = data;
    return tmp;
}

node insert(node root, int data){
    if(root == NULL) root = newNode(data);
    else{
        if(root->key > data) root->left = insert(root->left, data);
        else if(root->key < data) root->right = insert(root->right, data);
        if(root->key == data){
            // If duplicated are allow 
            root->left = insert(root->left, data); // or we can you root->right = insert(root->right, data); 
            // If duplicated are not allow
            // return root; 
        }
    }
    return root;
}

node findMinNode(node curr){
    curr = curr->right;
    while(curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

node delNode(node root, int x){
    if(root == NULL) return root;

    if(root->key > x) root->left = delNode(root->left, x);
    else if(root->key < x) root->right = delNode(root->right, x);
    else{
        if(root->left == NULL){
            node temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            node temp = root->left;
            delete root;
            return temp;
        }

        node succ = findMinNode(root);
        root->key = succ->key;
        root->right = delNode(root->right, succ->key);
    }

    return root;
}

void NLR(node root){
    if(root == NULL) return;
    cout << root->key << " ";
    NLR(root->left);
    NLR(root->right);
}

void LNR(node root){
    if(root == NULL) return;
    LNR(root->left);
    cout << root->key << " ";
    LNR(root->right);
}

void LRN(node root){
    if(root == NULL) return;
    LRN(root->left);
    LRN(root->right);
    cout << root->key << " ";
}

int height(node root){
	if(root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

node search(node root, int data){
    if(root == NULL) return NULL;
    if(root->key > data) return search(root->left, data);
    if(root->key < data) return search(root->right, data);
    return root;
}

bool isEmpty(node root){
    return root == NULL;
}

void EmptyTheTree(node &root) {
    if(root == NULL) return;

    EmptyTheTree(root->left);
    EmptyTheTree(root->right);

    delete root;
    root = NULL;
}

int main(){
	int n = 10;
    int a[10] = {1, 4, 3, 5, 9, 2, 10, 6, 8, 7}; // initiate with positive number
    
    node root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, a[i]);
    NLR(root); cout << endl;
    LNR(root); cout << endl;
    LRN(root); cout << endl;

    int x = 5;
    node t = search(root, 5);
    cout << height(t);

    return 0;
}
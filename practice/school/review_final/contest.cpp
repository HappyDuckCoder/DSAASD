#include<iostream>
#include<vector>

#define vi vector<int>

using namespace std;

struct Node{
    int data;
    int height;
    Node *left;
    Node *right;
};

typedef Node* node;

node make_node(int data){
    node tmp = new Node();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;
    tmp->data = data;

    return tmp;
}

int Height(node root){
    if(!root) return 0;
    return root->height;
}

node insert(node root, int data){
    if(!root) return make_node(data);

    if(data < root->data) root->left = insert(root->left, data);
    else if(data > root->data) root->right = insert(root->right, data);
    
    root->height = 1 + max(Height(root->left), Height(root->right));

    return root;
}

bool check(node root){
    if(!root) return true;

    int t = Height(root->left) - Height(root->right);
    if(t > 1 || t < -1) return false;

    return check(root->left) && check(root->right);
}


int main(){

    int n; cin >> n;
    vi a(n); for(int i = 0; i < n; i++) cin >> a[i];
    node root = NULL;
    for(int i = 0; i < n; i++){
        root = insert(root, a[i]);
    } 
    (check(root)) ? cout << 1 : cout << 0;

    return 0;
}
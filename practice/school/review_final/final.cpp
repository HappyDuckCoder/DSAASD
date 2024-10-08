#include<iostream>
#include<queue>

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
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

node insert(node root, int data){
    if(!root) return make_node(data);

    if(data < root->data) root->left = insert(root->left, data);
    else if(data > root->data) root->right = insert(root->right, data);

    return root;
}

int depth(node root, int k){
    if(!root) return 0;

    queue<node> qu;

    int h = 0;
    int res = 0;

    qu.push(root);
    while(!qu.empty()){
        int size = qu.size();
        h++;

        while(size--){
            node tmp = qu.front();
            
            if(tmp->data == k){
                res = h;
            }

            qu.pop();

            if(tmp->left) qu.push(tmp->left);
            if(tmp->right) qu.push(tmp->right);
        }
    }

    // cout << endl;
    return res;
}

int main(){

    int n; cin >> n;
    node root = NULL;
    for(int i = 0; i < n; i++){
        int data; cin >> data;
        root = insert(root, data);
    }

    // int deep = depth

    return 0;
}
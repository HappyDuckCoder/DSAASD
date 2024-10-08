#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
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
    if(data > root->data) root->right = insert(root->right, data);
    else if(data < root->data) root->left = insert(root->left, data);
    return root;
}

vector<int> count_node(node root, int k){
    if(!root) return {};

    queue<node> qu;
    qu.push(root);

    int h = 0;
    vector<int> res;    

    while(!qu.empty()){
        int size = qu.size();
        h++;
        for(int i = 0; i < size; i++){
            node tmp = qu.front();
            qu.pop();

            if(h > k && !tmp->left && !tmp->right) 
                res.push_back(tmp->data);

            if(tmp->left) qu.push(tmp->left);
            if(tmp->right) qu.push(tmp->right);
        }
    }

    return res;
}

int height(node root){
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right)); 
}

node find_deepest_node(node root){
    if(!root) return NULL;

    int h = height(root);
    
    queue<node> qu;
    qu.push(root);

    int k = 0;
    while(!qu.empty()){
        k++;
        int size = qu.size();
        while(size--){
            node tmp = qu.front();
            qu.pop();

            if(k == h) return tmp;

            if(tmp->left) qu.push(tmp->left);
            if(tmp->right) qu.push(tmp->right);
        }
    }
    return NULL;
}

void print(node root, node res){
    if(!root) return;

    cout << root->data << " ";
    if(res->data < root->data) print(root->left, res);
    else if(res->data > root->data) print(root->right, res);
}

int main(){

    int n, k; cin >> n >> k;
    node root = NULL;
    for(int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        root = insert(root, tmp);
    }

    // vector<int> res = count_node(root, k);
    // for(auto i : res) cout << i << " ";

    // cout << height(root);

    node res = find_deepest_node(root);
    // cout << res->data << "\n";
    print(root, res);

    return 0;
}
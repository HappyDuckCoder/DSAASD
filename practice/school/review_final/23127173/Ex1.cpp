#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Node{
    int data;
    int height;
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
    if(root == NULL){
        return make_node(data);
    }
    
    if(data < root->data) root->left = insert(root->left, data);
    else if(data > root->data) root->right = insert(root->right, data);
    
    return root;
}

void LNR(node root){
    if(!root) return;
    
    LNR(root->left);
    cout << root->data << " ";
    LNR(root->right);
}

int depth(node root, int k){
    if(root == NULL) return 0;
    
    queue<node> qu;
    qu.push(root);
    
    int h = 0;
    int res = -1;  
    
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
    
    return res;
}


void search(node root, node cur, vector<int> &a, int deep){    

    if(root == NULL || cur == NULL) return;
    
    search(root, cur->left, a, deep);

	int t = depth(root, cur->data); 
    if(t == deep) a.push_back(cur->data);

    search(root, cur->right, a, deep);
}

int main(){
    
    int n, k;
    cin >> n >> k;
    
    node root = NULL;
    
    for(int i = 0; i < n; i++){
        int data; cin >> data;
        root = insert(root, data);
    }
    
    int deep = depth(root, k);
    
    if(deep == -1) {
        // If the node k is not found in the tree
        cout << "null";
        return 0;
    }
    
    vector<int> a;
    
    search(root, root, a, deep);
    
    if(a.size() == 1){
        cout << "null"; 
    } else {
        int j = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == k){
                j = i;
            }
        }
        if(j == a.size() - 1){
            cout << "null";
        } else {
            cout << a[j + 1]; 
        }
    } 
    
    return 0;
}

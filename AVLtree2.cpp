#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int key;
    int height;
    Node *left;
    Node *right;
};

typedef Node* node;

node makeNode(int data){
    node tmp = new Node();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->key = data;
    tmp->height = 1;
    return tmp;
}

int height(node root){
    if(!root) return 0;
    return root->height;
}

int getBalance(node root){
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

//        x
//     y      T1
// T3   T2

node rightRotate(node root){
    node x = root;
    node y = x->left;
    node T2 = y->right;
    x->left = T2;
    y->right = x;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

//         x
//     T1      y
//          T2   T3

node leftRotate(node root){
    node x = root;
    node y = x->right;
    node T2 = y->left;
    x->right = T2;
    y->left = x;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

node makebalance(node root){
    root->height = 1 + max(height(root->left), height(root->right));
    int bal = getBalance(root);
    int balleft = getBalance(root->left);
    int balright = getBalance(root->right);
    
    // left - left
    if(bal > 1 && balleft >= 0) return rightRotate(root);
    
    // right - right 
    if(bal < -1 && balright <= 0) return leftRotate(root);
    
    // left - right
    if(bal > 1 && balleft <= 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // right - left
    if(bal < -1 && balright >= 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

node insert(node root, int data){
    if(root == NULL) return makeNode(data);
    if(data > root->key) root->right = insert(root->right, data);
    else if(data < root->key) root->left = insert(root->left, data);
    else{
        cout << "do not add";
        return root;
    }
    
    root = makebalance(root);
    
    return root;
}

node deleteNode(node root, int data){
    if(root == NULL){
        "can not delete";
        return NULL;
    }
    if(data > root->key) root->right = deleteNode(root->right, data);
    else if(data < root->key) root->left = deleteNode(root->left, data);
    else {
        if(root->left == NULL || root->right == NULL){
            node temp = root->left ? root->left : root->right;

            if(temp == NULL){ 
                temp = root;
                root = NULL;
            } else { 
                *root = *temp; 
            }
            delete temp;
        } else {
            node temp = root->left;
            while(temp->right != NULL) temp = temp->right;

            root->key = temp->key;

            root->left = deleteNode(root->left, temp->key);
        }
    }
    
    if(root == NULL){
        return NULL;
    }
    
    root = makebalance(root);
    
    return root;
}

void LevelOrder(node root){
    if(root == NULL) return;
    queue<node> qu;
    qu.push(root);
    while(!qu.empty()){
        node current = qu.front();
        qu.pop();
        cout << current->key << " ";
        if(current->left != NULL) qu.push(current->left);
        if(current->right != NULL) qu.push(current->right);
    }
}

int main(){
    int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 75};
    int n = 11;
    node root = NULL;
    for(int i = 0; i < n; i++)
        root = insert(root, a[i]);
    LevelOrder(root); cout << endl;
    root = deleteNode(root, 1);
    root = deleteNode(root, 2);
    LevelOrder(root); cout << endl;
    
    return 0;
}
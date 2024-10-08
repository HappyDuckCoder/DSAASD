#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    int height;
};

typedef Node* node;

node newNode(int data){
    node tmp = new Node();
    tmp->key = data; 
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;
    return tmp;
}

int getMax(int a, int b){
    if(a > b) return a;
    return b;
}

int getHeight(node x){
    if(x == NULL) return 0;
    return x->height;
}

int getBalance(node x){
    if(x == NULL) return 0;
    return getHeight(x->left) - getHeight(x->right);
}

node leftRotate(node root){
    node x = root;
    node y = x->right;
    node T2 = y->left;
    y->left = x;
    x->right = T2;
    y->height = 1 + getMax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + getMax(getHeight(x->left), getHeight(x->right));
    return y;
}

node rightRotate(node root){
    node y = root;
    node x = y->left;
    node T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + getMax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + getMax(getHeight(x->left), getHeight(x->right));
    return x;
}

node insertNode(node root, int data){
    if(root == NULL){
        node tmp = newNode(data);
        root = tmp;
    } 
    else{
        if(root->key == data){
            cout << "do not add existing keys";
            return root; 
        } else if(root->key > data){
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    
    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));  
                        
    int balance = getBalance(root);  
  
    // Left Left Case  
    if(balance > 1 && data < root->left->key)  
        return rightRotate(root);  
  
    // Right Right Case  
    if(balance < -1 && data > root->right->key)  
        return leftRotate(root);  
  
    // Left Right Case  
    if(balance > 1 && data > root->left->key){  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Left Case  
    if(balance < -1 && data < root->right->key){  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  

    return root;  
}

node searchNode(node root, int data){
    if(root == NULL) return NULL;
    if(root->key > data) return searchNode(root->left, data);
    if(root->key < data) return searchNode(root->right, data);
    return root;
}

node deleteNode(node root, int data){
    if(root == NULL) return NULL;

    if(data < root->key){
        root->left = deleteNode(root->left, data);
    }else if(data > root->key){
        root->right = deleteNode(root->right, data);
    } else {
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
            node temp = root->right;
            while(temp->left != NULL) temp = temp->left;

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if(root == NULL) return root;
    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // Left Left Case
    if(balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
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
    int n = 10;
    int a[10] = {1, 4, 3, 5, 9, 2, 10, 6, 8, 7};
    

    node root = NULL;
    for (int i = 0; i < n; i++) root = insertNode(root, a[i]);
    LNR(root); cout << endl;

    root = deleteNode(root, 1);
    NLR(root); cout << endl;

    root = deleteNode(root, 2);
    LRN(root); cout << endl;

    root = deleteNode(root, 3);
    LevelOrder(root); cout << endl;
    
    node tmp = searchNode(root, 5);
    cout << "Search 5: " << tmp->key;
    
    return 0;
}

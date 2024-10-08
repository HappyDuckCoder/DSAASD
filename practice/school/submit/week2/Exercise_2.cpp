#include<iostream>
#include<queue>
#include<vector>
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

bool isFull(node root){
    if(root == NULL) return true;
  
    if(root->left == NULL && root->right == NULL)
        return true;
  
    if((root->left) && (root->right))
        return (isFull(root->left) && isFull(root->right));
  
    return false;
}

bool isComplete(node root){
    queue<node> q;
    q.push(root);
    bool flag = false;
 
    while(!q.empty()){
        node temp = q.front();
        q.pop();
        if(temp->left){
            if(flag == true) return false;
            q.push(temp->left); 
        }
        else flag = true;

        if(temp->right){
            if(flag == true) return false;
            q.push(temp->right); 
        }
        else flag = true;
    }

    return true;
}

bool isPerfect(node root){
    if(root == NULL) return true;
    
    if(getBalance(root) != 0) return false;
    return (isPerfect(root->left) && isPerfect(root->right));
}


bool findPath(node root, vector<int>& path, int k){
    if(root == NULL)
        return false;
 
    path.push_back(root->key);
 
    if(root->key == k)
        return true;
 
    if((root->left && findPath(root->left, path, k))
        || (root->right && findPath(root->right, path, k)))
        return true;
 
    path.pop_back();
    return false;
}
 

int findCommonAncestor(node root, int n1, int n2){
    vector<int> path1, path2;
 
    if(!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;
 
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}

void printSpecialNodes(node root){
    if(root == NULL) return;
    
    printSpecialNodes(root->left);
    
    if(root->left != NULL && root->right != NULL){
        if(root->right->key % root->left->key == 0){
            cout << root->key << " ";
        }
    }
    printSpecialNodes(root->right);
    
}

int main(){
    int n = 10;
    int a[10] = {1, 4, 3, 5, 9, 2, 10, 6, 8, 7};
    

    node root = NULL;
    for (int i = 0; i < n; i++) root = insertNode(root, a[i]);
    LevelOrder(root); cout << endl;

    // root = deleteNode(root, 2);
    // root = deleteNode(root, 4);
    // root = deleteNode(root, 7);
    // root = deleteNode(root, 10);
    // root = deleteNode(root, 8);
    LevelOrder(root); cout << endl;

    (isFull(root)) ? cout << "YES\n" : cout << "NO\n";
    (isComplete(root)) ? cout << "YES\n" : cout << "NO\n";
    (isPerfect(root)) ? cout << "YES\n" : cout << "NO\n";
    cout << findCommonAncestor(root, 10, 8); cout << endl;
    printSpecialNodes(root);
    
    return 0;
}

#include<iostream>

using namespace std;

struct Node {
    int data;
    int height; 
    Node *left;
    Node *right;
};

typedef Node* node;

node createNode(int data) {
    node newNode = new Node();
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

class AVLTree {
private:
    node root;

    int height(node n){
        if(n == NULL) return 0;
        return n->height;
    }

    int getBalance(node n){
        if(n == NULL) return 0;
        return height(n->left) - height(n->right);
    }

    node rightRotate(node y){
        node x = y->left;
        node T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    node leftRotate(node x){
        node y = x->right;
        node T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    node minValueNode(node n){
        node current = n;
        while (current->left != NULL)
            current = current->left;
        return current;
    }


    node insert(node root, int data){
        if(root == NULL) return createNode(data);

        if(data < root->data)
            root->left = insert(root->left, data);
        else if(data > root->data)
            root->right = insert(root->right, data);
        else
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // Left Left Case
        if(balance > 1 && data < root->left->data)
            return rightRotate(root);

        // Right Right Case
        if(balance < -1 && data > root->right->data)
            return leftRotate(root);

        // Left Right Case
        if(balance > 1 && data > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if(balance < -1 && data < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    node deleteNode(node root, int data){
        if(root == NULL) return root;

        if(data < root->data)
            root->left = deleteNode(root->left, data);
        else if(data > root->data)
            root->right = deleteNode(root->right, data);
        else{
            if((root->left == NULL) || (root->right == NULL)){
                node temp = NULL;
                (root->left) ? temp = root->left : temp = root->right;

                if(temp == NULL){
                    temp = root;
                    root = NULL;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                node temp = minValueNode(root->right);

                root->data = temp->data;

                root->right = deleteNode(root->right, temp->data);
            }
        }

        if(root == NULL) return root;

        root->height = 1 + max(height(root->left), height(root->right));

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


    void inorder(node root){
        if(root != NULL){
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

public:
    AVLTree(){
        root = NULL;
    }

    void remove(int data){
        root = deleteNode(root, data);
    }

    void insert(int data){
        root = insert(root, data);
    }

    void display(){
        inorder(root);
        cout << endl;
    }
};

int main(){
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    tree.insert(35);

    // tree.remove(30);
    tree.remove(50);

    tree.display();

    return 0;
}

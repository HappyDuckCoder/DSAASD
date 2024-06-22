#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

typedef Node* node;

node createNode(int data){
    node newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

class Tree{
private:
    node root;
    int size;
    void insertNode(node &root, int data, int &size){
        node tmp = createNode(data);
        if(root == NULL){
            root = tmp;
            size++;
        } else {
            if(data == root->data){
                cout << "Duplicate data";
                return;
            } else {
                size++;
                if(data < root->data) insertNode(root->left, data, size);
                else insertNode(root->right, data, size);
            }
        }
    }

    void NLR(node root){
        if(root == NULL) return;
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }

    void LNR(node root){
        if(root == NULL) return;
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }

    void LRN(node root){
        if(root == NULL) return;
        LRN(root->left);
        LRN(root->right);
        cout << root->data << " ";
    }

    void levelOrder(node root, int level){
        if(root == NULL) return;
        if(level == 1) cout << root->data << " ";
        else if(level > 1){
            levelOrder(root->left, level - 1);
            levelOrder(root->right, level - 1);
        }
    }

    void leverOrderByQueue(node root){
        if(root == NULL) return;
        queue<node> q;
        q.push(root);
        while(!q.empty()){
            node tmp = q.front();
            cout << tmp->data << " ";
            q.pop();
            if(tmp->left != NULL) q.push(tmp->left);
            if(tmp->right != NULL) q.push(tmp->right);
        }
    }

    void deleteNode(node &root, int data){
        if(root == NULL) return;
        if(data < root->data) deleteNode(root->left, data);
        else if(data > root->data) deleteNode(root->right, data);
        else {
            if(root->left == NULL){
                node tmp = root;
                root = root->right;
                delete tmp;
            } else if(root->right == NULL){
                node tmp = root;
                root = root->left;
                delete tmp;
            } else {
                node tmp = root->right;
                while(tmp->left != NULL) tmp = tmp->left;
                root->data = tmp->data;
                deleteNode(root->right, tmp->data);
            }
        }
    }

    void deleteTree(node root){
        if(root == NULL) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

public:
    Tree(int data){
        root = createNode(data);
        size = 1;
    }
    Tree(){
        root = NULL;
        size = 0;
    }

    int getSize(){return size;}

    void insert(int data){insertNode(root, data, size);}

    void NLR(){NLR(root); cout << endl;}
    void LNR(){LNR(root); cout << endl;}
    void LRN(){LRN(root); cout << endl;}

    void levelOrder(int level){levelOrder(root, level);}
    void leverOrderByQueue(){leverOrderByQueue(root);}

    void deleteNode(int data){deleteNode(root, data);}

    void deleteTree(){deleteTree(root);}
};

int main(){
    int a[10] = {5, 3, 7, 2, 4, 6, 8, 1, 9, 10};
    int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tree bst;
    
    for(int i = 0; i < 10; i++) bst.insert(a[i]);
    

    bst.NLR();
    bst.LNR();
    bst.LRN();

    for(int i = 1; i <= bst.getSize(); i++) bst.levelOrder(i);
    cout << endl;

    bst.leverOrderByQueue(); cout << endl;

    bst.deleteNode(b[3]);
    bst.LNR();

    bst.deleteTree();

    return 0;
}

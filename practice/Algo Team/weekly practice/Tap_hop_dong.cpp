#include <iostream>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* node;

node createNode(int key){
    node tmp = new Node();
    tmp->key = key;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

class BinaryTree {
private:
    node root;

    node insert(node root, int key){
        if(root == NULL) return createNode(key);
        if(key < root->key) root->left = insert(root->left, key);
        else if(key > root->key) root->right = insert(root->right, key);
        return root;
    }

    node deleteNode(node root, int key){
        if(root == NULL) return root;
        if(key < root->key) root->left = deleteNode(root->left, key);
        else if(key > root->key) root->right = deleteNode(root->right, key);
        else {
            if(root->left == NULL){
                node temp = root->right;
                delete root;
                return temp;
            }else if (root->right == NULL){
                node temp = root->left;
                delete root;
                return temp;
            }
            node temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    node minValueNode(node root){
        node current = root;
        while(current && current->left != NULL) current = current->left;
        return current;
    }

    node maxValueNode(node root){
        node current = root;
        while(current && current->right != NULL) current = current->right;
        return current;
    }

    node successor(node root, int key){
        node succ = NULL;
        while(root != NULL){
            if(key < root->key){
                succ = root;
                root = root->left;
            } else root = root->right;
        }
        return succ;
    }

    node successorOrEqual(node root, int key){
        node succ = NULL;
        while(root != NULL){
            if(key <= root->key){
                succ = root;
                root = root->left;
            } else root = root->right;
        }
        return succ;
    }

    node predecessor(node root, int key){
        node pred = NULL;
        while(root != NULL){
            if(key > root->key){
                pred = root;
                root = root->right;
            } else root = root->left;
        }
        return pred;
    }

    node predecessorOrEqual(node root, int key){
        node pred = NULL;
        while(root){
            if(key >= root->key){
                pred = root;
                root = root->right;
            } else root = root->left;
        }
        return pred;
    }

public:
    BinaryTree(){
        root = NULL;
    }

    void ADD(int key){
        root = insert(root, key);
    }

    void DELETE(int key){
        root = deleteNode(root, key);
    }

    int MINIMUM(){
        node tmp = minValueNode(root);
        return tmp ? tmp->key : -1;
    }

    int MAXIMUM(){
        node tmp = maxValueNode(root);
        return tmp ? tmp->key : -1;
    }

    int SUCC(int key){
        node tmp = successor(root, key);
        return tmp ? tmp->key : -1;
    }

    int SUCC_2(int key){
        node tmp = successorOrEqual(root, key);
        return tmp ? tmp->key : -1;
    }

    int PRED(int key){
        node tmp = predecessor(root, key);
        return tmp ? tmp->key : -1;
    }

    int PRED_2(int key){
        node tmp = predecessorOrEqual(root, key);
        return tmp ? tmp->key : -1;
    }
};

int main(){
    BinaryTree tree;
    int option, x;

    while(cin >> option){
        if(option == 0) break;

        switch(option){
            case 1: // ADD
                cin >> x;
                tree.ADD(x);
                break;
            case 2: // DELETE
                cin >> x;
                tree.DELETE(x);
                break;
            case 3: // MINIMUM
                {
                    int minVal = tree.MINIMUM();
                    if (minVal == -1) cout << "empty" << endl;
                    else cout << minVal << endl;
                }
                break;
            case 4: // MAXIMUM
                {
                    int maxVal = tree.MAXIMUM();
                    if (maxVal == -1) cout << "empty" << endl;
                    else cout << maxVal << endl;
                }
                break;
            case 5: // SUCC
                cin >> x;
                {
                    int succ = tree.SUCC(x);
                    if (succ == -1) cout << "no" << endl;
                    else cout << succ << endl;
                }
                break;
            case 6: // SUCC_2
                cin >> x;
                {
                    int succ2 = tree.SUCC_2(x);
                    if (succ2 == -1) cout << "no" << endl;
                    else cout << succ2 << endl;
                }
                break;
            case 7: // PRED
                cin >> x;
                {
                    int pred = tree.PRED(x);
                    if (pred == -1) cout << "no" << endl;
                    else cout << pred << endl;
                }
                break;
            case 8: // PRED_2
                cin >> x;
                {
                    int pred2 = tree.PRED_2(x);
                    if (pred2 == -1) cout << "no" << endl;
                    else cout << pred2 << endl;
                }
                break;
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    long long data;
    Node* left;
    Node* right;
};

typedef Node* node;
typedef long long ll;

node createNode(ll data) {
    node tmp = new Node();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    return tmp;
}

class BST {
private:
    node root;

    void ADD(node& root, ll data) {
        if (root == NULL) root = createNode(data);
        else if (data < root->data) ADD(root->left, data);
        else ADD(root->right, data);
    }

    void DELETE(node& root, ll data) {
        if (root == NULL) return;
        else if (data < root->data) DELETE(root->left, data);
        else if (data > root->data) DELETE(root->right, data);
        else {
            if (root->left == NULL && root->right == NULL) root = NULL;
            else if (root->left == NULL) root = root->right;
            else if (root->right == NULL) root = root->left;
            else {
                node tmp = root->right;
                while (tmp->left != NULL) tmp = tmp->left;
                root->data = tmp->data;
                DELETE(root->right, tmp->data);
            }
        }
    }

    ll MINIMUM(node root) {
        if (root == NULL) return -1;
        if (root->left == NULL) return root->data;
        while (root->left != NULL) root = root->left;
        return root->data;
    }

    ll MAXIMUM(node root) {
        if (root == NULL) return -1;
        if (root->right == NULL) return root->data;
        while (root->right != NULL) root = root->right;
        return root->data;
    }

    ll SUCC(node root, ll data) {
        node succ = NULL;
        while (root != NULL) {
            if (data < root->data) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ ? succ->data : -1;
    }

    ll SUCC_2(node root, ll data) {
        if (root == NULL) return -1;
        if (root->data <= data) {
            return SUCC_2(root->right, data);
        } else {
            ll leftSucc = SUCC_2(root->left, data);
            return (leftSucc != -1 && leftSucc >= data) ? leftSucc : root->data;
        }
    }

    ll PRED(node root, ll data) {
        node pred = NULL;
        while (root != NULL) {
            if (data > root->data) {
                pred = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return pred ? pred->data : -1;
    }

    ll PRED_2(node root, ll data) {
        if (root == NULL) return -1;
        if (root->data >= data) {
            return PRED_2(root->left, data);
        } else {
            ll rightPred = PRED_2(root->right, data);
            return (rightPred != -1 && rightPred <= data) ? rightPred : root->data;
        }
    }

public:
    BST() { root = NULL; }
    void ADD(ll data) {
        ADD(root, data);
    }

    void DELETE(ll data) {
        DELETE(root, data);
    }

    ll MINIMUM() {
        return MINIMUM(root);
    }

    ll MAXIMUM() {
        return MAXIMUM(root);
    }

    ll SUCC(ll data) {
        return SUCC(root, data);
    }

    ll SUCC_2(ll data) {
        return SUCC_2(root, data);
    }

    ll PRED(ll data) {
        return PRED(root, data);
    }

    ll PRED_2(ll data) {
        return PRED_2(root, data);
    }
};

int main() {
    BST b;
    while (true) {
        ll opt; cin >> opt;
        ll x;

        if (opt == 1) {
            cin >> x;
            b.ADD(x);
        } else if (opt == 2) {
            cin >> x;
            b.DELETE(x);
        } else if (opt == 3) {
            ll minVal = b.MINIMUM();
            if (minVal == -1) cout << "empty" << endl;
            else cout << minVal << endl;
        } else if (opt == 4) {
            ll maxVal = b.MAXIMUM();
            if (maxVal == -1) cout << "empty" << endl;
            else cout << maxVal << endl;
        } else if (opt == 5) {
            cin >> x;
            ll succ = b.SUCC(x);
            if (succ == -1) cout << "no" << endl;
            else cout << succ << endl;
        } else if (opt == 6) {
            cin >> x;
            ll succ2 = b.SUCC_2(x);
            if (succ2 == -1) cout << "no" << endl;
            else cout << succ2 << endl;
        } else if (opt == 7) {
            cin >> x;
            ll pred = b.PRED(x);
            if (pred == -1) cout << "no" << endl;
            else cout << pred << endl;
        } else if (opt == 8) {
            cin >> x;
            ll pred2 = b.PRED_2(x);
            if (pred2 == -1) cout << "no" << endl;
            else cout << pred2 << endl;
        } else {
            break;
        }   

        if (opt == 0) break;
    }
}
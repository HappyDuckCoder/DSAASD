#include<iostream>
#include<queue>
#include<cstring>

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
    tmp->height = 1;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

int Height(node root){
    if(root) return root->height;
    return 0;
}

int balance(node root){
    if(root == NULL) return 0;
    return Height(root->left) - Height(root->right);
}

//         x                      y
//     y       T1   <--->     T3       x
// T3      T2                       T2    T1 

node rotateRight(node root){
    node y = root->left;
    node T2 = y->right;

    y->right = root;
    root->left = T2;

    root->height = 1 + max(Height(root->left), Height(root->right));
    y->height = 1 + max(Height(y->left), Height(y->right));

    return y;
}

node rotateLeft(node root){
    node x = root->right;
    node T2 = x->left;

    x->left = root;
    root->right = T2;

    root->height = 1 + max(Height(root->left), Height(root->right));
    x->height = 1 + max(Height(x->left), Height(x->right));

    return x;
}

node balancing(node root){
    int bal = balance(root); 
    int balLeft = balance(root->left);
    int balRight = balance(root->right);

    // left - left 
    if(bal > 1 && balLeft >= 0){
        root = rotateRight(root);
    } 

    // right - right
    if(bal < -1 && balRight <= 0){
        root = rotateLeft(root);
    }

    // left - right 
    if(bal > 1 && balLeft < 0){
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }

    // right - left
    if(bal < -1 && balRight > 0){
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }

    return root;
}

//if the value represent in the tree, add to the right
node ADD(node root, int data){
    if(root == NULL){
        return make_node(data);
    } 
    if(data < root->data) root->left = ADD(root->left, data);
    else if(data > root->data) root->right = ADD(root->right, data);
    else{
        cout << root->data << " already appear, insert to right\n";
        root->right = ADD(root->right, data);
    }

    root->height = 1 + max(Height(root->left), Height(root->right));

    root = balancing(root);

    return root;
}

node findMax(node root){
    if(root == NULL) return NULL;
    while(root->right != NULL) root = root->right;
    return root;
}

node findMin(node root){
    if(root == NULL) return NULL;
    while(root->left != NULL) root = root->left;
    return root;
}

node DELETE(node root, int data){
    if(root == NULL){
        cout << "can not delete!\n";
        return NULL;
    }

    if(data < root->data) root->left = DELETE(root->left, data);
    else if(data > root->data) root->right = DELETE(root->right, data);
    else{
        if(root->left == NULL || root->right == NULL){
            node tmp = NULL;

            if(root->left) tmp = root->left;
            else tmp = root->right;
            
            if(tmp == NULL){
                tmp = root;
                root = NULL;
            } else {
                *root = *tmp;
            }
        } else {
            node tmp = findMax(root->left);
            root->data = tmp->data;
            root->left = DELETE(root->left, tmp->data);
        }
    }

    if(root == NULL) return root;

    root->height = 1 + max(Height(root->left), Height(root->right));
    root = balancing(root);

    return root;
}

void levelOrder(node root){
    if(!root) return;

    queue<node> qu;
    qu.push(root);

    int h = 0;

    while(!qu.empty()){
        int size = qu.size();

        h++;

        for(int i = 0; i < size; i++){
            node tmp = qu.front();
            cout << tmp->data << " ";
            qu.pop();

            if(tmp->left) qu.push(tmp->left);
            if(tmp->right) qu.push(tmp->right);
        }
        cout << '\n';   
    }

    cout << endl;
    // cout << "deep: " << h << "\n";
}
        // while(size--){
        //     node tmp = qu.front();
        //     cout << tmp->data << " ";
        //     qu.pop();

        //     if(tmp->left) qu.push(tmp->left);
        //     if(tmp->right) qu.push(tmp->right);
        // }

node MAX(node root){
    return findMax(root);
}

node MIN(node root){
    return findMin(root);
}

node search(node root, int data){
    if(root == NULL){
        cout << "key not found!";
        return NULL;
    } 
    if(root->data > data) return search(root->left, data);
    else if(root->data < data) return search(root->right, data);
    else return root;

    return NULL;
}


// find the min value > data
node upperbound(node root, int data){
    node res = NULL;
    while(root){
        if(root->data > data){
            res = root;
            root = root->left; 
        } else {
            root = root->right;
        }
    }
    return res;
}

// find the max value < data
node lowerbound(node root, int data) {
    node res = NULL;
    while(root){
        if(root->data < data){
            res = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return res;
}

int SUM(node root){
    if(root == NULL) return 0;
    int l = SUM(root->left);
    int r = SUM(root->right);
    return root->data + l + r;
}

bool isFull(node root){
    if(root == NULL) return true;
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) return false;
    return isFull(root->left) && isFull(root->right);
}

bool isComplete(node root){
    if(root == NULL) return true;

    queue<node> qu;
    qu.push(root);

    bool flag = false;

    while(!qu.empty()){
        node tmp = qu.front();
        qu.pop();

        if(tmp->left){
            if(flag) return false;
            qu.push(tmp->left);
        } else {
            flag = true;
        }

        if(tmp->right){
            if(flag) return false;
            qu.push(tmp->right);
        } else {
            flag = true;
        }
    }

    return true;
}

bool isPerfect(node root){
    if(root == NULL) return true;

    int depth = 0;
    node tmp = root;
    while(tmp){
        depth++;
        tmp = tmp->left;
    }

    queue<node> q;
    q.push(root);
    int level = 0;

    while(!q.empty()){
        int size = q.size();
        level++;
        while(size--){
            node n = q.front();
            q.pop();

            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);

            if(n->left == NULL && n->right != NULL) return false;
            if(n->left != NULL && n->right == NULL) return false;
        }
    }

    return depth == level;
}

int count1(node root){
    if(root->left == NULL || root->right == NULL) return 0;
    else{
        int t = root->left->data + root->right->data;
        if(t % 2 == 0) return 1 + count1(root->right) + count1(root->left);
        else return count1(root->right) + count1(root->left);
    }
}

int main(){
    node root = NULL;

    int a[10] = {47, 12, 53, 22, 12, 29, 90, 33, 123, 10};
    for(int i = 0; i < 10; i++){
        root = ADD(root, a[i]);
    }

    levelOrder(root);

    int b[5] = {47, 22, 12, 1, 2};
    for(int i = 0; i < 5; i++){
        root = DELETE(root, b[i]);
    }

    levelOrder(root);

    int sum = SUM(root);
    int h = Height(root);
    int c1 = count1(root);

    node x1 = search(root, 1);
    node x2 = lowerbound(root, 2);
    node x3 = upperbound(root, 90);
    node x4 = MAX(root);
    node x5 = MIN(root);

    bool check1 = isFull(root);
    bool check2 = isComplete(root);
    bool check3 = isPerfect(root);

    // Print the result 
    cout << "Sum of nodes: " << sum << endl;
    cout << "Height of tree: " << h << endl;
    cout << "Number of node have sum child is even: " << c1 << endl;
    cout << "Search result: " << (x1 ? x1->data : -1) << endl;
    cout << "Lower bound: " << (x2 ? x2->data : -1) << endl;
    cout << "Upper bound: " << (x3 ? x3->data : -1) << endl;
    cout << "Max node: " << (x4 ? x4->data : -1) << endl;
    cout << "Min node: " << (x5 ? x5->data : -1) << endl;
    cout << "Is full tree: " << (check1 ? "Yes" : "No") << endl;
    cout << "Is complete tree: " << (check2 ? "Yes" : "No") << endl;
    cout << "Is perfect tree: " << (check3 ? "Yes" : "No") << endl;

    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};

typedef Node* node;

node newNode(int data){
    node tmp = new Node();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->key = data;
    return tmp;
}

node insert(node root, int data){
    if(root == NULL) root = newNode(data);
    else{
        if(root->key > data) root->left = insert(root->left, data);
        else if(root->key < data) root->right = insert(root->right, data);
    }
    return root;
}

node search(node root, int data){
    if(root == NULL) return NULL;
    if(root->key > data) return search(root->left, data);
    if(root->key < data) return search(root->right, data);
    return root;
}

node deleteNode(node root, int data){
    if(root == NULL) return NULL;
    if(data < root->key) root->left = deleteNode(root->left, data);
    else if(data > root->key) root->right = deleteNode(root->right, data);
    else{
        if(root->left == NULL){
            node tmp = root;
            root = root->right;
            delete tmp;
        } 
        else if(root->right == NULL){
            node tmp = root;
            root = root->left;
            delete tmp;
        } 
        else{
            node succParent = root;
            node succ = root->right;
            while(succ->left != NULL){
                succParent = succ;
                succ = succ->left;
            }

            root->key = succ->key;

            if(succParent->left == succ) succParent->left = succ->right;
            else succParent->right = succ->right;

            delete succ;
        }
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

int height(node root){
	if(root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

int countNode(node root){
	if(root == NULL) return 0;
	int l = countNode(root->left);
	int r = countNode(root->right);
	return l + r + 1;
}

int sumNode(node root){
	if(root == NULL) return 0;
	int l = sumNode(root->left);
	int r = sumNode(root->right);
	return root->key + l + r;
}

int countLeaf(node root){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	return countLeaf(root->left) + countLeaf(root->right);
}

int countLess(node root, int x){
	if(root == NULL) return 0;
	
//	cout << root->key << "root curr" << endl;
	
	int i = countLess(root->left, x);
	if(root->key < x){
		i += countLess(root->right, x);
	}

	if(root->key < x) return 1 + i;
	
	return i;
}

int countLarge(node root, int x){
	if(root == NULL) return 0;
	
//	cout << root->key << "root curr" << endl;
	
	int i = countLarge(root->right, x);
	if(root->key > x){
		i += countLarge(root->left, x);
	}

	if(root->key > x) return 1 + i;
	
	return i;
}

int main(){
	int n = 10;
    int a[10] = {1, 4, 3, 5, 9, 2, 10, 6, 8, 7};
    

    node root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, a[i]);
    LNR(root); cout << endl;

//    root = deleteNode(root, 1);
//    NLR(root); cout << endl;
//
//    root = deleteNode(root, 10);
//    LRN(root); cout << endl;
//
//    root = deleteNode(root, 5);
    LevelOrder(root); cout << endl;

	int H = height(root);
	cout << H << endl;
	
	int cnt = countNode(root);
	cout << cnt << endl;
	
	int sum = sumNode(root);
	cout << sum << endl;

	int cntLeft = countLeaf(root);
	cout << cntLeft << endl;
	
	int cntLess = countLess(root, 7);
	cout << cntLess << endl;
	
	int cntLarge = countLarge(root, 2);
	cout << cntLarge << endl;

    return 0;
}
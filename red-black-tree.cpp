#include <bits/stdc++.h>
using namespace std;

class RedBlackTree{
private:
	struct Node{
		int data;
		Node* left;
		Node* right;
		char colour;
		Node* parent;
	};
	
	typedef Node* node;
	node makeNode(int data){
	    node tmp = new Node();
	    tmp->left = NULL;
	    tmp->right = NULL;
	    tmp->parent = NULL;
	    tmp->colour = 'R';
	    tmp->data = data;
	    return tmp;
	}

	Node* root;
	bool ll; // Left-Left Rotation flag
	bool rr; // Right-Right Rotation flag
	bool lr; // Left-Right Rotation flag
	bool rl; // Right-Left Rotation flag

    //          root
    //      T          x
    //               y

	// Function to perform Left Rotation
	node rotateLeft(node root){
		node x = root->right;
		node y = x->left;
		x->left = root;
		root->right = y;
		root->parent = x;
		if(y != nullptr) y->parent = root;
		return x;
	}
	
	//           root
    //      x           T      
    //         y     

	// Function to perform Right Rotation
	node rotateRight(node root){
		node x = root->left;
		node y = x->right;
		x->right = root;
		root->left = y;
		root->parent = x;
		if(y != nullptr) y->parent = root;
		return x;
	}

	// Helper function for insertion
	node insertHelp(node root, int data){
		bool f = false; // Flag to check RED-RED conflict

		if(root == nullptr) return makeNode(data);
		else if(data < root->data){
			root->left = insertHelp(root->left, data);
			root->left->parent = root;
			if(root != this->root){
				if(root->colour == 'R' && root->left->colour == 'R')
					f = true;
			}
		} 
		else if(data > root->data){
			root->right = insertHelp(root->right, data);
			root->right->parent = root;
			if(root != this->root){
				if(root->colour == 'R' && root->right->colour == 'R')
					f = true;
			}
		}

		// Perform rotations
		if(ll){
			root = rotateLeft(root);
			root->colour = 'B';
			root->left->colour = 'R';
			ll = false;
		}else if(rr){
			root = rotateRight(root);
			root->colour = 'B';
			root->right->colour = 'R';
			rr = false;
		}else if(rl){
			root->right = rotateRight(root->right);
			root->right->parent = root;
			root = rotateLeft(root);
			root->colour = 'B';
			root->left->colour = 'R';
			rl = false;
		}else if (lr){
			root->left = rotateLeft(root->left);
			root->left->parent = root;
			root = rotateRight(root);
			root->colour = 'B';
			root->right->colour = 'R';
			lr = false;
		}

		// Handle RED-RED conflicts
		if(f){
			if(root->parent->right == root){
				if(root->parent->left == nullptr || root->parent->left->colour == 'B'){
					if(root->left != nullptr && root->left->colour == 'R') rl = true;
					else if(root->right != nullptr && root->right->colour == 'R') ll = true;
				} 
				else{
					root->parent->left->colour = 'B';
					root->colour = 'B';
					if (root->parent != this->root)
						root->parent->colour = 'R';
				}
			} 
			else {
				if(root->parent->right == nullptr || root->parent->right->colour == 'B'){
					if(root->left != nullptr && root->left->colour == 'R') rr = true;
					else if (root->right != nullptr && root->right->colour == 'R') lr = true;
				} else {
					root->parent->right->colour = 'B';
					root->colour = 'B';
					if (root->parent != this->root)
						root->parent->colour = 'R';
				}
			}
			
			f = false;
		}
		return root;
	}

	// Helper function to perform Inorder Traversal
	void inorderTraversalHelper(node root){
		if(root != nullptr){
			inorderTraversalHelper(root->left);
			cout << root->data << " ";
			inorderTraversalHelper(root->right);
		}
	}

	// Helper function to print the tree
	void printTreeHelper(node root, int space){
		if(root != nullptr){
			space += 10;
			printTreeHelper(root->right, space);
			cout << endl;
			for (int i = 10; i < space; i++)
				std::cout << " ";
			cout << root->data << endl;
			printTreeHelper(root->left, space);
		}
	}

public:
	RedBlackTree() : root(nullptr), ll(false), rr(false), lr(false), rl(false) {}

	// Function to insert data into the tree
	void insert(int data) {
		if (root == nullptr) {
			root = makeNode(data);
			root->colour = 'B';
		} else
			root = insertHelp(root, data);
	}

	// Function to perform Inorder Traversal of the tree
	void inorderTraversal() {
		inorderTraversalHelper(root);
	}

	// Function to print the tree
	void printTree() {
		printTreeHelper(root, 0);
	}
};

int main() {
	// Test the RedBlackTree
	RedBlackTree t;
	int arr[] = {1, 4, 6, 3, 5, 7, 8, 2, 9};
	for (int i = 0; i < 9; i++) {
		t.insert(arr[i]);
		cout << endl;
		t.inorderTraversal();
	}
	t.printTree();
	return 0;
}

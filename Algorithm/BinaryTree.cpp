/*
 * It's a level order traversal of a binary tree
 * if the two givn nodes are cousin or not in binary tree, we can check it by this code
 * two nodes are cousin if they are in same depth in a tree but their parents are different */

#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left, *right;
	node(int data){
		this->data = data;
		left = right = NULL;
	}
};
int arr[201];
int k = 1;
int level[201]; 
void LevelOrder(node *root) {
	if(root == NULL) return;
	queue<node*> Q;
	Q.push(root); 
	
	//level[root->data] = 0;
	//while there is at least one discovered node
	while(!Q.empty()) {
		node* current = Q.front();
		Q.pop(); // removing the element at front
		if(current->left != NULL) {Q.push(current->left); arr[current->left->data] = current->data; level[current->left->data] = level[current->data]+1;}
		if(current->right != NULL) {Q.push(current->right); arr[current->right->data] = current->data; level[current->right->data] = level[current->data]+1;}
	}
}
int main(){
	
	struct node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	
	LevelOrder(root);
	
	for(int i = 1; i < k; i++)
		cout<<arr[i]<<' '<<level[i]<<endl;
	//cout<<endl;
}

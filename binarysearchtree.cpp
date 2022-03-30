#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout<< root->key <<" ";
		inorder(root->right);
	}
}

//{struct node*}data type  {insert}function name {(struct node* node, int key)} function paramenter

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

int main()
{
    int n;
	struct node* root = NULL;
 
  while(1)
  {  cin>>n;
    if(n>0){ 
      root=insert(root,n);
    }
    else break;
  }
  cout<<"Tree values are: \n";
	inorder(root);
	return 0;
}


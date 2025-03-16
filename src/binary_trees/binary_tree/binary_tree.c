#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "binary_tree.h"

BinaryTree* BinaryTreeInsert(BinaryTree* root, int data)
{
	static int called = 0;
	if (called == 0)
	{
		srand(time(NULL));
		called = 1;
	}
	if (!root)
	{
		BinaryTree* new = malloc(sizeof(BinaryTree));
		if (!new) exit(1);
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		return new;
	}
	if (!root->left)
	{
		BinaryTree* new = malloc(sizeof(BinaryTree));
		if (!new) exit(1);
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		root->left = new;
	}
	else if (!root->right)
	{
		BinaryTree* new = malloc(sizeof(BinaryTree));
		if (!new) exit(1);
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		root->right = new;
	}
	else
	{
		if (rand() % 2)
		{
			root->left = BinaryTreeInsert(root->left, data);
		}
		else
		{
			root->right = BinaryTreeInsert(root->right, data);
		}
	}
	return root;
}

BinaryTree* BinaryTreeDelete(BinaryTree* root, BinaryTree* tobedeleted);

BinaryTree* BinaryTreeEmpty(BinaryTree* root);

BinaryTree* BinaryTreeFind(BinaryTree* root, int data)
{
	if (!root) return NULL;
	if (data == root->data) return root;
	BinaryTree* result = NULL;
	result = BinaryTreeFind(root->left,data);
	if (result) return result;
	result = BinaryTreeFind(root->right, data);
	return result;
}

BinaryTree* BinaryTreeFindParent(BinaryTree* root, BinaryTree* node);

BinaryTree* BinaryTreeFindLeaf(BinaryTree* root);

int BinaryTreeIsEmpty(BinaryTree* root)
{
	return !root;
}

void BinaryTreePrint(BinaryTree* root)
{
	if (!root)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePrint(root->left);
	printf("%d ", root->data);
	BinaryTreePrint(root->right);
}

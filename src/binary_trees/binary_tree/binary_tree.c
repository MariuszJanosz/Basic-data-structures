#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "binary_tree.h"

static int seed = 0;
static int initialized_seed = 0;

static int rnd(int* n)
{
	return *n = (18225409 * (*n)) % 268435399;
}

BinaryTree* BinaryTreeInsert(BinaryTree* root, int data)
{
	if (initialized_seed == 0)
	{
		seed = time(NULL);
		initialized_seed = 1;
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
		if (rnd(&seed) % 2)
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

BinaryTree* BinaryTreeDelete(BinaryTree* root, BinaryTree* tobedeleted)
{
	if (!tobedeleted) return root;
	if (!root) exit(1);
	BinaryTree* parent = BinaryTreeFindParent(root, tobedeleted);
	if (!parent)
	{
		if (root == tobedeleted)
		{
			BinaryTree* leaf = BinaryTreeFindLeaf(root);
			if (leaf == tobedeleted)
			{
				free(tobedeleted);
				return NULL;
			}
			BinaryTree* lparent = BinaryTreeFindParent(root, leaf);
			if (lparent->left == leaf) lparent->left = NULL;
			else lparent->right = NULL;
			leaf->left = tobedeleted->left;
			leaf->right = tobedeleted->right;
			free(tobedeleted);
			return leaf;
		}
		else exit(1);
	}
	if (!tobedeleted->left && !tobedeleted->right)
	{
		if (parent->left == tobedeleted)
		{
			parent->left = NULL;
			free(tobedeleted);
			return root;
		}
		parent->right = NULL;
		free(tobedeleted);
		return root;
	}
	BinaryTree* leaf = BinaryTreeFindLeaf(root);
	BinaryTree* lparent = BinaryTreeFindParent(root, leaf);
	if (lparent->left == leaf) lparent->left = NULL;
	else lparent->right = NULL;
	if (parent->left == tobedeleted) parent->left = leaf;
	else parent->right = leaf;
	leaf->left = tobedeleted->left;
	leaf->right = tobedeleted->right;
	free(tobedeleted);
	return root;
}

BinaryTree* BinaryTreeEmpty(BinaryTree* root)
{
	while (root)
	{
		root = BinaryTreeDelete(root, BinaryTreeFindLeaf(root));
	}
	return root;
}

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

BinaryTree* BinaryTreeFindParent(BinaryTree* root, BinaryTree* node)
{
	if (!node||!root) return NULL;
	if (node == root) return NULL;
	if (root->left == node || root->right == node) return root;
	BinaryTree* result = NULL;
	if (root->left) result = BinaryTreeFindParent(root->left, node);
	if (result) return result;
	if(root->right) result = BinaryTreeFindParent(root->right, node);
	return result;
}

BinaryTree* BinaryTreeFindLeaf(BinaryTree* root)
{
	if (!root) return NULL;
	if (!root->left && !root->right) return root;
	if (initialized_seed == 0)
	{
		seed = time(NULL);
		initialized_seed = 1;
	}
	if (root->left && root->right)
	{
		if (rnd(&seed))
		{
			return BinaryTreeFindLeaf(root->left);
		}
		else
		{
			return BinaryTreeFindLeaf(root->right);
		}
	}
	else if(root->left)
	{
		return BinaryTreeFindLeaf(root->left);
	}
	return BinaryTreeFindLeaf(root->right);
}

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

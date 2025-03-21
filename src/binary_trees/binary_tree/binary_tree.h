#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct BinaryTree
{
	int data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BinaryTree;

BinaryTree* BinaryTreeInsert(BinaryTree* root, int data);

BinaryTree* BinaryTreeDelete(BinaryTree* root, BinaryTree* tobedeleted);
BinaryTree* BinaryTreeEmpty(BinaryTree* root);

BinaryTree* BinaryTreeFind(BinaryTree* root, int data);
BinaryTree* BinaryTreeFindParent(BinaryTree* root, BinaryTree* node);
BinaryTree* BinaryTreeFindLeaf(BinaryTree* root);

int BinaryTreeIsEmpty(BinaryTree* root);

void BinaryTreePrint(BinaryTree* root);
#endif

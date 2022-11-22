#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(node) !node
#define MAX_TERMS 100 // number of nodes
#define _CRT_SECURE_NO_WARNINGS


typedef struct Node* NodePointer;  //Declare node type and pointer type
typedef struct Node
{
	NodePointer leftChild;
	int key;
	NodePointer rightChild;
} Node;
void inorder(NodePointer); // inorder traversal
void preorder(NodePointer); // preorder traversal
void insert(NodePointer*, int); // insert node function
NodePointer modifiedSearch(NodePointer, int); 
void free_tree(NodePointer);

int main()
{
	FILE* fp = fopen("input.txt", "r");
	int i, n, A[MAX_TERMS];
	NodePointer root = NULL;
	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(fp, "%d", &A[i]); // Read the number and data with a file pointer and save it in A
	for (i = 0; i < n; i++)
		insert(&root, A[i]); // Insert into the tree
	printf("inorder() -> ");
	inorder(root); // inorder traversal result
	printf("\npreorder() -> ");
	preorder(root); // preorder traversal result
	free_tree(root); // Recall a function that releases dynamic memory used
	fclose(fp);
	return 0;
}
void inorder(NodePointer root)
{
	if (!root)
		return;
	inorder(root->leftChild);
	printf("%d ", root->key); // inorder
	inorder(root->rightChild);
}
void preorder(NodePointer root)
{
	if (!root)
		return;
	printf("%d ", root->key); // preorder
	preorder(root->leftChild);
	preorder(root->rightChild);
}
void insert(NodePointer* root, int key)
{
	NodePointer newnode, temp = modifiedSearch(*root, key);
	// newnode is Pointer to point to a node to be newly dynamically assigned,
  
		if (temp || !(*root)) // If the node is not in the tree,  New Insert must be turned
		{
			newnode = (NodePointer)malloc(sizeof(Node)); 
			
				if (IS_FULL(newnode))
				{
					fprintf(stderr, "The memory if full");
					exit(1);
				}
			newnode->key = key;
			newnode->leftChild = newnode->rightChild = NULL; // newnode 
			

void free_tree(NodePointer root)
{
	
	if (!root)
		return;
	free_tree(root->leftChild);
	free_tree(root->rightChild);
	free(root);
}
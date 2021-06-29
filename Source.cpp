// Iterative Preorder Traversal (Non-recursive)
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <time.h>

TreeNode* createTree(int num);
void preorder_recursive(TreeNode* root);
void preorder_non_recursive(TreeNode* root);

TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n)
{
	// Base case for recursion
	if (i < n)
	{

		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->data = arr[i];
		temp->left = NULL;
		temp->right = NULL;
		root = temp;

		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);		// insert left child
																			//arr   = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
																			//index = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);		// insert right child
	}
	return root;
}

int main()
{
	int num;
	printf("Enter number of nodes : ");
	scanf("%d", &num);
	TreeNode *root = createTree(num);

	printf("Recursive Preorder : \n");
	preorder_recursive(root);

	printf("\n\nNon-Recursive Preorder : \n");
	preorder_non_recursive(root);
	_getch();
}

TreeNode* createTree(int num)
{
	if (num == 0)
		return NULL;

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));

	int* arr = (int*)malloc(num * sizeof(int));
	for (int i = 1; i <= num; i++)
		arr[i - 1] = i;
	// arr = 1,2,3,4...10
	root = insertLevelOrder(arr, root, 0, num);

	return root;
}

void preorder_recursive(TreeNode* root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%d \t", root->data);
		preorder_recursive(root->left);
		preorder_recursive(root->right);
	}
}

void preorder_non_recursive(TreeNode* root)
{
	stack *s = createStack();
	TreeNode *curr = root;
	TreeNode *tr;

	if (curr == NULL)
		return;

	while (1)
	{
		while (curr)
		{
			printf("%d \t", curr->data);
			push(s, curr);
			curr = curr->left;
		}

		if (isEmpty(s))
			break;

		tr = peek(s);
		pop(s);

		curr = tr->right;
	}
	disposeStack(s);
}
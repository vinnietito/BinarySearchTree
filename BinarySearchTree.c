			//VINCENT KIMANTHI NJUGUNA  SCT221-0690/2022
			//GERISHON KIHATO GIKORE    SCT221-0219/2022


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int arr[], int start, int end, int value)
{
	int i;
    for (i = start; i <= end; i++) 
	{
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inOrder[], int postOrder[], int inStart, int inEnd, int* postIndex)
{
    if (inStart > inEnd)
        return NULL;

    struct Node* node = newNode(postOrder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd)
        return node;

    int inIndex = findIndex(inOrder, inStart, inEnd, node->data);

    node->right = buildTree(inOrder, postOrder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inOrder, postOrder, inStart, inIndex - 1, postIndex);

    return node;
}

void breadthFirstSearch(struct Node* root)
{
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
	{
        struct Node* tempNode = queue[++front];
        printf("%d ", tempNode->data);

        if (tempNode->left != NULL)
            queue[++rear] = tempNode->left;
        if (tempNode->right != NULL)
            queue[++rear] = tempNode->right;
    }
}

struct Node* bst_construct(int inOrder[], int postOrder[], int size)
{
    int postIndex = size - 1;
    return buildTree(inOrder, postOrder, 0, size - 1, &postIndex);
}

int main()
{
    int postOrder[] = {5, 15, 10, 25, 45, 30, 20};
    int inOrder[] = {5, 10, 15, 20, 25, 30, 45};
    int size = sizeof(inOrder) / sizeof(inOrder[0]);

    struct Node* root = bst_construct(inOrder, postOrder, size);
    
    printf("Breadth First Search Traversal:\n");
    breadthFirstSearch(root);

    return 0;
}


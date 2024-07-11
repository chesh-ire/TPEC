#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *left, *right;
};
struct node *lca (struct node *root, int n1, int n2)
{
while (root != NULL)
{


if (root->data > n1 && root->data > n2)
root = root->left;
else if (root->data < n1 && root->data < n2)
root = root->right;
else
break;
}
return root;
}
struct node *newNode (int data)
{
struct node *node = (struct node *) malloc (sizeof (struct node));
node->data = data;
node->left = node->right = NULL;
return (node);
}
int main ()
{
struct node *root = newNode (20);
root->left = newNode (8);
root->right = newNode (22);
root->left->left = newNode (4);
root->left->right = newNode (12);
10
root->left->right->left = newNode (10);
root->left->right->right = newNode (14);
int n1 = 10, n2 = 14;
struct node *t = lca (root, n1, n2);
printf ("LCA of %d and %d is %d \n", n1, n2, t->data);
n1 = 14, n2 = 8;
t = lca (root, n1, n2);
printf ("LCA of %d and %d is %d \n", n1, n2, t->data);
n1 = 10, n2 = 22;
t = lca (root, n1, n2);
printf ("LCA of %d and %d is %d \n", n1, n2, t->data);
getchar ();
return 0;
}
OUTPUT : LCA of 10 and 14 is 12
LCA of 14 and 8 is 8
LCA of 10 and 22 is 20
2. Height of a Binary Tree
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
int height (struct node *node)
{
if (node == NULL)
return 0;
else
{
int leftHeight = height (node->left);
int rightHeight = height (node->right);
if (leftHeight > rightHeight)
return (leftHeight + 1);
else
return (rightHeight + 1);
}
}
struct node *newNode (int data)
{
struct node *node = (struct node *) malloc (sizeof (struct node));
node->data = data;
node->left = NULL;
node->right = NULL;
11
return (node);
}
int main ()
{
struct node *root = newNode (10);
root->left = newNode (20);
root->right = newNode (30);
root->left->left = newNode (40);
root->left->right = newNode (50);
printf ("Height of tree is %d", height (root));
return 0;
}
OUTPUT : Height of tree is 3
#include <stdio.h>
#include <stdlib.h>
typedef int Data;

struct Node
{
    Data val;
    struct Node * left;
    struct Node * right;
};

struct Node * tree_add(struct Node * tree, Data x)
{
    if(tree == NULL)
    {
        struct Node * tree = (struct Node *)malloc(sizeof(struct Node));
        tree->val = x;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    if(x < tree->val)
    {
        tree->left = tree_add(tree->left, x);
        return tree;
    }
    if(x > tree->val)
    {
        tree->right = tree_add(tree->right, x);
        return tree;
    }
    return tree;
}

void tree_print(struct Node * tree)
{
    if(tree != NULL)
    {
        tree_print(tree->left);
        printf("%d ", (int)tree->val);
        tree_print(tree->right);
    }
}

void tree_destroy(struct Node * tree)
{
    if(tree != NULL)
    {
        tree_destroy(tree->left);

        tree_destroy(tree->right);
        free(tree);
    }
}
int main()
{
    struct Node * tree = NULL;
    int i = 0;
    Data n = 0;

    scanf("%d", &n);
    while(n != 0)
    {
        tree = tree_add(tree, n);
        scanf("%d", &n);

    }

    tree_print(tree);
    tree_destroy(tree);
    return 0;
}

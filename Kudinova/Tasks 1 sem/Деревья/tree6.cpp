#include <stdio.h>
#include <stdlib.h>
typedef int Data;

struct Node {

    int c;
    Data val;
    struct Node * left;
    struct Node * right;
};

struct Node * tree_add(struct Node * tree, Data x);
void tree_print(struct Node * tree);
void list(struct Node * tree);
void tree_destroy(struct Node * tree);

int main() {

    struct Node * tree = NULL;
    Data n = 0;

    scanf("%d", &n);

    while(n != 0) {

        tree = tree_add(tree, n);

        scanf("%d", &n);
    }

    tree_print(tree);

    tree_destroy(tree);

    return 0;
}

struct Node * tree_add(struct Node * tree, Data x) {

    if(tree == NULL) {

        struct Node * tree = (struct Node *)malloc(sizeof(struct Node));

        tree->val = x;
        tree->left = NULL;
        tree->right = NULL;
        tree->c = 1;

        return tree;
    }

    if(x < tree->val) {

        tree->left = tree_add(tree->left, x);

        return tree;
    }

    if(x > tree->val) {

        tree->right = tree_add(tree->right, x);

        return tree;
    }

    if (x == tree->val) {

        tree++->c;

        return tree;
    }

    return tree;
}

void tree_print(struct Node * tree) {

    if(tree != NULL) {

        tree_print(tree->left);

        printf("%d %d\n", (int)tree->val, tree->c);

        tree_print(tree->right);
    }
}

void list(struct Node * tree) {

    if(tree != NULL) {

        if(tree->left != NULL)
            list(tree->left);

        if((tree->left == NULL) && (tree->right == NULL))
            printf("%d ", (int)tree->val);

        if(tree->right != NULL)
            list(tree->right);
    }
}

void tree_destroy(struct Node * tree) {

    if(tree != NULL) {

        tree_destroy(tree->left);

        tree_destroy(tree->right);

        free(tree);
    }
}

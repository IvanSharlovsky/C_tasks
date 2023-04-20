#include <stdio.h>
#include <stdlib.h>
typedef int Data;

struct Node {

    int l;
    Data val;
    struct Node * left;
    struct Node * right;
};

struct Node * tree_add(struct Node * tree, Data x, int lev) {

    if(tree == NULL) {

        struct Node * tree = (struct Node *)malloc(sizeof(struct Node));

        tree->val = x;
        tree->left = NULL;
        tree->right = NULL;
        tree->l = lev + 1;

        return tree;
    }

    if(x < tree->val) {

        tree->left = tree_add(tree->left, x, tree->l);

        return tree;
    }

    if(x > tree->val) {

        tree->right = tree_add(tree->right, x, tree->l);

        return tree;
    }

    return tree;
}

void lmax(struct Node * tree);
void tree_print(struct Node * tree);
void tree_destroy(struct Node * tree);
int Maximum = 0;

int main() {

    struct Node * tree = NULL;
    Data n = 0;

    scanf("%d", &n);

    while(n != 0) {

        tree = tree_add(tree, n, 0);
        scanf("%d", &n);

    }

    lmax(tree);

    printf("%d", Maximum);

    tree_destroy(tree);

    return 0;
}

void tree_print(struct Node * tree) {

    if(tree != NULL) {

        tree_print(tree->left);

        printf("%d ", (int)tree->val);

        tree_print(tree->right);
    }
}

void tree_destroy(struct Node * tree) {

    if(tree != NULL) {

        tree_destroy(tree->left);

        tree_destroy(tree->right);

        free(tree);
    }
}

void lmax(struct Node * tree) {



    if(tree != NULL) {

        lmax(tree->left);

        if(Maximum < tree->l) {
            Maximum = tree->l;
        }

        lmax(tree->right);
    }
}

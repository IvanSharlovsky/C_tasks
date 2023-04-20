#include <stdio.h>
#include <stdlib.h>

struct Elem *tree;// глобальная переменная, хранящая указатель на начало дерева

struct Elem {
    int val;// значение, которое хранится в элементе ((!) может быть указателем на строку, например)
    struct Elem * lv, * pr; // указатели на левого и правого потомков
};

struct Elem *add_elem(struct Elem * tree, int x);// рекурсивное добавление элемента
struct Elem *find_min(struct Elem *tree);
struct Elem *find_elem(struct Elem *tree, int k);// нахождение элемента
struct Elem *parent_find_elem(struct Elem *tree, struct Elem *find_elem);

void move_elem(struct Elem *tree, struct Elem *current, struct Elem *chenge_to);// передвижение элемента
void Erase(struct Elem *tree, struct Elem *Find);// стирание элемента из дерева
void print_tree_dfs(struct Elem *tree);// рекурсивный обход дерева в глубину
void tree_destroy(struct Elem * tree);// очищение памяти

int main() {
    tree = NULL;
    int x = 0;
    printf("Write elements of tree (press 0 to finish):\n");
    scanf("%d", &x);
    while (x != 0) {
        tree = add_elem(tree, x);
        scanf("%d", &x);
    }
    printf("\nTree:");
    print_tree_dfs(tree);
    printf("\nElement you want to delete: ");
    int k = 0;
    scanf("%d", &k);
    printf("\n");
    struct Elem *Find = find_elem(tree, k);
    Erase(tree, Find);
    print_tree_dfs(tree);
    tree_destroy(tree);

    return 0;
}

struct Elem * add_elem(struct Elem * tree, int x) {
    if(tree == NULL) {
        struct Elem * tree = (struct Elem *)malloc(sizeof(struct Elem));
        tree->val = x;
        tree->lv = NULL;
        tree->pr = NULL;
        return tree;
    }
    if(x < tree->val) {
        tree->lv = add_elem(tree->lv, x);
        return tree;
    }
    if(x > tree->val) {
        tree->pr = add_elem(tree->pr, x);
        return tree;
    }
    return tree;
}

struct Elem *find_min(struct Elem *tree) {// нахождение минимального элемента левого поддерева
    if (tree->lv == NULL) {
        return tree;
    }
    return find_min(tree->lv);
}

struct Elem* find_elem(struct Elem *tree, int k) {// рекурсивное нахождение элемента
    if ((tree == NULL) || (k == tree->val)) {
        return tree;
    }
    if (k < tree->val) {
        return find_elem(tree->lv, k);
    }
    else {
        return find_elem(tree->pr, k);
    }
}

struct Elem *parent_find_elem(struct Elem *tree, struct Elem *find_elem) {
    if ((tree->pr == find_elem) || ((tree->lv) == find_elem)) {
        return tree;
    }
    else {
        if (tree->val < find_elem->val) {
            parent_find_elem(tree->pr, find_elem);
        }
        else {
            parent_find_elem(tree->lv, find_elem);
        }
    }
}

void move_elem(struct Elem *tree, struct Elem *current, struct Elem *chenge_to) {
    struct Elem *current_parent = parent_find_elem(tree, current);
    struct Elem *chenge_to_parent = parent_find_elem(tree, chenge_to);

    if ( current == current_parent->lv) {
        current_parent->lv = chenge_to;
    }
    else {
        current_parent->pr = chenge_to;
    }
    if (chenge_to != NULL) {
        chenge_to_parent = current_parent;
    }
}

void Erase(struct Elem *tree, struct Elem *z) {
    if (z->lv == NULL) {
        move_elem(tree, z, z->pr);
    }
    else if (z->pr == NULL) {
        move_elem(tree, z, z->lv);
    }
    else {
        struct Elem *y = find_min(z->pr);
        struct Elem *y_parent = parent_find_elem(tree, y);
        struct Elem *y_lv = parent_find_elem(tree, y->lv);
        struct Elem *y_pr = parent_find_elem(tree, y->pr);
        if (y_parent != z) {
            move_elem(tree,y, y->pr);
            y->pr = z->pr;
            y_pr = y;
        }
        move_elem(tree, z, y);
        y->lv = z->lv;
        y_lv = y;
    }

}

void print_tree_dfs(struct Elem *tree) {// рекурсивный обход дерева в глубину
    if (tree == NULL){
		return;
	}

	print_tree_dfs(tree->lv); // распечатать левое поддерево все целиком
	printf("%d ", (int)tree->val); // распечатать значение текущего элемента
	print_tree_dfs(tree->pr); // распечатать правое поддерево все целиком

	return;

void tree_destroy(struct Elem * tree) {// очищение памяти
    if(tree != NULL) {
        tree_destroy(tree->lv);

        tree_destroy(tree->pr);
        free(tree);
    }
}

#include <stdio.h>
#include <stdlib.h>

struct Elem *tree;// глобальная переменная, хранящая указатель на начало дерева

struct Elem {
    int val;// значение, которое хранится в элементе ((!) может быть указателем на строку, например)
    struct Elem * lv, * pr, * parent; // указатели на левого и правого потомков и на родителя
};

struct Elem *add_elem(struct Elem *tree, int x, struct Elem *parent);// рекурсивное добавление элемента
struct Elem *find_elem(struct Elem *tree, int k);// нахождение элемента
struct Elem *find_min(struct Elem *tree);// нахождение минимального элемента левого поддерева

void move_elem(struct Elem *tree, struct Elem *current, struct Elem *change_to);// передвижение элемента
void Erase(struct Elem *tree, struct Elem *del_elem);// стирание элемента из дерева
void print_tree_dfs(struct Elem *tree);// рекурсивный обход дерева в глубину
void tree_destroy(struct Elem * tree);// очищение памяти


int main() {
    tree = NULL;
    int x = 0;
    printf("Write elements of tree (press 0 to finish):\n");
    scanf("%d", &x);
    int is_root = x;
    while (x != 0) {
        tree = add_elem(tree, x, NULL);
        scanf("%d", &x);
    }
    printf("\nTree:");
    print_tree_dfs(tree);
    printf("\nElement you want to delete: ");
    int delete_elem;
    scanf("%d", &delete_elem);
    if (is_root == delete_elem) {
        print_tree_dfs(tree->lv);
        print_tree_dfs(tree->pr);
    }
    else {
        struct Elem *del_Elem_struct = find_elem(tree, delete_elem);
        Erase(tree, del_Elem_struct);
        printf("\n");
        print_tree_dfs(tree);
    }
    return 0;
}


struct Elem *add_elem(struct Elem *tree, int x, struct Elem *parent) {// рекурсивное добавление элемента
    // если дерево пусто
    if (tree == NULL) {
        struct Elem *tree = (struct Elem *)malloc(sizeof(struct Elem));// выделить под элемент память
        tree->val = x;// заполнить его поля
        tree->lv = NULL;
        tree->pr = NULL;

        tree->parent = parent;
        return tree;
    }

    if (x < tree->val) {
        tree->lv = add_elem(tree->lv, x, tree);
        return tree;
    }

    if (x > tree->val) {
        tree->pr = add_elem(tree->pr, x, tree);
        return tree;
    }
    return tree;
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

struct Elem *find_min(struct Elem *tree) {// нахождение минимального элемента правого поддерева
    if (tree->lv == NULL) {
        return tree;
    }

    find_min(tree->lv);
}

void move_elem(struct Elem *tree, struct Elem *current, struct Elem *change_to) {
    if (current->parent->lv == current) {
        current->parent->lv = change_to;
    }
    else {
        current->parent->pr = change_to;
    }
    if ( change_to != NULL) {
        change_to->parent = current->parent;
    }

    return;
}


void Erase(struct Elem *tree, struct Elem *del_elem) {
    if (del_elem->lv == NULL)  {
        move_elem(tree, del_elem, del_elem->pr);
    }

    else if (del_elem->pr == NULL)  {
        move_elem(tree, del_elem, del_elem->lv);
    }

    else {
        struct Elem *Minimum = find_min(del_elem->pr);
        if (Minimum->parent != del_elem) {
            move_elem(tree, Minimum, Minimum->pr);
            Minimum->pr = del_elem->pr;
            Minimum->parent->pr = Minimum;
        }
        move_elem(tree, del_elem, Minimum);
        Minimum->lv = del_elem->lv;
        Minimum->parent->lv = Minimum;
    }

    return;
}

void print_tree_dfs(struct Elem *tree) {// рекурсивный обход дерева в глубину
    if (tree == NULL){
		return;
	}

	print_tree_dfs(tree->lv); // распечатать левое поддерево все целиком
	printf("%d ", (int)tree->val); // распечатать значение текущего элемента
	print_tree_dfs(tree->pr); // распечатать правое поддерево все целиком

	return;
}

void tree_destroy(struct Elem * tree) {// очищение памяти
    if(tree != NULL) {
        tree_destroy(tree->lv);

        tree_destroy(tree->pr);
        free(tree);
    }

    return;
}

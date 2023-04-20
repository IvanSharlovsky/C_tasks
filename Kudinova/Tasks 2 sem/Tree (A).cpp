#include <stdio.h>
#include <stdlib.h>

struct Elem *tree;// ���������� ����������, �������� ��������� �� ������ ������

struct Elem {
    int val;// ��������, ������� �������� � �������� ((!) ����� ���� ���������� �� ������, ��������)
    struct Elem * lv, * pr, * parent; // ��������� �� ������ � ������� �������� � �� ��������
};

struct Elem *add_elem(struct Elem *tree, int x, struct Elem *parent);// ����������� ���������� ��������
struct Elem *find_elem(struct Elem *tree, int k);// ���������� ��������
struct Elem *find_min(struct Elem *tree);// ���������� ������������ �������� ������ ���������

void move_elem(struct Elem *tree, struct Elem *current, struct Elem *change_to);// ������������ ��������
void Erase(struct Elem *tree, struct Elem *del_elem);// �������� �������� �� ������
void print_tree_dfs(struct Elem *tree);// ����������� ����� ������ � �������
void tree_destroy(struct Elem * tree);// �������� ������


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


struct Elem *add_elem(struct Elem *tree, int x, struct Elem *parent) {// ����������� ���������� ��������
    // ���� ������ �����
    if (tree == NULL) {
        struct Elem *tree = (struct Elem *)malloc(sizeof(struct Elem));// �������� ��� ������� ������
        tree->val = x;// ��������� ��� ����
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


struct Elem* find_elem(struct Elem *tree, int k) {// ����������� ���������� ��������
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

struct Elem *find_min(struct Elem *tree) {// ���������� ������������ �������� ������� ���������
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

void print_tree_dfs(struct Elem *tree) {// ����������� ����� ������ � �������
    if (tree == NULL){
		return;
	}

	print_tree_dfs(tree->lv); // ����������� ����� ��������� ��� �������
	printf("%d ", (int)tree->val); // ����������� �������� �������� ��������
	print_tree_dfs(tree->pr); // ����������� ������ ��������� ��� �������

	return;
}

void tree_destroy(struct Elem * tree) {// �������� ������
    if(tree != NULL) {
        tree_destroy(tree->lv);

        tree_destroy(tree->pr);
        free(tree);
    }

    return;
}

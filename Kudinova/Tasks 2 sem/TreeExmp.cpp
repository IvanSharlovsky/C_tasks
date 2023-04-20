#include<stdio.h>
#include<stdlib.h>

struct Elem * root; // ���������� ����������, �������� ��������� �� ������ ������

struct Elem {
	int val; // ��������, ������� �������� � �������� ((!) ����� ���� ���������� �� ������, ��������)
	struct Elem * lv, * pr; // ��������� �� ������ � ������� ��������
};

void print_tree_dfs(struct Elem * p){ // ����������� ����� ������ � �������
	if (p == NULL){
		return;
	}

	print_tree_dfs(p->lv); // ����������� ����� ��������� ��� �������
	printf("%d ", p->val); // ����������� �������� �������� ��������
	print_tree_dfs(p->pr); // ����������� ������ ��������� ��� �������

	return;
}
void print_tree_bfs(struct Elem * p); // ����� ������ � ������, ��. ����

void add_elem(int x){ // ��� ������������� ����������, �� ������ � ����������� ������� ����, �� �������� � print_tree_dfs
	struct Elem * p = (struct Elem *)malloc(sizeof(struct Elem)); // �������� ��� ������� ������
	p->val = x; // ��������� ��� ����
	p->lv = NULL;
	p->pr = NULL;

	// ���� ��� ���� ���������� ����� � ������
	// ���� ������ �����
	if (root == NULL){
		root = p;
		return;
	}

	// ���� ������ �� �����, ���� ��� ���� ������������ ������� (��������� ������ ��� ����)
	struct Elem * q = root;
	while(1){
		if (x < q->val){ // ���� x ������, ��� �������� �������� ��������, �� ��������� � ����� ���������
			if (q->lv != NULL){
				q = q->lv; // ��������� � ������ ������� �������� ��������
			}
			else{
				q->lv = p; // ��������� ����� �������, ���� ������ ������� �� ����
				break;
			}
		}
		else{ // ���� x ������ ��� �����, �� - � ������ ���������
			if (q->pr != NULL){
				q = q->pr; // ������� � ������� �������
			}
			else{
				q->pr = p; // ������� � �������� ������� �������
				break;
			}
		}
	}

	return;
}

 // ��� ������������� ����������, �� ������ � ����������� ������ ����, �� �������� � print_tree_dfs
struct Elem * find_elem(int x){ // ������ �� ������ � ���� ������ ���������� add_elem

	if (root == NULL){
		printf("Empty tree");
		return NULL;
	}

	struct Elem * p = root; // p - ����� ���������� �� ������� ������� �� ������ ��������
	while(1){
		if(x == p->val) // ���� �������� ������� - �� ����� ������ �������
			return p;
		if(x < p->val){ // ���� x ������, ���� ������ � ����� ���������
			if(p->lv != NULL)
				p = p->lv; // ���� ����� ��������� ���� - ��������� ������ �������
			else
				return NULL; // ���� ������ ��������� ��� - ������ �� ����� ������ �������
		}
		if(x > p->val){ // ���� x ������, ���� ������ � ������ ���������
			if(p->pr != NULL)
				p = p->pr;
			else
				return NULL;
		}
	}

	return NULL;
}

// ������
int main(){
	root = NULL;
	add_elem(7); // ������� � �������� �������
	add_elem(5); // ������ ��� ����� ������� 7
	add_elem(8); // ������ ��� ������ ������� 7
	add_elem(6); // ������ ��� ������ ������� 5
	add_elem(3); // ������ ��� ����� ������� 5
	add_elem(1); // ������ ��� ����� ������� 3
	add_elem(4); // ������ ��� ������ ������� 3
	add_elem(9); // ������ ��� ������ ������� 8
	printf("Print as Depth-first search (DFS):\n"); // see https://en.wikipedia.org/wiki/Depth-first_search
	print_tree_dfs(root); // ����������� ��� ������ �������
	printf("\n");
	printf("Print subtree as (DFS):\n");
	print_tree_dfs(find_elem(3)); // ����������� ��������� � ������ � ��������, ������� �������� = 3
	printf("\n");
	printf("Print as breadth-first search (BFS):"); // see https://en.wikipedia.org/wiki/Breadth-first_search
	print_tree_bfs(root);
	// ������ � ����� ������ �������� ���:
	// .......7.......
	// ...5.......8...
	// .3...6.......9.
	// 1.4............
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// ������ ����� ����� ������ � ������ - ������� ��� �������� ������� ������� �(�������� ��) ������
// ��� ��� ���������� ����������� ������� ��� �������� ��� �� ������������ ������,
// ������� ����� �������������, ��������, ����� ������
// ��� ����� ����������� �������
void add_to_queue(struct Elem * p); // �������� ������� � ������� (����., �������� � ����� ������)
struct Elem * take_from_queue(); // ������ ������� �� ������� (����., ������� �� ������ ������)
int queue_not_empty(); // ���������, ��� ������� �� ����� (����., ��������� �� ������ ������ != NULL)
// ������� ���� ������� ��� ������� ���� � https://github.com/mkudinova/2021-2022-MIPT/blob/main/2021-12-03-list.c ��� https://github.com/mkudinova/C/blob/main/Nov/20

void print_tree_bfs(struct Elem * p){
	struct Elem * q; // ��������� ����������, �� ������ �������� ����� ����� ������� ����� ��������������� ��������

	add_to_queue(p); // �������� �������
	while(queue_not_empty()){ // ���� � ��� ���� ��������
		q = take_from_queue(); // ����� ������� �� �������
		printf("%d ", q->val); // ���������� ���, ��������, ����������� ��� ��������
		add_to_queue(q->lv); // ������� � ������� ��� ��������
		add_to_queue(q->pr);
		//(��� ����� ����������� � �������, ��� ������ add_to_queue(), ���� ���������, ��� ����� ������� ������ ����)
	}
	return;
}

// � ����� �� ������� ��� ������� ����� ������ (��� ��������� ��������)
#define max_N_elem 100
struct Elem * queue[max_N_elem]; // ������� ������, ������� ������ ������ ������
int i_beg = 0, i_end = 0, i_layer = 0; // i_beg - ������ �������, i_end - ����� �������,
// i_layer - ������ ������� �� ���� ������ (����� ��� ������������� �� ����� �������, � �� ������� ������)
void add_to_queue(struct Elem * p){ // �������� ��������� �� ������� ������ � ������
	if(p == NULL) // ������ �� ������, ���� �� ����� ���� ������� ���
		return;
	queue[i_end] = p; // �������� � �����
	i_end++; // ����������� ������, ������� ��������� �� ����� ������� (��������� ����������� ������ ������� + 1)
	return;
}
struct Elem * take_from_queue(){
	if(i_beg == i_layer){ // ��� ������, ����� ������� �� ������� ������
		printf("\n"); // ������ ��� ������ ��������� ������� ������, �������� "\n", ������� ����� ���������� ������
		i_layer = i_end;
	}
	struct Elem * q = queue[i_beg]; // ��������� ��������, ����� ����� ������� return
	i_beg++; // ��������� ������ ������ ������� (i_beg = ������ ������� �� �������������� ���������)
	return q;
}
int queue_not_empty(){
	if(i_beg != i_end)
		return 1;
	else
		return 0;
}




/////////////////////////////////////////////////////////////////////////////
// ������ �������� ��������� �� ���� ���������
#include <stdio.h>
#include <stdlib.h>

struct Elem{
	int val; // ��������, ������� �������� � �������� ((!) ����� ���� ���������� �� ������, ��������)
	struct Elem * lv, * pr; // ��������� �� ������ � ������� ��������
};

int main(){
    struct Elem * p = (struct Elem *)malloc(sizeof(struct Elem)); // �������� ������ ��� ���������
    p->lv = p; // ��������� ����, �� ����� ���
	// ���� ����� ��� "��������� �� ���������"

    struct Elem ** p_field; // ������� ����������, ������� ����� ����� ���������� �� ��� ����
	// �.�., ��������� �� ��������� �� ���������

    p_field = &( p->lv ); // ��������� ���� ���������� ����� ���� ������ ���������
    printf("%p", *p_field); // ���������� � ���� ����� ���������

    return 0;
}
// ��� ���������, ��� ���� ����� �� � ����� �������� ������ ������
// int a;
// a = 5;
// int * b = &a;
// printf("%d", *b);


/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

// ������ ������� ��������� ���������, ��� ����� ������ ����������
struct Info{
    struct Elem ** p_field; // ��������� �� ���� ������ ������������ ���������, �������� ��������� �� ��������� �������
    struct Elem * del_el; // ��������� �������
    struct Elem * most_right; // ������������ ������� ������ ���������
    struct Elem ** parent_most_right; // ��������� �� ���� ������ �������� ������������� ��������
};

// ������ �������� ������� ��� ������ ����������� ����������
int find_elem(struct Info * y){
// ���������� int - ��� ������, 0 - �����, ��������� �������� - ��������� ������
// struct Elem * root - ����� � �� ������
// struct Info * y - �������� � ������� ��������� �� ���������, ������� ���������� ���������
// ����� �� �������� �� int scanf("%d", &n);

	y->p_field = NULL; //&( p->lv ); // ������ � ���� p_field ����� ���� lv ������ ���������, ������������� �� ������ p

	return -1;
}
// ������ ������ ���� �������, ��������, �� main
int main(){
	struct Info A;
	int res = find_elem( &A );
	switch (res){
		case 0: printf("Success\n"); break;
		case 1: printf("Error in func ____ \n"); break;
		default: printf("Unknown error\n");
	}
	return 0;
}

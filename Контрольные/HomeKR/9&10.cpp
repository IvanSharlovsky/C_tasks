#include <stdio.h>

struct A{
    int a;
    char c;
};

void func2(struct A *x);

int main() {
    struct A x;

    scanf("%d", &x.a);

    func2(&x);

    printf("%d", x.a);
}

void func2(struct A *x) {
    x->a += 1;
}

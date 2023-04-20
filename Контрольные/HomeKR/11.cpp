#include <stdio.h>

struct A {
    int a;
    char c;
    double d;
};

int main() {
    struct A a, b, c, d, e;
    struct A arr[5] = {a, b, c, d, e};

    for(int i = 0; i < 5; i++) {
        arr[i].a = i;
    }

    for(int j = 0; j < 5; j++) {
        printf("%d ", arr[j].a);
        printf("%u ", sizeof(arr[j].a));

        int * p = &arr[j].a;
        printf("%p\n", p);
    }
}

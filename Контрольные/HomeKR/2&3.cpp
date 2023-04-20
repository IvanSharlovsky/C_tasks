#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point{
    double x, y;
};

struct Quad{
    struct Point left_bottom, left_top, right_bottom, right_top;
};

double lenght( struct Point a, struct Point b);
double perim(struct Quad x);

int main() {
    struct Quad a;

    a.left_bottom.x = -5,2, a.left_bottom.y = 0,8, a.left_top.x = 1, a.left_top.y = 10;
    a.right_bottom.x = 4, a.right_bottom.y = 5,2, a.right_top.x = 6, a.right_top.y = 15;

    printf("%f", perim(a));
}

double lenght( struct Point a, struct Point b) {
    double p = sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y-b.y)*(a.y-b.y)));

    return p;

}

double perim(struct Quad x) {
    double P = lenght(x.right_bottom, x.right_top) + lenght(x.right_top, x.left_top)
    + lenght (x.left_top, x.left_bottom ) + lenght(x.left_bottom,x.right_bottom);

    return P;
}

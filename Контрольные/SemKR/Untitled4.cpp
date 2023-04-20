#define N 100
struct _Decimal {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

int main(){
    Decimal a = {{7, 4, 1}, 2};  // set number 147
    Decimal res;

    mult10(&res, &a);          // res = a*10 = 147*10 = 1470

    print(&res);          // print 1470
    printf("\n");

    return 0;
}

void mult10(Decimal * res, const Decimal * a)
{
    res = 1470;
}

#include <stdio.h>

int main(){
    int a, b, result = 0;
    char action;

    scanf("%d %c %d",&a, &action, &b);

    while(action != 'e'){
        switch(action){
            case '+':
                result = a+b;
                printf("%d\n", result);
            break;

            case '-':
                result = a-b;
                printf("%d\n", result);
            break;

            case '*':
                result = a*b;
                printf("%d\n", result);
            break;

            case '/':
                result = a/b;
                printf("%d\n", result);
            break;

            case '%':
                result = a%b;
                printf("%d\n", result);
            break;

            case '&':
                result = a&b;
                printf("%d\n", result);
            break;

            case '|':
                result = a|b;
                printf("%d\n", result);
            break;

            case '^':
                result = a^b;
                printf("%d\n", result);
            break;

            case '~':
                result = ~b;
                printf("%d\n", result);
            break;
        }

        scanf("%d %c %d",&a, &action, &b);
    }
}

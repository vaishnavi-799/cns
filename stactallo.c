
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    printf("\nStack Allocation:\n");
    printf("Variable a = %d, Address = %p\n", a, (void *)&a);
    printf("Variable b = %d, Address = %p\n", b, (void *)&b);

    return 0;
}

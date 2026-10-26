
#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[20];
    int value;
};

int main() {
    struct Symbol s[20];
    int n, i;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter symbol name: ");
        scanf("%19s", s[i].name);

        printf("Enter data type: ");
        scanf("%19s", s[i].type);

        printf("Enter value: ");
        scanf("%d", &s[i].value);
    }

    printf("\n--- SYMBOL TABLE ---\n");
    printf("Name\tType\tValue\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%s\t%d\n",
               s[i].name, s[i].type, s[i].value);
    }

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char t1[20], t2[20];

    printf("Enter type of first variable (int/float/char): ");
    scanf("%19s", t1);

    printf("Enter type of second variable (int/float/char): ");
    scanf("%19s", t2);

    if (strcmp(t1, t2) == 0) {
        printf("Type checking successful.\n");
        printf("Both types are compatible.\n");
    }
    else {
        printf("Type mismatch error.\n");
    }

    return 0;
}

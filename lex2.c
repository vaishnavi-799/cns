#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char s[200];
    int i = 0;
    printf("Enter a statement: ");
    fgets(s, sizeof(s), stdin);
    while (s[i] != '\0') {
        if (isspace(s[i])) {
            i++;
        }
        else if (isalpha(s[i]) || s[i] == '_') {
            printf("Identifier: ");
            while (isalnum(s[i]) || s[i] == '_')
                printf("%c", s[i++]);
            printf("\n");
        }
        else if (isdigit(s[i])) {
            printf("Constant: ");
            while (isdigit(s[i]) || s[i] == '.')
                printf("%c", s[i++]);
            printf("\n");
        }
        else if (s[i] == '/' && s[i + 1] == '/') {
            printf("Comment: %s", s + i);
            break;
        }
        else if (s[i] == '/' && s[i + 1] == '*') {
            printf("Comment: ");
            i += 2;
            while (s[i] != '\0' &&
                   !(s[i] == '*' && s[i + 1] == '/'))
                printf("%c", s[i++]);
            if (s[i] != '\0')
                i += 2;
            printf("\n");
        }
        else if (strchr("+-*/%=<>!", s[i])) {
            printf("Operator: ");
            printf("%c", s[i++]);
            if (strchr("=<>!", s[i - 1]) && s[i] == '=') {
                printf("%c", s[i++]);
            }
            printf("\n");
        }
        else {
            printf("Special symbol: %c\n", s[i++]);
        }
    }

    return 0;
}

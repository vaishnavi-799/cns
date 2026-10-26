
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[200];
    char *kw[] = {"int", "float", "char", "if", "else",
                  "while", "for", "return", "void"};
    int i = 0, j, flag;

    printf("Enter a statement: ");
    fgets(s, sizeof(s), stdin);

    while (s[i] != '\0') {
        if (isspace(s[i])) {
            i++;
        }
        else if (isalpha(s[i]) || s[i] == '_') {
            char w[50];
            int k = 0;

            while (isalnum(s[i]) || s[i] == '_')
                w[k++] = s[i++];
            w[k] = '\0';

            flag = 0;
            for (j = 0; j < 9; j++) {
                if (strcmp(w, kw[j]) == 0) {
                    flag = 1;
                    break;
                }
            }

            if (flag)
                printf("%s : Keyword\n", w);
            else
                printf("%s : Identifier\n", w);
        }
        else if (isdigit(s[i])) {
            printf("%c", s[i]);
            i++;
            while (isdigit(s[i])) {
                printf("%c", s[i++]);
            }
            printf(" : Constant\n");
        }
        else if (strchr("+-*/%=<>!", s[i])) {
            printf("%c : Operator\n", s[i]);
            i++;
        }
        else {
            printf("%c : Special Symbol\n", s[i]);
            i++;
        }
    }

    return 0;
}

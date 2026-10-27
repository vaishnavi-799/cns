#include <stdio.h>

int main()
{
    char s[100];
    int i;

    printf("Enter string: ");
    scanf(" %[^\n]", s);

    for(i = 0; s[i] != '\0'; i++)
        printf("%c", s[i] ^ 0);

    return 0;
}
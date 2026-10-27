#include <stdio.h>

int main()
{
    char s[100];
    int i;

    printf("Enter string: ");
    scanf(" %[^\n]", s);

    printf("AND with 127: ");
    for(i = 0; s[i] != '\0'; i++)
        printf("%c", s[i] & 127);

    printf("\nXOR with 127: ");
    for(i = 0; s[i] != '\0'; i++)
        printf("%02X ", (unsigned char)(s[i] ^ 127));

    return 0;
}
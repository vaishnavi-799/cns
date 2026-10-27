#include <stdio.h>
#include <string.h>
#include <openssl/blowfish.h>

int main() {
    BF_KEY key;
    unsigned char in[8] = "HELLO";
    unsigned char enc[8], dec[8];
    char k[] = "12345678";
    int i;

    BF_set_key(&key, strlen(k), (unsigned char *)k);

    BF_ecb_encrypt(in, enc, &key, BF_ENCRYPT);

    printf("Encrypted: ");
    for (i = 0; i < 8; i++)
        printf("%02X", enc[i]);

    BF_ecb_encrypt(enc, dec, &key, BF_DECRYPT);
    dec[7] = '\0';

    printf("\nDecrypted: %s\n", dec);

    return 0;
}


// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char s[100], k[100], e[100], d[100];
//     int i, n, m;

//     printf("Enter plaintext: ");
//     scanf("%99s", s);

//     printf("Enter key: ");
//     scanf("%99s", k);

//     n = strlen(s);
//     m = strlen(k);

//     for(i = 0; i < n; i++)
//         e[i] = s[i] ^ k[i % m];

//     printf("Encrypted: ");
//     for(i = 0; i < n; i++)
//         printf("%02X ", (unsigned char)e[i]);

//     for(i = 0; i < n; i++)
//         d[i] = e[i] ^ k[i % m];

//     d[n] = '\0';
//     printf("\nDecrypted: %s\n", d);

//     return 0;
// }
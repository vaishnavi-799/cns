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
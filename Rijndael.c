
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    AES_KEY ek, dk;
    unsigned char key[16] = "123456789012345";
    unsigned char in[16] = "Hello world";
    unsigned char enc[16], dec[16];
    int i;

    AES_set_encrypt_key(key, 128, &ek);
    AES_set_decrypt_key(key, 128, &dk);

    AES_encrypt(in, enc, &ek);

    printf("Encrypted: ");
    for (i = 0; i < 16; i++)
        printf("%02X", enc[i]);

    AES_decrypt(enc, dec, &dk);
    dec[11] = '\0';

    printf("\nDecrypted: %s\n", dec);

    return 0;
}

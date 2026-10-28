
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class Rijndael {
    public static void main(String[] args) throws Exception {
        String msg = "Hello World";

        KeyGenerator kg = KeyGenerator.getInstance("AES");
        kg.init(128);
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("AES/ECB/PKCS5Padding");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(msg.getBytes("UTF-8"));

        String encrypted = Base64.getEncoder().encodeToString(enc);
        System.out.println("Encrypted: " + encrypted);

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(Base64.getDecoder().decode(encrypted));

        System.out.println("Decrypted: " +
                           new String(dec, "UTF-8"));
    }
}

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class Blowfish {
    public static void main(String[] args) throws Exception {
        String msg = "Hello World";

        KeyGenerator kg = KeyGenerator.getInstance("Blowfish");
        kg.init(128);
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("Blowfish/ECB/PKCS5Padding");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(msg.getBytes("UTF-8"));

        String encrypted = Base64.getEncoder().encodeToString(enc);
        System.out.println("Encrypted: " + encrypted);

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(Base64.getDecoder().decode(encrypted));

        System.out.println("Decrypted: " +
                           new String(dec, "UTF-8"));
    }
}

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

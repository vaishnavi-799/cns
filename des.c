#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    DES_cblock key = "12345678";
    DES_key_schedule ks;
    DES_cblock in, out, dec;

    char msg[100];

    printf("Enter message (max 8 characters): ");
    scanf("%8s", msg);

    DES_set_key_unchecked(&key, &ks);

    memset(in, 0, 8);
    strncpy((char *)in, msg, 8);

    DES_ecb_encrypt(&in, &out, &ks, DES_ENCRYPT);
    printf("Encrypted text: ");
    for (int i = 0; i < 8; i++)
        printf("%02X", out[i]);

    DES_ecb_encrypt(&out, &dec, &ks, DES_DECRYPT);
    dec[7] = '\0';
    printf("\nDecrypted text: %s\n", dec);

    return 0;
}


import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class DES {
    public static void main(String[] args) throws Exception {
        String msg = "Hello World";

        KeyGenerator kg = KeyGenerator.getInstance("DES");
        kg.init(56);
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("DES/ECB/PKCS5Padding");

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

// #include <stdio.h>

// int main() {
//     int l = 10, r = 20, k = 5;
//     int t, i;

//     printf("Original: L=%d R=%d\n", l, r);

//     // Encryption
//     for (i = 0; i < 4; i++) {
//         t = r;
//         r = l ^ (r + k);
//         l = t;
//     }

//     printf("Encrypted: L=%d R=%d\n", l, r);

//     // Decryption: reverse the rounds
//     for (i = 0; i < 4; i++) {
//         t = l;
//         l = r ^ (l + k);
//         r = t;
//     }

//     printf("Decrypted: L=%d R=%d\n", l, r);

//     return 0;
// }


import java.util.Scanner;

class RSA {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int p = 3, q = 11;
        int n = p * q;
        int phi = (p - 1) * (q - 1);
        int e = 3, d = 7;

        System.out.print("Enter message (number less than 33): ");
        int m = sc.nextInt();

        int c = 1;
        for (int i = 0; i < e; i++)
            c = c * m % n;

        System.out.println("Encrypted: " + c);

        int dec = 1;
        for (int i = 0; i < d; i++)
            dec = dec * c % n;

        System.out.println("Decrypted: " + dec);
        sc.close();
    }
}

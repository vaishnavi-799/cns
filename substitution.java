import java.util.Scanner;

class Substitution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        System.out.print("Enter text: ");
        String s = sc.nextLine().toUpperCase();

        System.out.print("Enter 26-letter key: ");
        String k = sc.nextLine().toUpperCase();

        if (k.length() != 26) {
            System.out.println("Key must have 26 letters.");
            return;
        }

        for (int i = 0; i < 26; i++) {
            if (k.indexOf(a.charAt(i)) == -1) {
                System.out.println("Invalid key.");
                return;
            }
        }

        String e = "", d = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= 'A' && c <= 'Z')
                e += k.charAt(a.indexOf(c));
            else
                e += c;
        }

        for (int i = 0; i < e.length(); i++) {
            char c = e.charAt(i);
            if (c >= 'A' && c <= 'Z')
                d += a.charAt(k.indexOf(c));
            else
                d += c;
        }

        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + d);
    }
}
import java.util.Scanner;

class Hill {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text (letters only): ");
        String s = sc.nextLine().toUpperCase().replace(" ", "");

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < 'A' || s.charAt(i) > 'Z') {
                System.out.println("Enter letters A-Z only.");
                return;
            }
        }

        if (s.length() % 2 != 0)
            s += "X";

        String e = "", d = "";

        int a = 3, b = 3, c = 2, f = 5;

        for (int i = 0; i < s.length(); i += 2) {
            int x = s.charAt(i) - 'A';
            int y = s.charAt(i + 1) - 'A';

            e += (char)((a * x + b * y) % 26 + 'A');
            e += (char)((c * x + f * y) % 26 + 'A');
        }

        for (int i = 0; i < e.length(); i += 2) {
            int x = e.charAt(i) - 'A';
            int y = e.charAt(i + 1) - 'A';

            d += (char)((15 * x + 17 * y) % 26 + 'A');
            d += (char)((20 * x + 9 * y) % 26 + 'A');
        }

        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + d);
    }
}
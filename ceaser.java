import java.util.Scanner;

class Caesar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String s = sc.nextLine().toUpperCase();

        System.out.print("Enter key: ");
        int k = sc.nextInt();

        String e = "", d = "";
        k = ((k % 26) + 26) % 26;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= 'A' && c <= 'Z')
                e += (char)((c - 'A' + k) % 26 + 'A');
            else
                e += c;
        }

        for (int i = 0; i < e.length(); i++) {
            char c = e.charAt(i);
            if (c >= 'A' && c <= 'Z')
                d += (char)((c - 'A' - k + 26) % 26 + 'A');
            else
                d += c;
        }

        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + d);
    }
}
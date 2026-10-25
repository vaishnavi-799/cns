
import java.security.MessageDigest;
import java.util.Scanner;

public class SHA1 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String s = sc.nextLine();

        MessageDigest md = MessageDigest.getInstance("SHA-1");
        byte[] b = md.digest(s.getBytes("UTF-8"));

        StringBuilder hex = new StringBuilder();

        for (byte x : b) {
            hex.append(String.format("%02x", x & 0xff));
        }

        System.out.println("SHA-1 Digest: " + hex);
        sc.close();
    }
}

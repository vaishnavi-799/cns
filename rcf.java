
class RC4 {
    public static void main(String[] args) {
        String msg = "Hello world";
        String key = "key";
        int s[] = new int[256];

        for (int i = 0; i < 256; i++)
            s[i] = i;

        int j = 0, t;
        for (int i = 0; i < 256; i++) {
            j = (j + s[i] + key.charAt(i % key.length())) % 256;
            t = s[i];
            s[i] = s[j];
            s[j] = t;
        }

        int i = 0;
        j = 0;
        System.out.print("Encrypted: ");

        for (int n = 0; n < msg.length(); n++) {
            i = (i + 1) % 256;
            j = (j + s[i]) % 256;

            t = s[i];
            s[i] = s[j];
            s[j] = t;

            int k = s[(s[i] + s[j]) % 256];
            System.out.printf("%02X ", msg.charAt(n) ^ k);
        }
        System.out.println();
    }
}

import java.util.Scanner;

public class VigenereCipher {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the plaintext: ");
        String plaintext = sc.nextLine();
        System.out.print("Enter the key: ");
        String key = sc.nextLine();
        
        String ciphertext = encrypt(plaintext, key);
        System.out.println("Ciphertext: " + ciphertext);
        
        String decryptedText = decrypt(ciphertext, key);
        System.out.println("Decrypted Text: " + decryptedText);
    }
    
    public static String encrypt(String plaintext, String key) {
        plaintext = plaintext.toUpperCase();
        key = key.toUpperCase();
        String ciphertext = "";
        int j = 0;
        for (int i = 0; i < plaintext.length(); i++) {
            char c = plaintext.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                int shift = key.charAt(j) - 'A';
                char encrypted = (char) (((c - 'A' + shift) % 26) + 'A');
                ciphertext += encrypted;
                j = (j + 1) % key.length();
            } else {
                ciphertext += c;
            }
        }
        return ciphertext;
    }
    
    public static String decrypt(String ciphertext, String key) {
        ciphertext = ciphertext.toUpperCase();
        key = key.toUpperCase();
        String plaintext = "";
        int j = 0;
        for (int i = 0; i < ciphertext.length(); i++) {
            char c = ciphertext.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                int shift = key.charAt(j) - 'A';
                char decrypted = (char) (((c - 'A' - shift + 26) % 26) + 'A');
                plaintext += decrypted;
                j = (j + 1) % key.length();
            } else {
                plaintext += c;
            }
        }
        return plaintext;
    }
}

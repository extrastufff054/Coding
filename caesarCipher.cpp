#include <iostream>
#include <string>
using namespace std;

string encrypt(string message, int shift) {
    string result = "";
    for (int i = 0; i < message.length(); i++) {
        if (isalpha(message[i])) {
            char c = message[i];
            if (isupper(c)) {
                c = (c + shift - 'A') % 26 + 'A';
            } else {
                c = (c + shift - 'a') % 26 + 'a';
            }
            result += c;
        } else {
            result += message[i];
        }
    }
    return result;
}

string decrypt(string message, int shift) {
    return encrypt(message, 26 - shift);
}

int main() {
    string message;
    int shift;
    cout << "Enter message to encrypt: ";
    getline(cin, message);
    cout << "Enter shift value: ";
    cin >> shift;
    string ciphertext = encrypt(message, shift);
    cout << "Ciphertext: " << ciphertext << endl;
    string plaintext = decrypt(ciphertext, shift);
    cout << "Plaintext: " << plaintext << endl;
    return 0;
}


/*
    The encrypt function takes a message string and a shift value as inputs, and returns the encrypted ciphertext string. The decrypt function takes a ciphertext string and a shift value as inputs, and returns the decrypted plaintext string.

In the main function, the user is prompted to enter a message and a shift value, and the program encrypts and decrypts the message using the Caesar cipher.
*/
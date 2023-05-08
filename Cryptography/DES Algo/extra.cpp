#include <iostream>
#include <string>

using namespace std;

// Key permutation table (PC1)
int PC1[56] = { 57, 49, 41, 33, 25, 17, 9, 1,
                58, 50, 42, 34, 26, 18, 10, 2,
                59, 51, 43, 35, 27, 19, 11, 3,
                60, 52, 44, 36, 63, 55, 47, 39,
                31, 23, 15, 7, 62, 54, 46, 38,
                30, 22, 14, 6, 61, 53, 45, 37,
                29, 21, 13, 5, 28, 20, 12, 4 };

// Key permutation table (PC2)
int PC2[48] = { 14, 17, 11, 24, 1, 5, 3, 28,
                15, 6, 21, 10, 23, 19, 12, 4,
                26, 8, 16, 7, 27, 20, 13, 2,
                41, 52, 31, 37, 47, 55, 30, 40,
                51, 45, 33, 48, 44, 49, 39, 56,
                34, 53, 46, 42, 50, 36, 29, 32 };

// Key rotation schedule
int rotations[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

// Function to perform the key permutation
string permute_key(string key, int* table, int size) {
    string result(size, ' ');
    for (int i = 0; i < size; i++) {
        result[i] = key[table[i] - 1];
    }
    return result;
}

// Function to generate subkeys
void generate_subkeys(string key, string subkeys[16]) {
    // Perform initial key permutation
    string permuted_key = permute_key(key, PC1, 56);

    // Split the key into two halves
    string C = permuted_key.substr(0, 28);
    string D = permuted_key.substr(28, 28);

    // Generate 16 subkeys
    for (int i = 0; i < 16; i++) {
        // Rotate the halves
        char temp = C[0];
        for (int j = 0; j < 27; j++) {
            C[j] = C[j + 1];
        }
        C[27] = temp;
        temp = D[0];
        for (int j = 0; j < 27; j++) {
            D[j] = D[j + 1];
        }
        D[27] = temp;

        // Concatenate the halves and permute to generate the subkey
        string CD = C + D;
        subkeys[i] = permute_key(CD, PC2, 48);
    }
}

int main() {
    // Example key
    string key = "0001001100110100010101110111100110011011101111001101111111110001";

    // Generate subkeys
    string subkeys[16];
    generate_subkeys(key, subkeys);

    // Print the subkeys
    for (int i = 0; i < 16; i++) {
        cout << "Subkey " << i + 1 << ": " << subkeys[i] << endl;
    }

    return 0;
}
// Implementing aiffen cipher in cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int key1, key2;
    int p;
    string plaintext, ciphertext;

    cout << "Enter key1 and key2: ";
    cin >> key1 >> key2;

    if (key1 < 1 || key1 > 25)
    {
        cout << "Error : Key must be between 1 and 25. " << endl;
        return 1;
    }

    if (key2 < 1 || key2 > 25)
    {
        cout << "Error : Key must be between 1 and 25. " << endl;
        return 1;
    }

    cout << "Enter the plaintext: ";
    cin.ignore();
    getline(cin, plaintext);

    for (char c : plaintext)
    {
        if (isalpha(c))
        {
            c = toupper(c);

            c = ((c - 'A') * key1) % 26 + 'A';
            p = ((c - 'A' + key2) % 26) + 'A';
        }
        ciphertext += p;
    }

    cout << "Cipher text:" << ciphertext << endl;
    return 0;
}
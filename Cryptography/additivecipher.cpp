#include<iostream>
#include<string>

using namespace std;

int main()
{
    int key;
    string plaintext, ciphertext;

    //Prompt user for key
    cout<<"Enter the key (an int between 1 and 25)";
    cin>>key;

    //Check if key is valid
    if(key<1 || key >25){
        cout<<"Error : key must be between 1 and 25 "<<endl;
        return 1;
    }

    //Prompt user for plaintext
    cout<<"Enter the plaintext: ";
    cin.ignore();   //Ignore newline character
    getline(cin, plaintext);

    //Enrypt the plaintext
    for(char c: plaintext)
    {
        if (isalpha(c))
        {
            //Convert the character to uppercase
            c=toupper(c);

            //Apply additive cipher
            c=((c-'A' +key )%26)+'A';
            
        }

        ciphertext+=c;
    }

    //Print the ciphertext
    cout<<"Ciphertext : "<<ciphertext<<endl;

    return 0;

}
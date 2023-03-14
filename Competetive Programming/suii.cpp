#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    cout << "Enter first half scores (A:B): ";
    cin >> A >> B;
    cout << "Enter second half scores (C:D): ";
    cin >> C >> D;
    if (C < A || D < B) {
        cout << "Given scores are not possible.\n";
    } else {
        int diffA = C - A;
        int diffB = D - B;
        if (diffA > diffB) {
            cout << "Ronaldo wins!\n";
        } else if (diffA < diffB) {
            cout << "Opposing team wins!\n";
        
        } else {
            cout << "It's a draw!\n";
        }
    }
    return 0;
}

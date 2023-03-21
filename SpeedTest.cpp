#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    string prompt = "The quick brown fox jumps over the lazy dog.";
    cout << "Type the following sentence:\n\n" << prompt << "\n\n";
    string input;
    getline(cin, input);
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    duration<double, milli> elapsed_time = end - start;
    int num_errors = 0;
    for (int i = 0; i < prompt.length(); i++) {
        if (input[i] != prompt[i]) {
            num_errors++;
        }
    }
    int num_chars = prompt.length();
    double typing_speed = (num_chars / (elapsed_time.count() / 1000.0)) * 60.0;
    cout << "\nTime: " << elapsed_time.count() / 1000.0 << " seconds\n";
    cout << "Speed: " << typing_speed << " characters per minute\n";
    cout << "Errors: " << num_errors << endl;
    return 0;
}

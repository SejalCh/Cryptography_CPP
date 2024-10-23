#include <iostream>
#include <string>

using namespace std;

// Caesar Cipher encryption/decryption
string caesar(string text, int shift, bool encrypt) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            shift = encrypt ? shift : 26 - shift; // Reverse shift for decryption
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

// Vigenère Cipher encryption/decryption
string vigenere(string text, string key, bool encrypt) {
    string result = "";
    int keyLength = key.length();
    for (int i = 0, j = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char keyBase = isupper(key[j % keyLength]) ? 'A' : 'a';
            int shift = encrypt ? (key[j % keyLength] - keyBase) : -(key[j % keyLength] - keyBase);
            result += (c - base + shift + 26) % 26 + base;
            j++;
        } else {
            result += c;
        }
    }
    return result;
}

// Main function
int main() {
    int algorithm, operation;
    cout << "==============================\n";
    cout << "   Cryptography Tool\n";
    cout << "==============================\n";
    cout << "Choose an algorithm to use:\n";
    cout << "1. Caesar Cipher\n";
    cout << "2. Vigenere Cipher\n";
    cout << "Please enter the number corresponding to your choice: ";
    cin >> algorithm;
    cin.ignore(); // To consume newline

    string message, key;
    int shift;

    if (algorithm == 1) { // Caesar Cipher
        cout << "\n--- Caesar Cipher ---\n";
        cout << "Enter your message: ";
        getline(cin, message);
        cout << "Enter the shift value (1-25): ";
        cin >> shift;
        cout << "Choose an operation:\n";
        cout << "1. Encrypt the message\n";
        cout << "2. Decrypt the message\n";
        cout << "Please enter your choice: ";
        cin >> operation;

        cout << (operation == 1 ? "Encrypted message: " : "Decrypted message: ") 
             << caesar(message, shift, operation == 1) << endl;

    } else if (algorithm == 2) { // Vigenère Cipher
        cout << "\n--- Vigenere Cipher ---\n";
        cout << "Enter your message: ";
        getline(cin, message);
        cout << "Enter your keyword (alphabetic only): ";
        getline(cin, key);
        cout << "Choose an operation:\n";
        cout << "1. Encrypt the message\n";
        cout << "2. Decrypt the message\n";
        cout << "Please enter your choice: ";
        cin >> operation;

        cout << (operation == 1 ? "Encrypted message: " : "Decrypted message: ") 
             << vigenere(message, key, operation == 1) << endl;

    } else {
        cout << "Invalid algorithm choice! Please the program and try again." << endl;
    }

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

string encryptVigenere(string plaintext, string keyword) {
    string encryptedText = "";
    int keyLength = keyword.length();
    int textLength = plaintext.length();

    for (int i = 0; i < textLength; ++i) {
        char plainChar = plaintext[i];
        char keyChar = keyword[i % keyLength];
        int shift = (int(keyChar) + int(plainChar)) % 256; // Assuming ASCII

        encryptedText += char(shift);
    }

    return encryptedText;
}

string decryptVigenere(string ciphertext, string keyword) {
    string decryptedText = "";
    int keyLength = keyword.length();
    int textLength = ciphertext.length();

    for (int i = 0; i < textLength; ++i) {
        char cipherChar = ciphertext[i];
        char keyChar = keyword[i % keyLength];
        int shift = (int(cipherChar) - int(keyChar) + 256) % 256; // Assuming ASCII

        decryptedText += char(shift);
    }

    return decryptedText;
}

int main() {
    string plaintext = "Hello! This is a test message 1234 %$#";
    string keyword = "KEY";

    string encrypted = encryptVigenere(plaintext, keyword);
    string decrypted = decryptVigenere(encrypted, keyword);

    cout << "Original text: " << plaintext << endl;
    cout << "Encrypted text: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// Vigenere encryption
string vigenereEncrypt(const string& plaintext, const string& key) {
    string encryptedText = "";
    int currentCharIndex = 0; // bac texti heratakan elmenti indexy
    // cikl bac textov
    for (char c : plaintext) {
        // check if the current character letter or not
        if (isalpha(c)) {
            // isupper() = mecatare  te voj
            // base-y hamap ascii kdderi het ashxatelu hamare
            char base = isupper(c) ? 'A' : 'a';
            // bac texti ev banalu hamap tareri ascii koderi +
            char encryptedChar = ((c - base) + (key[currentCharIndex % key.length()] - 'A')) % 26 + base;
            encryptedText += encryptedChar;
            currentCharIndex++;
        }
        else {
            encryptedText += c; // chpopoxel voj aybenakan simvolnery
        }
    }

    return encryptedText;
}

// vigenere decryption
string vigenereDecrypt(const string& ciphertext, const string& key) {
    string decryptedText = "";
    int currentCharIndex = 0;

    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            // +26, vorpeszi tivy chlini bacasakan
            char decryptedChar = ((c - base) - (key[currentCharIndex % key.length()] - 'A') + 26) % 26 + base;
            decryptedText += decryptedChar;
            currentCharIndex++;
        }
        else {
            decryptedText += c; // Keep non-alphabetic characters unchanged
        }
    }

    return decryptedText;
}

int main() {
    string plaintext = "HELLO"; // bac text
    string key = "KEY"; // banali

    // Encryption
    string encryptedText = vigenereEncrypt(plaintext, key);
    cout << "Encrypted Text: " << encryptedText << endl;

    // Decryption
    string decryptedText = vigenereDecrypt(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
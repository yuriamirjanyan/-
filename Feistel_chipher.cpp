#include <iostream>
#include <bitset>

const int NUM_ROUNDS = 4;

// Function to perform a simple Feistel round using XOR operation
uint32_t feistelRound(uint32_t block, uint32_t key) {
    return block ^ key;
}

// Feistel Cipher function
uint32_t feistelCipher(uint32_t block, uint32_t key) {
    uint32_t left = block >> 16; // Splitting block into left and right halves
    uint32_t right = block & 0xFFFF;

    for (int i = 0; i < NUM_ROUNDS; ++i) {
        uint32_t temp = right;
        right = left ^ feistelRound(right, key);
        left = temp;
    }

    return (right << 16) | left; // Combining left and right halves
}

int main() {
    // Example block to be encrypted
    uint32_t block = 0b11001100110011001100110011001100;

    // Example key
    uint32_t key = 0b10101010101010101010101010101010;

    std::cout << "Original Block: " << std::bitset<32>(block) << std::endl;

    // Encrypt the block using Feistel Cipher
    uint32_t encryptedBlock = feistelCipher(block, key);

    std::cout << "Encrypted Block: " << std::bitset<32>(encryptedBlock) << std::endl;

    // Decrypt the encrypted block (using the same Feistel Cipher)
    uint32_t decryptedBlock = feistelCipher(encryptedBlock, key);

    std::cout << "Decrypted Block: " << std::bitset<32>(decryptedBlock) << std::endl;

    return 0;
}
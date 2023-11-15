//tnayin 3
#include <iostream>
#include <cmath>
#define SIZE 50
using namespace std;
void swapChars(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}
int stringLength(const char msg[]) {
    int count = 0;
    for (int i = 0; msg[i] != '\0'; i++) {
        ++count;
    }
    return count;
}
void fillMatrix(char* matrix, const int size_M, const char msg[]) {
    int counter = 0;
    bool check = true;
    for (int i = 0; i < size_M; ++i) {
        for (int j = 0; j < size_M; ++j) {
            if (check) {
                //matrix[i][j] = msg[counter++];
                *(matrix + size_M * i + j) = msg[counter++];
            }
            else {
                //matrix[i][j] = ' ';
                *(matrix + size_M * i + j) = ' ';
            }
            if (msg[counter] == '\0') {
                check = false;
            }
        }
    }
}
void printMatrix(const char* matrix, const int size_M) {
    int counter = 0;
    bool check = true;
    for (int i = 0; i < size_M; ++i) {
        for (int j = 0; j < size_M; ++j) {
            cout << *(matrix + size_M * i + j) << " ";
        }
        cout << endl;
    }
}
void modifyMatrix(char* matrix, const int size_M) {
    for (int i = 0; i < size_M; ++i) {
        for (int j = i + 1; j < size_M; ++j) {
            swapChars(*(matrix + size_M * i + j), *(matrix + size_M * j + i));
        }
    }
}
void printEncryptedText(const char* matrix, const int size_M) {
    for (int i = 0; i < size_M; ++i) {
        for (int j = 0; j < size_M; ++j) {
            cout << *(matrix + size_M * i + j);
        }
    }
}
int main() {

    char msg[SIZE] = "cat dog 2";
    cout << "Text : " << msg << endl << endl;
    int length = stringLength(msg);

    const int size_M = (const int)ceil(sqrt(length));
    char matrix[size_M][size_M];

    fillMatrix(&matrix[0][0], size_M, msg);
    cout << "Table :" << endl;
    printMatrix(&matrix[0][0], size_M);

    modifyMatrix(&matrix[0][0], size_M); // toxery poxel syunerov
    cout << endl;
    //printMatrix(&matrix[0][0], size_M);
    cout << "Encrypted : ";
    printEncryptedText(&matrix[0][0], size_M);
    cout << endl;

    return 0;
}
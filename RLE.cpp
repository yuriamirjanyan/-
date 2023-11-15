// (RLE) run length encoding
#include <iostream>
using namespace std;
void printRLE(string str)
{
    int n = str.length();
    for (int i = 0; i < n; i++) {
        // Count occurrences of current character
        int count = 1;
        // vorpeszi toxi verjin simvoly chntrvi (i+1)-i patcharov 
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        // Print character and its count
        cout << str[i] << count;
    }
}
int main()
{
    string str = "wwwwaaadexxxxxxywww";
    cout << str << endl;
    printRLE(str);
    return 0;
}
#include <iostream>
using namespace std;
int findAbsentedElement(const int arr[], const int N) {
    for (int i = 1; i < N + 1; ++i) { // digits loop 1 to N + 1
        bool check = true;
        for (int j = 0; j <= N; ++j) { // array loop
            if (arr[j] == i) {
                check = false;
                break;
            }
        }
        if (check) {
            return i; // verdaracnum enq chgtnvac elementy
        }
    }
    return 0;
}

int main()
{
    int arr[] = { 3, 4, 5, 2, 10, 9, 1, 7, 6 }; // 8 is not
    int N = sizeof(arr) / sizeof(arr[0]);

    int absentElement = findAbsentedElement(arr, N);
    cout << "Absented element : " << absentElement << endl;

    return 0;
}
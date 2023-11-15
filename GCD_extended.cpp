#include <iostream>
using namespace std;
/*
    ax + by = gcd(a, b)
    gcd(a, b) = gcd(b%a, a)
    gcd(b%a, a) = (b%a)x1 + ay1
    ax + by = (b%a)x1 + ay1
    ax + by = (b – [b/a] * a)x1 + ay1
    ax + by = a(y1 – [b/a] * x1) + bx1

    // Comparing LHS and RHS,
    x = y1 – ⌊b/a⌋ * x1
    y = x1
*/
int gcdExtended(int a, int b, int* x, int* y) {  //Greatest common divisor extented
    // Base case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main() {

    int x, y, a = 35, b = 15;
    int res = gcdExtended(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b << ") = " << res << endl;

    return 0;
}
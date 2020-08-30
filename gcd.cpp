#include <iostream>
#include <algorithm>

int gcd(int m, int n) {
    return m > n ? 
        n == 0 ? m : gcd(n, m%n):
        m == 0 ? n : gcd(m, n%m);
}

int main () {
    int m = 12, n = 8;

    std::cout << gcd(12, 8) << std::endl;
    std::cout << gcd(8, 12) << std::endl;
    return 0;
}
#include <iostream>
#include <cmath>

int main() {

    long long n;
    std::cin >> n;

    //center
    if (n == 1) {
        std::cout << "(0,0)" << std::endl;
        return 0;
    }

    long long root = static_cast<long long>(ceil(sqrt(n)));
    if (root % 2 == 0) {
        root++;
    }
    long long k = (root - 1) / 2;


    long long side_len = 2 * k;
    long long p_max = root * root;

    long long x, y;

    if (p_max - side_len < n && n <= p_max) {
        y = k;
        x = k - (p_max - n);

    } else if (p_max - 2 * side_len < n && n <= p_max - side_len) {
        x = -k;
        y = k - ((p_max - side_len) - n);

    } else if (p_max - 3 * side_len < n && n <= p_max - 2 * side_len) {
        y = -k;
        x = -k + ((p_max - 2 * side_len) - n);

    } else {
        x = k;
        y = -k + ((p_max - 3 * side_len) - n);
    }

    std::cout << "(" << x << "," << y << ")" << std::endl;

    return 0;
}
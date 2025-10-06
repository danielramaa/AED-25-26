#include <iostream>

void print_prime_factorization(int num) {
    int original_num = num;
    std::cout << original_num << "=";

    bool is_first_factor = true;


    auto print_factor = [&](int factor) {
        if (!is_first_factor) {
            std::cout << "*";
        }
        std::cout << factor;
        is_first_factor = false;
    };


    while (num % 2 == 0) {
        print_factor(2);
        num /= 2;
    }

    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            print_factor(i);
            num /= i;
        }
    }

    if (num > 1) {
        print_factor(num);
    }

    std::cout << std::endl;
}

int main() {

    int n;
    std::cin >> n;


    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        print_prime_factorization(a);
    }

    return 0;
}
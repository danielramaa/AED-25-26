#include <iostream>


int remove(int a[], int n, int x) {
    int used = 0;
    int pos = 0;
    while (pos < n) {
        if (a[pos] != x) {
            a[used] = a[pos];
            used++;
        }
        pos++;
    }
    return used;
}

int main(){
    int n;
    int x;
    std::cin >> n >> x;

    int arr[100];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int new_size = remove(arr, n, x);
    std::cout << new_size << std::endl;
    for (int i = 0; i < new_size; ++i) {
        std::cout << arr[i];
        if (i < new_size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
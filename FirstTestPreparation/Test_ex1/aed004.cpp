#include <iostream>
#include <vector>

std::vector<int> primeFactor (int a){
    std::vector<int> ans;
    while(a % 2 ==0){
        ans.push_back(2);
        a = a/2;
    }
    for (long long i =3; i*i <= a;i +=2){
        while (a % i == 0){
            ans.push_back(i);
            a = a/i;
        }
    }

    if (a > 1) {
        ans.push_back(a);
    }
    return ans;
}

int main(){
    int n;
    std::cin >> n;

    int a;     

    for (int i = 0; i < n; i++){
        
        std::cin >> a;
        std::vector<int> ans = primeFactor(a);
        std::cout << a << "=";

        std::string separator = "";

        for(auto x : ans){
            std::cout << separator << x;
            separator = "*";
        } 
        std::cout << std::endl;
    }
}
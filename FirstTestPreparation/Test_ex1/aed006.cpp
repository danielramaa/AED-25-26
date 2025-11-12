#include <iostream>
#include <vector>


int main(){

    int n;
    std::cin >> n;

    std::vector<long long> prefix_sum(n+1,0);
    prefix_sum[0] = 0;


    
    for (int i=1;i<=n;i++){
        int energy;
        std::cin >> energy;
        prefix_sum[i] = prefix_sum[i-1] + energy;    
    }

    int p;    
    std::cin >> p;

    for (int j=0;j<p;j++){
        int a;
        int b;
        std::cin >> a >> b;
        long long result = prefix_sum[b] - prefix_sum[a-1];
        std::cout << result << std::endl;
    }
    

    return 0;
}
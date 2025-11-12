#include <iostream>
#include <vector>

int main(){
    int n, k, t;
    std::cin >> n >> k >> t;

    std::vector<int> t_depth(n);
    for (int i=0; i<n; i++){
        std::cin >> t_depth[i];
    }  

    std::vector<int> is_deep(n);
    for (int i=0; i<n; i++){
        if (t_depth[i] >= t){
            is_deep[i] = 1;
        }
        else{
            is_deep[i] = 0; 
        }
    }

    int total_valid_sections = 0;
    int min_deep_needed = (k + 1) / 2;

    int current_window = 0;

    for (int i=0; i<k; i++){
        current_window += is_deep[i];
    }

    if(current_window >= min_deep_needed){
        total_valid_sections++;
    }


    for (int i = 1; i <= n-k; i++){
        current_window = current_window - is_deep[i-1] + is_deep[i+k-1];

        if (current_window >= min_deep_needed){
            total_valid_sections++;
        }

    }

    std::cout << total_valid_sections << std::endl;
    return 0;

}
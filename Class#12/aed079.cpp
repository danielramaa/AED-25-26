#include <iostream>
#include <vector>


bool is_maxHeap(const std::vector<int> & v){
    int n = v.size() -1;
    for (int i =1; i<=n; i++){
        if (2*i <= n && v[i] < v[i*2] ) return false;
        if (2*i+1 <= n && v[i] < v[i*2+1] ) return false;
    }
    return true;
}

bool is_minHeap(const std::vector<int> & v){
    int n = v.size() -1;
    for (int i =1; i<=n; i++){
        if (2*i <= n && v[i] > v[i*2] ) return false;
        if (2*i+1 <= n && v[i] > v[i*2+1] ) return false;
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;
        std::vector<int> v(m + 1);
        for (int j = 1; j <= m; j++)
        {
            std::cin >> v[j];
        }

        if (is_maxHeap(v) && is_minHeap(v)){
            std::cout << "max or min heap\n";
        }
        else if (is_maxHeap(v)){
            std::cout << "max heap\n";
        }
        else if (is_minHeap(v)){
            std::cout << "min heap\n";
        }        
        else{
            std::cout << "none\n";
        }            
    }
    return 0;
}
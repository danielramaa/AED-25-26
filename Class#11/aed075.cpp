#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int K;
    if (!(std::cin >> K)) return 0;
    std::string S;
    std::cin >> S;

    std::unordered_map<std::string, int> counts;
    int n = S.length();
    

    for (int i = 0; i <= n - K; ++i) {
        std::string sub = S.substr(i, K);
        counts[sub]++;
    }

    int maxFreq = 0;
    for (auto const& p : counts) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
        }
    }

    int countMax = 0;
    std::string maxMotif = "";
    for (auto const& p : counts) {
        if (p.second == maxFreq) {
            countMax++;
            maxMotif = p.first;
        }
    }

    std::cout << maxFreq << std::endl;
    if (countMax == 1) {
        std::cout << maxMotif << std::endl;
    } else {
        std::cout << countMax << std::endl;
    }

    return 0;
}
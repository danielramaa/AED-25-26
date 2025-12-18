#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <iterator>

int main() {
    std::string sentence;
    std::getline(std::cin, sentence);

    std::stringstream ss(sentence);
    std::string word;
    int k = 0;

    while (ss >> word) {
        k++;
    }

    int n;
    std::cin >> n;

    std::list<std::string> children;
    for (int i = 0; i < n; i++) {
        std::string name;
        std::cin >> name;
        children.push_back(name);
    }

    std::list<std::string>::iterator current = children.begin();

    while (!children.empty()) {
        int steps = (k - 1) % children.size();

        for (int i = 0; i < steps; i++) {
            current++;
            if (current == children.end()) {
                current = children.begin();
            }
        }
        std::cout << *current << std::endl;

        current = children.erase(current);

        if (current == children.end() && !children.empty()) {
            current = children.begin();
        }
    }

    return 0;
}

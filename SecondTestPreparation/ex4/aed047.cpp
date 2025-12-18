#include <iostream>
#include <set>

int main()
{
    int c;
    std::cin >> c;

    int c_card;
    std::set<int> initial_set;
    for (int j = 0; j < c; j++)
    {
        std::cin >> c_card;
        initial_set.insert(c_card);
    }

    std::set<int> final_set;

    int new_cards;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> new_cards;
        if (initial_set.find(new_cards) == initial_set.end())
        {
            final_set.insert(new_cards);
        }
    }
    std::cout << final_set.size();
    if (final_set.size() > 0)
    {
        std::cout<< "\n";
        bool first = true;
        for (auto card : final_set)
        {
            if (first)
                first=false;
            else
                std::cout <<" ";
            std::cout << card;
        }
    }

    std::cout << "\n";
    return 0;
}
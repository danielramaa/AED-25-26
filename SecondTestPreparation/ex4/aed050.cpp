#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    map<string, pair<int, int>> movies;

    for (int i = 0; i < N; ++i) {
        string name;
        int score;
        cin >> name >> score;

        movies[name].first++;
        if (score >= 5) {
            movies[name].second++;
        }
    }

    cout << movies.size() << endl;

    int max_reviews = 0;
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->second.first > max_reviews) {
            max_reviews = it->second.first;
        }
    }

    int count_max_reviews = 0;
    int count_good_movies = 0;

    for (auto it = movies.begin(); it != movies.end(); ++it) {
        int total = it->second.first;
        int positive = it->second.second;
        int negative = total - positive;

        if (total == max_reviews) {
            count_max_reviews++;
        }

        if (positive > negative) {
            count_good_movies++;
        }
    }

    cout << max_reviews << " " << count_max_reviews << endl;

    cout << count_good_movies << endl;

    return 0;
}

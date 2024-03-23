#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    std::vector<std::pair<int, int>> vec = {{3, 1}, {0, 2}, {2, 3}};

    std::sort(vec.begin(), vec.end(), compare);

    for (const auto& p : vec) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}
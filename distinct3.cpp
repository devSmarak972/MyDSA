#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    // Using unordered_set to store distinct values
    std::unordered_set<int> distinctValues(values.begin(), values.end());

    // Output the number of distinct values
    std::cout << distinctValues.size() << std::endl;

    return 0;
}

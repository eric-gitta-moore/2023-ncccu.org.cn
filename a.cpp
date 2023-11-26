#include "bits/stdc++.h"

signed main() {
    double n, k;
    std::cin >> n >> k;
    k = k / 100.0;
    double housePrice = 150;
    for (int year = 0; year < 10; year++) {
        double found = n * year;
        if (housePrice <= found) {
            printf("%d %.2lf", year, housePrice);
            return 0;
        }
        housePrice *= 1 + k;
    }
    std::cout << "Impossible";
}
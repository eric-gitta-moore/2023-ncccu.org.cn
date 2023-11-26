#include "bits/stdc++.h"

signed main() {
    std::string inputString;

    std::getline(std::cin, inputString);

    int vowelCount = 0;
    for (char c: inputString) {
        char lowercaseChar = std::tolower(c);
        if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' || lowercaseChar == 'o' ||
            lowercaseChar == 'u') {
            vowelCount++;
        }
    }

    std::string stringWithoutVowels = inputString;
    stringWithoutVowels.erase(std::remove_if(stringWithoutVowels.begin(), stringWithoutVowels.end(),
                                             [](char c) {
                                                 return std::tolower(c) == 'a' || std::tolower(c) == 'e' ||
                                                        std::tolower(c) == 'i' || std::tolower(c) == 'o' ||
                                                        std::tolower(c) == 'u';
                                             }),
                              stringWithoutVowels.end());

    std::cout << vowelCount << std::endl << stringWithoutVowels;
}
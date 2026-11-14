//
// Created by milan on 09-Nov-26.
//

#include "levenshtein.h"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int levenshteinDistance(const std::string& s1, const std::string& s2) {
    const int m = s1.size();
    const int n = s2.size();

    std::vector<std::vector<int>> d(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
        d[i][0] = i;
    for (int j = 0; j <= n; j++)
        d[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
            if (s1[i-1] == s2[j-1]) {
                cost = 0;
            }else {
                cost = 1;
            }
            d[i][j] = std::min( { d[i - 1][j] + 1,
                                 d[i][j - 1] + 1,
                                 d[i - 1][j - 1] + cost } );
        }
    }
    return d[m][n];
}

std::vector<int> levenshteinSearch(std::ifstream& file, const std::string& pattern) {
    std::vector<int> result;
    int maxDistance = 0.2 * static_cast<float>(pattern.size());
    std::string substring;
    char c;
    while (substring.size() < pattern.size() - 1) {
        file.get(c);
        substring.push_back(c);
    }

    int index = 0;

    while (file.get(c)) {
        substring.push_back(c);
        int distance = levenshteinDistance(substring, pattern);
        if (distance > 0 && distance <= maxDistance) {
            result.push_back(index);
            //std::cout << substring << " " << distance << " index: " << index << std::endl;
        }
        substring.erase(substring.begin());
        index++;
    }
    return result;
}



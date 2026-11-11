//
// Created by milan on 08-Nov-26.
//

#include "kmp.h"

#include <iostream>
std::vector<int> computePrefixFunction(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);

    //k je dužina trenutno najduzeg prefiksa-sufiksa za pattern[0..i-1]
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = lps[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        lps[i] = k;
    }
    return lps;
}


std::vector<int> kmpSearch(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();

    std::vector<int> result;
    if (m == 0 || m > n) return result;

    std::vector<int> lps = computePrefixFunction(pattern);

    //broj matchovanih karaktera
    int q = 0;

    for (int i = 0; i < n; i++) { //za svaki karakter
        while (q > 0 && pattern[q] != text[i]) {
            q = lps[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            //pojavljuje se na lokaciji i-m+1
            result.push_back(i-m+1);
            q = lps[q - 1];
        }
    }

    return result;
}

std::vector<int> kmpSearch(std::ifstream &file, const std::string &pattern) {
    if (!file.is_open()) return {};
    int m = pattern.size();

    std::vector<int> result;
    if (m == 0) return result;

    std::vector<int> lps = computePrefixFunction(pattern);

    //broj matchovanih karaktera
    int q = 0;

    char c;
    int i = 0;
    while (file.get(c)) { //za svaki karakter
        while (q > 0 && pattern[q] != c) {
            q = lps[q - 1];
        }
        if (pattern[q] == c) {
            q++;
        }
        if (q == m) {
            //pojavljuje se na lokaciji i-m+1
            result.push_back(i-m+1);
            q = lps[q - 1];
        }
        i++;
    }

    return result;
}


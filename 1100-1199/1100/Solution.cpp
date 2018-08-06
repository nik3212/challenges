/*
1100. Final Standings

Time limit: 1.0 second
Memory limit: 16 MB

Old contest software uses bubble sort for generating final standings. But now, there are too many teams 
and that software works too slow. You are asked to write a program, which generates exactly the same final 
standings as old software, but fast.

Input

The first line of input contains only integer 1 < N ≤ 150000 — number of teams. Each of the next N lines contains
two integers 1 ≤ ID ≤ 107 and 0 ≤ M ≤ 100. ID — unique number of team, M — number of solved problems.

Output

Output should contain N lines with two integers ID and M on each. Lines should be sorted by M in descending order 
as produced by bubble sort (see below).

*/

#include <iostream>
#include <vector>
#include <map>

typedef std::pair<int, int> Item;

void merge(std::vector<Item>& vec, int l, int m, int r) {
    int start = m - l + 1;
    int end = r - m;

    std::vector<Item> left;
    std::vector<Item> right;

    for (int i = 0; i < start; ++i) {
        left.push_back(vec[l + i]);
    }

    for (int i = 0; i < end; ++i) {
        right.push_back(vec[m + i + 1]);
    }

    unsigned int i = 0;
    unsigned int j = 0;

    int k = l;

    while (i < left.size() && j < right.size()) {
        if (left[i].second < right[j].second) {
            vec[k] = right[j];
            j++;
        } else {
            vec[k] = left[i];
            i++;
        }

        k++;
    }

    if (j == right.size()) {
        while (i < left.size()) {
            vec[k] = left[i];
            i++;
            k++;
        }
    }
}

void mergeSort(std::vector<Item> & vec, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(vec, l, m);
        mergeSort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}

int main() {
    int count;
    std::cin >> count;

    std::vector<Item> vec(count);

    int id;
    int result;

    for (int i = 0; i < count; ++i) {
        std::cin >> id;
        std::cin >> result;

        vec[i] = std::make_pair(id, result);
    }

    mergeSort(vec, 0, vec.size() - 1);

    for (int i = 0; i < count; ++i) {
        std::cout << vec[i].first << " " << vec[i].second << std::endl;
    }

    return 0;
}

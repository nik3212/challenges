/*

1203. Scientific Conference

Time limit: 1.0 second
Memory limit: 64 MB

Functioning of a scientific conference is usually divided into several simultaneous sections. For example, there may be a section on parallel computing, a section on visualization, a section on data compression, and so on.
Obviously, simultaneous work of several sections is necessary in order to reduce the time for scientific program of the conference and to have more time for the banquet, tea-drinking, and informal discussions. However, it is possible that interesting reports are given simultaneously at different sections.
A participant has written out the time-table of all the reports which are interesting for him. He asks you to determine the maximal number of reports he will be able to attend.

Input

The first line contains the number 1 ≤ N ≤ 100000 of interesting reports. Each of the next N lines contains two integers Ts and Te separated with a space (1 ≤ Ts < Te ≤ 30000). These numbers are the times a corresponding report starts and ends. Time is measured in minutes from the beginning of the conference.

Output

You should output the maximal number of reports which the participant can attend. The participant can attend no two reports simultaneously and any two reports he attends must be separated by at least one minute. For example, if a report ends at 15, the next report which can be attended must begin at 16 or later.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;

int count_of_conferences(std::vector<Segment>& segments) {
    std::sort(segments.begin(), segments.end(), [](const std::pair<int, int>& x, const std::pair<int, int>& y) {
        return (x.second - y.second) < 0;
    });


    int max = 0;
    int count = 0;

    for (size_t i = 0; i < segments.size(); ++i) {
        if (segments[i].first <= max) {
            continue;
        }

        max = segments[i].second;
        count++;
    }

    return count;
}

int main() {
    size_t size;
    std::cin >> size;

    std::vector<Segment> segments(size);

    for (auto& s: segments) {
        std::cin >> s.first >> s.second;
    }

    std::cout << count_of_conferences(segments) << std::endl;

    return 0;
}

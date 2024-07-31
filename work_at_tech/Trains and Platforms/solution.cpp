/*

Trains and Platforms

You are given the arrival and departure times for n trains at a railway station. Find the minimum number of platforms the railway station needs so that none of the trains have to wait.

The time is given in minutes from midnight. All trains have departures on the same day.

*/

/* This is the Train class definition
class Train {
public:
    int arrival, departure;
    Train(int arrival, int departure) {
        this->arrival = arrival;
        this->departure = departure;
    }
};
*/

int minPlatforms(vector<Train*> &trains) {
    int n = trains.size();
    int res = 0;
    int p = 0;

    int m = trains[0]->departure;
    for (int i = 1; i < n; ++i) {
        m = std::max(m, trains[i]->departure);
    }

    std::vector<int> v(m + 2, 0);

    for (int i = 0; i < n; ++i) {
        v[trains[i]->arrival]++;
        v[trains[i]->departure + 1]--;
    }

    for (int i = 0; i <= m + 1; ++i) {
        p += v[i];
        res = std::max(res, p);
    }

    return res;
}
/*

Median of Row-wise Sorted Matrix

Given an n*m matrix which is sorted row-wise, you need to find the median of the matrix.

Median of a group of numbers is the middle element after they are sorted. Both n and m are guaranteed to be odd numbers, therefore there’s only one middle number.

*/

int binary_search(std::vector<int> &v, int x) {
    int lo = 0;
    int hi = v.size() - 1;
    
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        
        if (v[m] <= x) {
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    
    return lo;
}

int count(std::vector<std::vector<int>> &v, int n, int m, int x) {
    int res = 0;
    
    for (int i = 0; i < n; ++i) {
        res += binary_search(v[i], x);
    }
    
    return res;
}

int median(std::vector<std::vector<int>> &v, int n, int m) {
    int lo = v[0][0];
    int hi = v[0][0];

    for (int i = 0; i < n; ++i) {
        lo = std::min(lo, v[i][0]);
        hi = std::max(hi, v[i][m - 1]);
    }
    
    int r = (n * m) / 2;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int e = count(v, n, m, mid);
        
        if (e <= r) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    return lo;
}

int calculateMedianOfMatrix(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    return median(matrix, n, m);
}

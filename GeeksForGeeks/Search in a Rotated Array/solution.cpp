/*

Search in a Rotated Array

Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A. The whole array A is given as the range to search.

*/

class Solution{
    private:
        int binary_search(int A[], int l, int r, int key) {
            while (l <= r) {
                int m = (l + r) / 2;
                
                if (A[m] == key) {
                    return m;
                }
                
                if (A[m] < key) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            
            return -1;
        } 
    public:
    int search(int A[], int l, int h, int key){
        int n = h;

        while (l <= h) {
            int m = (l + h) / 2;
            
            if (A[m] > A[n]) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        
        if (A[n] < key) {
            return binary_search(A, 0, l - 1, key);
        } else {
            return binary_search(A, l, n, key);
        }
    }
};
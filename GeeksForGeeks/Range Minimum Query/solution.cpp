/*

Range Minimum Query

Given an array A[ ] and its size N your task is to complete two functions  a constructST  function which builds the segment tree  and a function RMQ which finds range minimum query in a range [a,b] of the given array.

Input:
The task is to complete two functions constructST and RMQ.
The constructST function builds the segment tree and takes two arguments the array A[ ] and the size of the array N.
It returns a pointer to the first element of the segment tree array.
The RMQ function takes 4 arguments the first being the segment tree st constructed, second being the size N and then third and forth arguments are the range of query a and b. The function RMQ returns the min of the elements in the array from index range a and b. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function RMQ should return the min element in the array from range a to b.

*/

void build(int arr[], int tree[], int v, int l, int r) {
    if (l == r) {
        tree[v] = arr[l];
        return;
    }
    
    int m = (l + r) / 2;
    
    build(arr, tree, 2 * v + 1, l, m);
    build(arr, tree, 2 * v + 2, m + 1, r);
    
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
}

/* The functions which builds the segment tree */
int *constructST(int arr[], int n) {
    int *tree = new int[4 * n + 1];
    build(arr, tree, 0, 0, n - 1);
    return tree;
}

int min_tree_element(int st[], int parent, int start, int end, int a, int b) {
    if (a <= start && end <= b) {
        return st[parent];
    }

    if (b < start || end < a) {
        return INT_MAX;
    }
    
    int m = (start + end) / 2;
    
    return min(
        min_tree_element(st, 2 * parent + 1, start, m, a, b),
        min_tree_element(st, 2 * parent + 2, m + 1, end, a, b)
    );
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
    return min_tree_element(st, 0, 0, n - 1, a, b);
}
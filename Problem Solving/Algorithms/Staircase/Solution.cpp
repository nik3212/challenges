/*

Consider a staircase of size n = 4:

   #
  ##
 ###
####

Observe that its base and height are both equal to , and the image is drawn using # symbols and spaces. The last line is not preceded by any spaces.

Write a program that prints a staircase of size .

Function Description

Complete the staircase function in the editor below. It should print a staircase as described above.

staircase has the following parameter(s):

n: an integer
Input Format

A single integer, , denoting the size of the staircase.

Constraints

0 < n <= 100

Output Format

Print a staircase of size  using # symbols and spaces.

Note: The last line must have  spaces in it.

Sample Input

6 

Sample Output

     #
    ##
   ###
  ####
 #####
######

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (n - i - 1 <= j) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}

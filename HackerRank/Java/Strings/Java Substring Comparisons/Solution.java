/*

Lexicographical Order, also known as alphabetic or dictionary order, orders characters as follows: 

A < B < ... < Y < Z < a < b < ... < y < z

For example, ball < cat, dog < dorm, Happy < happy, Zoo < ball.

A substring of a string is a contiguous block of characters in the string. For example, the substrings of abc are a, b, c, ab, bc, and abc.

Given a string, s, and an integer, k, complete the function so that it finds the lexicographically smallest and largest substrings of length k.

Input Format

The first line contains a string denoting s. 
The second line contains an integer denoting k.

Constraints

1 <= |s| <= 1000
s consists of English alphabetic letters only (i.e., [a-zA-Z]).

Output Format

Return the respective lexicographically smallest and largest substrings as a single newline-separated string.

Sample Input 0

welcometojava
3

Sample Output 0

ava
wel

*/

import java.util.Scanner;

public class Solution {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = s.substring(0, k);
        String largest = s.substring(0, k);
        
        for (int i = 1; i < s.length() - k + 1; ++i) {
            String curr = s.substring(i, i + k);
            if (curr.compareTo(smallest) < 0) {
                smallest = curr;
            }

            if (curr.compareTo(largest) > 0) {
                largest = curr;
            }
        }

        return smallest + "\n" + largest;
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        System.out.println(getSmallestAndLargest(s, k));
    }
}
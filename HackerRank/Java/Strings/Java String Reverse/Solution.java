/*

Given a string A, print Yes if it is a palindrome, print No otherwise.

Constraints

A will consist at most 50 lower case english letters.

Sample Input

madam

Sample Output

Yes

*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.next();

        System.out.println(A.equals( new StringBuilder(A).reverse().toString()) 
    ? "Yes" : "No");
    }
}
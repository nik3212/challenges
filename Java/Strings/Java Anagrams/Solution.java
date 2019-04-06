/*

Two strings, a and b, are called anagrams if they contain all the same characters in the same frequencies. For example, the anagrams of CAT are CAT, ACT, TAC, TCA, ATC, and CTA.

Complete the function in the editor. If a and b are case-insensitive anagrams, print "Anagrams"; otherwise, print "Not Anagrams" instead.

Input Format

The first line contains a string denoting a. 
The second line contains a string denoting b.

Constraints

1 <= length(a), length(b) <= 50
String a and b consist of English alphabetic characters 
The comparison should NOT be case sensitive.

Output Format

Print "Anagrams" if a and b are case-insensitive anagrams of each other; otherwise, print "Not Anagrams" instead.

Sample Input 0

anagram
margana

Sample Output 0

Anagrams

Explanation 0

Character   Frequency: anagram  Frequency: margana
A or a              3                   3
G or g              1                   1
N or n              1                   1
M or m              1                   1
R or r              1                   1

The two strings contain all the same letters in the same frequencies, so we print "Anagrams".

Sample Input 1

anagramm
marganaa

Sample Output 1

Not Anagrams

*/

import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        char[] first = a.toLowerCase().toCharArray(); 
        char[] second = b.toLowerCase().toCharArray();
   
        if (first.length != second.length) {
            return false;
        }

        int[] counts = new int[26]; 

        for (int i = 0; i < first.length; ++i) {
            counts[first[i] - 97]++;
        }

        for (int i = 0; i < second.length; ++i) {
            if (counts[second[i] - 97] == 0) {
                return false;
            }
            counts[second[i] - 97]--;
        }

        return true;
    }

  public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}

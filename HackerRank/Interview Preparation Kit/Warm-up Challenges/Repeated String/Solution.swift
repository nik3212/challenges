/*

Lilah has a string, s, of lowercase English letters that she repeated infinitely many times.

Given an integer, n, find and print the number of letter a's in the first n letters of Lilah's infinite string.

For example, if the string s = 'abcac' and n = 10, the substring we consider is abcacabcac, the first 10 characters of her infinite string. There are 4 occurrences of a in the substring.

Function Description

Complete the repeatedString function in the editor below. It should return an integer representing the number of occurrences of a in the prefix of length n in the infinitely repeating string.

repeatedString has the following parameter(s):

s: a string to repeat
n: the number of characters to consider

Input Format

The first line contains a single string, s. 
The second line contains an integer, n.

Constraints

1 <= |s| <= 100
1 <= n <= 10^12

For 25% of the test cases, n <= 10^6.

Output Format

Print a single integer denoting the number of letter a's in the first n letters of the infinite string created by repeating s infinitely many times.

Sample Input 0

aba
10

Sample Output 0

7

Explanation 0 

The first n = 10 letters of the infinite string are abaabaabaa. Because there are 7 a's, we print 7 on a new line.

Sample Input 1

a
1000000000000

Sample Output 1

1000000000000

Explanation 1

Because all of the first n = 1000000000000 letters of the infinite string are a, we print 1000000000000 on a new line.

*/

import Foundation

extension String {
  subscript (i: Int) -> Character {
    return self[index(startIndex, offsetBy: i)]
  }
}

// Complete the repeatedString function below.
func repeatedString(s: String, n: Int) -> Int {
    var count = 0
    var k = 0
    for c in s {
        if c == "a" {
            count += 1
        }
    }
    count *= n / s.count
    k = n % s.count
    if k != 0 {
        for i in 0..<k {
            if s[i] == "a" {
                count += 1
            }
        }
    }
    return count
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let s = readLine() else { fatalError("Bad input") }

guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

let result = repeatedString(s: s, n: n)

fileHandle.write(String(result).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)

/*

Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each of the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in your array.

For example, the length of your array of zeros n = 10. Your list of queries is as follows:

    a b k
    1 5 3
    4 8 7
    6 9 1
Add the values of k between the indices a and b inclusive:

index->  1 2 3  4  5 6 7 8 9 10
    [0,0,0, 0, 0,0,0,0,0, 0]
    [3,3,3, 3, 3,0,0,0,0, 0]
    [3,3,3,10,10,7,7,7,0, 0]
    [3,3,3,10,10,8,8,8,1, 0]

The largest value is 10 after all operations are performed.

Function Description

Complete the function arrayManipulation in the editor below. It must return an integer, the maximum value in the resulting array.

arrayManipulation has the following parameters:

n - the number of elements in your array
queries - a two dimensional array of queries where each queries[i] contains three integers, a, b, and k.

Input Format

The first line contains two space-separated integers n and m, the size of the array and the number of operations. 
Each of the next m lines contains three space-separated integers a, b and k, the left index, right index and summand.

Constraints

3 <= n <= 10^7
1 <= m <= 2 * 10^5
1 <= a <= b <= n
0 <= k <= 10^9

Output Format

Return the integer maximum value in the finished array.

Sample Input

5 3
1 2 100
2 5 100
3 4 100

Sample Output

200

*/

import Foundation

// Complete the arrayManipulation function below.
func arrayManipulation(n: Int, queries: [[Int]]) -> Int {
    var arr: [Int] = Array(repeating: 0, count: n + 1)

    for q in queries {
        var a = q[0]
        var b = q[1]
        var k = q[2]

        arr[a] += k

        if b + 1 <= n {
            arr[b + 1] -= k;
        }
    }

    var max = 0
    var tmp = 0

    for i in 0...n {
        tmp += arr[i]
        if tmp > max {
            max = tmp
        }
    }

    return max
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let nmTemp = readLine() else { fatalError("Bad input") }
let nm = nmTemp.split(separator: " ").map{ String($0) }

guard let n = Int(nm[0].trimmingCharacters(in: .whitespacesAndNewlines))
else { fatalError("Bad input") }

guard let m = Int(nm[1].trimmingCharacters(in: .whitespacesAndNewlines))
else { fatalError("Bad input") }

let queries: [[Int]] = AnyIterator{ readLine() }.prefix(m).map {
    let queriesRow: [Int] = $0.split(separator: " ").map {
        if let queriesItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
            return queriesItem
        } else { fatalError("Bad input") }
    }

    guard queriesRow.count == 3 else { fatalError("Bad input") }

    return queriesRow
}

guard queries.count == m else { fatalError("Bad input") }

let result = arrayManipulation(n: n, queries: queries)

fileHandle.write(String(result).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)

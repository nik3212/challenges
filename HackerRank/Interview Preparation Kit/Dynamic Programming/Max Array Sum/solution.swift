/*

Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.

For example, given an array arr = [-2, 1, 3, -4, 5] we have the following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
Our maximum subset sum is 8.

Function Description

Complete the maxSubsetSum function in the editor below. It should return an integer representing the maximum subset sum for the given array.

maxSubsetSum has the following parameter(s):

* arr: an array of integers

Input Format

The first line contains an integer, n.
The second line contains n space-separated integers arr[i].

Constraints

1 <= n <= 10^5
-10^4 <= arr[i] <= 10^4

Output Format

Return the maximum sum described in the statement.

*/


import Foundation

// Complete the maxSubsetSum function below.
func maxSubsetSum(arr: [Int]) -> Int {
    var incl = arr[0]
    var excl = 0

    for i in arr[1...] {
        let tmp = max(incl, excl)
        incl = i + excl
        excl = tmp
    }

    return max(incl, excl)
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let arrTemp = readLine() else { fatalError("Bad input") }
let arr: [Int] = arrTemp.split(separator: " ").map {
    if let arrItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
        return arrItem
    } else { fatalError("Bad input") }
}

guard arr.count == n else { fatalError("Bad input") }

let res = maxSubsetSum(arr: arr)

fileHandle.write(String(res).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)

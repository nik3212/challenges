/*

Consider an array of integers, arr = [arr[0], arr[1], ..., arr[n - 1]]. We define the absolute difference between two elements, a[i] and a[j] (where i != j), to be the absolute value of a[i] - a[j].

Given an array of integers, find and print the minimum absolute difference between any two elements in the array. For example, given the array arr = [-2, 2, 4] we can create 3 pairs of numbers: [-2, 2], [-2, 4] and [2, 4]. The absolute differences for these pairs are |(-2) - 2| = 4, |(-2) - 4| = 6 and |2 - 4| = 2. The minimum absolute difference is 2.

Function Description

Complete the minimumAbsoluteDifference function in the editor below. It should return an integer that represents the minimum absolute difference between any pair of elements.

minimumAbsoluteDifference has the following parameter(s):

* n: an integer that represents the length of arr
* arr: an array of integers

Input Format

The first line contains a single integer n, the size of arr.
The second line contains n space-separated integers arr[i].

Constraints

* 2 <= n <= 10^5
* -10^9 <= arr[i] <= 10^9

Output Format

Print the minimum absolute difference between any two elements in the array.

*/

import Foundation

// Complete the minimumAbsoluteDifference function below.
func minimumAbsoluteDifference(arr: [Int]) -> Int {
    let nums = arr.sorted(by: <)
    var min = Int.max

    for i in 0..<nums.count - 1 {
        let diff = abs(nums[i] - nums[i + 1])
        min = (min > diff) ? diff : min
    }

    return min
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

let result = minimumAbsoluteDifference(arr: arr)

fileHandle.write(String(result).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)

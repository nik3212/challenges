/*

It's New Year's Day and everyone's in line for the Wonderland rollercoaster ride! There are a number of people queued up, and each person wears a sticker indicating their initial position in the queue. Initial positions increment by 1 from 1 at the front of the line to n at the back.

Any person in the queue can bribe the person directly in front of them to swap positions. If two people swap positions, they still wear the same sticker denoting their original places in line. One person can bribe at most two others. For example, if n = 8 and Person 5 bribes Person 4, the queue will look like this: 1, 2, 3, 5, 4, 6, 7, 8.

Fascinated by this chaotic queue, you decide you must know the minimum number of bribes that took place to get the queue into its current state!

Function Description

Complete the function minimumBribes in the editor below. It must print an integer representing the minimum number of bribes necessary, or Too chaotic if the line configuration is not possible.

minimumBribes has the following parameter(s):

q: an array of integers

Input Format

The first line contains an integer , the number of test cases.

Each of the next  pairs of lines are as follows: 
- The first line contains an integer , the number of people in the queue 
- The second line has  space-separated integers describing the final state of the queue.

Constraints

1 <= t <= 10
1 <= n <= 10^5

Subtasks

For 60% score 1 <= n <= 10^3 
For 100% score 1 <= n <= 10^5

Output Format

Print an integer denoting the minimum number of bribes needed to get the queue into its final state. Print Too chaotic if the state is invalid, i.e. it requires a person to have bribed more than  people.

Sample Input

2
5
2 1 5 3 4
5
2 5 1 3 4

Sample Output

3
Too chaotic

*/

import Foundation

// Complete the minimumBribes function below.
func minimumBribes(q: [Int]) -> Void {
    var count = 0
    
    for i in (0..<q.count).reversed() {
        if q[i] - (i + 1) > 2 {
            print("Too chaotic")
            return
        } else {
            var j = max(0, q[i] - 2)
            while (j < i) {
                if q[j] > q[i] {
                    count += 1
                }
                j += 1
            }
        }
    }
    
    print(count)
}

guard let t = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

for tItr in 1...t {
    guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
    else { fatalError("Bad input") }

    guard let qTemp = readLine() else { fatalError("Bad input") }
    let q: [Int] = qTemp.split(separator: " ").map {
        if let qItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
            return qItem
        } else { fatalError("Bad input") }
    }

    guard q.count == n else { fatalError("Bad input") }

    minimumBribes(q: q)
}

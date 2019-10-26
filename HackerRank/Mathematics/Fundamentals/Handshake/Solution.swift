/*

At the annual meeting of Board of Directors of Acme Inc, every one starts shaking hands with everyone else in the room. Given the fact that any two persons shake hand exactly once, Can you tell the total count of handshakes?

Input Format 
The first line contains the number of test cases T, T lines follow. 
Each line then contains an integer N, the total number of Board of Directors of Acme.

Output Format

Print the number of handshakes for each test-case in a new line.

Constraints

1 <= T <= 1000 
0 < N < 10^6

Sample Input

2
1
2

Sample Output

0
1

Explanation

Case 1 : The lonely board member shakes no hands, hence 0. 
Case 2 : There are 2 board members, 1 handshake takes place.

*/

import Foundation

/*
 * Complete the handshake function below.
 */
func handshake(n: Int) -> Int {
	if n == 0 || n == 1 {
		return 0
	}

	return n * (n - 1) / 2
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let t = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

for tItr in 1...t {
    guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
    else { fatalError("Bad input") }

    let result = handshake(n: n)

    fileHandle.write(String(result).data(using: .utf8)!)
    fileHandle.write("\n".data(using: .utf8)!)
}

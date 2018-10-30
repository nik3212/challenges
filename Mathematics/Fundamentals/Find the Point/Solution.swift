/*

Consider two points, p =  (p_x, p_y) and q = (q_x, q_y). We consider the inversion or point reflection, r = (r_x, r_y), of point p across point q to be a 180 rotation of point p around q.

Given n sets of points p and q, find r for each pair of points and print two space-separated integers denoting the respective values of r_x and r_y on a new line.

Input Format

The first line contains an integer, n, denoting the number of sets of points. 
Each of the n subsequent lines contains four space-separated integers describing the respective values of p_x, p_y, q_x, and q_y defining points p = (p_x, p_y) and q = (q_x, q_y).

Constraints

1 <= n <= 15
-100 <= p_x, p_y, q_x, q_y <= 100

Output Format

For each pair of points p and q, print the corresponding respective values of r_x and r_y as two space-separated integers on a new line.

Sample Input

2
0 0 1 1
1 1 2 2
Sample Output

2 2
3 3

*/

import Foundation

/*
 * Complete the findPoint function below.
 */
func findPoint(px: Int, py: Int, qx: Int, qy: Int) -> [Int] {
    var res = [Int]()
    
    var x = qx + (px - qx) * (-1)
    var y = qy + (py - qy) * (-1)
    
    res.append(x)
    res.append(y)
    
    return res
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

for nItr in 1...n {
    guard let pxPyQxQyTemp = readLine() else { fatalError("Bad input") }
    let pxPyQxQy = pxPyQxQyTemp.split(separator: " ").map{ String($0) }

    guard let px = Int(pxPyQxQy[0].trimmingCharacters(in: .whitespacesAndNewlines))
    else { fatalError("Bad input") }

    guard let py = Int(pxPyQxQy[1].trimmingCharacters(in: .whitespacesAndNewlines))
    else { fatalError("Bad input") }

    guard let qx = Int(pxPyQxQy[2].trimmingCharacters(in: .whitespacesAndNewlines))
    else { fatalError("Bad input") }

    guard let qy = Int(pxPyQxQy[3].trimmingCharacters(in: .whitespacesAndNewlines))
    else { fatalError("Bad input") }

    let result = findPoint(px: px, py: py, qx: qx, qy: qy)

    fileHandle.write(result.map{ String($0) }.joined(separator: " ").data(using: .utf8)!)
    fileHandle.write("\n".data(using: .utf8)!)
}

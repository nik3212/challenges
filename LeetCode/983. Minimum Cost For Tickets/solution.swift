/*

983. Minimum Cost For Tickets

In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

* a 1-day pass is sold for costs[0] dollars;
* a 7-day pass is sold for costs[1] dollars;
* a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

*/

class Solution {
    func mincostTickets(_ days: [Int], _ costs: [Int]) -> Int {
        let daysSet: Set<Int> = Set(days)
        var results = Array(repeating: -1, count: 366)
        
        results[0] = 0
        
        for day in 1..<results.count {
            if daysSet.contains(day) {
                let answer = min(results[day - 1] + costs[0], results[max(0, day - 7)] + costs[1])
                results[day] = min(answer, results[max(0, day - 30)] + costs[2])
            } else {
                results[day] = results[day - 1]
            }
        }

        return results[365]
    }
}
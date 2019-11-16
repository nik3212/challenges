/*

2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var p = l1
        var q = l2
        var carry = 0
        var node: ListNode?
        var head: ListNode?

        while p != nil || q != nil {
            let value = (p?.val ?? 0) + (q?.val ?? 0) + carry
            let digit = value % 10
            carry = value / 10

            p = p?.next
            q = q?.next

            let newNode = ListNode(digit)
            node?.next = newNode
            node = newNode

            if head == nil {
                head = newNode
            }
        }

        if carry > 0 {
            let newNode = ListNode(carry)
            node?.next = newNode
            node = newNode
        }

        return head
    }
}
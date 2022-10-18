import Foundation
 
/*

 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

 https://leetcode.com/problems/two-sum/

*/

var array = [1, 4, 45, 6, 10, 8 ]
let sum = 16

// Simple solution using loop
func solution1() {
    for i in 0..<(array.count - 1) {
        for j in (i+1)..<(array.count) {
            if (sum == (array[i] + array[j])) {
                print("Solution 1")
                print(array[i], array[j])
            }
        }
    }
}

/// Two pointer solution
func solution2() {
    array.sort()
    print(array)
    var l = 0
    var r = (array.count - 1)
    while (l < r) {
        if (array[l] + array[r] == sum) {
            print("Solution 2")
            print(array[l], array[r])
            break
        } else if (array[l] + array[r] < sum) {
            l+=1
        } else {
            r-=1
        }
    }
}

/// Hashing method
func solution3() {
    print(array)
    print("Solution 3")
    var setData = Set<Int>()
    for i in 0..<(array.count - 1) {
        let temp = sum - array[i]
        if (setData.contains(temp)) {
            print(array[i] , temp)
        }
        setData.insert(array[i])
    }
}

solution1()
solution2()
solution3()

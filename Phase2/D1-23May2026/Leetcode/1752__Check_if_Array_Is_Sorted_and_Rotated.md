# Problem: Check if Array Is Sorted and Rotated

## Approach Analysis & Intent Identification

### Hints & Intent Discovered in the Problem
- **Straightforward Goal:** We need to find out if the given array was initially sorted in non-decreasing order and then rotated at some pivot point.
- **Mathematical Definition:** The problem description defines rotation as: `B[i] == A[(i+x) % A.length]`. This explicit equation indicates that the array undergoes a **left rotation** by $x$ positions.
- **Constraints Analysis:**

```text
  1 <= nums.length <= 100
  1 <= nums[i] <= 100
```

The constraints given for this problem are exceptionally small. This allows an O(N^2) simulation approach to pass effortlessly within runtime limits, but it also invites us to hunt down an optimized O(N) linear-time alternative.

## Approach 1: Simulation (Brute Force)

Intuition & Strategy
The core idea is to simulate the rotation process step-by-step to see if the array ever lands back into its original, perfectly sorted state. We generate a benchmark reference array which is a completely sorted duplicate of the input. We then simulate a left rotation on the input array element-by-element up to N times. (Rotating more than N times is redundant as it resets the cycle). If at any point during these individual shifts the input array matches our reference array exactly, we have found a match and can confidently return true.


## Simulation Walkthrough

Input Array (nums): [3, 4, 5, 1, 2]
Reference Array (ref_arr sorted): [1, 2, 3, 4, 5]

We cycle through the rotations:
Initial State: Compare [3, 4, 5, 1, 2] with [1, 2, 3, 4, 5] ➔ No match.
Left Rotation 1: Compare [4, 5, 1, 2, 3] with [1, 2, 3, 4, 5] ➔ No match.
Left Rotation 2: Compare [5, 1, 2, 3, 4] with [1, 2, 3, 4, 5] ➔ No match.
Left Rotation 3: Compare [1, 2, 3, 4, 5] with [1, 2, 3, 4, 5] ➔ Match Found!

Since a complete match is found with the sorted reference array at rotation 3, the loop terminates early and returns true.

## Complexity Analysis

Time Complexity: O(N^2)

Sorting the reference array initially takes O(NlogN) time. The simulation loop runs N times. Inside this loop, evaluating vector equality via nums == ref_arr takes linear O(N) time, and executing std::rotate also takes linear O(N) time. This establishes the inner loop complexity at O(N)+O(N)=O(N). Multiplying this by the N outer loop iterations yields O(N×N)=O(N^2) operations.
Since N^2 grows at a vastly dominant rate compared to NlogN, the lower-order term is dropped, making the overall time complexity O(N^2).

Space Complexity: O(N)
This approach requires allocating an independent vector ref_arr of size N to store and sort the baseline comparison numbers.


## CODE

```
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(std::vector<int>& nums) {
        // Create an independent baseline copy and sort it
        std::vector<int> ref_arr = nums;
        std::sort(ref_arr.begin(), ref_arr.end());
        
        // Rotate up to N times and compare states
        for (int i = 0; i < nums.size(); i++) {
            if (nums == ref_arr) return true;
            
            // Perform a left rotation by 1 element
            std::rotate(nums.begin(), nums.begin() + 1, nums.end());
        }
        return false;
    }
};
```

## Approach 2: Drop Counting (Optimized)
The goal here is to eliminate the reference array entirely and see if we can solve this in a single pass. Let's look closely at a valid sorted and rotated array to see what patterns emerge.

## Visualizing the Cycle
Take the example nums = [3, 4, 5, 1, 2]. If we write out every possible left rotation, the entire cycle looks like this:

Initial State:   [3, 4, 5, 1, 2]
Left Rotation 1: [4, 5, 1, 2, 3]
Left Rotation 2: [5, 1, 2, 3, 4] 
Left Rotation 3: [1, 2, 3, 4, 5]  <-- Perfectly Sorted Benchmark
Left Rotation 4: [2, 3, 4, 5, 1] 
Left Rotation 5: [3, 4, 5, 1, 2]  <-- Back to the start

## The "Single Drop" Rule
Notice that no matter how many times a sorted array is rotated, there is only ever one single point where a number is strictly greater than the next number (nums[i] > nums[i+1]). Think of it like a staircase. A sorted array only goes up. When you rotate it, you create exactly one cliff or "drop-off" point where the sequence falls from the highest number back to the lowest number.

From this, we can derive a clear rule:
- If an array has 0 or 1 drop-off point, it is a valid sorted and rotated array.
- If it has 2 or more drop-off points, it is completely scrambled and impossible to fix via rotation.

## Why We Must Check the "Corner"
We have to make sure we don't accidentally treat the array as a straight line. Because a rotation wraps the end of the array back to the front, we have to check the transition from the very last element back to the very first element.
Consider a broken example like [2, 1, 3, 4].

If we only look at it in a straight line from left to right, there is only one drop-off (2 > 1). If we stopped searching at the end of the index array, we would incorrectly say this is a valid rotated array.

However, if we look at it like a circular loop, the last element (4) connects back to the first element (2). Because 4 > 2, that creates a second drop-off point, which correctly alerts our code that the array is invalid.

To check this final boundary seamlessly without writing extra code, we use the modulo operator: (i + 1) % n. When i is at the last index, this formula beautifully wraps our comparison right back to index 0.

## Complexity Analysis
Time Complexity: O(N), We iterate through the array exactly once in a single loop.
Space Complexity: O(1),  We do not copy the array or use a reference array. We only track a simple integer counter in memory.

## Code

```
class Solution {
public:
    bool check(vector<int>& nums) {
        int count_drops = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Compare the current element to the next one, wrapping around at the end
            if (nums[i] > nums[(i + 1) % n]) {
                count_drops++;
            }
        }
        
        // A valid array will have either 0 drops (already sorted) or 1 drop (rotated)
        return count_drops <= 1;
    }
};
```

## Take away from this problem:

- If we have a sorted array which is rotated, then that would just have only 1 drop point (point where arr[i] > arr[(i+1)%n]). 
- We should check the corner case element also hold this rule. 

## NEW LEARNINGS:

- Learning 1:

```
std::rotate(forward_iterator first, forward_iterator middle, forward_iterator last);
```

The Three Parameters Explained
- first: The start of the range you want to rotate.
- middle: The exact element that you want to become the new first element.
- last: The end of the range (remember, in C++, this is exclusive, meaning it points just past the last element).


- Learning 2:

```
int old_val = exchange(variable, new_value);
```

Exchange is a built-in C++ STL function, which replaces the varibale with the new_value and also give the old value that was present in the variable.

```
int a = 10;
int old_val = exchange(a, 20);
print(old_val) -> Prints 10.
print(a) -> Prints 20.
```


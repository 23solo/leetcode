* 2 Sum
  - Sort the array, now take two pointers one at the start and other at the end
  - Now if sum is greater than target decrement right pointer.
  - If sum is less than target then increment left pointer.
  - Repeat till sum == ans 
* 4 Sum 
  - The steps are as follows:

  - First, we will sort the entire array.
  - We will use a loop(say i) that will run from 0 to n-1. This i will represent one of the fixed pointers. In each iteration, this value will be fixed for all different values of the rest of the 3 pointers. Inside the loop, we will first check if the current and the previous element is the same and if it is we will do nothing and continue to the next value of i.
  - After checking inside the loop, we will introduce another fixed pointer j(runs from i+1 to n-1) using another loop. Inside this second loop, we will again check for duplicate elements and only perform any further operation if the elements are different.
  - Inside the second loop, there will be 2 moving pointers i.e. k(starts from j+1) and l(starts from the last index). The pointer k will move forward and the pointer l will move backward until they cross each other while the value of i and j will be fixed.
  - Now we will check the sum i.e. nums[i]+nums[j]+nums[k]+nums[l].
  - If the sum is greater, then we need lesser elements and so we will decrease the value of l.
  - If the sum is lesser than the target, we need a bigger value and so we will increase the value of k. 
  - If the sum is equal to the target, we will simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l] into our answer and move the pointers k and l skipping the duplicate elements(i.e. by checking the adjacent elements while moving the pointers).
  - Finally, we will have a list of unique quadruplets.

* Longest Consecutive Sequence
  - We will first push all elements in the HashSet. Then we will run a for loop and check for any number(x) if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet. Using this we can calculate the length of the longest consecutive subsequence.

* Longest SubArray with 0 sum
  - First, let us initialize a variable say sum = 0 which stores the sum of elements traversed so far and another variable says max = 0 which stores the length of the longest subarray with sum zero.
  - Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as a key and its index as a value.
  - Now traverse the array, and add the array element to our sum. 
  - (i)  If sum = 0, then we can say that the subarray until the current index has a sum = 0, -   so we update max with the maximum value of (max, current_index+1)

  - (ii)  If the sum is not equal to zero then we check the hashmap if we’ve seen a subarray with this sum before

  - if HashMap contains sum -> this is where the above-discussed case occurs (subarray with equal sum), so we update our max 

  - else -> Insert (sum, current_index) into hashmap to store prefix sum until the current index

  - After traversing the entire array our max variable has the length of the longest substring having a sum equal to zero, so return max.

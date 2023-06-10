* Set Matrix 0
  - Approach (Using two extra arrays):

  - The steps are as follows:

  - First, we will declare two arrays: a row array of size N and a col array of size M and both are initialized with 0.
  - Then, we will use two loops(nested loops) to traverse all the cells of the matrix.
  - If any cell (i,j) contains the value 0, we will mark ith index of row array i.e. row[i] and jth index of col array col[j] as 1. It signifies that all the elements in the ith row and jth column will be 0 in the final matrix.
  - We will perform step 3 for every cell containing 0.
  - Finally, we will again traverse the entire matrix and we will put 0 into all the cells (i, j) for which either row[i] or col[j] is marked as 1.
  - Thus we will get our final matrix.

* Pascals Triangle
  - Approach:
  - The steps are as follows:
  - First, we will run a loop(say row) from 1 to n.
  - We will use a loop(say col) to iterate over each column i.e. from 1 to n. And inside the nested loops, we will do the following steps:
  - First, we will consider row-1 as n and col-1 as r.
  - After that, we will simply calculate the value of the combination using a loop. 
  - The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
  - Finally, we will add the element to a temporary list.
  - After calculating all the elements for all columns of a row, we will add the temporary list to our final answer list.
  - Finally, we will return the answer list.

* Next Permutation
  - The steps are the following:

  - Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
  - For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
  - To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
  - If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
  - So, in this case, we will reverse the whole array and will return it as our answer.
  - If a break-point exists:
  - Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
  - Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.

* Kadanes Algo
  - Intuition:
  - The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
  - Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.
  - Thus we can solve this problem with a single loop.
  - Approach:
  - The steps are as follows:
  - We will run a loop(say i) to iterate the given array.
  - Now, while iterating we will add the elements to the sum variable and consider the maximum one.
  - If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

* Sort 0 1 and 2

  - Algorithm / Intuition
  - This problem is a variation of the popular Dutch National flag algorithm. 
  - This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:
  - arr[0….low-1] contains 0. [Extreme left part]
  - arr[low….mid-1] contains 1.
  - arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
  - The middle part i.e. arr[mid….high] is the unsorted segment. So, hypothetically the array with different markers will look like the following:
  - In our case, we can assume that the entire given array is unsorted and so we will place the pointers accordingly. For example, if the given array is: [2,0,2,1,1,0], the array with the 3 pointers will look like the following:
  - Here, as the entire array is unsorted, we have placed the mid pointer in the first index and the high pointer in the last index. The low is also pointing to the first index as we have no other index before 0. Here, we are mostly interested in placing the ‘mid’ pointer and the ‘high’ pointer as they represent the unsorted part in the hypothetical array.
  - Now, let’s understand how the pointers will work to make the array sorted.

  - Approach:
  - The steps will be the following:
  - First, we will run a loop that will continue until mid <= high.
  - There can be three different values of mid pointer i.e. arr[mid]
  - If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
  - If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
  - If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.
  - In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.
  - Finally, our array should be sorted.

* Stock Buy & Sell

  - Intuition: We will linearly travel the array. We can maintain a minimum from the start of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

  - Approach:

  - Create a variable maxPro and store 0 initially.
  - Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
  - Run a for loop from 0 to n.
  - Update the minPrice if it is greater than the current element of the array
  - Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
  - Return the maxPro.

* Rotate Matrix
  - Algorithm / Intuition
  - Intuition: By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).
  - Approach:
  - Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
  - Step 2: Reverse each row of the matrix.

* Merge Overlapping Intervals
  - Approach:
  - The steps are as follows:

  - First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
  - After that, we will start traversing the array using a loop(say i) and insert the first element into our answer list(as the answer list is empty).
  - Now, while traversing we will face two different cases:
  - Case 1: If the current interval can be merged with the last inserted interval of the answer list:
  - In this case, we will update the end of the last inserted interval with the maximum(current interval’s end, last inserted interval’s end) and continue moving afterward. 
  - Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:
  - In this case, we will insert the current interval in the answer array as it is. And after this insertion, the last inserted interval of the answer list will obviously be updated to the current interval.
  - Thus the answer list will be updated with the merged intervals and finally, we will return the answer list.
  - Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our answer list.

* Merge two Sorted arrayy inplace
  - Approach:
  - The sizes of the given arrays are n(size of arr1[]) and m(size of arr2[]).

  - The steps are as follows:

  - We will declare two pointers i.e. left and right. The left pointer will point to the last index of the arr1[](i.e. Basically the maximum element of the array). The right pointer will point to the first index of the arr2[](i.e. Basically the minimum element of the array).
  - Now, the left pointer will move toward index 0 and the right pointer will move towards the index m-1. While moving the two pointers we will face 2 different cases like the following:
  - If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers to the next positions.
  - If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[] are containing correct elements.
  - Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain all bigger elements. Finally, we will sort the two arrays.

  - Optimal Approach 2 (Using gap method): 

  - This gap method is based on a sorting technique called shell sort. The intuition of this method is simple. 

  - Intuition: Similar to optimal approach 1, in this approach, we will use two pointers i.e. left and right, and swap the elements if the element at the left pointer is greater than the element at the right pointer. 

  - But the placing of the pointers will be based on the gap value calculated. The formula to calculate the initial gap is the following:

  - Initial gap = ceil((size of arr1[] + size of arr2[]) / 2)

  - Assume the two arrays as a single continuous array and initially, we will place the left pointer at the first index and the right pointer at the (left+gap) index of that continuous array.

  - Now, we will compare the elements at the left and right pointers and move them by 1 place each time after comparison. While comparing we will swap the elements if the element at the left pointer > the element at the right pointer. After some steps, the right pointer will reach the end and the iteration will be stopped.

  - After each iteration, we will decrease the gap and will follow the same procedure until the iteration for gap = 1 gets completed. Now, after each iteration, the gap will be the following:

  - gap = ceil( previous gap / 2)

  - The whole process will be applied to the imaginary continuous array constructed using arr1[] and arr2[].

  - Approach:

  - The steps are as follows:

  - First, assume the two arrays as a single array and calculate the gap value i.e. ceil((size of arr1[] + size of arr2[]) / 2).
  - We will perform the following operations for each gap until the value of the gap becomes 0:
  - Place two pointers in their correct position like the left pointer at index 0 and the right pointer at index (left+gap).
  - Again we will run a loop until the right pointer reaches the end i.e. (n+m). Inside the loop, there will be 3 different cases:
  - If the left pointer is inside arr1[] and the right pointer is in arr2[]: We will compare arr1[left] and arr2[right-n] and swap them if arr1[left] > arr2[right-n].
  - If both the pointers are in arr2[]: We will compare arr1[left-n] and arr2[right-n] and swap them if arr1[left-n] > arr2[right-n].
  - If both the pointers are in arr1[]: We will compare arr1[left] and arr2[right] and swap them if arr1[left] > arr2[right].
  - After the right pointer reaches the end, we will decrease the value of the gap and it will become ceil(current gap / 2). 
  - Finally, after performing all the operations, we will get the merged sorted array.

* Find Duplicate no. n+1
  - Initially, we have 2, then we got to the second index, we have 9, then we go to the 9th index, we have 1, then we go to the 1st index, we again have 5, then we go to the 5th index, we have 3, then we go to the 3rd index, we get 6, then we go to the 6th index, we get 8, then we go to the 8th index, we get 7, then we go to the 7th index and we get 9 and here cycle is formed.

  - Now initially, the slow and fast pointer is at the start, the slow pointer moves by one step, and the fast pointer moves by 2 steps.

  - The slow and fast pointers meet at 7. Now take the fast pointer and place it at the first element i.e 2 and move the fast and slow pointer both by 1 step. The point where they collide will be the duplicate number.

  - So 9 is the duplicate number.

  - Intuition: Since there is a duplicate number, we can always say that cycle will be formed.

  - The slow pointer moves by one step and the fast pointer moves by 2 steps and there exists a cycle so the first collision is bound to happen.
  - Let’s assume the distance between the first element and the first collision is a. So slow pointer has traveled a distance while fast(since moving 2 steps at a time) has traveled 2a distance. For slow and a fast pointer to collide 2a-a=a should be multiple of the length of cycle, Now we place a fast pointer to start. Assume the distance between the start and duplicate to be x. So now the distance between slow and duplicate shows also be x, as seen from the diagram, and so now fast and slow pointer both should move by one step.

* Repeat and Missing No.
  - Assume the repeating number to be X and the missing number to be Y.

  - The steps are as follows:

  - First, find out the values of S and Sn and then calculate S – Sn.
  - Then, find out the values of S2 and S2n and then calculate S2 – S2n.
  - After performing steps 1 and 2, we will be having the values of X + Y and X – Y. Now, by substitution of values, we can easily find the values of X and Y.

* Count inversions in an array (Merge Sort)
- Approach:
- The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just a one-line addition inside the merge() function. Inside the merge(), we need to add the number of pairs to the count when a[left] > a[right].

- The steps of the merge() function were the following:

- In the merge function, we will use a temp array to store the elements of the two sorted arrays after merging. Here, the range of the left array is low to mid and the range for the right half is mid+1 to high.
- Now we will take two pointers left and right, where left starts from low and right starts from mid+1.
- Using a while loop( while(left <= mid && right <= high)), we will select two elements, one from each half, and will consider the smallest one among the two. Then, we will insert the smallest element in the temp array. 
- After that, the left-out elements in both halves will be copied as it is into the temp array.
- Now, we will just transfer the elements of the temp array to the range low to high in the original array.
- Modifications in merge() and mergeSort(): 

- In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the merge().
- While comparing a[left] and a[right] in the 3rd step of merge(), if a[left] > a[right], we will simply add this line:
- cnt += mid-left+1 (mid+1 = size of the left half)
- Now, we will return this cnt from merge() to mergeSort(). 
- Inside mergeSort(), we will keep another counter variable that will store the final answer. With this cnt, we will add the answer returned from mergeSort() of the left half, mergeSort() of the right half, and merge().
- Finally, we will return this cnt, as our answer from mergeSort().

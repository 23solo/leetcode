* 2D Search
  - As it is sorted horizontally and vertically.
  - Start from the extreme end of first row, if element is less that means it'll be in that particular row only
  - As it is vertically sorted too all the elements below it will be greater so search for the element in that row on the left side
  - If it is greater then go below.

* x pow n
  - Initialize ans as 1.0  and store a duplicate copy of n i.e nn using to avoid overflow

  - Check if nn is a negative number, in that case, make it a positive number.

  - Keep on iterating until nn is greater than zero, now if nn is an odd power then multiply x with ans ans reduce nn by 1. Else multiply x with itself and divide nn by two.

  - Now after the entire binary exponentiation is complete and nn becomes zero, check if n is a negative value we know the answer will be 1 by and.

* Majority element n/2
  - We maintain a counter and the element, idea is if an element is present > n/2 times it means count of that element will cancel out all other elements count.
  - And at the end the counter will be 1 with the element present in `ele` variable.

* Majority element n/3
  - It's same as before but in this case we can have max 2 elements that can fullfill the criteria so now we maintain two counter and two variables instead of 1.

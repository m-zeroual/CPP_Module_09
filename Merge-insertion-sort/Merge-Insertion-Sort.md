# Merge-Insertion Sort

Merge-Insertion Sort is a hybrid sorting algorithm that combines the strengths of Merge Sort and Insertion Sort. It is particularly effective for sorting large datasets where the overhead of pure Merge Sort might be significant.

## Overview

Merge-Insertion Sort follows a divide-and-conquer approach like Merge Sort but switches to Insertion Sort for small subarrays. This combination helps in reducing the overall time complexity, making it efficient for a wide range of input sizes.




## Algorithm

1. **Merge Sort Phase:**
   - If the size of the array is larger than a certain threshold, perform the Merge Sort.
   - Divide the array into two halves.
   - Recursively sort each half using Merge-Insertion Sort.
   - Merge the sorted halves.

2. **Insertion Sort Phase:**
   - If the size of the array is smaller than or equal to the threshold, switch to Insertion Sort.
   - Use Insertion Sort to sort the small subarray.

## Time Complexity

- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

## Space Complexity

- O(n) additional space for the merging phase.

### Total Comparisons:

The total number of comparisons made during the sorting process is: **76**.

## Example
### Step-by-Step Execution
##### Initial Recursion:
- Rest: 939
- Pairs: [80 :102 ][650 :692][695 :967][130 :262][220 :335][47 :605][204 :483][406 :773][69 :284][495 :542]
#### First Merge Phase:
- Merging pairs while noting the remaining elements.
- Rest: NULL
- Merged: [80 102 :650 692][130 262 :695 967][220 335 :47 605][204 483 :406 773][69 284 :495 542]
#### Second Merge Phase:
- Further merging with remaining elements.
- Rest: 69 284 495 542
- Merged: [80 102 650 692 :130 262 695 967][220 335 47 605 :204 483 406 773]
#### Final Merge Phase:
- Completing the merge process.
- Rest: NULL
- Merged: [220 335 47 605 204 483 406 773 :80 102 650 692 130 262 695 967]
#### Reverse Phase (Final Merging Steps)
### Step 1:
- Input: [220 335 47 605 204 483 406 773 :80 102 650 692 130 262 695 967]
- Main Chain: 80 102 650 692 130 262 695 967
- Paned: 220 335 47 605 204 483 406 773
- Result: 220 335 47 605 204 483 406 773 80 102 650 692 130 262 695 967
### Step 2:
- Input: [220 335 47 605 :204 483 406 773 ][80 102 650 692 :130 262 695 967]
- Main Chain: 204 483 406 773 ,130 262 695 967
- Paned: 220 335 47 605 ,80 102 650 692 ,69 284 495 542
- Result: 69 284 495 542 220 335 47 605 80 102 650 692 204 483 406 773 130 262 695 967
### Step 3:
- Input: [69 284 :495 542 ][220 335 :47 605 ][80 102 :650 692 ][204 483 :406 773 ][130 262 :695 967]
- Main Chain: 495 542 ,47 605 ,650 692 ,406 773 ,695 967
- Paned: 69 284 ,220 335 ,80 102 ,204 483 ,130 262
- Result: 80 102 130 262 69 284 220 335 204 483 495 542 47 605 650 692 406 773 695 967
### Step 4:
- Input: [80 :102 ][130 :262 ][69 :284][220 :335][204 :483][495 :542 ][47 :605][650 :692][406 :773][695 :967]
- Main Chain: 102 ,262 ,284 ,335 ,483 ,542 ,605 ,692 ,773 ,967
- Paned: 80 ,130 ,69 ,220 ,204 ,495 ,47 ,650 ,406 ,695 ,939
- Result: 47 69 80 102 130 204 220 262 284 335 406 483 495 542 605 650 692 695 773 939 967
### Final Output
- The final sorted array is:
47 69 80 102 130 204 220 262 284 335 406 483 495 542 605 650 692 695 773 939 967

##### [simulation](https://github.com/m-zeroual/CPP_Module_09/blob/master/Merge-insertion-sort/Exemple/exemple)
## Conclusion

The Merge-Insertion Sort algorithm effectively sorted the input array through systematic merging and reversing, resulting in a completely ordered output with a detailed record of operations.




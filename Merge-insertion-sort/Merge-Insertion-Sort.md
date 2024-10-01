# Merge-Insertion Sort

Merge-Insertion Sort is a hybrid sorting algorithm that combines the strengths of Merge Sort and Insertion Sort. This method is particularly effective for sorting a wide range of datasets, adapting dynamically to the input's characteristics.

## Overview

Merge-Insertion Sort follows a two-phase approach:
1. **Merge Phase:** The algorithm initially divides the array into pairs and sorts these pairs using a merge-like operation.
2. **Insertion Phase:** After merging, it refines the sorted output using insertion sorting, especially beneficial for nearly sorted data.

## How Merge-Insertion Sort Works

1. **Initial Array:**
   The algorithm starts with an unsorted array:
   ```
   [80, 102, 650, 692, 967, 695, 130, 262, 220, 335, 605, 47, 204, 483, 773, 406, 284, 69, 542, 495, 939]
   ```

2. **First Recursion: Merging Pairs**
   - The array is divided into pairs:
     ```
     [80, 102], [650, 692], [967, 695], [130, 262], [220, 335], [47, 605], [204, 483], [406, 773], [69, 284], [495, 542]
     ```
   - Each pair is sorted:
     ```
     {80, 102}, {650, 692}, {695, 967}, {130, 262}, {220, 335}, {47, 605}, {204, 483}, {406, 773}, {69, 284}, {495, 542}
     ```

3. **Second Recursion: Merging Larger Groups**
   - The sorted pairs are merged into larger groups:
     ```
     {80, 102, 650, 692} - {130, 262, 695, 967} => {80, 102, 130, 262, 650, 692, 695, 967}
     ```

4. **Continue Merging:**
   - The merging continues until the entire array is sorted:
     ```
     Final Merged Output: {47, 69, 80, 102, 130, 204, 220, 262, 284, 335, 406, 483, 495, 542, 605, 650, 692, 695, 773, 939, 967}
     ```

5. **Insertion Sort Phase:**
   - After merging, the insertion sort phase refines the output, leading to the final sorted array.

## Example Breakdown

Using the provided data and results from the Merge-Insertion Sort:

1. **Recursive Merges:**
   ```
   >>>>> REC <<<<<
   rest = 939 
   [80 :102 ][650 :692 ][695 :967 ][130 :262 ][220 :335 ][47 :605 ][204 :483 ][406 :773 ][69 :284 ][495 :542 ]
   >>>>> REC <<<<<
   rest = 
   [80 102 :650 692 ][130 262 :695 967 ][220 335 :47 605 ][204 483 :406 773 ][69 284 :495 542 ]
   ```

2. **Further Merging:**
   ```
   >>>>> REV <<<<<
   [220 335 47 605 :80 102 650 692 130 262 695 967 ]
   ```

3. **Final Merged Output:**
   ```
   >>>>> REV <<<<<
   [80 :102 ][130 :262 ][69 :284 ][220 :335 ][204 :483 ][495 :542 ][47 :605 ][650 :692 ][406 :773 ][695 :967 ]
   main_chain : 47 69 80 102 130 204 220 262 284 335 406 483 495 542 605 650 692 695 773 939 967 
   ```

4. **Final Sorted Array:**
   ```
   47, 69, 80, 102, 130, 204, 220, 262, 284, 335, 406, 483, 495, 542, 605, 650, 692, 695, 773, 939, 967 
   ```

## Advantages

- Efficient for both small and large datasets.
- Adaptive to nearly sorted arrays due to the incorporation of Insertion Sort.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

# Merge-Insertion Sort

Merge-Insertion Sort is a hybrid sorting algorithm that combines the strengths of Merge Sort and Insertion Sort. This method is particularly effective for sorting a wide range of datasets, adapting dynamically to the input's characteristics.

## Overview (Step-by-Step)

## Random Numbers
- 80 102 650 692 967 695 130 262 220 335 605 47 204 483 773 406 284 69 542 495 939 

### Initial Recursion:

- **Rest:** 939  
- **Pairs:** `[80 :102 ][650 :692][695 :967][130 :262][220 :335][47 :605][204 :483][406 :773][69 :284][495 :542]`

### First Merge Phase:

- **Merging pairs while noting the remaining elements.**  
- **Rest:** NULL  
- **Merged:** `[80 102 :650 692][130 262 :695 967][220 335 :47 605][204 483 :406 773][69 284 :495 542]`

### Second Merge Phase:

- **Further merging with remaining elements.**  
- **Rest:** `69 284 495 542`  
- **Merged:** `[80 102 650 692 :130 262 695 967][220 335 47 605 :204 483 406 773]`

### Final Merge Phase:

- **Completing the merge process.**  
- **Rest:** NULL  
- **Merged:** `[220 335 47 605 204 483 406 773 :80 102 650 692 130 262 695 967]`

### Reverse Phase (Final Merging Steps):

**Reverse merging to complete the sorting.**

#### Step 1:

- **Input:** `[220 335 47 605 204 483 406 773 :80 102 650 692 130 262 695 967]`  
- **Main Chain:** `80 102 650 692 130 262 695 967`  
- **Paned:** `220 335 47 605 204 483 406 773`  
- **Result:** `220 335 47 605 204 483 406 773 80 102 650 692 130 262 695 967`

#### Step 2:

- **Input:** `[220 335 47 605 :204 483 406 773 ][80 102 650 692 :130 262 695 967]`  
- **Main Chain:** `204 483 406 773 ,130 262 695 967`  
- **Paned:** `220 335 47 605 ,80 102 650 692 ,69 284 495 542`  
- **Result:** `69 284 495 542 220 335 47 605 80 102 650 692 204 483 406 773 130 262 695 967`

#### Step 3:

- **Input:** `[69 284 :495 542 ][220 335 :47 605 ][80 102 :650 692 ][204 483 :406 773 ][130 262 :695 967]`  
- **Main Chain:** `495 542 ,47 605 ,650 692 ,406 773 ,695 967`  
- **Paned:** `69 284 ,220 335 ,80 102 ,204 483 ,130 262`  
- **Result:** `80 102 130 262 69 284 220 335 204 483 495 542 47 605 650 692 406 773 695 967`

#### Step 4:

- **Input:** `[80 :102 ][130 :262 ][69 :284][220 :335][204 :483][495 :542 ][47 :605][650 :692][406 :773][695 :967]`  
- **Main Chain:** `102 ,262 ,284 ,335 ,483 ,542 ,605 ,692 ,773 ,967`  
- **Paned:** `80 ,130 ,69 ,220 ,204 ,495 ,47 ,650 ,406 ,695 ,939`  
- **Result:** `47 69 80 102 130 204 220 262 284 335 406 483 495 542 605 650 692 695 773 939 967`

### Final Output:

The final sorted array is:
   47 69 80 102 130 204 220 262 284 335 406 483 495 542 605 650 692 695 773 939 967


### Total Comparisons:

The total number of comparisons made during the sorting process is: **76**.

## Conclusion

The Merge-Insertion Sort algorithm effectively sorted the input array through systematic merging and reversing, resulting in a completely ordered output with a detailed record of operations.

## License

This project is licensed under the MIT License. See the LICENSE file for details.


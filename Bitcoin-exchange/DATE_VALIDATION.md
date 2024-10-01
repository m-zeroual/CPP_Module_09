
# Date Validation Hint

## Issue:
On line 7, an error occurred due to an invalid date and a negative value. The date `2012-02-30` is not valid because February only has 29 days in a leap year. Additionally, the value `-1` must be positive.

## Solution:
- Correct the date to a valid date. Since 2012 is a leap year, the correct date should be `2012-02-29`.
- Ensure that the value is positive. Replace `-1` with a positive value.

### Corrected Line:
```bash
2012-02-29 | 1
```
This ensures the date is valid and the value is positive.

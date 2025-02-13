By: Ian Henson and Michael Batchelor

Desc: implementation of qsort, quick sort, merge sort, and stl sort. The merge, stl, and quick sort functions were written by Ian. Michael wrote the original quick and qsort functions.

Ian took his measurements using the time cmd in terminal.
| Mode | Size | Time |
|------|------|------|
|merge |100000|.278  |
|merge |500000|.947  |
|merge |1000000|1.981|
|merge |10000000|22.742|
|merge |25000000|61.524|
|stl   |100000|.205|
|stl   |500000|1.141|
|stl   |1000000|2.627|
|stl   |10000000|26.984|
|stl   |25000000|71.010|
|quick|100000|.561|
|quick|500000|3.13|
|quick|1000000|5.81|
|quick|10000000|61.574|
|quick|25000000|81.984|
|qsort|100000|.394|
|qsort|500000|1.132|
|qsort|1000000|2.238|
|qsort|10000000|21.724|
|qsort|25000000|54.519|

Results: The merge and stl sort increase at about the same rate, merge sort seems to run the fastest out of the two. After looking at the quick and qsort, it seems that qsort ran the fastest by a reasonable margin too. I speculate this was due to differences in implementation introducing error. This is about what is to be expected, this data was also fully randomized so it should replicate "real data" as much as possible.

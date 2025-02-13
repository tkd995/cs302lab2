By: Ian Henson and ...

Desc: implementation of qsort, quick sort, merge sort, and stl sort. The merge, stl, and quick sort functions were written by Ian.

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
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||
||||

Results: The merge and stl sort increase at about the same rate, merge sort seems to run the fastest out of the two. This is about what is to be expected, this data was also fully randomized so it should replicate "real data" as much as possible.

Discussion of Results: 

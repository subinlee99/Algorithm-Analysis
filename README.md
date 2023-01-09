# Algorithm-Analysis-
Yonsei University(CSI3108.01-00) Algorithm Analysis HW

HW_01
Homework #1, 2

Q1. Solve the following recurrences using the Master method. If cannot be solved by the Master method, please say “not applicable.”

  A.	T(n) = 5T(n/3) + 1/n (5pts)
  
  B.	T(n) = T(n-5) + 3/n (5pts)
  
  C.	T(n) = 2T(n/8) + n (5pts)
  
  
Q2. Solve the following recurrences using the substitution method. You have to use the mathematical induction and derive the same answers as those in Q1.

  D.	T(n) = 5T(n/3) + 1/n (10pts)
  
  E.	T(n) = 2T(n/8) + n (10pts)
  
  
Q3. Implement and compare the following sorting algorithms with the distributed five arrays of (big) integers: 1) insertion sort, 2) merge sort, 3) quicksort, 4) counting sort, and 5) radix sort with a stable comparison auxiliary sorting algorithm. You can choose any stable comparison sorting algorithm (refer to https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_sorts). In your report, please make it clear which stable comparison sorting algorithm had been chosen and why. The first two arrays contain integer numbers, and the last three arrays contain big integers. For the three big integer arrays, you can skip counting sort since it may cause memory limit errors (although you can adopt a special data structure to enable the sorting algorithm, which is out of the scope of this homework). Do not use Python. You should answer the following questions for each array:

  1.	Determine the rankings of your implementations (for all algorithms) in terms of wall-clock runtime. (50pts, i.e., 10pts for each array)
  2.	Determine the rankings of your implementations (for all comparison sorting algorithms, i.e., except counting sort) in terms of the number of    comparisons with an appropriate profiling tool or with a counter variable. (50pts, i.e., 10pts for each array)
  3.	Reproduce the trade-off curve of radix sort. Test with at least five different options for “r” and draw the curves for their theoretical and wall-clock runtime. (50pts, i.e., 10pts for each array)
  4.	(Not graded) If interested, report the number of page faults for your implementations. Refer to the following web page: https://www.cyberciti.biz/faq/linux-command-to-see-major-minor-pagefaults.
If your answers are written in a sloppy/unclear/insufficient/inexact way, 0 pts will be given for each question. You should write with a word processor, but you can insert your clear hand-written recurrence tree or formula after taking their photos.

HW_02

The attached file contains two lines, and you should find the length of the LCS between the two lines. Each line consists of 70K letters. You cannot create a matrix with 4900M elements for this homework. 

HW_03

-> There are three graphs and you should find the longest shortest-path in each graph. You MUST report i) your strategy to solve, ii) (src, dst, path weight) of the longest shortest-path you found in conjunction with iii) runnable, complete source codes. If there are multiple answers, you can report one of them. Please make a zip file containing your report and codes.

-> The longest shortest-path means that the longest one (in terms of the path weight) among all-pair shortest paths.

-> You can use any programming languages with access to basic APIs for data structures, e.g., priority queue.

-> The graph file format is that each line contains (src, dst, edge weight). In other words, those graphs are weighted, directed graphs. You MUST be very careful about this. If you consider them as unweighted and/or undirected, totally different results will come out and you will receive 0 pts.


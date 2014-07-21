Sudoku Solver

This solver (written in C++) is able to solve board and generate all available
unique solutions. What is more, you can save the result to a file.

If you want to see how fast it can be look at these examples
(processor: Intel Pentium Dual Core T4300 2.1GHz (notebook)):

1)	
	-6--2--4-				
	5--3-----
	-8--1----
	6----7---
	-37---28-
	-2-8---3-
	---------
	7--4----1
	----6--2-
	
	Solutions: 1917
	
	With compiler optimalization:
		-O0 : 168 ms
		-O1 : 54 ms
		-O2 : 49 ms
		-O3 : 34 ms
		
2)  8___3__4_				
    _____9__5
    _51__6_3_
    __5_4___9
    ___1_2___
    ______3__
    _3_7__68_
    _________
    _________
	
	Solutions 253238
	
	With compiler optimalization:
		-O0 : 13104 ms
		-O1 : 4320 ms
		-O2 : 3806 ms
		-O3 : 2547 ms

Sudoku Solver

This solver (written in C++) is able to solve board and generate all available
unique solutions. What is more, you can save the result to a file.

If you want to see how fast it can be look at these examples
(processor: Intel Pentium Dual Core T4300 2.1GHz (notebook)):

1)	_6__2__4_				Solutions: 1917
	5__3_____
	_8__1____
	6____7___
	_37___28_
	_2_8___3_
	_________
	7__4____1
	____6__2_
	
	With compiler optimalization:
		-O0 : 168 ms
		-O1 : 54 ms
		-O2 : 49 ms
		-O3 : 34 ms
		
2)  8___3__4_				Solutions 253238
    _____9__5
	_51__6_3_
	__5_4___9
	___1_2___
	______3__
	_3_7__68_
	_________
	_________
	
	With compiler optimalization:
		-O0 : 13104 ms
		-O1 : 4320 ms
		-O2 : 3806 ms
		-O3 : 2547 ms

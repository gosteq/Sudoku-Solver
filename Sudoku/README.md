Sudoku Solver

This solver (written in C++) is able to solve board and generate all available
unique solutions. What is more, you can save the result to a file.

If you want to see how fast it can be look at these examples
(processor: Intel Pentium Dual Core T4300 2.1GHz (notebook)):

1)	
	060020040								
	500300000								
	080010000								
	600007000								
	037000280								
	020800030								
	000000000								
	700400001								
	000060020									
	
	Solutions: 1917
	
	With compiler optimalization:
		-O0 : 168 ms
		-O1 : 54 ms
		-O2 : 49 ms
		-O3 : 34 ms
		
2)  
	8---3--4-
	-----9--5
    	-51--6-3-
    	--5-4---9
    	---1-2---
    	------3--
    	-3-7--68-
    	---------
    	---------
	
	Solutions 253238
	
	With compiler optimalization:
		-O0 : 13104 ms
		-O1 : 4320 ms
		-O2 : 3806 ms
		-O3 : 2547 ms

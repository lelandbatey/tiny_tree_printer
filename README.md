Tiny Binary Tree Printer in 505 bytes of C
==========================================

This is a tiny (sub-1kB) program that vertically prints a binary tree on the command line. Additionally, it prints the first two lines of the poem "Algoryhme" by Radia Perlman. 

The unobfuscated source code, including comments, is found in the `tree_print.c` file. It is about triple the size of the minified version of which I'm quoting the size. The minified source code is in the file `tree_print--unreadable.c`.

Running
-------

To build the minified source from the larger source, run:

	make

To generate the minified source, compile it, and execute it, run:

	make run


Techniques
----------

Here are some brief explanations of things I've done to try to make this small. I haven't looked at any C shrinking techniques before, so I don't know if this is well covered ground (it probably is) or if there's an obvious thing I'm missing.

1. Using `typedef` to shrink `int` declarations
2. Use single characters for variable names
3. Use the comma operator to combine expressions into a single statement, avoiding the need for braces
4. Make use of bit-shifting for powers of two
5. Compress `for` loops where possible, to the form `for (; iterations; --iterations)`


Notes
-----

The code is valid ISO C90, and should work with any compliant compiler (tested with gcc, clang, and msvc). It takes advantage of implicit declarations to call `atoi` and `putchar` without any includes, which may generate a warning on some compilers. However, in the case of these two functions, the implied declarations will be correct.

Part of the goal of this exercise was to experiment with obfuscation in addition to minification. Thus, the code uses no string or character literals, even though they could allow the size to be reduced further.


Credits
-------

The first version of this tiny tree printer was 777 bytes, and was written by Leland Batey. However, the current and much more impressive version has been written by Erik Jensen and is just **505** bytes! Additionally, he edited and improved this readme significantly.

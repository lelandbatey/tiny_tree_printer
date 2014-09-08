Tiny Binary Tree Printer in 777 bytes of C
==========================================

This is a tiny (sub-1kb) program that vertically prints a binary tree on the command line. Additionally, it prints the first two lines of the poem "Algoryhme" by Radia Perlman. 

The un-obfuscated source code, including comments, is found in the `tree_print.c` file. It is about triple the size of the minified version that I'm quoting the size of. The minified source code is in the file `tree_print--unreadable.c`.

Running
-------

To build the minified source from the larger source, run:

	make

To generate the minified source, compile it, and execute it, run:

	make run


Techniques
----------

Here are some brief explanations of things I've done to try to make this small. I haven't looked at any C shrinking techniques before, so I don't know if this is well covered ground (it probably is) or if there's an obvious thing I'm missing.

1. Using `define` to shrink `int` declarations
2. Use single characters for variable names
3. Use ternary `if` where possible
4. Make use of bit-shifting to do things like get powers of two.
5. Compress `for` loops where possible, to the form `for (;0 < iterations; --iterations){};`


Notes
-----

In an effort to use as little outside code as possible, I've gotten rid of the two major external functions that I had in prior versions: `putchar` and `pow`. I really didn't need `pow` since I was using it to get powers of two which is faster and smaller to do via bit shifting. For `putchar`, I felt a little bit like it was cheating. Instead, I now directly write to `stdout` in my own function (which has the added bonus of letting me fold in a for loop for the number of times to print a character).



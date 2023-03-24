# Introduction in memory managment
Write a program that demonstrates the order of variables in memory and the effect of alignment on the size of structures.

Create a function that takes a pointer to an array of structures allocated dynamically and determine the size of the array inside the function (using compiler-specific hacks for accessing overhead information) using the pointer and pointer arithmetic.
The function will have to explicitly call the destructor on each element of the array.
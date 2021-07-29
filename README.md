# Calculator-with-C

This is a calculator program using C language 

This project records the process of creating a calculator for simple computational calculations in Linux environments and its results.

To briefly describe the program, it is a program that reads text files written in prefix form (operator operand operand) by line and performs calculations. The operand can have a hexadecimal number or a register from 0 to 9. If a hexadecimal number comes, convert it to a decimal number and perform the calculation, and if a register comes, the values stored in the register number are loaded and perform the operation.

Also, I made a new operation called move, compare, jump, and branch, respectively, through the symbols M, C, J, and B. <br />
First, 'move' stores the value of 'operand2' in the register corresponding to 'operand1. <br />
Second, 'compare' stored 0 in register 0 if operand1>=operand2 otherwise stored 1. <br />
Third, 'jump' is calculated by moving to the desired line according to operation 1. <br />
Fourth, 'branch' is similar to jump, but coded to run only when register 0 is 1.<br />

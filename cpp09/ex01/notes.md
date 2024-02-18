use stack
always take the last two digits before on operator and do the operation on that
then remove the last digit and replace the second to last (new last) with the result of the operation
do until all operations are done


flow:
	1. take Inverted Polish Mathematical exression as argument
		- numbers are always < 10
			- + positive
	2. validate given input
		- all numbers < 10 and positive
		- should contain only valid numbers and operators ("+ - / *)
		- there should be one less operand than numbers (2 2 + + is not valid)
		- first two characters should be numbers, after that there should always
		  be enough numbers on the stack (2) while there are operand left
			- this is propably easier done during the calculation
		- only a single digit as input is valid, just print out that digit :D
	3. process input and output result
		- the logic of rpn as I understand it:
			- start adding the input numbers to stack
			- when you reach an operand, take the top two elements (numbers) on
			  the stack and do the operation on them
			- remove the top element of your stack and replace the new top with
			  the result of the operation you just did
			- keep doing this while you still have more than 1 element on the stack
			  and operands to work with + input string left
			  	- an obvious porblem is if you run out of numbers or operands
	- NOTE: all error messages should be printed on standard output!

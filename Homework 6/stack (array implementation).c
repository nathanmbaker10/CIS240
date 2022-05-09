#include <stdio.h>
#include <ctype.h>

typedef struct fraction_struct {
	int numerator;
	int denominator;
} Fraction;


typedef struct fraction_stack_struct {
	Fraction fractionArray[];
	int size;

} Stack;

Fraction newFraction(int n, int d) {
	Fraction output;
	output.numerator = n;
	output.denominator =d;
}


//Constructs a new stack with initial array size of 10
Stack newStack(){
	Stack *newStack;
	newStack = (Stack*) malloc(sizeof(fraction_stack_struct) + 10);
	*newStack.size = 0;

	Fraction array[10];
	*newStack.fractionArray = array;


	return *newStack;
}

/* Doubles the size of the array*/
void resizeUp(Stack s) {
	Stack * stackPointer = &s;

	stackPointer = realloc(stackPointer, sizeof(s) + sizeof(Fraction) * s.size);
}


//Pushes fraction element onto stack. If adding the element requires an increase in size, then we double array size.
void pushTo(Stack toStack, Fraction addElement){
	if(toStack.size == toStack.fractionArray.length) {
		resizeUp(toStack);
	}
	toStack.fractionArray[toStack.size] = addElement;

	toStack.size++;
}

/*Halves the size of the array*/
void resizeDown(Stack s) {
	Stack * stackPointer = &s;

	stackPointer = realloc(stackPointer, sizeof(s) - sizeof(Fraction) * size/2);
}

//Pops element from stack. If(size < (array.length /4)), resizes down
Fraction popFrom(Stack stack) {
	int output = stack.fractionArray[stack.size - 1];
	stack.size--;
	if (stack.size < stack.fractionArray.length / 4) {
		resizeDown(stack);
	}

	return output;
}





//Returns most recent item from stack without popping
Fraction peak(Stack stack){
	return stack.fractionArray[stack.size - 1];
}

int main() {
	Fraction new_frac = newFraction(5, 1);

	Stack newStack = newStack();

	addElement(newStack, new_frac);

	Fraction firstElement = peak(newStack);

	printf("Numerator of first element: %d\n Denominator: %d\n", &firstElement.numerator, &firstElement.denominator);
}









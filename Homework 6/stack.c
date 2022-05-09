
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"

Fraction *newFraction(int n, int d) {
	Fraction frac;

	frac.numerator = n;
	frac.denominator = d;

	Fraction *output = (Fraction*) malloc(sizeof(frac));
	*output = frac;
	return output;
}

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	} else if (b == 0 || a == b) {
		return a;
	} else if (a > b) {
		return gcd(a - b, b);
	} else {
		return gcd (a, b - a);
	}
}

Fraction *reduceFraction(Fraction* f){
	int numerator = (*f).numerator;
	int denominator = (*f).denominator;
	int GCD = gcd(abs(numerator), abs(denominator));

	numerator /= GCD;
	denominator /= GCD;

	// free(f);

	return newFraction(numerator, denominator);
}

StackHead *newStackHead() {
	StackHead stack_head;
	stack_head.head = NULL;

	StackHead *output = malloc(sizeof(stack_head));

	*output = stack_head;

	return output;
}

StackElement *newStackElementFromFrac(Fraction *f){
	StackElement newStackElement;
	Fraction *reducedFraction = reduceFraction(f);
	newStackElement.value = *reducedFraction;
	newStackElement.next = NULL;

	// free(f);

	StackElement *output = (StackElement*) malloc(sizeof(newStackElement));

	*output = newStackElement;

	return output;
}

StackElement *newStackElementFromIntegers(int n, int d) {
	Fraction *v = newFraction(n, d);

	return newStackElementFromFrac(v);

}


//Do not call on an empty stack. Output will not work properly.
Fraction popFrom(StackHead *e) {
	StackElement *head = e->head;

	Fraction output = head->value;
	if(head->next != NULL) {
		e->head = head->next;
	} else {
		e->head = NULL;
	}

	free(head);

	return output;
}


void addFractionTo(StackHead* e, Fraction* f){
	Fraction *reducedInput = reduceFraction(f);
	StackElement *newStackElement = newStackElementFromFrac(reducedInput);

	if(e->head != NULL) {
		newStackElement -> next = e -> head;
		e -> head = newStackElement;
	}	
	e -> head = newStackElement;
	
}

void addIntegersTo(StackHead* e, int n, int d) {
	Fraction *f = newFraction(n, d);
	addFractionTo(e, reduceFraction(f));
}


void duplicateHead(StackHead* e) {
	StackElement* currentHead = e->head;
	if(currentHead) {
		addFractionTo(e, &currentHead->value);	
	} else {
		printf("STACK ERROR\n");
	}	
}

void swap(StackHead* e) {
	StackElement *topPointer = e->head;
	
	if(!topPointer) {
		printf("STACK ERROR\n");
		return;
	}
	Fraction top = popFrom(e);
	StackElement *secondPointer = e->head;

	if(!secondPointer) {
		printf("STACK ERROR\n");
		return;
	}

	Fraction second = popFrom(e);

	addFractionTo(e, &top);
	addFractionTo(e, &second);
}

void drop(StackHead* e) {
	popFrom(e);
}

void clear(StackHead* e) {
	while(e->head) {
		popFrom(e);
	}
}


void addFracs(StackHead* e) {
	StackElement *topPointer = e->head;
	
	if(!topPointer) {
		printf("STACK ERROR\n");
		return;
	}
	Fraction f1 = popFrom(e);
	StackElement *secondPointer = e->head;

	if(!secondPointer) {
		printf("STACK ERROR\n");
		return;
	}

	Fraction f2 = popFrom(e);

	int numerator = (f1.numerator) * (f2.denominator) + (f2.numerator) * (f1.denominator);
	int denominator = (f1.denominator) * (f2.denominator);

	Fraction *newFrac = newFraction(numerator, denominator);

	addFractionTo(e, reduceFraction(newFrac));
}


void subtractFracs(StackHead *e) {
	StackElement *topPointer = e->head;
	
	if(!topPointer) {
		printf("STACK ERROR\n");
		return;
	}
	Fraction f1 = popFrom(e);
	StackElement *secondPointer = e->head;

	if(!secondPointer) {
		printf("STACK ERROR\n");
		return;
	}

	Fraction f2 = popFrom(e);
	int numerator = (f2.numerator) * (f1.denominator) - (f1.numerator) * (f2.denominator);
	int denominator = (f1.denominator) * (f2.denominator);

	Fraction *newFrac = newFraction(numerator, denominator);

	addFractionTo(e, reduceFraction(newFrac));
}

void multiplyFracs(StackHead* e) {
	StackElement *topPointer = e->head;
	
	if(!topPointer) {
		printf("STACK ERROR\n");
		return;
	}
	Fraction f1 = popFrom(e);
	StackElement *secondPointer = e->head;

	if(!secondPointer) {
		printf("STACK ERROR\n");
		return;
	}

	Fraction f2 = popFrom(e);

	int numerator = (f1.numerator) * (f2.numerator);
	int denominator = (f1.denominator) * (f2.denominator);

	Fraction *newFrac = newFraction(numerator, denominator);

	addFractionTo(e, reduceFraction(newFrac));
}

int divideFracs(StackHead *e) {
	StackElement *topPointer = e->head;
	
	if(!topPointer) {
		printf("STACK ERROR\n");
		return 2;
	}
	Fraction f1 = popFrom(e);
	StackElement *secondPointer = e->head;

	if(!secondPointer) {
		printf("STACK ERROR\n");
		return 2;
	}

	Fraction f2 = popFrom(e);

	if(f1.numerator == 0) {
		printf("DIVIDE BY ZERO\n");
		return 0;
	} else {
		int denominator = (f1.numerator) * (f2.denominator);
		int numerator = (f1.denominator) * (f2.numerator);

		Fraction *newFrac = newFraction(numerator, denominator);

		addFractionTo(e, reduceFraction(newFrac));

		return 1;
	}

	
}





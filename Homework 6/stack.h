//Fraction Data Struct
typedef struct fraction_struct {
	int numerator;
	int denominator;
} Fraction;

typedef struct fraction_stack_element {
	Fraction value;
	struct fraction_stack_element* next;

} StackElement;

typedef struct initial_stack_element {
	struct fraction_stack_element* head;
} StackHead;


//Returns a new fraction with numerator n and denominator d
Fraction *newFraction(int n, int d);

//Returns GCD of integer inputs a and b
int gcd(int a, int b);

//Creates a new stackhead with a null head
StackHead *newStackHead();

//Return a new Stack Element from a fraction
StackElement *newStackElementFromFrac(Fraction *f);

//Returns a new Stack Element from given numerator and deonominator as parameters
StackElement *newStackElementFromIntegers(int n, int d);

/* Returns top element from stack and removes it from the stack
If the resulting stack is negative, it is represented by setting the numerator and denominator of the value to 2
This representation is possible because fractions are always reduced when added to the stack*/
Fraction popFrom(StackHead *e);

/*Adds fraction to top of stack */
void addFractionTo(StackHead* e, Fraction* f);

/*Adds integers parameters for numerator and denominator to top of stack*/
void addIntegersTo(StackHead* e, int n, int d);


void duplicateHead(StackHead* e);

void swap(StackHead* e);

void drop(StackHead* e);


void clear(StackHead* e);

void addFracs(StackHead* e);
void subtractFracs(StackHead *e);
void multiplyFracs(StackHead* e);
int divideFracs(StackHead *e);



#include <iostream>
#include <string>

using namespace std;

int rvalue()
{
	return 10;
}

// Parameter must be Lvalue (Basic function Call-by-Value)
void setLvalue(int paramValue) {
	int innerLvalueA = paramValue;  // Deep copy 
	int &innerLvalueB = paramValue; // Reference to paramValue (New variable in this function with Deep copy)

	cout << "paramValue\t: " << paramValue << endl;
	cout << "innerLvalueA\t: " << innerLvalueA << endl;
	cout << "&innerLvalueB\t: " << innerLvalueB << endl << endl;


	cout << "innerLvalueA = 100" << endl;
	cout << "innerLvalueB = 1000" << endl << endl;
	innerLvalueA = 100;
	innerLvalueB = 1000; // This is equal with (paramValue = 1000)

	cout << "paramValue\t: " << paramValue << endl;
	cout << "innerLvalueA\t: " << innerLvalueA << endl;
	cout << "&innerLvalueB\t: " << innerLvalueB << endl;
}

// Parameter must be Lvalue reference
void setLvalueWithReference(int &paramValue) {
	int innerLvalueA = paramValue;  // Deep copy 
	int &innerLvalueB = paramValue; // Reference to paramValue (Parameter variable outside this function)

	cout << "paramValue\t: " << paramValue << endl;
	cout << "innerLvalueA\t: " << innerLvalueA << endl;
	cout << "&innerLvalueB\t: " << innerLvalueB << endl << endl;


	cout << "innerLvalueA = 100" << endl;
	cout << "innerLvalueB = 1000" << endl << endl;	
	innerLvalueA = 100;
	innerLvalueB = 1000; // This is equal with (paramValue = 1000)

	cout << "paramValue\t: " << paramValue << endl;
	cout << "innerLvalueA\t: " << innerLvalueA << endl;
	cout << "&innerLvalueB\t: " << innerLvalueB << endl;
}

// Parameter must be Rvalue reference
// But in function, parameter variable is Lvalue (paramValue = Deep copy)
void setRvalue(int &&paramValue) {
	int innerRvalueA = paramValue;  // Deep copy
	int &innerRvalueB = paramValue; // Reference to paramValue
	// int &&rvalueB = paramValue;  // Can not bind Lvalue(paramValue) to rvalue Reference (ravlueB)

	cout << "paramValue\t: " << paramValue << endl;
	cout << "innerRvalueA\t: " << innerRvalueA << endl;
	cout << "&innerRvalueB\t: " << innerRvalueB << endl << endl;


	cout << "innerRvalueA = 100" << endl;
	cout << "innerRvalueB = 1000" << endl << endl;
	innerRvalueA = 100;
	innerRvalueB = 1000; 

	cout << "paramValue\t: " << paramValue << endl;
	cout << "innerRvalueA\t: " << innerRvalueA << endl;
	cout << "&innerRvalueB\t: " << innerRvalueB << endl;
}

int main(void)
{
	int Lvalue = 10;

	// Lvalue to variable
	int Lvalue_A = Lvalue;		// Deep copy
	int &Lvalue_B = Lvalue;		// Lvalue Reference
	// int &Lvalue_C;			// Error : Reference must be initialized
	// int &&Lvalue_C = lvalue;	// Error : Can not bind lvalue to rvalue

	// Rvalue
	int &&Rvalue_A = 10;		// Rvalue reference
	int &&Rvalue_B = rvalue();	// Ravlue reference
	// int &&Rvalue_C;			// Error : Reference must be initialized 
	// int &&Rvalue_C = Lvalue;	// Error : Can not bind rvalue to lvalue


	cout << "==========================" << endl;
	cout << "[Initial Value]" << endl;
	cout << "lvalue\t\t: " << Lvalue << endl;
	cout << "Lvalue_A\t: " << Lvalue_A << endl;
	cout << "&Lvalue_B\t: " << Lvalue_B << endl;
	cout << "rvalue()\t: " << rvalue() << endl;
	cout << "&&Rvalue_A\t: " << Rvalue_A << endl;
	cout << "&&Rvalue_B\t: " << Rvalue_B << endl;
	cout << "==========================" << endl << endl;
	/*
	==========================
	[Initial Value]
	lvalue : 10
	Lvalue_A : 10
	Lvalue_B : 10
	rvalue() : 10
	Rvalue_A : 10
	Rvalue_B : 10
	==========================
	*/

	Lvalue_A = 1;
	Lvalue_B = 2; // Changes variable "Lvalue" becuase it is reference.
	Rvalue_A = 3;
	Rvalue_B = 4;

	cout << "[Change Value]" << endl;
	cout << "Lvalue_A\t= 1" << endl;
	cout << "Lvalue_B\t= 2" << endl;
	cout << "Rvalue_A\t= 3" << endl;
	cout << "Rvalue_B\t= 4" << endl << endl;

	cout << "==========================" << endl;
	cout << "[After Change]" << endl;
	cout << "Lvalue\t\t: " << Lvalue << endl;
	cout << "Lvalue_A\t: " << Lvalue_A << endl;
	cout << "&Lvalue_B\t: " << Lvalue_B << endl;
	cout << "rvalue()\t: " << rvalue() << endl;
	cout << "&&Rvalue_A\t: " << Rvalue_A << endl;
	cout << "&&Rvalue_B\t: " << Rvalue_B << endl;
	cout << "==========================" << endl << endl;
	/*
	==========================
	[Change Value]
	Lvalue : 2
	Lvalue_A : 1
	Lvalue_B : 2
	rvalue() : 10
	Rvalue_A : 3
	Rvalue_B : 4
	==========================
	*/

	cout << "============================================================================" << endl;
	cout << "[Call setLvalue(int paramValue) with Parameter : Lvalue_B]" << endl;
	setLvalue(Lvalue_B);	// Lvalue Reference to Param
	cout << "&Lvalue_B\t: " << Lvalue_B << endl;
	cout << "============================================================================" << endl << endl;

	// setLvalue(10);		// Basic function call
	// setLvalue(rvalue());	// Basic function call
	// setLvalue(Lvalue_A);	// Basic function call

	/*
	==========================
	[Call setLvalue(int paramValue) with Parameter : Lvalue_B]
	paramValue      : 2
	innerLvalueA    : 2
	&innerLvalueB   : 2

	innerLvalueA = 10
	innerLvalueB = 11

	paramValue      : 11
	innerLvalueA    : 10
	&innerLvalueB   : 11

	&Lvalue_B       : 2	// Becuase setLvalue(int paramValue) transfer (Lvalue_B) with Deep copy.
	==========================
	*/


	cout << "============================================================================" << endl;
	cout << "[Call setLvalueWithReference(int &paramValue) with Parameter : Lvalue_A]" << endl;
	setLvalueWithReference(Lvalue_A);
	cout << "&Lvalue_A\t: " << Lvalue_A << endl;
	cout << "============================================================================" << endl << endl;

	/*
	setLvalueWithReference(Lvalue_B); // Same result with Lvalue_A
			 : Same result with Lvalue_A. Lvalue_B is also changed.
			   This means, It is not important Lvalue_A or Lvalue_B is lvalue reference or not in case of parameter.
			   if function is declared with lvalue reference parameter (Call-by-reference), variable is passed with reference.
			   if function is declared with lvalue parameter (Call-by-Value), variable is passed with call-by-value (Deep copy).
	*/

	/*
	============================================================================
	[Call setLvalueWithReference(int &paramValue) with Parameter : Lvalue_A]
	paramValue      : 1
	innerLvalueA    : 1
	&innerLvalueB   : 1

	innerLvalueA = 100
	innerLvalueB = 1000

	paramValue      : 1000
	innerLvalueA    : 100
	&innerLvalueB   : 1000
	&Lvalue_A       : 1000
	============================================================================
	*/

	// setRvalue(rvalue()); // Equal with setRvalue(10)
	// setRvalue(Lvalue);   // Error : Can not bind lvalue(Lvalue) to rvalue reference (&&paramValue);
	cout << "============================================================================" << endl;
	cout << "[Call setRvalue(int &&paramValue) with Parameter : 10]" << endl;
	setRvalue(10);
	// Do not need to print rvalue because it is temporary value
	cout << "============================================================================" << endl;
	
	/*
	============================================================================
	[Call setRvalue(int &&paramValue) with Parameter : 10]
	paramValue      : 10
	innerRvalueA    : 10
	&innerRvalueB   : 10

	innerRvalueA = 100
	innerRvalueB = 1000

	paramValue      : 1000
	innerRvalueA    : 100
	&innerRvalueB   : 1000
	============================================================================
	*/
}
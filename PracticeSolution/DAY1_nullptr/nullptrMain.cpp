#include <iostream>
#include <string>

using namespace std;


void TEST_printNULL(int i)
{
	cout << "Value : " << i << endl;
}

void TEST_printNULL(const int* i)
{
	cout << "Pointer : NULL(0)" << endl;
}

// This function makes error in TEST_printNULL(nullptr)
/*
void TEST_printNULL(const char* i)
{
cout << "Pointer : NULL(0) << endl";
}
*/

void TEST_nullptr()
{
	cout << "==========================" << endl;
	cout << "Type Name : " << typeid(nullptr).name() << endl;
	// cout << "Value : " << nullptr << endl; // ERROR
	cout << "Size : " << sizeof(nullptr) << endl;
	cout << "Value == 0 ? : " << (nullptr == 0 ? "TRUE" : "FALSE") << endl;
	TEST_printNULL(nullptr);
	cout << "==========================" << endl << endl;

	/*
	* [RESULT]
	* Type Name : std:nullptr_t
	* Size : 4
	* Value == 0 ? TRUE
	* Pointer : NULL(0)
	*/

	cout << "==========================" << endl;
	cout << "Type Name : " << typeid(NULL).name() << endl;
	cout << "Value : " << NULL << endl;
	cout << "Size : " << sizeof(NULL) << endl;
	cout << "Value == 0 ? : " << (NULL == 0 ? "TRUE" : "FALSE") << endl;
	TEST_printNULL(NULL);
	cout << "==========================" << endl << endl;

	/*
	* [RESULT]
	* Type Name : int
	* Size : 4
	* Value == 0 ? TRUE
	* Value : 0
	*/
}

int main(void)
{
	TEST_nullptr();
}
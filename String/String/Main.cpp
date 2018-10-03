#include <iostream>
#include "String.h"

int main()
{
	String a("hello");
	String b(a);
	b = "bye";

	system("pause");
	return 0;
}
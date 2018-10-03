#ifndef __STRING_H__
#define __STRING_H__

#include <assert.h>

typedef unsigned int uint;

class String
{
public:
	char* string = nullptr;
	uint allocated_memory = 0u;

public:
	// Constructors
	String()
	{}

	String(const char* c)
	{
		assert(c != nullptr);

		uint n = 0;
		while (c[n] != '\0')
			n++;

		allocated_memory = n;
		string = new char[n];

		while (*string++ = *c++);
	}

	String(const String& s)
	{
		allocated_memory = s.allocated_memory;
		string = new char[allocated_memory];

		for (uint i = 0; i < allocated_memory; i++)
		{
			string[i] = s.string[i];
		}
	}

	// Destructor
	~String()
	{
		if (string != nullptr)
		{
			delete[] string;
			string = nullptr;
			allocated_memory = 0;
		}
	}

	// Utility functions
	String operator=(const char* c)
	{
		uint n = 0;
		while (c[n] != '\0')
			n++;

		if (n > allocated_memory)
		{
			delete[] string;
			string = new char[allocated_memory];

			while (*string++ = *c++);
		}

		allocated_memory = n;

		return (*this);
	}

	/*
	String operator=(const String& s)
	{
	allocated_memory = s.allocated_memory;
	string = new char[allocated_memory];

	for (uint i = 0; i < allocated_memory; i++)
	{
	string[i] = s.string[i];
	}

	return (*this);
	}
	*/

	bool operator==(const char* c) const
	{
		String s(c);
		return (*this == s);
	}

	bool operator==(const String& s) const
	{
		if (allocated_memory != s.allocated_memory)
		{
			return false;
		}

		uint n = 0;
		while (string[n] == s.string[n])
		{
			n++;
		}

		return (n == allocated_memory);
	}
};

#endif // __STRING_H__
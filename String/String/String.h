#ifndef __STRING_H__
#define __STRING_H__

typedef unsigned int uint;

class String
{
public:
	char* data;
	uint length;

public:
	// Constructors
	String()
	{
		data = new char[0];
		length = 0;
	}

	String(const char* c)
	{
		uint n = 0;
		while (c[n] != '\0')
		{
			length = n;
			data = new char[n];
		}

		for (uint i = 0; i < n; i++)
		{
			data[i] = c[i];
		}
	}

	String(const String& s)
	{
		length = s.length;
		data = new char[length];

		for (uint i = 0; i < length; i++)
		{
			data[i] = s.data[i];
		}
	}

	// Destructor
	~String()
	{
		delete[] data;
	}

	// Utility functions
	bool operator==(const String& s) const
	{
		if (length != s.length)
		{
			return false;
		}

		uint n = 0;
		while (data[n] == s.data[n])
		{
			n++;
		}

		return (n == length);
	}

	bool operator==(const char* c) const
	{
		String s(c);
		return (*this == s);
	}

	String operator=(const String& s)
	{
		length = s.length;
		data = new char[length];

		for (uint i = 0; i < length; i++)
		{
			data[i] = s.data[i];
		}

		return (*this);
	}

	String operator=(const char* c)
	{
		String s(c);
		*this = s;

		return (*this);
	}
};

#endif // __STRING_H__
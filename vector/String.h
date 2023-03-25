#pragma once
#include <iostream>

class String {

private:
	size_t	m_length;
	char*	m_string;
	size_t	m_capacity;
	void			 resize();

public:

	String();
	String(const char* string);
	String(const String& other);
	~String();


	String&			operator=(const String& string);
	String&			operator=(const char* string);
	String&			operator+(const char* to_append);
	bool			operator==(String& other);
	bool			operator==(const char* other);
	bool			operator!=(const char* other);
	char&			operator[](size_t index);


	void			pop_back();
	void			print();
	String			append(char to_append);
	String&			append(const char* to_append);
	size_t			length();
	int				find(const char* str);
	bool			contains(const char* substring);
	void			toUpperCase();
	void			toLowerCase();
	String			slice(size_t index);
	String			cut(size_t index);
	String			substr(size_t start, size_t end);
	char			at(size_t index);
	char*			c_str();
	void			clear();
	int				countChar(char c);
	void			trim();

	friend std::ostream& operator<<(std::ostream& os, const String& string);
	friend std::istream& operator>>(std::istream& is, String& out);
};



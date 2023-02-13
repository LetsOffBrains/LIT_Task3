#pragma once
#include <string>

class StringRepresentation
{
private:
	std::string str = "";
	int num = 0;
public:
	StringRepresentation(int = 0);
	void setNumber(int);

	std::string getString();
	int getNumber();
};


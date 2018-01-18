
#ifndef NUMBER_HPP
#define NUMBER_HPP



#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 

using namespace std;

class Number
{
public:
	Number() { }
	Number(string &str);
	Number(short num);
	Number operator *(const Number &oth);
	const string& getNum() const ;

private:
	string number;
	void removeSign(string &str1, string &str2, bool &b1, bool &b2);
	string strAdd(string &num1, string &num2, bool neg = false);
	string strSubtract(string &num1, string &num2);
	string strMultiply(string &num, char mul);
	friend ostream& operator <<(ostream &ekran, const Number &sag);

};

#endif
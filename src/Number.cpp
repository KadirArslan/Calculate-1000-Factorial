
#include "Number.hpp"
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
using namespace std;
Number::Number(string & str)
{
	number = str;
}

Number::Number(short numb)
{
	stringstream sstr;
	sstr << numb;
	number = sstr.str();
}

Number Number::operator*(const Number & oth)
{
	string numb = number, other = oth.number;
	bool num_pos, other_pos;
	removeSign(numb, other, num_pos, other_pos);

	string min, max;
	if (numb.length() < other.length()) {
		min = numb;
		max = other;
	}
	else {
		max = numb;
		min = other;
	}
	vector<string> strarray;
	int biggest = 0;

	int length = min.length() - 1;
	for (int i = length; i >= 0; --i) {
		string res = strMultiply(max, min[i]).append(length - i, '0');

		if (res.length() > biggest)
			biggest = res.length();
		strarray.push_back(res);
	}
	for (int i = 0; i < strarray.size(); ++i)
		strarray[i].insert(0, biggest - strarray[i].length(), '0');

	string result = strarray[0];
	for (int i = 1; i < strarray.size(); ++i) {
		result = strAdd(result, strarray[i]);
	}
	if (num_pos != other_pos)
		result.insert(0, 1, '-');

	return Number(result);
}

const string & Number::getNum() const
{
	return number;
}

void Number::removeSign(string & str1, string & str2, bool & b1, bool & b2)
{
	b1 = b2 = true;
	if (str1[0] == '-') {
		str1.erase(0, 1);
		b1 = false;
	}
	if (str2[0] == '-') {
		str2.erase(0, 1);
		b2 = false;
	}

}

string Number::strAdd(string & num1, string & num2, bool neg)
{
	const char dif = 48;
	char sum, carry = 0;
	string result;


	for (int i = num1.length() - 1; i >= 0; --i) {
		sum = (num1[i] - dif) + (num2[i] - dif) + carry;
		carry = 0;
		if (sum > 9) {
			sum -= 10;
			carry = 1;
		}
		result.insert(0, 1, sum + dif);
	}
	if (carry != 0)
		result.insert(0, 1, '1');
	if (neg)
		result.insert(0, 1, '-');
	return result;
}

string Number::strSubtract(string & num1, string & num2)
{
	bool neg = false;
	string min, max;

	if (num1 < num2) {
		min = num1;
		max = num2;
		neg = true;
	}
	else {
		max = num1;
		min = num2;
	}
	const char dif = 48;
	string result;
	int i;

	for (i = max.length() - 1; i >= 0; --i) {
		char x = max[i] - dif;
		char n = min[i] - dif;
		if (x < n) {
			x += 10;
			--max[i - 1];
		}
		result.insert(0, 1, x - n + dif);
	}
	for (i = 0; i < result.length() - 1 && result[i] == '0'; ++i);
	result.erase(0, i);

	if (neg)
		result.insert(0, 1, '-');
	return result;
}

string Number::strMultiply(string & num, char mul)
{
	const char dif = 48;
	int carry = 0;
	string result;
	mul -= dif;

	for (int i = num.length() - 1; i >= 0; --i) {
		int res = mul * (num[i] - dif) + carry;
		carry = res / 10;
		result.insert(0, 1, res % 10 + dif);
	}
	if (carry != 0)
		result.insert(0, 1, carry + dif);
	return result;
}

ostream & operator<<(ostream & ekran, const Number & sag)
{
	
	ekran << sag.getNum();
	return ekran;
}


#include <iostream>
#include"Number.hpp"
#include <time.h>
using namespace std;
int main()
{
	system("cls");
	int sayi, i = 0;
	cout << "Faktoryeli alinacak sayi: ";
	cin >> sayi;
	clock_t say = clock();
	Number fakt = 1;
	while (++i < sayi)
		fakt = fakt * Number(i + 1);
	cout << "Sonuc: " << fakt<< endl;
	clock_t dur = clock();
	cout<<"Hesaplanma Suresi : "<<(dur-say)/CLOCKS_PER_SEC <<"sn";
	
	return 0;
}
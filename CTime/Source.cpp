#include <iostream>
#include <conio.h>
#include "Time.h"
using namespace std;
int main()
{
	Time t(123456);
	Time t1, t2, t3(123456), t4(4, 22, 58, 01);
	cout << "t1 = " << t1 << '\n';   cout << "t2 = " << t2 << '\n';  
	cout << "t3 = " << t3 << '\n';   cout << "t4 = " << t4 << '\n';
	cout << "Enter first Time object (DAYS~HH:MM:SS):  ";   cin >> t1;
	cout << "Enter second Time object (DAYS~HH:MM:SS):  ";   cin >> t2;
	cout << "\n\n";
	cout << t1 << " + ";
	cout << t2 << " = ";
	cout << t1 + t2 << '\n';
	cout << t1 << " - ";
	cout << t2 << " = ";
	cout << t1 - t2 << "\n\n";
	if (t1 < t2)         
		cout << t1 << " <  " << t2 << " is TRUE\n";   
	if (t1 > t2)         
		cout << t1 << " >  " << t2 << " is TRUE\n";   
	if (t1 == t2)        
		cout << t1 << " == " << t2 << " is TRUE\n";   
	if (t1 != t2)        
		cout << t1 << " != " << t2 << " is TRUE\n\n";
	/*cout << t1 << " * 3 = " << t1 * 3 << '\n'; */ 
	cout << "t2++  = " << t2++ << '\n';
	_getche();
}
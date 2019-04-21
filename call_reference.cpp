#include <iostream>
#include <string.h>
using namespace std;

int return_value(int *addr, int y){
	cout << "addr " << addr << endl;
	cout << "y " << y << endl;
	*addr = 20;
	y = 20;
	return y;
}

int main(){
	int x=15, y=15, y_new_val;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	int* ptr = &x;
	y_new_val = return_value(&x, y);
        cout << "x=" << x << endl;
        cout << "y_new_val" << y_new_val << endl;
	cout << "y" << y << endl;
	
	string d;
	getline(cin,d); 
	string a = "hello";
	string b = "hi";
	string  c = a+b;
	cout << c << endl;
	cout << d << endl;
	return 0;
}

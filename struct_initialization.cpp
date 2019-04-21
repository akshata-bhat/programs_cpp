#include <iostream>
using namespace std;

int main(){
	struct Employee{
		int id;
		short age;
		double wage;
		string Name;

/*   #########   The below code will not work in C++ versions prior to C++11

                short age = 25;
                double wage = 100.0;
                string Name = "Not mentioned";
*/

	};

	Employee joe = {2, 25, 6};
	cout << joe.id << endl;
	cout << joe.wage << endl;
	cout << joe.Name << endl;

        Employee frank = {20, 30, 6, "Franky Tribbiani"};
        cout << frank.id << endl;
        cout << frank.wage << endl;
	cout << frank.age << endl;
        cout << frank.Name << endl;

	return 0;
}

#include<iostream>
using namespace std;

template <typename T>
T myMax(T a, T b){
	return (a > b) ? a : b;	
}

int main(){
	// here implicit deduction of the return type will be done
	cout << myMax(3, 7) << endl;
	
	// Just trying out for a different return datatype
	cout << myMax<int>(6.7, 4.5) << endl;

	// Here we have to explicitly specify the return type - since it conflicts at this stage
	cout << myMax<float>(3.8, 9.7) << endl;
	
	cout << myMax<int>(4.59, 4.6) << endl;

        cout << myMax (true, false) << endl;

	return 0;
}


/*

O/P:

7
6
9.7
4
1


*/

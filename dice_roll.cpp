#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

srand(time(0));
int randomNumber = rand();
int die = (randomNumber % 6) + 1;
cout << die << "rolled" << endl;
return 0;
}

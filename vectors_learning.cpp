#include <iostream>
#include <vector>
using namespace std;

void playing_with_vectors()
{
        cout << "first: " << endl;
        vector<int> first = {1, 2, 4, 4, 5};
        cout << first.size();
        for(int i=0; i<first.size(); i++)
                cout << first[i]<< "\t";
        cout << endl;


        vector<int> second(4,100);
        vector<int> third(second.begin(), second.end());
        cout << "third" << endl;
        for(int i=0; i<third.size(); i++)
                cout << third[i]<< "\t";
        cout << endl;
}

int main()
{
        vector<int> my_vect(4,0); //Initializing a 1D array of size 4 with 0's

        for(int i=0;i<10;i++)
                my_vect.push_back(i); // Appending values(1-9) to the array

        my_vect.resize(8); // Resizing the array to a smaller sized  array of 8 elements and the remaining elements will be lost 
        my_vect.resize(12,33); // Resizing the array and initializing the newer elements to 33 
        my_vect.resize(14); // resizing - the newer elements are initialized to 0 by default 

        cout << "Testing the resizing part: " << endl;
        for(int i=0; i<my_vect.size();i++)
                cout<<my_vect[i]<<"\t";

        cout << endl;
        playing_with_vectors();
        return 0;
}


/* OUTPUT:

Testing the resizing part: 
0	0	0	0	0	1	2	3	33	33	33	33	0	0	
first: 
51	2	4	4	5	
third
100	100	100	100	

*/

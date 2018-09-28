#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Difference {
private:
    vector<int> elements;

public:
    int maximumDifference;


    // Add your code here
    Difference(vector<int> input_values){
        this->elements=input_values;
        for (int i = 0; i < input_values.size(); ++i) {
        //    cout<< elements[i] << endl;
        }
    }

    void computeDifference(){
        int length = elements.size();
        int index=0;
        vector<int> diff_values(length*length);
        for(int i=0; i<elements.size(); i++){
            for(int j=0;j<elements.size(); j++){
                int temp;
                temp=abs(elements[i]-elements[j]);
                diff_values[index] = temp;
                index++;
            }
        }

        //Insertion sort
        int key, j;
        for(int i=1; i< length*length; i++){
            key = diff_values[i];
            j=i-1;
            while(j>=0 && diff_values[j] > key){
                diff_values[j+1] = diff_values[j];
                j=j-1;
            }
            diff_values[j+1] = key;
        }
        this->maximumDifference = diff_values[length*length-1];
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference << endl;
    string  number="3792";

    if(atoi(number.c_str())){
        cout << atoi(number.c_str()) << endl;
    }
    else
        cout << "Bad string" << endl;

    return 0;
}

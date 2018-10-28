#include<iostream>
using namespace std;

int calc_len_static(int a[]){
	int len = sizeof(a)/sizeof(a[0]);
	return len;
}

int calc_len_dynamic(int* a){
        int len = sizeof(a)/sizeof(a[0]);
        return len;
}

	
int main(){
	//STATIC ARRAY
	int arr1[5] = {2,3,4,5,6};
	int len_main_static = sizeof(arr1)/sizeof(arr1[0]);
	int len_func_static = calc_len_static(arr1);

        // DYNAMIC ARRAY ALLOCATION
        int *arr2 = NULL;
        arr2 = new int[2,4,5,6,7];
        int len_main_dynamic = sizeof(arr2)/sizeof(arr2[0]);
	int len_func_dynamic = calc_len_dynamic(arr2);

	cout << "Length from main: Static " << len_main_static << endl;
        cout << "Length from func: Static " << len_func_static << endl;
	cout << endl;
        cout << "Length from main: Dynamic " << len_main_dynamic << endl;
	cout << "Length from func: Dynamic " << len_func_dynamic << endl;
	
	return 0;

}

/* Output: 

Length from main: Static 5
Length from func: Static 2

Length from main: Dynamic 2
Length from func: Dynamic 2

*/

#include <iostream> 
using namespace std; 


 
int main() { 
	int list[10][2]={{18, 1},
                        	{12, 0},
                         	{14, 7},
                        	{15, 144},
                         	{10, 1},
                         	{1, 1},
                         	{13, 1},
                         	{1, 9},
                        	{2, 14},
                        	{13, 4}};

	int length = 10; 
	int i,j=0,temp1, temp2; 
	bool swapped = false;
	for(i=0;i<length;++i){ 
		for(j=0;j<(length-i);++j){//This"length-i"isneededcauseattheendofeachloop-the 
			if(list[j][0]>list[j+1][0]){//largestelementispushedtowardstheendandhencethereisnoneed 
			temp1=list[j][0];
			temp2=list[j][1];//toloopthroughthesortedelements 
			list[j][0]=list[j+1][0];
			list[j][1]=list[j+1][1]; 
			list[j+1][0]=temp1;
			list[j+1][1]=temp2; 
			swapped=true; 
			} 
		} 
		if(!(swapped)){ 	
			cout<<"The list is sorted"<<endl; 
			break; 
		} 
	}
	for (int i = 0; i < length; ++i)
	{
		cout << list[i][0] << "\t" << list[i][1] << endl;
 	}
	
return 0; 
} 
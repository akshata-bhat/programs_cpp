#include <iostream>
using namespace std;


int stac_size = 100;
char stac[100];
int top = -1;

int pop()
{
	if(top == -1){
		cout << "Stack empty" << endl;
		return NULL;
	}
	else{
		char data = stac[top];
		top-=1;
		return data;
	}
}

int push(char data){
	if(top >= stac_size){
		cout << "Stack full" << endl;
		return NULL;
	}
	else{
		stac[top+1] = data;
		top+=1;
		return top;
	}
}

int main()
{
	char data;
	for(int i=0; i<5; i++) push('A'+i);

	for(int i=0; i<7; i++){
		data =pop();
		cout << data << endl;
	}
}

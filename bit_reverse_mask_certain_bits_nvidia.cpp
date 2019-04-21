#include<stdio.h>

int main(){
	int lo = 1, hi = 2;
	int n = 15;
	int mask=0;
	int temp;
	for(int i=lo; i<=hi; i++)
	{
 	temp = 1;
	temp = temp << i;
	mask = mask | temp;
	}
	int ans = n^mask;
	printf("%d",ans);
}

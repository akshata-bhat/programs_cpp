#include<stdio.h>

int main(){
	int lo = 0, hi = 7;
	int n = 0;
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

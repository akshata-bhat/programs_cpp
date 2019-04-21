#include <stdio.h>
int main()
{
int array[8] = {1,6,2,3,9,12,4,6};
int size = sizeof(array)/(sizeof(int));
printf("%d\n", size);
int count=0;
	for(int i=0;i<size;i=i+2)
	{
		for(int j=i+2;j<size;j=j+2)
		{	
			if(array[j]<array[i+1] || array[j+1]<array[i])
			{
				count++;
			}
		}
	}
	printf("%d", count);
//return count;
}
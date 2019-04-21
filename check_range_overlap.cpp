 #include <stdio.h>

 int main()
 {
 int array[8] = {1,6,2,3,9,12,4,6};
 int size = sizeof(array)/(sizeof(int));
 printf("%d\n", size);
 int count =0;
 if(size<=2){
 	count = 0;
 	printf("%d\n", count);
 	//exit();
 	//return 0;
 }
 int i = 0;
 while (i<size-3){
 	if (array[i]>array[i+2] || array[i+1] > array[i+3] || array[i+2] < array[i+1] ){
 		count+=1;
 	}
 	i=i+2;
 }

 //int count = find_range(arr, size);
 printf("%d", count);
 return 0;
 }
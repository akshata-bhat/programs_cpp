#include <iostream>
using namespace std;
int hit_miss(){
	string shrink_thin[9] = {"00m0m0000", "m000m0000", "0000m00m0", "0000mm000", "0am0mbm00", "mb0am000m", "00mam0mb0", "m000mb0am", "mmdmmdddd"};
	char temp; int abc_found;
	string image = "11111111";
	int hit_value;
	for (int i = 0; i < 9; ++i)
	{
		hit_value=1;
		string mask = bond1[i];
		temp='0';
		abc_found=0;
		for (int j = 0; j < 9; ++j)
		{
			if (mask[j]=='a' || mask[j]=='b' || mask[j]=='c')
			{
				cout << mask[j]<< endl;
				temp=(unsigned char)(temp | image[j]);
				abc_found++;
				continue;
			} 	
			if(mask[j]=='d')
				continue;
			if(mask[j]=='m'){
				if (image[j]=='1')
					continue;
				else{
					hit_value=0;
					break;
				}
			}
			if (mask[j]!=image[j]){
				hit_value=0;
				break;
			}
		} 
		if(temp!='1' && abc_found>0)
			hit_value=0;
		cout << temp << endl;
		cout << abc_found << endl;

		if(hit_value == 1)
			return 1;
	}
	return 0;
}


int main(){
	int hit_value = hit_miss();
	if(hit_value == 1)
		cout << "Match" << endl;
	//cout << (unsigned char)('0' | bond1[1][1])<< endl;
	//string temp = "hello";
	//cout << temp[3] << endl;
	return 0;
}
//if(mask[0]=='0' && mask[1]=='0' && mask[2]=='1' && mask[3]=='0' && mask[4]=='1'
	//&& mask[5]=='0' && mask[6]=='0' && mask[7]=='0' && mask[8]=='0')
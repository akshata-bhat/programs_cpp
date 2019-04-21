#include<iostream>
#include<vector>
using namespace std;


int find_tax_due(vector<int> tt, int deductible, int income, vector<float> rate){  
  int tax_due = 0;
  int rem;
  int net = income - deductible;
  int i;
  for(i=1; i<tt.size(); i++){
  int temp = tt[i] - tt[i-1];
    if(net >= (temp)){
      rem = net - (temp);
      tax_due += temp*rate[i-1];
    }
    else if(net < temp){
       tax_due += net*rate[i-1];
       break;
    }
    net = rem;
    }
    return tax_due;
}

int main(){
	vector<int> taxtable = {0, 10, 30, 80, 150, 200, 500};
	vector<float> rate = {0.1, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37};
	int result = find_tax_due(taxtable, 20, 800, rate);
	cout << result;
	return 0;
}

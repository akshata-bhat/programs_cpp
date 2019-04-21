#include<iostream>
#include<vector>
using namespace std;

int main(){

	string firstName, lastName;
	int id, score_count;
	vector<int> scores;
	cin >> firstName >> lastName >> id >> score_count;
	for(int i=0; i<score_count; i++)
	{
		int tempScore;
		cin >> tempScore;
		scores.push_back(tempScore);
	}

	cout << firstName << endl << lastName << endl<< id << endl;
	for(int i=0; i<scores.size(); i++)
		cout << scores[i] << endl;
	return 0;
}

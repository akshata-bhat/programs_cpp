/*
Consider a game in which a player can move in 4 directions on a map: north, west, south and east. Write a function that will generate all the possible sequences of movements, given an integer indicating the number of movements. However do not include sequences where the player would immediately "backtrack" from the previous movement. For instance, if the previous movement was north, the next movement should not be south.

Each sequence should be represented in a separate line as a string as "NWEN", where each letter indicates the direction of movement.
The lines should be sorted in this order: N, W, S, E
*/


// SOLUTION
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
	queue<string> q;
	q.push("N");
	q.push("W");
	q.push("S");
	q.push("E");
	int n = 3, len;
	string temp;
	while(q.empty() != 1){
		temp = q.front();
		q.pop();
		if(temp.length() == n)
			cout << temp << endl;
		else{
			len = temp.length();

			// To access last character of string 
			if(temp[len-1] == 'N'){
				q.push(temp+"N");
				q.push(temp+"W");
				q.push(temp+"E");
			}
			
			// To access last character of string - using back() does not work for C++98
			else if(temp.back() == 'W'){
                                q.push(temp+"N");
                                q.push(temp+"W");
                                q.push(temp+"S");
			}
                        else if(temp.back() == 'S'){
                                q.push(temp+"W");
                                q.push(temp+"S");
                                q.push(temp+"E");
                        }
                        else if(temp.back() == 'E'){
                                q.push(temp+"N");
                                q.push(temp+"S");
                                q.push(temp+"E");
                        }
		}
	}
	return 0;
}

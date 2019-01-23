#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;

int i, j, h,person , n;
int a[100][100];

int main(){
	
	cin >> n;
	person = 1;
	a[1][1] = 1; 
	h = 1;
	for(i = 1; i <= n ; ++i)
		person = person *2;
		
	do{
		for(i = 1; i <= h; i++)
		for(j = 1; j <= h ; j++){
			a[i] [j+h] = a[i][j] + h;
			a[i+h][j] = a[i][j+h];
			a[i+h][j+h]= a[i][j];	
			
		}
		h = h *2;
//	for(i = 1; i <= n; i++)	{
//		for(j = 1; j <=n; j++)
//		cout <<setw(4)<< a[i][j];
//		cout <<"\n";
//		}
//		cout <<"\n";cout <<"\n";
	}while(!(h == person));
	
	for(i = 1; i <= person; i++)	{
		for(j = 1; j <=person; j++)
		cout <<setw(4)<< a[i][j];
		cout <<"\n";
		
	}	 
		
	return 0;
	 
} 

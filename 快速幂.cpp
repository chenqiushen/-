#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long Pow(long long x, long long n){
	long long result ;
	if(n == 0)
		return 1;
	else 
	{
		while(n& 1 == 0){
			n >>=1;
			x *= x;
		}
	}
	
	
	result = x;
	
	n >>= 1;
	while (n!= 0){
		x *= x;
		if((n& 1) != 0)
		result *=x;
		n >>=1;
		
	}
	return result;
}

int main(){
	
	long long x, n;
	cin >> x>> n;
	cout << Pow(x,n)<<endl;
	return 0;
	
	
	
}






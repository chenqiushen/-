//N皇后——递归算法 
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[21];

void print(){   //打印棋子布局 
	for(int i = 1; i<= n; i++)
	cout <<a[i];
	cout <<endl;
}

void printGraph(){		//图形化打印布局 
	system("color F0"); 	//Dos命令改变背景色和前景色，颜色为16进制数0~F 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j)
			if(a[i] == j)
				cout << "◎"; 
			else
				cout<<"□";
		cout << endl; 
		}
	cout << endl;
}

int Try(int x, int y){   //测试x 行Y列可否摆放棋子，成功返回1，否则返回0 
	int j = 1;
	while(j < x){		//与数组中已经放好的数比较 
		if(a[j] == y|| abs(x- j) == abs(a[j] - y))
			return 0;
		++j;  	//右移一格继续尝试 
	} 
	return 1;
} 

void place(int x){
	int y;
	if(x > n){
		 print();
		printGraph(); 
	}
	
	else 
		for(y = 1 ; y <= n; ++y)
			if(Try(x, y)){
				a[x] = y;
				place(x + 1);
			} 
}


int main (){
	cin >> n;
	place(1);
	return 0;
} 

//N�ʺ󡪡��ݹ��㷨 
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[21];

void print(){   //��ӡ���Ӳ��� 
	for(int i = 1; i<= n; i++)
	cout <<a[i];
	cout <<endl;
}

void printGraph(){		//ͼ�λ���ӡ���� 
	system("color F0"); 	//Dos����ı䱳��ɫ��ǰ��ɫ����ɫΪ16������0~F 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j)
			if(a[i] == j)
				cout << "��"; 
			else
				cout<<"��";
		cout << endl; 
		}
	cout << endl;
}

int Try(int x, int y){   //����x ��Y�пɷ�ڷ����ӣ��ɹ�����1�����򷵻�0 
	int j = 1;
	while(j < x){		//���������Ѿ��źõ����Ƚ� 
		if(a[j] == y|| abs(x- j) == abs(a[j] - y))
			return 0;
		++j;  	//����һ��������� 
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

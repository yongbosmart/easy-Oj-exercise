//============================================================================
// Name        : OJ_ant.cpp
// Author      : yongbo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<stdio.h>
#include <iostream>
using namespace std;
//int MAX_N=100000;//ע����ȷ�Ĵ����涨��ʽѧϰһ�£��Լ���������ʹ�÷�ʽ
int L,n;
int x[100000];

void solve(){
	scanf("%d",&L);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);//ע������������÷���
	}
	//�������ʱ��
	int minT=0;
	for(int i=0;i<n;i++){
		minT=max(minT,min(x[i],L-x[i]));//�õ������Сֵ
	}
	int maxT=0;
	for(int i=0;i<n;i++){
		maxT=max(maxT,max(x[i],L-x[i]));
	}
	printf("%d%d\n",minT,maxT);
	getchar();
	getchar();

}

int main() {
//	cout << "hello,world" << endl; // prints hello,world
	//����
	solve();
	return 0;
}
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
//int MAX_N=100000;//注意正确的大数规定方式学习一下，以及浮点数的使用方式
int L,n;
int x[100000];

void solve(){
	scanf("%d",&L);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);//注意这里加上引用符号
	}
	//计算最短时间
	int minT=0;
	for(int i=0;i<n;i++){
		minT=max(minT,min(x[i],L-x[i]));//得到最大，最小值
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
	//输入
	solve();
	return 0;
}

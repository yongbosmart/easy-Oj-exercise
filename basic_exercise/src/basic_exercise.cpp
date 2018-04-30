//============================================================================
// Name        : basic_exercise.cpp
// Author      : yongbo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
#include <iostream>
using namespace std;
//空间大的最简单的排序：桶排序
/**
 * 初始化一个数组，然后放入数字，=0不输出，=1输出
 */
//system("pause")可以暂停程序
//如果排序需要去重的话，我个人认为输出的时候去重比较好（似乎 of course）


int a[100],n;//

void quicksort(int *a,int x,int y){//x,起始点，y,长度 递归实现的快排，好像是这样的QAQ
	if(y>1){
		int tmp=a[x];
		for(int j=0;j<y-1;j++){//这么多次循环
			if(a[x]<a[j+x]&a[0]>a[j+x+1]){
				int temp=a[j+x];
				a[j+x]=a[x];
				a[x]=temp;
				quicksort(a,x,j-x);
				quicksort(a,j+1,y-j);
			}
		}
	}
	for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;

}
void xuanze(int *a){//由大到小
//	int *b=a;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				int tmp=a[j];
				a[j]=a[i];
				a[i]=tmp;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void maopao(int *a){
//	int *b=a;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(a[j]<a[j+1]){
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
		printf("%s"," ");
	}
	getchar();//用来暂停程序，以便查看程序输出，用system（“pause”）可以起到相同的效果
	getchar();//get字符（可能顺序有反，不过有一个是暂停的perhaps）
}

int main() {
	scanf("%d",&n);//输入一个数
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	maopao(a);
	xuanze(a);
	quicksort(a,0,n);
	return 0;
}

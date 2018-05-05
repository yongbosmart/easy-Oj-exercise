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

void quicksort(int *a,int left,int right){//x,起始点，y,长度 递归实现的快排，好像是这样的QAQ
	//注意对比和标程的区别
	int i,j,t,temp;
	if(left>right)
		return;

	temp=a[left];//temp中存基准数
	i=left;
	j=right;
	while(i!=j){
		//顺序很重要，要先从右往左找
		while(a[j]>=temp&&i<j)
			j--;//找到基准右侧比基准小的数
		//再从左往右找
		while(a[i]<=temp&&i<j)
			i++;//找到基准左侧比基准大的数
		//交换两个数在数组中的位置，
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}

	}
	//最终将基准数归位。即基准数为最左边那个数，先把它右边的数大于它小于它的排好，再将基准数归位。
	a[left]=a[i];
	a[i]=temp;

	quicksort(a,left,i-1);
	quicksort(a,i+1,right);
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
int binary_search(int i,int *a){

}

int main() {
	scanf("%d",&n);//输入一个数
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
//	maopao(a);
//	xuanze(a);
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

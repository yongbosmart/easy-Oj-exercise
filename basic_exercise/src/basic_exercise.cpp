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
//�ռ�����򵥵�����Ͱ����
/**
 * ��ʼ��һ�����飬Ȼ��������֣�=0�������=1���
 */
//system("pause")������ͣ����
//���������Ҫȥ�صĻ����Ҹ�����Ϊ�����ʱ��ȥ�رȽϺã��ƺ� of course��


int a[100],n;//

void quicksort(int *a,int x,int y){//x,��ʼ�㣬y,���� �ݹ�ʵ�ֵĿ��ţ�������������QAQ
	if(y>1){
		int tmp=a[x];
		for(int j=0;j<y-1;j++){//��ô���ѭ��
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
void xuanze(int *a){//�ɴ�С
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
	getchar();//������ͣ�����Ա�鿴�����������system����pause������������ͬ��Ч��
	getchar();//get�ַ�������˳���з���������һ������ͣ��perhaps��
}

int main() {
	scanf("%d",&n);//����һ����
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	maopao(a);
	xuanze(a);
	quicksort(a,0,n);
	return 0;
}
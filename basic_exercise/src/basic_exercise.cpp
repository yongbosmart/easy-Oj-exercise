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

void quicksort(int *a,int left,int right){//x,��ʼ�㣬y,���� �ݹ�ʵ�ֵĿ��ţ�������������QAQ
	//ע��ԱȺͱ�̵�����
	int i,j,t,temp;
	if(left>right)
		return;

	temp=a[left];//temp�д��׼��
	i=left;
	j=right;
	while(i!=j){
		//˳�����Ҫ��Ҫ�ȴ���������
		while(a[j]>=temp&&i<j)
			j--;//�ҵ���׼�Ҳ�Ȼ�׼С����
		//�ٴ���������
		while(a[i]<=temp&&i<j)
			i++;//�ҵ���׼���Ȼ�׼�����
		//�����������������е�λ�ã�
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}

	}
	//���ս���׼����λ������׼��Ϊ������Ǹ������Ȱ����ұߵ���������С�������źã��ٽ���׼����λ��
	a[left]=a[i];
	a[i]=temp;

	quicksort(a,left,i-1);
	quicksort(a,i+1,right);
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
int binary_search(int i,int *a){

}

int main() {
	scanf("%d",&n);//����һ����
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

//============================================================================
// Name        : queue_stack_ex1.cpp
// Author      : yongbo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/**
 * �����㷨�е�ֽ����Ϸ��stack-queue����ϰ��
 */

#include<stdio.h>
#include <queue>
#include<stack>
#include <iostream>
using namespace std;
bool awin=false,bwin=false;
struct stack2{
	int card[10];int top=0;
};
stack2 s;
int a_win(int x){
	for(int i=0;i<=s.top;i++){  //������ѭ���ƺ�����ȷ�����㷨������ֱ�Ӱ�����������ȥ��breakֻ������һ��ѭ���������Ҫ�������ѭ��ʱ������ʹ�ò�����
			if(x==s.card[i]){
				awin=true;
				return i;
//					break;//ֻ������һ��ѭ��
			}
	}
	return -1;
}
int b_win(int x){
	for(int i=0;i<=s.top;i++){  //������ѭ���ƺ�����ȷ�����㷨������ֱ�Ӱ�����������ȥ��breakֻ������һ��ѭ���������Ҫ�������ѭ��ʱ������ʹ�ò�����
			if(x==s.card[i]){
				bwin=true;
				return i;
//					break;//ֻ������һ��ѭ��
			}
	}
	return -1;
}

void card_game(){//������������жϷ������ܵ��úܶ�ȫ�ֱ�����
	int l,m,n;
	scanf("%d",&l);
	queue<int> a;
	queue<int> b;
	for(int i=0;i<l;i++){
		scanf("%d",&m);
		a.push(m);
	}
//	scanf("%d",&n);
	for(int i=0;i<l;i++){
		scanf("%d",&n);
		b.push(n);
	}
	//�������㷨��P38���е���������ģ��ջ��һ�������һ��top���ӡ�
	//һ���������棬so��card������10,������10�϶���������ͬ�������ˣ�����
	//һ��1,2,3,4,5��Ӧ�����±����Ҳ��Ӧ������card[1]�У��������˼��
	while((!a.empty())&(!b.empty())){
//		bool wina=false;
//		bool winb=false;
		int x=a.front();
		a.pop();
		int mm=a_win(x);
		if(mm!=-1){
			for(int j=s.top;j>=mm;j--){
				b.push(s.card[j]);
				s.card[j]=0;
				s.top--;
		   }
		}else{
			s.top++;
			s.card[s.top]=x;
		}
		int y=b.front();
		b.pop();
		int nn=b_win(y);
		if(nn!=-1){
			for(int j=s.top;j>=nn;j--){
				b.push(s.card[j]);
				s.card[j]=0;
				s.top--;
		   }
		}else{
			s.top++;
			s.card[s.top]=x;
		}
	}
	if(a.empty()) printf("%s","b");
	else printf("%s","a");

	getchar();
	getchar();
}


int main() {
//	cout << "!!!queue_stack_ex1!!!" << endl; // prints !!!queue_stack_ex1!!!
	card_game();
	return 0;
}

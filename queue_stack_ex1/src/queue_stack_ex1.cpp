//============================================================================
// Name        : queue_stack_ex1.cpp
// Author      : yongbo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/**
 * 啊哈算法中的纸牌游戏，stack-queue简单练习。
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
	for(int i=0;i<=s.top;i++){  //跳几层循环似乎难以确定，算法书上是直接把这个方法提出去了break只能跳出一个循环，因此需要跳出多个循环时，可以使用布尔量
			if(x==s.card[i]){
				awin=true;
				return i;
//					break;//只能跳出一层循环
			}
	}
	return -1;
}
int b_win(int x){
	for(int i=0;i<=s.top;i++){  //跳几层循环似乎难以确定，算法书上是直接把这个方法提出去了break只能跳出一个循环，因此需要跳出多个循环时，可以使用布尔量
			if(x==s.card[i]){
				bwin=true;
				return i;
//					break;//只能跳出一层循环
			}
	}
	return -1;
}

void card_game(){//方法出错。提出判断方法可能得用很多全局变量。
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
	//啊哈，算法（P38）中的利用数组模拟栈，一个数组和一个top足矣。
	//一共九种牌面，so，card不超过10,（超过10肯定有两个相同的牌面了）！！
	//一般1,2,3,4,5对应数组下标最后也对应。存在card[1]中！！这里的思想
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

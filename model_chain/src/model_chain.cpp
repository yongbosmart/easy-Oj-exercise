//============================================================================
// Name        : model_chain.cpp
// Author      : yongbo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/**
 * 模拟链表即一个数组存放data，另一个数组存放其next的值
 * 新插入数字放在末尾，然后改变对应的另一个数组存放的next值。
 * 一道使用模拟链表的算法题，破损的键盘
 * 在显示屏上盲打一段文字，在这过程中由于键盘的问题，Home键与end键会自动按下，显有一段文本，其中‘[’表示Home键按下，‘]’表示End键按下，求出显示屏上的文字排序
 *示例输入
 *This_is_a_[Beiju]_text
 *示例输出
 *BeijuThis_is_a__text
 */
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 100000+5;
int last,cur ,next[maxn];
char s[maxn];
//设输入字符串为s[1~n],则可以用next[i]表示在当前显示屏中s[i]右边的字符编号
//为了方便起见，假设字符串s的最前面还有一个虚拟的s[0], 则next[0]就可以表示显示屏最左边的字符，
//再用一个cur表示光标位置，则s[cur]即表示光标位于当前字符s[cur]的右边。s[0]表示光标在屏幕的初始位置。
//为了移动光标，还需要用一个变量last表示显示屏的最后一个字符是s[last]。

int main(){
    while(scanf("%s",s+1) == 1){
        //从控制台读取数据，然后将数据存到从s+1开始的地方
        int n =strlen(s+1);
        last=cur=0;//初始光标为0，末尾也为0，，注意这里字符串不用变，改变字符的next即可以
        next[0]=0;

        for(int i=1;i<n;i++){//从1开始有时候比较方便
            char ch=s[i];//s[0]虚拟，注意
            if(ch=='[') cur = 0;//此后字符将从头开始输入
            else if(ch==']')  cur = last;//此后字符将从末尾开始输入
            else {
                next[i] = next[cur];//难理解的根本原因是，这里是数组模拟的链表，所以一时忘记了
                next[cur] = i;//
                if(cur == last) last=i;
                cur = i;
            }

        }
        for( int i=next[0]; i!=0; i=next[i])//数组表示链表时的打印表达方式
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}

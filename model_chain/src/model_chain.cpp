//============================================================================
// Name        : model_chain.cpp
// Author      : yongbo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/**
 * ģ������һ��������data����һ����������next��ֵ
 * �²������ַ���ĩβ��Ȼ��ı��Ӧ����һ�������ŵ�nextֵ��
 * һ��ʹ��ģ��������㷨�⣬����ļ���
 * ����ʾ����ä��һ�����֣�������������ڼ��̵����⣬Home����end�����Զ����£�����һ���ı������С�[����ʾHome�����£���]����ʾEnd�����£������ʾ���ϵ���������
 *ʾ������
 *This_is_a_[Beiju]_text
 *ʾ�����
 *BeijuThis_is_a__text
 */
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 100000+5;
int last,cur ,next[maxn];
char s[maxn];
//�������ַ���Ϊs[1~n],�������next[i]��ʾ�ڵ�ǰ��ʾ����s[i]�ұߵ��ַ����
//Ϊ�˷�������������ַ���s����ǰ�滹��һ�������s[0], ��next[0]�Ϳ��Ա�ʾ��ʾ������ߵ��ַ���
//����һ��cur��ʾ���λ�ã���s[cur]����ʾ���λ�ڵ�ǰ�ַ�s[cur]���ұߡ�s[0]��ʾ�������Ļ�ĳ�ʼλ�á�
//Ϊ���ƶ���꣬����Ҫ��һ������last��ʾ��ʾ�������һ���ַ���s[last]��

int main(){
    while(scanf("%s",s+1) == 1){
        //�ӿ���̨��ȡ���ݣ�Ȼ�����ݴ浽��s+1��ʼ�ĵط�
        int n =strlen(s+1);
        last=cur=0;//��ʼ���Ϊ0��ĩβҲΪ0����ע�������ַ������ñ䣬�ı��ַ���next������
        next[0]=0;

        for(int i=1;i<n;i++){//��1��ʼ��ʱ��ȽϷ���
            char ch=s[i];//s[0]���⣬ע��
            if(ch=='[') cur = 0;//�˺��ַ�����ͷ��ʼ����
            else if(ch==']')  cur = last;//�˺��ַ�����ĩβ��ʼ����
            else {
                next[i] = next[cur];//�����ĸ���ԭ���ǣ�����������ģ�����������һʱ������
                next[cur] = i;//
                if(cur == last) last=i;
                cur = i;
            }

        }
        for( int i=next[0]; i!=0; i=next[i])//�����ʾ����ʱ�Ĵ�ӡ��﷽ʽ
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}

////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-05-02 10:50:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#define LEN 2000
int an1[LEN+10];
int an2[LEN+10];
char stra[LEN+10];
char strb[LEN+10];
int main()
{
int t,n=0,j;
scanf("%d",&t);
while(n++<t)
{
memset(an1,0,sizeof(an1));//�������ʼ����
        memset(an2,0,sizeof(an2));
scanf("%s", stra);
        scanf("%s", strb);
        int i, j;
        int Len1 = strlen( stra);
        for( j = 0, i = Len1 - 1;i >= 0 ; i--)  //����浽��һ������������ 
            an1[j++] = stra[i] - '0';
        int Len2 = strlen(strb);
        for( j = 0, i = Len2 - 1;i >= 0 ; i--)
            an2[j++] = strb[i] - '0';
        for( i = 0;i < LEN ; i ++ ) 
        {  an1[i] += an2[i]; //��λ���
           if( an1[i] >= 10 ) 
           { //���Ƿ�Ҫ��λ
              an1[i] -= 10;
              an1[i+1] ++; //��λ
           }
        }
         printf("Case %d:\n",n);//������
         printf("%s + %s = ",stra,strb);
         for(j=LEN+10;an1[j]==0;j--);//�Ӹ�λ��c������ĸ��ų�
         if(j<0)
            printf("0");
         else
         for(;j>=0;j--)
         {
            printf("%d",an1[j]);
         }
         printf("\n");
         if(n<t)           // ע����Ŀ�����ʽ 
           printf("\n");
    }
    return 0;
}
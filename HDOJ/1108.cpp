////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-01-25 19:22:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//��С���������������ĳ˻��������Լ��
#include <stdio.h>

int main(){
    int x, y, t, xx, yy;
    while( scanf( "%d%d", &x, &y ) == 2 ){
        xx = x; //����ԭ����
        yy = y;
        while( yy ){
            t = xx % yy;
            xx = yy;
            yy = t;
        } //xxΪ���Լ��,����������
        printf( "%d\n", x / xx * y ); //�����
    }
    return 0;
}

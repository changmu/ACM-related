////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-01-25 11:56:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAX 400 + 10
char a0[MAX], b0[MAX], s[MAX], aa[MAX], bb[MAX], ss0[MAX];  //aa����������a����С��

int main(){
	char *dot;
	while( scanf( "%s%s", a0, b0 ) == 2 ){
		char *a = a0, *b = b0, *ss = ss0;
		aa[0] = bb[0] = '0';  //���Ž�λ
		dot = strchr( a, '.' );
		if( dot == NULL ){ strcpy( aa + 1, a ); a[0] = '\0'; } //���a����������a�ÿ�
		else{ dot[0] = '\0'; strcpy( aa + 1, a ); a = dot + 1; }
		dot = strchr( b, '.' );
		if( dot == NULL ){ strcpy( bb + 1, b ); b[0] = '\0'; }
		else{ dot[0] = '\0'; strcpy( bb + 1, b ); b = dot + 1; }
		
		//��������ʼ������������aa+bb
		int aai = strlen( aa ), bbi = strlen( bb );  //��������λ��
		int ssi = aai > bbi ? aai : bbi;
		ss[ssi] = '\0';
		int i = aai < bbi ? aai : bbi;  //�����Сλ��
		int sign = 0, t; //�����λ
		while( i-- ){
			t = aa[--aai] - '0' + ( bb[--bbi] - '0' );
			t += sign; sign = 0;
			if( t > 9 ) { ++sign; t -= 10; }
			ss[--ssi] = t + '0';
		}
		while( aai ){ 
			t = aa[--aai] - '0';  //����1+99999�����
			t += sign; sign = 0;
			if( t > 9 ) { ++sign; t -= 10; }
			ss[--ssi] = t + '0'; 
		}
		while( bbi ){ 
			t = bb[--bbi] - '0'; 
			t += sign; sign = 0; 
			if( t > 9 ) { ++sign; t -= 10; }
			ss[--ssi] = t + '0'; 
		}
		//�������ӷ�aa+bb��ɣ�2014-1-25 00:59:04
		
		//С�����ֵļӷ���ע��λҪ���룬sign�ѱ�����0��2014-1-25 09:49:02
		int ai = strlen( a ), bi = strlen( b );  //����С��λ��
		int si = ai > bi ? ai : bi;
		s[si] = '\0';
		int j = ai < bi ? ai : bi;  //�����Сλ��
		while( j-- ){
			t = a[j] - '0' + ( b[j] - '0' );
			t += sign; sign = 0;
			if( t > 9 ){ ++sign; t -= 10; }
			s[j] = t + '0';
		}
		j = ai < bi ? ai : bi;
		if( ai < bi ) strcpy( s + j, b + j ); 
		else if( ai > bi ) strcpy( s + j, a + j );		
		
		//��С��λ���ܲ����Ľ�λ���ϵ�������ss��
		ssi = strlen( ss );
		if( sign ){ //���С����Ӳ����˸�λ��λ1
			while( ssi ){
				t = ss[--ssi] - '0' + sign;
				sign = 0;
				if( t > 9 ){ t -= 10; ++sign; }
				ss[ssi] = t + '0';
			} //���������������			
		}
		
		//����С���͵�ĩβ0
		si = strlen( s );
		while( si ){
			if( s[--si] == '0' ){ s[si] = '\0'; continue; }
			break;
		}
		
		//���������Ϳ��ܴ��ڵ�ǰ��0
		int ii = 0;
		for( ; ss[ii] != '\0'; ++ii ){
			if( ss[ii] == '0' ) continue;
			break;
		}
		ss = ss + ii;
		if( !strlen(ss) ){  //��ֹss�����ɿ��ַ���
			ss[0] = '0';
			ss[1] = '\0';
		}
		//������
		printf( "%s", ss );
		si = strlen( s );
		if( si ){
			putchar( '.' );
			printf( "%s", s );
		}
		putchar( '\n' );
	}
	return 0;
}
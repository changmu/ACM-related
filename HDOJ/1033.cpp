////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-05-09 11:32:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char str[202];

int main(){
	int x, y, len, dir;
	while(scanf("%s", str) == 1){
		printf("300 420 moveto\n310 420 lineto\n");
		x = 310; y = 420;
		len = strlen(str);
		dir = 1; //1�������ң�2�������£�3��������0��������
		for(int i = 0; i < len; ++i){
			if(str[i] == 'A'){
				switch(dir){
					case 1: y -= 10; break;
					case 2: x -= 10; break;
					case 3: y += 10; break;
					case 0: x += 10;
				}
				dir = (dir + 1) % 4;
			}else{
				switch(dir){
					case 1: y += 10; break;
					case 2: x += 10; break;
					case 3: y -= 10; break;
					case 0: x -= 10;
				}
				dir = (dir + 3) % 4;
			}
			printf("%d %d lineto\n", x, y);
		}
		printf("stroke\nshowpage\n");
	}
	return 0;
}
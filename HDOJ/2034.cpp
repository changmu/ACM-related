////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ��ľ
////Run ID: 
////Submit time: 2014-01-27 14:51:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int a, b, t, sign;
	vector<int> veca, vecb, vec;
	while(cin >> a >> b, a || b){
		sign = 1;
		//��������
		while(a--){
			cin >> t;
			veca.push_back(t);
		}
		while(b--){
			cin >> t;
			vecb.push_back(t);
		}
		//��ʼ����
		for(int i = 0; i != veca.size(); ++i){
			for(int j = 0; j != vecb.size(); ++j)
				if(veca[i] == vecb[j]){ sign = 0; break; }
			if(sign)
				vec.push_back(veca[i]);
			sign = 1;
		}
		//���
		if(vec.empty()) cout << "NULL";
		else{
			sort(vec.begin(), vec.end());
			for(int i = 0; i != vec.size(); ++i)
				cout << vec[i] << ' ';
		}
		cout << endl;
		//�������
		vec.clear(); veca.clear(); vecb.clear();
	}
	return 0;
}
/************************************************************* 
 * 4�����Ѿۻᣬ����һ��������������������ǵĶԻ���
 * A��������
 * B����C
 * C����D
 * D��C�ں�˵
 * ��֪����ֻ��һ������˵�ѣ��ʣ�˭��������ա�
 *************************************************************/ 
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int bir, i, sum;
    for (bir = 0; bir < 4; ++bir) {
        sum = (bir != 0) + (bir == 2) + (bir == 3) + (bir != 3);
        if (sum == 3) break;
    }
    cout << "Today is " << (char)('A' + bir) << "'s birthday!" << endl;
    return 0;
}

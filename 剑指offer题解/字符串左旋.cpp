/************************************************************* 
 * ��һ���ַ���ǰ�����ɸ�����ת�Ƶ��ַ���β�������������ַ���
 * "abcdefg"������2������Ϊ��"cdefgab".
 *************************************************************/ 
char *LeftRotateString(char *pStr, int n)
{
	if (pStr == NULL || n < 1) return NULL;

	int length = strlen(pStr);
	if (n >= length) return pStr;

	char *pFirstStart = pStr;
	char *pFirstEnd = pStr + n - 1;
	char *pSecondStart = pStr + n;
	char *pSecondEnd = pStr + length - 1;

	Reverse(pFirstStart, pFirstEnd);
	Reverse(pSecondStart, pSecondEnd);
	Reverse(pFirstStart, pSecondEnd);
	
	return pStr;
}

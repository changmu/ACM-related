/*
** ��Ŀ��ʵ��һ�����������ַ�����ÿ���ո��滻��'%20'����������'We are happy.'�������'We%20are%20happy.'��ֻ����ԭ�ַ��������滻�����ұ�֤������ַ����������㹻��Ŀ����ڴ档
*/

/*
** ˼·���ȱ���һ���ַ�������ȡ�ո���ĸ������Դ��ж���ɺ���ַ������ȣ�Ȼ��������ָ��p1ָ���´���β��p2ָ��ԭ����β������ָ��ͬʱ������ƶ����滻��
*/

// lengthΪ�ַ�������string��������
void ReplaceBlank(char string[], int length) {
	if (string == NULL || length <= 0) return;

	// originalLengthΪ�ַ���string��ʵ�ʳ���
	int originalLength = 0;
	int numberOfBlank = 0;

	for (int i = 0; string[i]; ++i) {
		++originalLength;
		if (string[i] == ' ') ++numberOfBlank;
	}

	// newLengthΪ�ո��滻��ĳ���
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length) return;

	int indexOfOriginal = originalLength;
	int indexOfNew = newLegnth;

	for ( ; indexOfOriginal >= 0 && indexOfOriginal < indexOfNew; --indexOfOriginal) {
		if (string[indexOfOriginal] == ' ') {
			string[indexOfnew--] = '0';
			string[indexOfnew--] = '2';
			string[indexOfnew--] = '%';
		} else string[indexOfnew--] = string[indexOfOriginal];
	}
}

// via:changmu

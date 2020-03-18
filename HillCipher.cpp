/* mrh_Andy
	Hill Cipher Calculator
	ϣ������������
	ΪɶҪ������Ӧ�أ���Ϊ��steam��������ϣ������������ģ������ְ���steam�������ˣ����Ҳ����������ˣ����д���==
	v1.0 2020/03/18	���Զ����������� ��֧�����֡���ĸ
	*/
#include<iostream>
using namespace std;
#define SIZE 20					//��������С

//ϣ��������㺯��
void HillCipher() {
	int a[4] = { 0 };					//������������ �����Ҵ��ϵ���a b c d
	int i;									//�Ϲ�������
	char tool = '\0';				//�Ϲ����˶���
	cout << "input the characteristic matrix:" << endl;
	cout<<"    |a    b|"<<endl;
	cout<<"    |c    d|"<<endl;
	for (i = 0; i < 4; i++) {
		tool = 'a' + i;
		cout << tool << ":";
		cin >> a[i];
	}

	char input[SIZE];
	memset(input, '\0' , SIZE)	;//��ʼ��
	cout << "input the sentence : (this can only work for double number characters)" << endl;
	cin >> input;
	int num[SIZE] = { 0 };
	int flag[SIZE] = { 0 };			//��ĸ1 ����0

	cout << "Key��";
	for (i = 0; input[i] != ' '; i++) {
		if (input[i] >= 48 && input[i] <= 57) 
			num[i] = input[i] - '0';
		else {
			num[i] = input[i] - 'a' + 1;
			flag[i] = 1;
		}

		if (i % 2) {						//ÿ��λһ�μ���
			num[i - 1] = (num[i - 1] * a[0] + num[i] * a[2]) % 26;
			num[i] = (num[i - 1] * a[1] + num[i] * a[3]) % 26;

			//����ĸ��0ת��Ϊ26
			if (num[i - 1] == 0 && flag[i - 1]) 
				num[i - 1] = 26;
			if (num[i] == 0 && flag[i]) 
				num[i] = 26;

			//�õ�����
			if (flag[i - 1]) 
				input[i - 1] = num[i - 1] + 'a' - 1;
			else 
				input[i - 1] = num[i - 1] + '0';
			if (flag[i]) 
				input[i] = num[i] + 'a' - 1;
			else 
				input[i] = num[i] + '0';

			cout << input[i - 1] << input[i];
		}
	}
	cout << endl;
}

int main() {
	HillCipher();
	return 0;
}
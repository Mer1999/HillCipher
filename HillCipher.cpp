/* mrh_Andy
	Hill Cipher Calculator
	希尔密码生成器
	为啥要做这玩应呢，因为我steam密码是用希尔密码造出来的，而我又把我steam密码忘了，而我不想再手算了，故有此物==
	v1.0 2020/03/18	可自定义特征矩阵 仅支持数字、字母
	*/
#include<iostream>
using namespace std;
#define SIZE 20					//最大数组大小

//希尔密码计算函数
void HillCipher() {
	int a[4] = { 0 };					//特征矩阵内容 从左到右从上到下a b c d
	int i;									//老工具人了
	char tool = '\0';				//老工具人二号
	cout << "input the characteristic matrix:" << endl;
	cout<<"    |a    b|"<<endl;
	cout<<"    |c    d|"<<endl;
	for (i = 0; i < 4; i++) {
		tool = 'a' + i;
		cout << tool << ":";
		cin >> a[i];
	}

	char input[SIZE];
	memset(input, '\0' , SIZE)	;//初始化
	cout << "input the sentence : (this can only work for double number characters)" << endl;
	cin >> input;
	int num[SIZE] = { 0 };
	int flag[SIZE] = { 0 };			//字母1 数字0

	cout << "Key：";
	for (i = 0; input[i] != ' '; i++) {
		if (input[i] >= 48 && input[i] <= 57) 
			num[i] = input[i] - '0';
		else {
			num[i] = input[i] - 'a' + 1;
			flag[i] = 1;
		}

		if (i % 2) {						//每两位一次计算
			num[i - 1] = (num[i - 1] * a[0] + num[i] * a[2]) % 26;
			num[i] = (num[i - 1] * a[1] + num[i] * a[3]) % 26;

			//将字母的0转换为26
			if (num[i - 1] == 0 && flag[i - 1]) 
				num[i - 1] = 26;
			if (num[i] == 0 && flag[i]) 
				num[i] = 26;

			//得到密码
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
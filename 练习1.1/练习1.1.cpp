#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	double power[99];
	int powerCount = 0;//当前数组中的元素个数
	double inserPower;
	int insertIndex = 0;//默认插入到第一个位置
	power[powerCount++] = 45771;
	power[powerCount++] = 42322;
	power[powerCount++] = 40907;
	power[powerCount++] = 40706;

	double temp;
	for (int i = 0; i < powerCount-1; i++) {
		for (int j = 0; j < powerCount - i - 1; i++) {
			if (power[j] < power[j + 1]) {
				temp = power[j];
				power[j] = power[j + 1];
				power[j + 1] = temp;
			}
		}
	}
	cout << "排序后:" << endl;
	for (int i = 0; i < powerCount; i++) {
		cout << power[i] << '\t';
	}
	cout << endl;
	//插入
	cout << "请输入要插入的数字";
	cin >> inserPower;
	insertIndex = powerCount;
	//1.找到第一个比插入数字大的位置insertIndex
	for (int i = 0; i < powerCount; i++) {
		if (inserPower > power[i]) {
			insertIndex = i;
			break;
		}
	}
	//2.从最后一个元素开始,将数字复制到后面一个元素中
	for (int i = powerCount - 1; i >= insertIndex; i--) {
		power[i + 1] = power[i];
	}
	//3.将要插入的数字赋值给下标为insertIndex的元素
	power[insertIndex] = inserPower;
	//4.将数组的总长度+1
	powerCount++;
	cout << "插入后:" << endl;
	for (int i = 0; i < powerCount; i++) {
		cout << power[i] << '\t';
	}
	cout << endl;
	//删除
	//1.找到要删除的元素下标
	double deletePower;
	int deleteIndex = INT_MIN;
	cout << "请输入要删除的数字:";
	cin >> deletePower;
	for (int i = 0; i < powerCount; i++) {
		if (deleteIndex == power[i]) {
			deleteIndex = i;
			break;
		}
	}
	if (deletePower == INT_MIN) {
		cout << "没有找到要删除的元素,删除失败!" << endl;
	}else {
        //2.从找到的下标开始,后面一个元素赋值给前面一个元素
		for (int i = deleteIndex; i < powerCount - 1; i++) {
			power[i] = power[i + 1];
		}
	    //3.总长度-1
		powerCount--;
	}
	cout << "删除后:" << endl;
	for (int i = 0; i < powerCount; i++) {
		cout << power[i] << '\t';
	}
	cout << endl;


	system("pause");
	return 0;
}
#include"myPeopleManage.h"
#include<ctime>
#include<cstdlib>//随机数
#include<Windows.h>

//全局变量
extern vector<Door> d;

vector<People>p = { {"小王",123,234},{"小孙",321,434} ,{"小李",111,234} };
int peopleID = p.size();

//生成随机的个人标识
int getRand(int min,int max) {
	srand(time(NULL));
	return (rand() % (max - min - 1)) + min;
}


void addNewPeople() {
	cout << "正在录入人员信息：" << endl;
	class People newPeople;
	int flag = 0;
	cout << "请输入登记人员的名字:";
	cin >> newPeople.m_name;
	cout << "正在给这个人一条独特的标识(三位数字)" << endl;
	Sleep(1000);
	newPeople.m_peopleKey = getRand(100,999);
	cout << "成功!" << endl;

	cout << "请问您是几号楼几单元(三位数字,1开头，后两位分别是楼号和单元号):";
	cin >> newPeople.haveGuard;

	for (Door everyDoor : d) {
		if (everyDoor.Key == newPeople.haveGuard) {
			cout << "即将给您颁发门禁" << endl;

			//简单加密
			newPeople.haveGuard += (newPeople.m_peopleKey);

			p.push_back(newPeople);
			cout << "成功" << endl;
			flag = 1;
		}
	}
	if (!flag) {
		cout << "失败" << endl;
	}
}


void erasePeople() {
	string tempName;
	int index = 0;
	cout << "请输入要删除的姓名:";
	cin >> tempName;
	for (People P : p) {
		if (P.m_name == tempName) {
			p.erase(p.begin()+index);
		}
		index++;
	}
	if (index == p.size()) {
		cout << "删除失败，请检查姓名是否正确" << endl;
	}
	else {
		cout << "删除成功!" << endl;
	}
}


void chgPeopleMessage() {
	string name;
	int flag = 1;
	cout << "请输入您的名字:";
	cin >> name;
	for (int i = 0; i < p.size(); i++) {
		if (p.at(i).m_name == name) {
			cout << "您只能更改几号楼几单元:";
			cin >> p.at(i).haveGuard;
			flag = 0;
			break;
		}
	}
	if (flag) {
		cout << "未能找到您的信息" << endl;
	}
	else {
		cout << "更改成功!" << endl;
	}
}

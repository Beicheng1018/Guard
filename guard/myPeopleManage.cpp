#include"myPeopleManage.h"

//全局变量
extern vector<Door> d;

vector<People>p = { {"小王",123,111}};
int peopleID = p.size();


void addNewPeople() {
	cout << "正在录入人员信息：" << endl;
	class People newPeople;
	int flag = 0;
	cout << "请输入登记人员的名字:";
	cin >> newPeople.m_name;
	cout << "请给这个人一条独特的标识(三位数字):";
	cin >> newPeople.m_peopleKey;
	cout << "请问您是几号楼几单元(三位数字,1开头，后两位分别是楼号和单元号):";
	cin >> newPeople.haveGuard;
	for (Door everyDoor : d) {
		if (everyDoor.Key == newPeople.haveGuard) {
			cout << "即将给您颁发门禁" << endl;
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
}


void chgPeopleMessage() {
	cout << "待添加此功能" << endl;
	//int tempID;
	//cout << "请输入要修改的人的id:";
	//cin >> tempID;
	//if (tempID <= peopleID) {
	//	class People newPeople;//创建新的门
	//	cout << "请输入要更改的人员的名字:";
	//	cin >> newPeople.m_name;
	//	cout << "请输入要更新的住址:";
	//	cin >> newPeople.address;
	//	newPeople.m_ID = p[tempID].m_ID;//id必须一样
	//	p.erase(p.begin() + tempID);//先删除
	//	p.insert(p.begin() + tempID, newPeople);//后插入，以实现修改
	//}
	//else {
	//	cout << "请输入一个有效的id" << endl;
	//}
}

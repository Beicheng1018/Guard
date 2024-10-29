#include"myPeopleManage.h"


vector<People>p = { { "小王" ,{ {0,124,"老王"},{1,123,"老王"}} } };
int peopleID = p.size();

void addNewPeople() {
	cout << "正在录入人员信息：" << endl;
	class People newPeople;
	cout << "请输入登记人员的名字:";
	cin >> newPeople.m_name;
	while (1) {
		cout << "正在增加一个新的门禁：" << endl;
		class Guard newGuard;
		cout << "请输入新的门禁持有者的名字:";
		cin >> newGuard.owner;
		cout << "请输入门的密钥:";
		cin >> newGuard.Key;
		newGuard.m_ID = guardID;
		guardID++;
		g.push_back(newGuard);
		newPeople.HaveGuard.push_back(newGuard);
		cout << "创建完成！" << endl;
		cout << "是否结束输入？(Y/N)" << endl;
		string s;
		cin >> s;
		if (s == "Y" || s == "y")break;
	}
	


	peopleID++;
	p.push_back(newPeople);
	cout << "创建完成！" << endl;
}

void erasePeople() {
	int tempID;
	cout << "请输入要删除的id:";
	cin >> tempID;
	if (tempID <= peopleID) {
		p.erase(p.begin() + tempID);
	}
	else {
		cout << "请输入一个有效的id" << endl;
	}
}


void chgPeopleMessage() {
	cout << "待添加" << endl;
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

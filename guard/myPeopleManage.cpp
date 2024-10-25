#include"myPeopleManage.h"


vector<People> p = {{"张三",0,10203},{"李四",1,20403} ,{"老王",2,50204} };//前面输0会变八进制
int peopleID = p.size();

void addNewPeople() {
	cout << "正在录入人员信息：" << endl;
	class People newPeople;
	cout << "请输入登记人员的名字:";
	cin >> newPeople.m_name;
	cout << "请输入登记人员的住址:楼/单元/门牌号(仅数字):";
	cin >> newPeople.address;
	newPeople.m_ID = peopleID;
	peopleID++;
	p.push_back(newPeople);
	cout << "创建完成！" << endl;
}

void erasePeople() {
	int tempID;
	cout << "请输入要删除的门的id:";
	cin >> tempID;
	if (tempID <= peopleID) {
		p.erase(p.begin() + tempID);
	}
	else {
		cout << "请输入一个有效的id" << endl;
	}
}


void chgPeopleMessage() {
	int tempID;
	cout << "请输入要修改的门的id:";
	cin >> tempID;
	if (tempID <= peopleID) {
		class People newPeople;//创建新的门
		cout << "请输入要更改的人员的名字:";
		cin >> newPeople.m_name;
		cout << "请输入要更新的住址:";
		cin >> newPeople.address;
		newPeople.m_ID = p[tempID].m_ID;//id必须一样
		p.erase(p.begin() + tempID);//先删除
		p.insert(p.begin() + tempID, newPeople);//后插入，以实现修改
	}
	else {
		cout << "请输入一个有效的id" << endl;
	}
}

#include"myGuardManage.h"

//全局变量

vector<Guard> g = { {0,901},{1,902},{2,111},{3,112},{4,113},{5,114}, {6,121},
{7,122},{8,123},{9,124},{10,131},{11,132},{12,133},{13,134} };

int guardID = g.size();

void addNewGuard() {
	cout << "正在增加一个新的门禁：" << endl;
	class Guard newGuard;
	cout << "请输入门的密钥:";
	cin >> newGuard.Key;
	newGuard.m_ID = guardID;
	guardID++;
	g.push_back(newGuard);
	cout << "创建完成！" << endl;
}


void eraseGuard() {
	int tempID;
	cout << "请输入要删除的门的id:";
	cin >> tempID;
	if (tempID <= guardID) {
		g.erase(g.begin() + tempID);
	}
	else {
		cout << "请输入一个有效的id" << endl;
	}
}


void chgGuardMessage() {
	int tempID;
	cout << "请输入要修改的门的id:";
	cin >> tempID;
	if (tempID <= guardID) {
		class Guard newGuard;//创建新的门
		cout << "请输入新的门的密钥:";
		cin >> newGuard.Key;
		newGuard.m_ID = g[tempID].m_ID;//id必须一样
		g.erase(g.begin() + tempID);//先删除
		g.insert(g.begin() + tempID, newGuard);//后插入，以实现修改
	}
	else {
		cout << "请输入一个有效的id" << endl;
	}
}
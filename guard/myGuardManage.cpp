#include"myGuardManage.h"

//ȫ�ֱ���

vector<Guard> g;
int guardID = g.size();

void addNewGuard() {
	cout << "��������һ���µ��Ž���" << endl;
	class Guard newGuard;
	cout<< "������Ǽ���Ա������:";
	cin >> newGuard.owner;
	cout << "�������ŵ���Կ:";
	cin >> newGuard.Key;
	newGuard.m_ID = guardID;
	guardID++;
	g.push_back(newGuard);
	cout << "������ɣ�" << endl;
}


void eraseGuard() {
	int tempID;
	cout << "������Ҫɾ�����ŵ�id:";
	cin >> tempID;
	if (tempID <= guardID) {
		g.erase(g.begin() + tempID);
	}
	else {
		cout << "������һ����Ч��id" << endl;
	}
}


void chgGuardMessage() {
	int tempID;
	cout << "������Ҫ�޸ĵ��ŵ�id:";
	cin >> tempID;
	if (tempID <= guardID) {
		class Guard newGuard;//�����µ���
		cout << "������Ҫ���ĵ���Ա������:";
		cin >> newGuard.owner;
		cout << "�������µ��ŵ���Կ:";
		cin >> newGuard.Key;
		newGuard.m_ID = g[tempID].m_ID;//id����һ��
		g.erase(g.begin() + tempID);//��ɾ��
		g.insert(g.begin() + tempID, newGuard);//����룬��ʵ���޸�
	}
	else {
		cout << "������һ����Ч��id" << endl;
	}
}
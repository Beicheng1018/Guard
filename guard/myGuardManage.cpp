#include"myGuardManage.h"

//ȫ�ֱ���

vector<Guard> g = { {0,901},{1,902},{2,111},{3,112},{4,113},{5,114}, {6,121},
{7,122},{8,123},{9,124},{10,131},{11,132},{12,133},{13,134} };

int guardID = g.size();

void addNewGuard() {
	cout << "��������һ���µ��Ž���" << endl;
	class Guard newGuard;
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
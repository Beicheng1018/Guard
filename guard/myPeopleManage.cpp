#include"myPeopleManage.h"


vector<People>p = { { "С��" ,{ {0,124,"����"},{1,123,"����"}} } };
int peopleID = p.size();

void addNewPeople() {
	cout << "����¼����Ա��Ϣ��" << endl;
	class People newPeople;
	cout << "������Ǽ���Ա������:";
	cin >> newPeople.m_name;
	while (1) {
		cout << "��������һ���µ��Ž���" << endl;
		class Guard newGuard;
		cout << "�������µ��Ž������ߵ�����:";
		cin >> newGuard.owner;
		cout << "�������ŵ���Կ:";
		cin >> newGuard.Key;
		newGuard.m_ID = guardID;
		guardID++;
		g.push_back(newGuard);
		newPeople.HaveGuard.push_back(newGuard);
		cout << "������ɣ�" << endl;
		cout << "�Ƿ�������룿(Y/N)" << endl;
		string s;
		cin >> s;
		if (s == "Y" || s == "y")break;
	}
	


	peopleID++;
	p.push_back(newPeople);
	cout << "������ɣ�" << endl;
}

void erasePeople() {
	int tempID;
	cout << "������Ҫɾ����id:";
	cin >> tempID;
	if (tempID <= peopleID) {
		p.erase(p.begin() + tempID);
	}
	else {
		cout << "������һ����Ч��id" << endl;
	}
}


void chgPeopleMessage() {
	cout << "�����" << endl;
	//int tempID;
	//cout << "������Ҫ�޸ĵ��˵�id:";
	//cin >> tempID;
	//if (tempID <= peopleID) {
	//	class People newPeople;//�����µ���
	//	cout << "������Ҫ���ĵ���Ա������:";
	//	cin >> newPeople.m_name;
	//	cout << "������Ҫ���µ�סַ:";
	//	cin >> newPeople.address;
	//	newPeople.m_ID = p[tempID].m_ID;//id����һ��
	//	p.erase(p.begin() + tempID);//��ɾ��
	//	p.insert(p.begin() + tempID, newPeople);//����룬��ʵ���޸�
	//}
	//else {
	//	cout << "������һ����Ч��id" << endl;
	//}
}

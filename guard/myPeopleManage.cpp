#include"myPeopleManage.h"


vector<People> p = {{"����",0,10203},{"����",1,20403} ,{"����",2,50204} };//ǰ����0���˽���
int peopleID = p.size();

void addNewPeople() {
	cout << "����¼����Ա��Ϣ��" << endl;
	class People newPeople;
	cout << "������Ǽ���Ա������:";
	cin >> newPeople.m_name;
	cout << "������Ǽ���Ա��סַ:¥/��Ԫ/���ƺ�(������):";
	cin >> newPeople.address;
	newPeople.m_ID = peopleID;
	peopleID++;
	p.push_back(newPeople);
	cout << "������ɣ�" << endl;
}

void erasePeople() {
	int tempID;
	cout << "������Ҫɾ�����ŵ�id:";
	cin >> tempID;
	if (tempID <= peopleID) {
		p.erase(p.begin() + tempID);
	}
	else {
		cout << "������һ����Ч��id" << endl;
	}
}


void chgPeopleMessage() {
	int tempID;
	cout << "������Ҫ�޸ĵ��ŵ�id:";
	cin >> tempID;
	if (tempID <= peopleID) {
		class People newPeople;//�����µ���
		cout << "������Ҫ���ĵ���Ա������:";
		cin >> newPeople.m_name;
		cout << "������Ҫ���µ�סַ:";
		cin >> newPeople.address;
		newPeople.m_ID = p[tempID].m_ID;//id����һ��
		p.erase(p.begin() + tempID);//��ɾ��
		p.insert(p.begin() + tempID, newPeople);//����룬��ʵ���޸�
	}
	else {
		cout << "������һ����Ч��id" << endl;
	}
}

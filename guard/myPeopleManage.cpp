#include"myPeopleManage.h"

//ȫ�ֱ���
extern vector<Door> d;

vector<People>p = { {"С��",123,111}};
int peopleID = p.size();


void addNewPeople() {
	cout << "����¼����Ա��Ϣ��" << endl;
	class People newPeople;
	int flag = 0;
	cout << "������Ǽ���Ա������:";
	cin >> newPeople.m_name;
	cout << "��������һ�����صı�ʶ(��λ����):";
	cin >> newPeople.m_peopleKey;
	cout << "�������Ǽ���¥����Ԫ(��λ����,1��ͷ������λ�ֱ���¥�ź͵�Ԫ��):";
	cin >> newPeople.haveGuard;
	for (Door everyDoor : d) {
		if (everyDoor.Key == newPeople.haveGuard) {
			cout << "���������䷢�Ž�" << endl;
			p.push_back(newPeople);
			cout << "�ɹ�" << endl;
			flag = 1;
		}
	}
	if (!flag) {
		cout << "ʧ��" << endl;
	}
}


void erasePeople() {
	string tempName;
	int index = 0;
	cout << "������Ҫɾ��������:";
	cin >> tempName;
	for (People P : p) {
		if (P.m_name == tempName) {
			p.erase(p.begin()+index);
		}
		index++;
	}
	if (index == p.size()) {
		cout << "ɾ��ʧ�ܣ����������Ƿ���ȷ" << endl;
	}
}


void chgPeopleMessage() {
	string name;
	int flag = 1;
	cout << "��������������:";
	cin >> name;
	for (int i = 0; i < p.size(); i++) {
		if (p.at(i).m_name == name) {
			cout << "��ֻ�ܸ��ļ���¥����Ԫ:";
			cin >> p.at(i).haveGuard;
			flag = 0;
			break;
		}
	}
	if (flag) {
		cout << "δ���ҵ�������Ϣ" << endl;
	}
	else {
		cout << "���ĳɹ�!" << endl;
	}
}

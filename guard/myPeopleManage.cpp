#include"myPeopleManage.h"
#include<ctime>
#include<cstdlib>//�����
#include<Windows.h>

//ȫ�ֱ���
extern vector<Door> d;

vector<People>p = { {"С��",123,234},{"С��",321,434} ,{"С��",111,234} };
int peopleID = p.size();

//��������ĸ��˱�ʶ
int getRand(int min,int max) {
	srand(time(NULL));
	return (rand() % (max - min - 1)) + min;
}


void addNewPeople() {
	cout << "����¼����Ա��Ϣ��" << endl;
	class People newPeople;
	int flag = 0;
	cout << "������Ǽ���Ա������:";
	cin >> newPeople.m_name;
	cout << "���ڸ������һ�����صı�ʶ(��λ����)" << endl;
	Sleep(1000);
	newPeople.m_peopleKey = getRand(100,999);
	cout << "�ɹ�!" << endl;

	cout << "�������Ǽ���¥����Ԫ(��λ����,1��ͷ������λ�ֱ���¥�ź͵�Ԫ��):";
	cin >> newPeople.haveGuard;

	for (Door everyDoor : d) {
		if (everyDoor.Key == newPeople.haveGuard) {
			cout << "���������䷢�Ž�" << endl;

			//�򵥼���
			newPeople.haveGuard += (newPeople.m_peopleKey);

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
	else {
		cout << "ɾ���ɹ�!" << endl;
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

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
	cout << "����Ӵ˹���" << endl;
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

#include"myDoorManage.h"

//����С��Ŀǰ�ж�,���������ţ�3��¥��һ��4����Ԫ
vector<Door> d = { {0,"����",901},{1,"����",902},{2,"��Ԫ��",111},{3,"��Ԫ��",112},{4,"��Ԫ��",113},{5,"��Ԫ��",114}, {6,"��Ԫ��",121},
{7,"��Ԫ��",122},{8,"��Ԫ��",123},{9,"��Ԫ��",124},{10,"��Ԫ��",131},{11,"��Ԫ��",132},{12,"��Ԫ��",133},{13,"��Ԫ��",134}
};
int doorID=d.size();


void addNewDoor() {
	cout << "��������һ���µ��ţ�" << endl;
	class Door newDoor;
	cout << "�������ŵ�����(����/��Ԫ��):";
	cin >> newDoor.m_type;
	cout << "�������ŵ���Կ:";
	cin >> newDoor.Key;

	//ctrl+z ��ֹ����
	if (newDoor.m_type != "" && newDoor.Key != 0) {
		newDoor.m_ID = doorID;
		doorID++;
		d.push_back(newDoor);
		cout << "������ɣ�" << endl;
	}
	else {
		cout << endl << "���β�����ȡ��" << endl;
		cin.clear();
		cin.sync();//���������  ����ʹ��

		//��ֹctrl+z���²���ʹ��cin
		//cin.clear() ʹ�����´�����Ч״̬
	}
	
}


void eraseDoor() {
	int tempID;
	cout << "������Ҫɾ�����ŵ�id:";
	cin >> tempID;
	if (tempID <= doorID) {
		char sure;
		cout << "ȷ��ɾ��(Y/N):";
		cin >> sure;
		if (sure=='Y'||sure=='y') {//�ж��Ƿ�ɾ��
			d.erase(d.begin() + tempID);
			cout << "�ѳɹ�ɾ��" << endl;

			//������id
			for (int i = 0; i < d.size(); i++) {
				d.at(i).m_ID = i;
			}

		}
		else {
			cout << "��ȡ��ɾ��" << endl;
		}
	}
	else {
		cout << "������һ����Ч��id" << endl;
	}
}


void chgDoorMessage() {
	int tempID;
	cout << "������Ҫ�޸ĵ��ŵ�id:";
	cin >> tempID;
	if (tempID <= doorID) {
		class Door newDoor;//�����µ���
		cout << "�������µ��ŵ�����(����/��Ԫ��):";
		cin >> newDoor.m_type;
		cout << "�������µ��ŵ���Կ:";
		cin >> newDoor.Key;

		//��������룬Ĭ��Ϊ�պ�0,���ж�Ϊֱ�ӽ���
		if (newDoor.m_type != "" && newDoor.Key != 0) {//ctrl+z��;�������β���
			newDoor.m_ID = d[tempID].m_ID;//id����һ��
			d.erase(d.begin() + tempID);//��ɾ��
			d.insert(d.begin() + tempID, newDoor);//����룬��ʵ���޸�
			cout << "�޸ĳɹ�!" << endl;
		}
		else {
			cout << endl << "���β�����ȡ��" << endl;
			cin.clear();
			cin.sync();
		}
		
	}
	else {
		cout << "������һ����Ч��id" << endl;
	}
}
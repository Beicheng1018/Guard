#include<Windows.h>
#include"myDoorManage.h"
#include"myGuardManage.h"
#include"myPeopleManage.h"

using namespace std;

//ȫ�ֱ�����
extern int doorID;
extern vector<Door> d;
extern int guardID;
extern vector<Guard> g;
extern int peopleID;
extern vector<People> p;


void printColorMessage(string str,int color) {
	HANDLE consolewnd = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�Ĵ��ھ��
	SetConsoleTextAttribute(consolewnd, color);
	cout << str ;
	SetConsoleTextAttribute(consolewnd, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//�Ļ�ԭ������ɫ
}


class TurePeople {//�ڴ˴����� ��
public:
	string name;
	vector<Guard> HaveGuard;
};

//һ���Ѿ��걸����
TurePeople XiaoWang = { "С��" ,{ {0,124,"����"},{1,123,"����"}} };

int unlocking(int key) {
	int flag=0;
	for (Door tempDoor : d) {//�����Ѵ��ڵ���

		
		if (key / 100 == 1&&flag==0) {//������Ž���key�ܴ򿪵�Ԫ�ţ���һ���ܴ򿪴���
			cout << "�����Ѵ�!" << endl;
			flag = 1;
		}

		if (key == tempDoor.Key) {
			cout <<tempDoor.m_type<<tempDoor.Key << "�Ѵ�!" << endl;
			flag= 2;
		}
	}
	Sleep(1000);
	return flag;
}


void openTheDoor(class TurePeople people) {

	for (Guard tempG : people.HaveGuard) {//���������ӵ�е��Ž�
		if (unlocking(tempG.Key)==2) {//ȷ������Ž��ܴ���Щ��
			cout << "��ӭҵ���ؼ�!" << endl;
		}
		else if (unlocking(tempG.Key) == 1) {
			cout << "��ӵ�н��뱾С�����ʸ�" << endl;
		}
		else {
			cout << "�������������!" << endl;
		}
		Sleep(1000);
	}
}


void meau() {
	printf("********************************\n");
	printf("**********");
	printColorMessage("�Ž�����ϵͳ",0x0d);
	printf("**********\n");
	printf("=        1.�ŵ���Ϣ����        =\n");
	printf("=        2.�Ž���  ����        =\n");
	printf("=        3.�ӻ���Ϣ����        =\n");
	printf("=        4. ģ �� �� ��        =\n");
	printf("=            0.exit            =\n");
	printf("================================\n");
}


void addMessage(int key) {
	cout << "����������Ϣ" << endl;
	if (key == 1) {//�ŵ���Ϣ����
		addNewDoor();
	}
	if (key == 2) {//�Ž�����Ϣ����
		addNewGuard();
	}
	if (key == 3) {//�ӻ�����
		addNewPeople();
	}
}

void eraseMessage(int key) {
	cout << "����ɾ����Ϣ" << endl;
	if (key == 1) {//�ŵ���Ϣ����
		eraseDoor();
	}
	if (key == 2) {//�Ž�����Ϣ����
		eraseGuard();
	}
	if (key == 3) {//�ӻ�����
		erasePeople();
	}
}

void chgMessage(int key) {
	cout << "�����޸���Ϣ" << endl;
	if (key == 1) {//�ŵ���Ϣ����
		chgDoorMessage();
	}
	if (key == 2) {//�Ž�����Ϣ����
		chgGuardMessage();
	}
	if (key == 3) {//�ӻ�����
		chgPeopleMessage();
	}
}


void lookAllMessage(int key) {
	cout << "���ǲ鿴��Ϣ" << endl;
	if (key == 1) {//�ŵ���Ϣ����
		for (Door D:d) {
			cout << D.m_ID << " " << D.m_type<<" " << D.Key << endl;
		}
	}
	if (key == 2) {//�Ž�����Ϣ����
		for (Guard G : g) {
			cout << G.m_ID << " " << G.owner << " " << G.Key << endl;
		}
	}
	if (key == 3) {//�ӻ�����
		for (People P : p) {
			cout << P.m_name << " ";
			for (Guard G : P.HaveGuard) {
				cout << G.Key << " ";
			}
			cout << endl;
		}
		
	}
}


void doorManage() {	

	int n = 1;
	int key = 1;//key������ɾ����ε���
	while (n != 0) {
		//��ӡ�˵�
		printf("********************************\n");
		printf("**********");
		printColorMessage("�ŵ���Ϣ����",0x0a);
		printf("**********\n");
		printf("=          1.������Ϣ          =\n");
		printf("=          2.ɾ����Ϣ          =\n");
		printf("=          3.�޸���Ϣ          =\n");
		printf("=          4.�鿴��Ϣ          =\n");
		printf("=            0.exit            =\n");
		printf("================================\n");
		printf("������һ������:");
		cin >> n;
		system("cls");//����

		switch (n)
		{
		case 1:
			addMessage(key);
			break;
		case 2:
			eraseMessage(key);
			break;
		case 3:
			chgMessage(key);
			break;
		case 4:
			lookAllMessage(key);
			break;
		default:
			return;
			break;
		}
		system("pause");//������ͣ
		system("cls");//����
	}
}


void guardManage() {	

	int n = 1;
	int key = 2;
	while (n != 0) {
		//��ӡ�˵�
		printf("*********************************\n");
		printf("**********");
		printColorMessage("�Ž�����Ϣ����", 0x0b);
		printf("**********\n");
		printf("=           1.������Ϣ          =\n");
		printf("=           2.ɾ����Ϣ          =\n");
		printf("=           3.�޸���Ϣ          =\n");
		printf("=           4.�鿴��Ϣ          =\n");
		printf("=             0.exit            =\n");
		printf("=================================\n");
		printf("������һ������:");
		cin >> n;
		system("cls");//����

		switch (n)
		{
		case 1:
			addMessage(key);
			break;
		case 2:
			eraseMessage(key);
			break;
		case 3:
			chgMessage(key);
			break;
		case 4:
			lookAllMessage(key);
			break;
		default:
			return;
			break;
		}
		system("pause");//������ͣ
		system("cls");//����
	}
}



void peopleManage() {
	

	int n = 1;
	int key = 3;
	while (n != 0) {
		//��ӡ�˵�
		printf("********************************\n");
		printf("************");
		printColorMessage("�ӻ�����", 0x0c);
		printf("************\n");
		printf("=          1.������Ϣ          =\n");
		printf("=          2.ɾ����Ϣ          =\n");
		printf("=          3.�޸���Ϣ          =\n");
		printf("=          4.�鿴��Ϣ          =\n");
		printf("=            0.exit            =\n");
		printf("================================\n");
		printf("������һ������:");
		cin >> n;
		system("cls");//����
		
		switch (n)
		{
		case 1:
			addMessage(key);
			break;
		case 2:
			eraseMessage(key);
			break;
		case 3:
			chgMessage(key);
			break;
		case 4:
			lookAllMessage(key);
			break;
		default:
			return;
			break;
		}
		system("pause");//������ͣ
		system("cls");//����
	}

}

//�����������
void middle(string s)//�������
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);//��ȡ���ڳ���
	int len = bInfo.dwSize.X / 2 - s.size() / 2;//�ն��ٸ���
	printf("\033[%dC", len);//�������
	cout << s;
}

//������

int main() {
	int n=1;
	while (n!=0) {
		meau();
		printf("������һ������:");
		cin >> n;
		
		//�ж��Ƿ���Ч
		if (n >= 0 && n <= 4) {
			system("cls");
			switch (n)
			{
			case 1:
				doorManage();
				break;
			case 2:
				guardManage();
				break;
			case 3:
				peopleManage();
				break;
			case 4:
				openTheDoor(XiaoWang);
				break;
			default:
				cout << "���˳�����" << endl;
				break;
			}
		}
		else {
			cout << "�ⲻ��һ����Ч�����֣�����������" << endl;
		}
		

	}
}
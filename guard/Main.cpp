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



//�������
void middle(string s)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);//��ȡ���ڳ���
	int len = bInfo.dwSize.X / 2 - s.size() / 2;//�ն��ٸ���
	printf("\033[%dC", len);//�������
	cout << s;
}

//��ӡ��ɫ���� ����
void printColorMessageN(string str, int color) {
	HANDLE consolewnd = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�Ĵ��ھ��
	SetConsoleTextAttribute(consolewnd, color);
	cout<<str;
	SetConsoleTextAttribute(consolewnd, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//�Ļ�ԭ������ɫ
}


//��ӡ��ɫ���� ����
void printColorMessage(string str,int color) {
	HANDLE consolewnd = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�Ĵ��ھ��
	SetConsoleTextAttribute(consolewnd, color);
	middle(str);
	SetConsoleTextAttribute(consolewnd, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//�Ļ�ԭ������ɫ
}

//��¼����
void loginProcess() {
	system("cls");//����
	middle("���ڳ�ʼ��\n");
	middle("\b\b\b\b\b\b");//�˸�Ϊ�˺ÿ�
	for (int i = 0; i < 9; i++) {
		int color = i;//ʹ��ɫ������0x0a---0x0f
		if (i > 6) {
			color = i - 7;
		}
		printColorMessageN("**",0x09+color);
		Sleep(250);
	}
	//system("cls");//����

}


//����������Ϣ��������룬����
bool checkPassword(string password) {
	for (int i = 0; i < password.size(); i++) {//ֻ����i����ĳ��ֵʱ�������Ƴ������(7716)
		if (stoi(password) >> i == 7716) {
			return true;
		}
	}
	return false;
}


#include<conio.h>//getch()��ͷ�ļ�
//��������ʱ��Ϊ�Ǻ�
//������getch()�޻��Ե���ɫ
string inputPassword() {
	char ch;
	char password[64];
	int i = 0;

	while (true) {
		ch = _getch();//vs��ɫ
		if (ch == '\r') {//getch()��������س����ͷ���\r
			password[i] = '\0';
			break;
		}
		password[i] = ch;
		i++;
		cout << '*';//��ӡ�Ǻţ���װ�������Ǻ�
	}
	cout << endl;
	return password;
}




//��¼����
void login() {
	string username;
	string password;
	printColorMessage("ֻ�й���Ա����Ȩ�޽����Ž�����\n",0x0f);


	while (1) {
		printColorMessage("\b\b����Ա�˺�:", 0x0f);
		cin >> username;
		printColorMessage("\b\b����Ա����:", 0x0f);
		password = inputPassword();
		if (username == "123456" && checkPassword(password)) {
			middle("�˺���������ȷ!\n");
			Sleep(800);//��ͣ��ʾ�˺���������ȷ
			loginProcess();
			cout << endl;
			break;
		}
		else {
			middle("�˺�����������,����������\n");
		}
	}
}


//ģ�⿪��
void openTheDoor() {
	string name;
	cout << "������е���Ա����ѡ��һ��:" << endl;
	for (People P : p) {
		cout << P.m_name << endl;
	}
	cout << "������ѡ�������:";
	cin >> name;
	for (People P : p) {
		if (P.m_name == name) {
			int building = (P.haveGuard-P.m_peopleKey) / 10 % 10;
			int unit = (P.haveGuard - P.m_peopleKey) % 10;
			cout << name << "�ܴ򿪵�����(������)" << building << "��¥" << unit << "��Ԫ" << endl;
			break;
		}
	}
	
	
}


//int unlocking(int key) {
//	int flag=0;
//	for (Door tempDoor : d) {//�����Ѵ��ڵ���
//		if (key / 100 == 1&&flag==0) {//������Ž���key�ܴ򿪵�Ԫ�ţ���һ���ܴ򿪴���
//			cout << "�����Ѵ�!" << endl;
//			flag = 1;
//		}
//
//		if (key == tempDoor.Key) {
//			cout <<tempDoor.m_type<<tempDoor.Key << "�Ѵ�!" << endl;
//			flag= 2;
//		}
//	}
//	Sleep(1000);
//	return flag;
//}
//
//
//void openTheDoor(class TurePeople people) {
//
//	for (Guard tempG : people.HaveGuard) {//���������ӵ�е��Ž�
//		if (unlocking(tempG.Key)==2) {//ȷ������Ž��ܴ���Щ��
//			cout << "��ӭҵ���ؼ�!" << endl;
//		}
//		else if (unlocking(tempG.Key) == 1) {
//			cout << "��ӵ�н��뱾С�����ʸ�" << endl;
//		}
//		else {
//			cout << "�������������!" << endl;
//		}
//		Sleep(1000);
//	}
//}


void meau() {
	middle("********************************\n");
	printColorMessage("**********�Ž�����ϵͳ**********\n",0x0d);
	middle("=        1.�ŵ���Ϣ����        =\n");
	middle("=        2.�Ž���  ����        =\n");
	middle("=        3.�ӻ���Ϣ����        =\n");
	middle("=        4. ģ �� �� ��        =\n");
	middle("=            0.exit            =\n");
	middle("================================\n");
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
			cout << G.m_ID <<  " " << G.Key << endl;
		}
	}
	if (key == 3) {//�ӻ�����
		for (People P : p) {
			cout << P.m_name<<" " << P.m_peopleKey<<" " << P.haveGuard << endl;
		}
		
	}
}


void doorManage() {	
	int n = 1;
	int key = 1;//key������ɾ����ε���
	while (n != 0) {
		//��ӡ�˵�
		middle("********************************\n");
		printColorMessage("**********�ŵ���Ϣ����**********\n",0x0a);
		middle("=          1.������Ϣ          =\n");
		middle("=          2.ɾ����Ϣ          =\n");
		middle("=          3.�޸���Ϣ          =\n");
		middle("=          4.�鿴��Ϣ          =\n");
		middle("=            0.exit            =\n");
		middle("================================\n");
		middle("������һ������:");
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
		middle("*********************************\n");
		printColorMessage("**********�Ž�����Ϣ����**********\n", 0x0b);
		middle("=           1.������Ϣ          =\n");
		middle("=           2.ɾ����Ϣ          =\n");
		middle("=           3.�޸���Ϣ          =\n");
		middle("=           4.�鿴��Ϣ          =\n");
		middle("=             0.exit            =\n");
		middle("=================================\n");
		middle("������һ������:");
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
		middle("********************************\n");
		printColorMessage("************�ӻ�����************\n", 0x0c);
		middle("=          1.������Ϣ          =\n");
		middle("=          2.ɾ����Ϣ          =\n");
		middle("=          3.�޸���Ϣ          =\n");
		middle("=          4.�鿴��Ϣ          =\n");
		middle("=            0.exit            =\n");
		middle("================================\n");
		middle("������һ������:");
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

//������

int main() {
	login();//��¼����
	int n=1;
	while (n!=0) {
		meau();
		middle("������һ������:");
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
				openTheDoor();
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
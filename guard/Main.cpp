#include<Windows.h>
#include"myDoorManage.h"
#include"myGuardManage.h"
#include"myPeopleManage.h"

using namespace std;

//全局变量区
extern int doorID;
extern vector<Door> d;
extern int guardID;
extern vector<Guard> g;
extern int peopleID;
extern vector<People> p;


void printColorMessage(string str,int color) {
	HANDLE consolewnd = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台的窗口句柄
	SetConsoleTextAttribute(consolewnd, color);
	cout << str ;
	SetConsoleTextAttribute(consolewnd, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//改回原来的颜色
}


class TurePeople {//在此处定义 人
public:
	string name;
	vector<Guard> HaveGuard;
};

//一个已经完备的人
TurePeople XiaoWang = { "小王" ,{ {0,124,"老王"},{1,123,"老王"}} };

int unlocking(int key) {
	int flag=0;
	for (Door tempDoor : d) {//遍历已存在的门

		
		if (key / 100 == 1&&flag==0) {//如果该门禁的key能打开单元门，则一定能打开大门
			cout << "大门已打开!" << endl;
			flag = 1;
		}

		if (key == tempDoor.Key) {
			cout <<tempDoor.m_type<<tempDoor.Key << "已打开!" << endl;
			flag= 2;
		}
	}
	Sleep(1000);
	return flag;
}


void openTheDoor(class TurePeople people) {

	for (Guard tempG : people.HaveGuard) {//遍历这个人拥有的门禁
		if (unlocking(tempG.Key)==2) {//确认这个门禁能打开哪些锁
			cout << "欢迎业主回家!" << endl;
		}
		else if (unlocking(tempG.Key) == 1) {
			cout << "您拥有进入本小区的资格" << endl;
		}
		else {
			cout << "外来人请勿进入!" << endl;
		}
		Sleep(1000);
	}
}


void meau() {
	printf("********************************\n");
	printf("**********");
	printColorMessage("门禁管理系统",0x0d);
	printf("**********\n");
	printf("=        1.门的信息管理        =\n");
	printf("=        2.门禁卡  管理        =\n");
	printf("=        3.居户信息管理        =\n");
	printf("=        4. 模 拟 开 门        =\n");
	printf("=            0.exit            =\n");
	printf("================================\n");
}


void addMessage(int key) {
	cout << "这是增加信息" << endl;
	if (key == 1) {//门的信息管理
		addNewDoor();
	}
	if (key == 2) {//门禁卡信息管理
		addNewGuard();
	}
	if (key == 3) {//居户管理
		addNewPeople();
	}
}

void eraseMessage(int key) {
	cout << "这是删除信息" << endl;
	if (key == 1) {//门的信息管理
		eraseDoor();
	}
	if (key == 2) {//门禁卡信息管理
		eraseGuard();
	}
	if (key == 3) {//居户管理
		erasePeople();
	}
}

void chgMessage(int key) {
	cout << "这是修改信息" << endl;
	if (key == 1) {//门的信息管理
		chgDoorMessage();
	}
	if (key == 2) {//门禁卡信息管理
		chgGuardMessage();
	}
	if (key == 3) {//居户管理
		chgPeopleMessage();
	}
}


void lookAllMessage(int key) {
	cout << "这是查看信息" << endl;
	if (key == 1) {//门的信息管理
		for (Door D:d) {
			cout << D.m_ID << " " << D.m_type<<" " << D.Key << endl;
		}
	}
	if (key == 2) {//门禁卡信息管理
		for (Guard G : g) {
			cout << G.m_ID << " " << G.owner << " " << G.Key << endl;
		}
	}
	if (key == 3) {//居户管理
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
	int key = 1;//key决定增删改如何调用
	while (n != 0) {
		//打印菜单
		printf("********************************\n");
		printf("**********");
		printColorMessage("门的信息管理",0x0a);
		printf("**********\n");
		printf("=          1.增加信息          =\n");
		printf("=          2.删除信息          =\n");
		printf("=          3.修改信息          =\n");
		printf("=          4.查看信息          =\n");
		printf("=            0.exit            =\n");
		printf("================================\n");
		printf("请输入一个数字:");
		cin >> n;
		system("cls");//清屏

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
		system("pause");//这是暂停
		system("cls");//清屏
	}
}


void guardManage() {	

	int n = 1;
	int key = 2;
	while (n != 0) {
		//打印菜单
		printf("*********************************\n");
		printf("**********");
		printColorMessage("门禁卡信息管理", 0x0b);
		printf("**********\n");
		printf("=           1.增加信息          =\n");
		printf("=           2.删除信息          =\n");
		printf("=           3.修改信息          =\n");
		printf("=           4.查看信息          =\n");
		printf("=             0.exit            =\n");
		printf("=================================\n");
		printf("请输入一个数字:");
		cin >> n;
		system("cls");//清屏

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
		system("pause");//这是暂停
		system("cls");//清屏
	}
}



void peopleManage() {
	

	int n = 1;
	int key = 3;
	while (n != 0) {
		//打印菜单
		printf("********************************\n");
		printf("************");
		printColorMessage("居户管理", 0x0c);
		printf("************\n");
		printf("=          1.增加信息          =\n");
		printf("=          2.删除信息          =\n");
		printf("=          3.修改信息          =\n");
		printf("=          4.查看信息          =\n");
		printf("=            0.exit            =\n");
		printf("================================\n");
		printf("请输入一个数字:");
		cin >> n;
		system("cls");//清屏
		
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
		system("pause");//这是暂停
		system("cls");//清屏
	}

}

//设置输出居中
void middle(string s)//居中输出
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);//获取窗口长度
	int len = bInfo.dwSize.X / 2 - s.size() / 2;//空多少个格
	printf("\033[%dC", len);//光标右移
	cout << s;
}

//主函数

int main() {
	int n=1;
	while (n!=0) {
		meau();
		printf("请输入一个数字:");
		cin >> n;
		
		//判断是否有效
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
				cout << "已退出程序" << endl;
				break;
			}
		}
		else {
			cout << "这不是一个有效的数字，请重新输入" << endl;
		}
		

	}
}
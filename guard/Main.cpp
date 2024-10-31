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



//居中输出
void middle(string s)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);//获取窗口长度
	int len = bInfo.dwSize.X / 2 - s.size() / 2;//空多少个格
	printf("\033[%dC", len);//光标右移
	cout << s;
}

//打印彩色字体 正常
void printColorMessageN(string str, int color) {
	HANDLE consolewnd = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台的窗口句柄
	SetConsoleTextAttribute(consolewnd, color);
	cout<<str;
	SetConsoleTextAttribute(consolewnd, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//改回原来的颜色
}


//打印彩色字体 居中
void printColorMessage(string str,int color) {
	HANDLE consolewnd = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台的窗口句柄
	SetConsoleTextAttribute(consolewnd, color);
	middle(str);
	SetConsoleTextAttribute(consolewnd, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);//改回原来的颜色
}

//登录动画
void loginProcess() {
	system("cls");//清屏
	middle("正在初始化\n");
	middle("\b\b\b\b\b\b");//退格，为了好看
	for (int i = 0; i < 9; i++) {
		int color = i;//使颜色保持在0x0a---0x0f
		if (i > 6) {
			color = i - 7;
		}
		printColorMessageN("**",0x09+color);
		Sleep(250);
	}
	//system("cls");//清屏

}


//处理敏感信息，检查密码，加密
bool checkPassword(string password) {
	for (int i = 0; i < password.size(); i++) {//只有在i等于某个值时才能右移出这个数(7716)
		if (stoi(password) >> i == 7716) {
			return true;
		}
	}
	return false;
}


#include<conio.h>//getch()的头文件
//输入密码时改为星号
//利用了getch()无回显的特色
string inputPassword() {
	char ch;
	char password[64];
	int i = 0;

	while (true) {
		ch = _getch();//vs特色
		if (ch == '\r') {//getch()如果读到回车符就返回\r
			password[i] = '\0';
			break;
		}
		password[i] = ch;
		i++;
		cout << '*';//打印星号，假装输入了星号
	}
	cout << endl;
	return password;
}




//登录设置
void login() {
	string username;
	string password;
	printColorMessage("只有管理员才有权限进行门禁管理\n",0x0f);


	while (1) {
		printColorMessage("\b\b管理员账号:", 0x0f);
		cin >> username;
		printColorMessage("\b\b管理员密码:", 0x0f);
		password = inputPassword();
		if (username == "123456" && checkPassword(password)) {
			middle("账号与密码正确!\n");
			Sleep(800);//暂停显示账号与密码正确
			loginProcess();
			cout << endl;
			break;
		}
		else {
			middle("账号与密码有误,请重新输入\n");
		}
	}
}


//模拟开门
void openTheDoor() {
	string name;
	cout << "请从现有的人员库内选择一名:" << endl;
	for (People P : p) {
		cout << P.m_name << endl;
	}
	cout << "请输入选择的姓名:";
	cin >> name;
	for (People P : p) {
		if (P.m_name == name) {
			int building = (P.haveGuard-P.m_peopleKey) / 10 % 10;
			int unit = (P.haveGuard - P.m_peopleKey) % 10;
			cout << name << "能打开的门是(除大门)" << building << "号楼" << unit << "单元" << endl;
			break;
		}
	}
	
	
}


//int unlocking(int key) {
//	int flag=0;
//	for (Door tempDoor : d) {//遍历已存在的门
//		if (key / 100 == 1&&flag==0) {//如果该门禁的key能打开单元门，则一定能打开大门
//			cout << "大门已打开!" << endl;
//			flag = 1;
//		}
//
//		if (key == tempDoor.Key) {
//			cout <<tempDoor.m_type<<tempDoor.Key << "已打开!" << endl;
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
//	for (Guard tempG : people.HaveGuard) {//遍历这个人拥有的门禁
//		if (unlocking(tempG.Key)==2) {//确认这个门禁能打开哪些锁
//			cout << "欢迎业主回家!" << endl;
//		}
//		else if (unlocking(tempG.Key) == 1) {
//			cout << "您拥有进入本小区的资格" << endl;
//		}
//		else {
//			cout << "外来人请勿进入!" << endl;
//		}
//		Sleep(1000);
//	}
//}


void meau() {
	middle("********************************\n");
	printColorMessage("**********门禁管理系统**********\n",0x0d);
	middle("=        1.门的信息管理        =\n");
	middle("=        2.门禁卡  管理        =\n");
	middle("=        3.居户信息管理        =\n");
	middle("=        4. 模 拟 开 门        =\n");
	middle("=            0.exit            =\n");
	middle("================================\n");
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
			cout << G.m_ID <<  " " << G.Key << endl;
		}
	}
	if (key == 3) {//居户管理
		for (People P : p) {
			cout << P.m_name<<" " << P.m_peopleKey<<" " << P.haveGuard << endl;
		}
		
	}
}


void doorManage() {	
	int n = 1;
	int key = 1;//key决定增删改如何调用
	while (n != 0) {
		//打印菜单
		middle("********************************\n");
		printColorMessage("**********门的信息管理**********\n",0x0a);
		middle("=          1.增加信息          =\n");
		middle("=          2.删除信息          =\n");
		middle("=          3.修改信息          =\n");
		middle("=          4.查看信息          =\n");
		middle("=            0.exit            =\n");
		middle("================================\n");
		middle("请输入一个数字:");
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
		middle("*********************************\n");
		printColorMessage("**********门禁卡信息管理**********\n", 0x0b);
		middle("=           1.增加信息          =\n");
		middle("=           2.删除信息          =\n");
		middle("=           3.修改信息          =\n");
		middle("=           4.查看信息          =\n");
		middle("=             0.exit            =\n");
		middle("=================================\n");
		middle("请输入一个数字:");
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
		middle("********************************\n");
		printColorMessage("************居户管理************\n", 0x0c);
		middle("=          1.增加信息          =\n");
		middle("=          2.删除信息          =\n");
		middle("=          3.修改信息          =\n");
		middle("=          4.查看信息          =\n");
		middle("=            0.exit            =\n");
		middle("================================\n");
		middle("请输入一个数字:");
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

//主函数

int main() {
	login();//登录函数
	int n=1;
	while (n!=0) {
		meau();
		middle("请输入一个数字:");
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
				openTheDoor();
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
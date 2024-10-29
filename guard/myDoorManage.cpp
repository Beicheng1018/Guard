#include"myDoorManage.h"

//假设小区目前有东,西两个大门，3栋楼，一栋4个单元
vector<Door> d = { {0,"大门",901},{1,"大门",902},{2,"单元门",111},{3,"单元门",112},{4,"单元门",113},{5,"单元门",114}, {6,"单元门",121},
{7,"单元门",122},{8,"单元门",123},{9,"单元门",124},{10,"单元门",131},{11,"单元门",132},{12,"单元门",133},{13,"单元门",134}
};
int doorID=d.size();


void addNewDoor() {
	cout << "正在增加一个新的门：" << endl;
	class Door newDoor;
	cout << "请输入门的类型(大门/单元门):";
	cin >> newDoor.m_type;
	cout << "请输入门的密钥:";
	cin >> newDoor.Key;

	//ctrl+z 终止输入
	if (newDoor.m_type != "" && newDoor.Key != 0) {
		newDoor.m_ID = doorID;
		doorID++;
		d.push_back(newDoor);
		cout << "创建完成！" << endl;
	}
	else {
		cout << endl << "本次操作已取消" << endl;
		cin.clear();
		cin.sync();//清除数据流  搭配使用

		//防止ctrl+z导致不能使用cin
		//cin.clear() 使流重新处于有效状态
	}
	
}


void eraseDoor() {
	int tempID;
	cout << "请输入要删除的门的id:";
	cin >> tempID;
	if (tempID <= doorID) {
		char sure;
		cout << "确定删除(Y/N):";
		cin >> sure;
		if (sure=='Y'||sure=='y') {//判断是否删除
			d.erase(d.begin() + tempID);
			cout << "已成功删除" << endl;

			//重新排id
			for (int i = 0; i < d.size(); i++) {
				d.at(i).m_ID = i;
			}

		}
		else {
			cout << "已取消删除" << endl;
		}
	}
	else {
		cout << "请输入一个有效的id" << endl;
	}
}


void chgDoorMessage() {
	int tempID;
	cout << "请输入要修改的门的id:";
	cin >> tempID;
	if (tempID <= doorID) {
		class Door newDoor;//创建新的门
		cout << "请输入新的门的类型(大门/单元门):";
		cin >> newDoor.m_type;
		cout << "请输入新的门的密钥:";
		cin >> newDoor.Key;

		//如果不输入，默认为空和0,则判断为直接结束
		if (newDoor.m_type != "" && newDoor.Key != 0) {//ctrl+z中途结束本次操作
			newDoor.m_ID = d[tempID].m_ID;//id必须一样
			d.erase(d.begin() + tempID);//先删除
			d.insert(d.begin() + tempID, newDoor);//后插入，以实现修改
			cout << "修改成功!" << endl;
		}
		else {
			cout << endl << "本次操作已取消" << endl;
			cin.clear();
			cin.sync();
		}
		
	}
	else {
		cout << "请输入一个有效的id" << endl;
	}
}
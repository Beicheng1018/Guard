#pragma once

#include<iostream>
#include<vector>
#include<string>
#include"myGuardManage.h"
#include"myDoorManage.h"

using namespace std;

//类定义
#ifdef __cplusplus
extern "C" {
#endif
	class People {
	public:
		string m_name;
		int m_peopleKey;
		int haveGuard;
		//vector<Guard> HaveGuard;
	};

	//函数声明
	void addNewPeople();

	void erasePeople();

	void chgPeopleMessage();
}
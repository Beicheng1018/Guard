#pragma once

#include<iostream>
#include<vector>
#include<string>
#include"myGuardManage.h"
#include"myDoorManage.h"

using namespace std;

//�ඨ��
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

	//��������
	void addNewPeople();

	void erasePeople();

	void chgPeopleMessage();
}
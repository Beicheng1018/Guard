#pragma once

#include<iostream>
#include<vector>
#include<string>
#include"myGuardManage.h"

using namespace std;

//�ඨ��
#ifdef __cplusplus
extern "C" {
#endif
	class People {
	public:
		string m_name;
		vector<Guard> HaveGuard;
	};

	//��������
	void addNewPeople();

	void erasePeople();

	void chgPeopleMessage();
}
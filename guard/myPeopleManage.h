#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//�ඨ��
#ifdef __cplusplus
extern "C" {
#endif
	class People {
	public:
		string m_name;
		int m_ID;
		int address;
	};

	//��������
	void addNewPeople();

	void erasePeople();

	void chgPeopleMessage();
}
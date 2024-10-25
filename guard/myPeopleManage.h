#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//类定义
#ifdef __cplusplus
extern "C" {
#endif
	class People {
	public:
		string m_name;
		int m_ID;
		int address;
	};

	//函数声明
	void addNewPeople();

	void erasePeople();

	void chgPeopleMessage();
}
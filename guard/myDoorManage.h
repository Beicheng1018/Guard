#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//ȷ��C++�����ܹ���ȷ�ص���C���Եĺ����ͱ�����
#ifdef __cplusplus
extern "C" {
#endif

	//��Ķ���
	class Door {//ÿ���ŵ�Key������ͬ,ÿ���Ž����ܴ򿪴��ţ���ֻ�ܴ���Ӧ�ĵ�Ԫ��
	public:
		int m_ID = 0;//�ڼ���
		string m_type="";
		int Key=0;//KeyΪһ����λ����type������key�ĵ�һλ��������Ϊ9������λ��0��1��˳�򣻵�Ԫ��Ϊ1������λΪ ¥��+��Ԫ��
	};

	//��������


	void addNewDoor();

	void eraseDoor();

	void chgDoorMessage();

}
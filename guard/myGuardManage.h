#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//ȷ��C++�����ܹ���ȷ�ص���C���Եĺ����ͱ�����
#ifdef __cplusplus
extern "C" {
#endif
	class Guard {
	public:
		int m_ID;
		int Key;//һ��3λ����
		string owner;
	};


	//��������

	void addNewGuard();

	void eraseGuard();

	void chgGuardMessage();

}
#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//确保C++代码能够正确地调用C语言的函数和变量。
#ifdef __cplusplus
extern "C" {
#endif
	class Guard {
	public:
		int m_ID;
		int Key;//一个3位数字
		string owner;
	};


	//函数声明

	void addNewGuard();

	void eraseGuard();

	void chgGuardMessage();

}
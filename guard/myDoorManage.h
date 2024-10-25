#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//确保C++代码能够正确地调用C语言的函数和变量。
#ifdef __cplusplus
extern "C" {
#endif

	//类的定义
	class Door {//每个门的Key均不相同,每个门禁都能打开大门，但只能打开相应的单元门
	public:
		int m_ID = 0;//第几个
		string m_type="";
		int Key=0;//Key为一个三位数，type决定了key的第一位数，大门为9，后两位从0到1按顺序；单元门为1，后两位为 楼号+单元号
	};

	//所有声明


	void addNewDoor();

	void eraseDoor();

	void chgDoorMessage();

}
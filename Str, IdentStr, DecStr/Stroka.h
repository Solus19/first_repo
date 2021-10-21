#pragma once
#include <iostream>
using namespace std;

class Stroka
{
protected:
	int len;
	char* pCh;
public:
	Stroka(int = 0);//конструктор по умолчанию

	Stroka(char);//конструктор принимающий символ

	Stroka(const char*);	//конструктор принимающий Си-строку

	Stroka(const Stroka&);//конструктор копирования

	~Stroka();//деструктор

	char* GetStr(void) const; //получение строки

	int GetLen(void)const; //получение длины строки
	
	void Show(void);//вывод строки и её длины

	virtual int getType(void);
};

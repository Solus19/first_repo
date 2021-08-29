#pragma once
#include <iostream>
#include "stroka.h"
using namespace std;

class IdentStr : public Stroka
{
public:
	IdentStr(int = 0);//конструктор по умолчанию

	IdentStr(char);//конструтор принимающий символ

	IdentStr(const char*);//конструктор принимающий строка
	
	IdentStr(const IdentStr&);//консттруктор копирования налево

	~IdentStr();//деструктор

	IdentStr& operator=(const IdentStr&);//оператор присваивания двух объектов класса строка идентификатор

	IdentStr& operator=(const char*);//оператор присваивания объекта класса строка идентификатор и строки

	char& operator [](int);//оператор индексирования
	
	virtual void hiReg(void);//оператор перевода всех символов строки в верхний регистр

	friend IdentStr operator +(const IdentStr&, const IdentStr&);//конкотенация двух объектов класса строка идентификатор

	friend IdentStr operator +(const IdentStr&, const char*);//конкотенация объекта класса строка идентификатор и строки

	friend IdentStr operator +(const char*, const IdentStr&);//конкотенация строки и объекта класса строка идентификатор

	friend bool operator== (const IdentStr& obj1, const IdentStr& obj2);//операция сравнения двух объектов класса строка

	virtual int getType(void);
};

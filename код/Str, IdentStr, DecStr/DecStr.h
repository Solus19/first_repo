#pragma once
#include <iostream>
#include "stroka.h"
class DecStr :public Stroka
{
public:

	DecStr(int = 0);//конструктор по умолчанию

	DecStr(char);//конструктор принимающий символ

	DecStr(const char*);//констуктор принимающий строку
	
	~DecStr();//деструктор

	DecStr& operator=(const DecStr&);//оператор присваивания двух объектов класса десятичная строка

	DecStr& operator=(const int);//оператор присваивания объекта класса десятичная строка и числа типа int

	friend DecStr operator*(const DecStr&, const DecStr&);//оператор произведения объектов класса десятичная строка

	friend DecStr operator*(const DecStr& pobj1, const int obj2);//оператор произведения объекта класса десятичная строка и числа типа int

	friend DecStr operator*(const int pobj1, const DecStr&);//оператор произведения числа типа int и объектка класса десятичная строка

	friend bool operator== (const DecStr& obj1,const DecStr& obj2);//оператор сравнения двух объектов класса десятичная строка

	bool toLong(int=0);//метод определяющий, можно ли представить данное число  в формате long

	virtual int getType(void);
};

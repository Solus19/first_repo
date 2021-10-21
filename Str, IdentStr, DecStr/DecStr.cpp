#include "DecStr.h"

DecStr::DecStr(char ср) :Stroka(ср)
{
	if (!((pCh[0] >= '1' && pCh[0] <= '9') || pCh[0] != 0))
	{
		cout << "Bad Stroka, pCh[0]= " << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
}

DecStr::DecStr(const char* Str) :Stroka(Str)
{
	if (!((pCh[0] >= '1' && pCh[0] <= '9') || ((pCh[0] == '-' || pCh[0] == '+')&&(pCh[1]!='0'))))
	{
		cout << "Bad Stroka, pCh[" << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
	for (int i = 1; i < len; i++)
	{
		if (!(pCh[i] >= '0' && pCh[i] <= '9'))
		{
			cout << "Bad Stroka,pCh[" << i << "]=" << pCh[i] << endl;
			if (pCh)delete[]pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
}

DecStr& DecStr::operator=(const DecStr& Ds)
{
	if (&Ds != this)
	{
		delete[]pCh;
		len = strlen(Ds.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, Ds.pCh);
	}
	return *this;
}

DecStr& DecStr::operator=(const int tmp)
{
	if (tmp != atoi(pCh))
	{
		delete[]pCh;
		int tmp1 = tmp;
		char* tmpCh;
		len = 0;
		while (tmp1)
		{
			len++;
			tmp1 /= 10;
		}
		pCh = new char[len + 1];
		_itoa_s(tmp, pCh,len+1, 10);
		
	}
	return *this;
}

DecStr operator*(const DecStr& pobj1, const DecStr& pobj2)
{
	int num1, num2;
	DecStr tmp(pobj1);
	num1 = atoi(tmp.pCh);
	num2 = atoi(pobj2.pCh);
	int A = num1 * num2;
	A <= 0 ? tmp.len = 1 : tmp.len = 0;
	num1 = A;
	if (A < 0)tmp.len++;
	while (num1) { num1 /= 10; tmp.len++; }
	if (tmp.pCh)delete[]tmp.pCh;
	tmp.pCh = new char[tmp.len+1];
	_itoa_s(A, tmp.pCh, tmp.len+1, 10);
	tmp.len = strlen(tmp.pCh);
	return tmp;
}

DecStr operator*(const int num1, const DecStr& pobj2)
{
	int num2;
	DecStr tmp(pobj2);
	num2 = atoi(pobj2.pCh);
	int A = num1 * num2;
	A <= 0 ? tmp.len = 1 : tmp.len = 0;
	num2 = A;
	if (A < 0)tmp.len++;
	while (num2) { num2 /= 10; tmp.len++; }
	if (tmp.pCh)delete[]tmp.pCh;
	tmp.pCh = new char[tmp.len + 1];
	_itoa_s(A, tmp.pCh, tmp.len + 1, 10);
	tmp.len = strlen(tmp.pCh);
	return tmp;
}

DecStr operator*(const DecStr& pobj2, const int num1)
{
	int num2;
	DecStr tmp(pobj2);
	num2 = atoi(pobj2.pCh);
	int A = num1 * num2;
	A <= 0 ? tmp.len = 1 : tmp.len = 0;
	num2 = A;
	if (A < 0)tmp.len++;
	while (num2) { num2 /= 10; tmp.len++; }
	if (tmp.pCh)delete[]tmp.pCh;
	tmp.pCh = new char[tmp.len + 1];
	_itoa_s(A, tmp.pCh, tmp.len + 1, 10);
	tmp.len = strlen(tmp.pCh);
	return tmp;
}

bool DecStr::toLong(int val)
{
	try
	{
		atol(this->pCh);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool operator==(const DecStr& obj1, const DecStr& obj2)
{
	if (obj1.GetLen() != obj2.GetLen())return false;;
	char* tmp1 = obj1.GetStr();
	char* tmp2 = obj2.GetStr();
	for (int i = 0; i < obj1.GetLen(); i++)
		if (tmp1[i] != tmp2[i])return false;
	return true;
}

int DecStr::getType(void)
{
	return 2;
}

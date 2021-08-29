#include "IdentStr.h"
IdentStr::IdentStr(int val) :Stroka(val)
{
	cout << "IdentStr::IdentStr(int val):Stroka(val),val=" << val << endl;
}

IdentStr::IdentStr(char Ch) : Stroka(Ch)
{
	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_')))
	{
		cout << "Bad Simvol; pCh[0]=" << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	}
}

IdentStr::IdentStr(const char* Str) : Stroka(Str)
{
	if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z') || (pCh[0] == '_')))
	{
		cout << "Bad Simvol,pCh[0]=" << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';

		return;
	}
	for (int i = 1; i < len; i++)
	{
		if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_')))
		{
			cout << "Bad Stroka, pCh[" << i << "]=" << pCh[i] << endl;
			if (pCh) delete[] pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
}

IdentStr& IdentStr::operator=(const IdentStr& Id)
{
	if (&Id != this)
	{
		delete[]pCh;
		len = strlen(Id.pCh);
		pCh = new char[len + 1];
		strcpy_s(pCh, len + 1, Id.pCh);
	}
	return *this;
}

IdentStr& IdentStr::operator=(const char* a)
{
	delete[]pCh;
	len = strlen(a);
	pCh = new char[len + 1];
	strcpy_s(pCh, len + 1, a);
	return *this;
}

char& IdentStr::operator[](int index)
{
	if (index >= 0 && index < len)
	{
		return pCh[index];
	}

	return pCh[0];

}

void IdentStr::hiReg(void) 
{	
	for (int i = 0; i < len; i++)
	{
		if ((pCh[i] >= 'a')&&((pCh[i])<='z'))
		pCh[i] = pCh[i] & 95;
	}
}

IdentStr operator + (const IdentStr& pobj1, const IdentStr& pobj2)
{
	IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());
	int i = 0, j = 0;
	while (tmp.pCh[i++] = pobj1.pCh[j++]);
	--i;                
	j = 0;
	while (tmp.pCh[i++] = pobj2.pCh[j++]);
	return tmp;
}

IdentStr operator +(const IdentStr& pobj1, const char* pobj2)
{
	IdentStr tmp1(pobj2);
	IdentStr tmp(pobj1.GetLen() + tmp1.GetLen());
	int i = 0, j = 0;
	while (tmp.pCh[i++] = pobj1.pCh[j++]);
	--i;                
	j = 0;
	while (tmp.pCh[i++] = tmp1.pCh[j++]);
	return tmp;
}

IdentStr operator +(const char* pobj1, const IdentStr& pobj2)
{

	IdentStr tmp1(pobj1);
	if (tmp1.len == 0)
	{
		IdentStr tmp(pobj2.GetLen());
		int i = 0, j = 0;                  
		while (tmp.pCh[i++] = pobj2.pCh[j++]);
		return tmp;
	}
	else
	{
		IdentStr tmp((int)strlen(pobj1) + pobj2.GetLen());
		int i = 0, j = 0;
		while (tmp.pCh[i++] = *pobj1++);
		--i;                 
		while (tmp.pCh[i++] = pobj2.pCh[j++]);
		return tmp;
	}
}

bool operator==(const IdentStr& obj1, const IdentStr& obj2)
{
	
	if (obj1.GetLen() != obj2.GetLen())
		return false;
	else
		for (int i = 0; i < obj1.GetLen(); i++)
		{
			if (!(obj1.GetStr()[i] == obj2.GetStr()[i])) return false;
		}
		return true;
}

int IdentStr::getType(void)
{
	return 1;
}

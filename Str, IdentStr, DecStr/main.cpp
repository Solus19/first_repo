#include <iostream>
#include <cstdlib>
#include "Stroka.h"
#include "DecStr.h"
#include "IdentStr.h"
#include <conio.h>
#include <Windows.h>

using namespace std;

void TextColor(int text);
void showElements(Stroka** ptr, int* operands,int size);
Stroka** Initializing(Stroka** ptr, int* operands,int size);
int StrokaOp();
int DecStrOp();
int IdentStrOp();
int* operand(Stroka** ptr, int* operands,int size);
void action(Stroka** ptr, int* operands, int operation,int size);
void arrow();


void arrow()
{
	TextColor(10);
	cout << " <--";
	TextColor(15);

}

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void action(Stroka** ptr,  int* operands, int operation,int size)
{
	showElements(ptr, operands, size);
	cout << "\n\n";
	int tmp;
	switch (operation)
	{
	case 1:
		cout << "GetStr()= " << ptr[operands[0]]->GetStr() << "\nВыбор операции снят\n";
		break;

	case 2:
		cout << "GetLen()= " << ptr[operands[0]]->GetLen() << "\nВыбор операции снят\n"; 
		break;

	case 3:
		cout << "Show();\n "; ptr[operands[0]]->Show();
		cout << "\nВыбор операции снят\n";
		break;

	case 4:
		if ((ptr[1]->getType() == 2) && ((ptr[0]->getType() == 2)))
		{
			*dynamic_cast<DecStr*>(ptr[operands[0]]) = *dynamic_cast<DecStr*>(ptr[operands[1]]);
			cout << "ptr[" << operands[0] << "] = ptr[" << operands[1] << "];" << "\nВыбор операции снят\n";
			break;
		}
		cout << "тип объектов должен быть DecStr\nВыбор операции снят\n";
		break;
	case 5:
		cout << "\nвведите номер объекта, в который будет записан результат\n";
		cin >> tmp;
		if ((ptr[1]->getType() == 2) && ((ptr[0]->getType() == 2)) && (ptr[tmp]->getType() == 2))
		{
			*dynamic_cast<DecStr*>(ptr[tmp]) = *dynamic_cast<DecStr*>(ptr[operands[0]]) * *dynamic_cast<DecStr*>(ptr[operands[1]]);
			cout << "\nВыбор операции снят\n";
		}
		cout << "тип объектов должен быть DecStr\nВыбор операции снят\n";
		break;
	case 6:
		if ((ptr[1]->getType() == 2) && ((ptr[0]->getType() == 2)))
		{
			cout << "*ptr[" << operands[0] << " ==*ptr[" << operands[1] << "];\n " << (*dynamic_cast<DecStr*>(ptr[operands[0]]) == *dynamic_cast<DecStr*>(ptr[operands[1]])) << "\nВыбор операции снят\n";
			break;
		}
		cout << "тип объектов должен быть DecStr\nВыбор операции снят\n";
		break;
	case 7:
		if (ptr[operands[0]]->getType() == 2)
		{
			cout << "ptr[" << operands[0] << "]->toLong();\n " << dynamic_cast<DecStr*>(ptr[operands[0]])->toLong() << "\nВыбор операции снят\n"; //ptr[operands[0]]->toLong();
			break;
		}
		cout << "тип объекта должен быть DecStr\nВыбор операции снят\n";
		break;
	case 8:
		if ((ptr[1]->getType() == 1) && ((ptr[0]->getType() == 1)))
		{
			*dynamic_cast<IdentStr*>(ptr[operands[0]]) = *dynamic_cast<IdentStr*>(ptr[operands[1]]);
			cout << "ptr[" << operands[0] << "] = ptr[" << operands[1] << "];" << "\nВыбор операции снят\n";
			break;
		}
		cout << "тип объектов должен быть IdentStr\nВыбор операции снят\n";
		break;

	case 9:
		cout << "\nвведите номер объекта, в который будет записан результат\n";
		cin >> tmp; 
		if ((ptr[1]->getType() == 1) && ((ptr[0]->getType() == 1)) && (ptr[tmp]->getType() == 1))
		{
			*dynamic_cast<IdentStr*>(ptr[tmp]) = *dynamic_cast<IdentStr*>(ptr[operands[0]]) + *dynamic_cast<IdentStr*>(ptr[operands[1]]);
			cout << "\nВыбор операции снят\n";
			break;
		}
		cout << "тип объектов должен быть IdentStr\nВыбор операции снят\n";
		break;

	case 10:
		if (ptr[operands[0]]->getType() == 1)
		{
			cout << "введите индекс\n";
			cin >> tmp;
			cout << "(ptr[" << operands[0] << "])[" << tmp << "]=" << ((*dynamic_cast<IdentStr*>(ptr[operands[0]]))[tmp]);

			break;
		}
		cout << "тип объекта должен быть IdentStr\nВыбор операции снят\n";
		break;

	case 11:
		if (ptr[operands[0]]->getType() == 1) 
		{
		dynamic_cast<IdentStr*>(ptr[operands[0]])->hiReg();
		cout << "\nВыбор операции снят\n";
		break;
		}
		cout << "тип объекта должен быть IdentStr\nВыбор операции снят\n";
		break;
	case 12:
		if ((ptr[1]->getType() == 1) && ((ptr[0]->getType() == 1)))
		{
			cout << "*ptr[" << operands[0] << " ==*ptr[" << operands[1] << "];\n " << (*dynamic_cast<IdentStr*>(ptr[operands[0]]) == *dynamic_cast<IdentStr*>(ptr[operands[1]])) << "\nВыбор операции снят\n";
			break;
		}
		cout << "тип объектов должен быть IdentStr\nВыбор операции снят\n";
		break;

	default:
		break;
	}
	operation = 0;
	cout << "\nдля продолжения нажмите любую клавишу";
	_getch();
}

int StrokaOp()
{
	int pos = 1;
	int tmp;
	while (1)
	{
		system("cls");
		cout << "Stroka operators\n";

		cout << "\n1. GetStr()";
		if (pos == 1)arrow();

		cout << "\n2. GetLen()";
		if (pos == 2)arrow();

		cout << "\n3. Show()";
		if (pos == 3)arrow();

		cout << "\nBack";
		if (pos == 4)arrow();
		tmp = _getch();
		if ((tmp == 72) && (pos > 1)) { pos--; };
		if ((tmp == 80) && (pos < 4)) { pos++; };
		if (tmp == 13)
			switch (pos)
			{
			case 1:return 1;
			case 2:return 2;
			case 3:return 3;
			case 4:return 0;
			
			default:
				break;
			}
	}

}

int DecStrOp()
{
	int pos = 1;
	int tmp;
	while (1)
	{
		system("cls");
		cout << "DecStr operators\n";
		cout << "\n1. = присваивание первого операнда и второго";
		if (pos == 1)arrow();

		cout << "\n2. *  умножение операндов и запись в выбранный";
		if (pos == 2)arrow();

		cout << "\n3. == сравнение операндов, выводит true/false";
		if (pos == 3)arrow();

		cout << "\n5. toLong()";
		if (pos == 4)arrow();

		cout << "\nBack";
		if (pos == 5)arrow();
		tmp = _getch();
		if ((tmp == 72) && (pos > 1)) { pos--; };
		if ((tmp == 80) && (pos < 5)) { pos++; };
		if (tmp==13)
		switch (pos)
		{
		case 1:return 4;
		case 2:return 5;
		case 3:return 6;
		case 4:return 7;
		case 5: return 0;
		default:
			break;
		}
	}

}

int IdentStrOp()
{
	int pos = 1;
	int tmp;
	while (1)
	{
		system("cls");
		cout << "IdenStr operators\n";
		cout << "1.  = присваивание первого операнда и второго";
		if (pos == 1)arrow();

		cout << "\n2. + конкотенация строк";
		if (pos == 2)arrow();

		cout << "\n3. [] возвращение символа хранящегося по индексу";
		if (pos == 3)arrow();

		cout << "\n4. hiReg() перевод всех букв в верхний регистр";
		if (pos == 4)arrow();

		cout << "\n5. == сравнение операндов, выводит true/false";
		if (pos == 5)arrow();

		cout << " \nBack\n "<<endl;
		if (pos == 6)arrow();
		tmp = _getch();
		if ((tmp == 72) && (pos > 1)) { pos--; };
		if ((tmp == 80) && (pos < 6)) { pos++; };
		if (tmp == 13)
			switch (pos)
			{
			case 1:return 8;
			case 2:return 9;
			case 3:return 10;
			case 4:return 11;
			case 5:return 12;
			case 6: return 0;
			default:
				break;
			}
	}
}

int* operand(Stroka** ptr, int* operands,int size)
{
	int tmp = 0;
	int i = 1;
	while (1)
	{
		system("cls");
		cout << "\nвведите номер операнда...";
		cout << "Для выхода введите -1\n";
		showElements(ptr, operands,size);
		
		cin >> tmp;
		if (tmp == -1)return operands;
		operands[i]=tmp; 
		
		++i=(i)%2;
	}
	
}

void showElements(Stroka** ptr, int* operands,int size)
{
	cout << "\nвыбранные элементы: ";
	if (operands[0] != -1) cout << operands[0]<<' ';
	if (operands[1] != -1) cout << operands[1];
	cout << "\nэлементы:";
	for (int i = 0; i < size; i++)
	{
		if (ptr[i]!=nullptr)
		{
			if ((operands[0] == i) || (operands[1] == i)) TextColor(9);
			cout << "\n" << i << ". " << ptr[i]->GetStr();
			TextColor(15);
			switch (ptr[i]->getType())
			{
			case 0: cout << "\ttype: Stroka"; break;
			case 1: cout << "\ttype: IdentStr"; break;
			case 2: cout << "\ttype: DecStr"; break;
			}
		}
		else

			cout << "\n" << i << ". " << "элемент не задан";

	}
	cout << '\n';
}

Stroka** Initializing(Stroka** ptr, int* operands,int size)//сделать что можно выйти из задания значений
{

	int type;
	char input[128];
	for (int i = 0; i < sizeof ptr; i++)
	{
		if (ptr[i]!=nullptr)continue;
		system("cls");
		cout << "Введите номер типа объекта:\n\t1.Stroka\n\t2.IdentStr\n\t3.DecStr\n4.Назад" << endl;
		cin >> type;
		if (type == 4)return ptr;
		//showElements(ptr, operands);
		if (type > 4)cout << "вы ввели неверное число, будет создан объект класса Stroka\n";
		cout << "базовое значение" << endl;
		cin >> input;
		switch (type)
		{
		case 1: ptr[i] = new Stroka(input); break;
		case 2: ptr[i] = new IdentStr(input); break;
		case 3: ptr[i] = new DecStr(input); break;
		default:
			ptr[i] = new Stroka(input);
			break;
		}
		Sleep(300);
	}
	return ptr;
}

void TextColor(int text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(text));
}

int main()
{
	setlocale(LC_ALL, "RU");

	TextColor(15);
	int size=0;
	Stroka** ptr;
	char input[512];
	int type;
	int tmp = 1;//номер кнопки
	int operation = 0;//действие с операндами
	//int operand1,operand2,operand3 = 0;//операнд
	int pos=1;//позиция
	bool initialized=false;
	int* operands =new int[2] { -1,-1 };

	while (1)
	{
		
			system("cls");
			cout << "1. Инициализация.";
			cout << "\n\t 1.1 Задать количество элементов";
			if (pos == 1)  arrow();
			cout << "\n\t 1.2 Задать начальные значения";
			if (pos == 2)  arrow();

			cout << "\n2. Тестирование";
			cout << "\n\t 2.1 Строка";
			if (pos == 3)  arrow();
			cout << "\n\t 2.2. СТРОКА_ИДЕНТИФИКАТОР";
			if (pos == 4)  arrow();
			cout << "\n\t 2.3. ДЕСЯТИЧНОЕ ЧИСЛО";
			if (pos == 5)  arrow();
			cout << "\n\t 2.4. Выбрать операнды";
			if (pos == 6)  arrow();
			cout << "\n3. Выход";
			if (pos == 7)  arrow();
			cout<<"\n\nДля начала необходимо ввести количество элементов";

		tmp = _getch();
		if ((tmp == 72) && (pos > 1)) { pos--; };
		if ((tmp == 80) && (pos < 7)) { pos++; };
		if ((tmp == 13) && (pos == 1))
		{
			system("cls");
			cout << "enter the number of items\n";
				cin >> size;
				
				if (size < 1)
				{
					cout << "введите число больше 0, пожалуйста\n";

					Sleep(600);
					size = 0;
					continue;
				}
				
				ptr = new Stroka * [size];
				for (int i = 0; i < size; i++)ptr[i] = nullptr;
				break;
				
				
		}
		if ((tmp == 13) && (pos == 7)) return 0;
	}


	while (1)
	{
		{
			system("cls");
			cout << "1. Инициализация.";
				cout << "\n\t 1.1 Задать количество элементов";
				if (pos == 1)  arrow();
				cout << "\n\t 1.2 Инициализировать и задать начальные значения";
				if (pos == 2)  arrow();

			cout << "\n2. Тестирование";
				cout << "\n\t 2.1 Строка";
				if (pos == 3)  arrow();
				cout << "\n\t 2.2. СТРОКА_ИДЕНТИФИКАТОР";
				if (pos == 4)  arrow();
				cout << "\n\t 2.3. ДЕСЯТИЧНОЕ ЧИСЛО";
				if (pos == 5)  arrow();
				cout << "\n\t 2.4. Выбрать операнды";
				if (pos == 6)  arrow();
				cout << "\n3. Выход\n";
				if (pos == 7)  arrow();
				if (initialized)	//вывод элементов, если они инициализированы
					showElements(ptr, operands,size);
		}
		if (!(initialized))cout << "\n\nнеобходимо инициализировать элементы перед использованием";
		tmp = _getch();
		if ((tmp == 72) && (pos > 1)) { pos--; };
		if ((tmp == 80) && (pos < 7)) { pos++; };
		
		if (tmp == 13)
		{
			switch (pos)
			{
			case 1: cout << "\n\nВвести повторно количество элементов невозможно" << endl; break;
			case 2: if ((ptr[size-1]==nullptr) && (size != 0)) { ptr = Initializing(ptr, operands,size); initialized = true; }
				else cout << "\n\nВсе элемента инициализированны, инициализировать повторно невозможно";  
				Sleep(600); break;
			case 3: if (initialized) operation = StrokaOp(); break;
			case 4: if (initialized) operation = IdentStrOp(); break;
			case 5: if (initialized) operation = DecStrOp(); break;
			case 6: if (initialized) operands=operand(ptr,operands,size); break;
			}
			if (operation)
			{
				action(ptr, operands, operation,size);
				operation = 0;
			}
		if (pos == 7)return 0;
		}
	}
}

#include <iostream>
#include <vector>
#include "struckts.h"
#include "Header.h"
using namespace std;

char sign_to_char(sign tmp)
{
    switch (tmp)
    {
    case (sign::cross):return 'X'; break;
    case (sign::zero): return 'O'; break;
    default:return ' ';
    }
}

bool check_end(int x, int y, game_field& data, vector <vector<sign>> &field)
{
    bool check = 1;
    int sum;
    //главная диагональ
    sum = 0;
    for (int i = 1; i < (data.win_size) * 2 - 1; i++)
    {
        if (x + i - data.win_size < 0 || x + i - data.win_size >= data.size
            || y + i - data.win_size < 0 || y + i - data.win_size >= data.size)//если вышли за пределы
            continue;
        if (field[x + i - data.win_size][y + i - data.win_size] != data.turn)
        {
            check = 0;
            sum = 0;
        }
        else
            sum++;
        if (sum == data.win_size) return 1;
    }

    //вертикаль
    sum = 0;
    for (int i = 1; i < (data.win_size) * 2 - 1; i++)
    {
        if (y + i - data.win_size < 0 || y + i - data.win_size >= data.size)//если вышли за пределы
            continue;
        if (field[x][y + i - data.win_size] != data.turn)
        {
            check = 0;
            sum = 0;
        }
        else
            sum++;
        if (sum == data.win_size) return 1;
    }

    //побочная диагональ
    sum = 0;
    for (int i = 1; i < (data.win_size) * 2 - 1; i++)
    {
        if (x - i + data.win_size < 0 || x - i + data.win_size >= data.field.size()
            || y + i - data.win_size < 0 || y + i - data.win_size >= data.field.size())//если вышли за пределы
            continue;
        if (field[x - i + data.win_size][y + i - data.win_size] != data.turn)
        {
            check = 0;
            sum = 0;
        }
        else
            sum++;
        if (sum == data.win_size) return 1;
    }

    //горизонталь
    sum = 0;
    for (int i = 1; i < (data.win_size) * 2 - 1; i++)
    {
        if (x + i - data.win_size < 0 || x + i - data.win_size >= data.field.size())//если вышли за пределы
            continue;
        if (field[x + i - data.win_size][y] != data.turn)
        {
            check = 0;
            sum = 0;
        }
        else
            sum++;
        if (sum == data.win_size) return 1;
    }
    return 0;
}

void print_UI(game_field& data)
{
    //system("cls");
    cout << "Сейчас очередь ходить: " << sign_to_char((data.get_turn())) << endl;
    cout << endl;
    draw_field(data);
    cout << endl;
}

void draw_field(game_field& data)
{
    for (int i = 0; i < data.size; i++)
    {
        cout << ' ' << sign_to_char(data.field[i][0]);
        for (int j = 1; j < data.size; j++)
        {
            cout << " | " << (sign_to_char(data.field[i][j]));
        }
        cout << endl;

        if (i < data.size - 1)
        {
            cout << "———";
            for (int j = 1; j < data.size; j++)
            {
                cout << "+———";
            }
            cout << endl;
        }
    }
}

void read_cords(coordinates& cords, int size, vector <vector<sign>> field)
{
    while (1)
    {
        cout << "Введите координаты (x,y), куда вы желаете походить, начиная от (1,1)\n";
        cin >> cords.y >> cords.x;
        cords.x--;
        cords.y--;
        if (cords.x > size || cords.y > size || cords.x < 0 || cords.y < 0)
        {
            cout << "Невозможные координаты, попробуйте ещё\n";
            continue;
        }

        if (field[cords.x][cords.y] != sign::none)
        {
            cout << "Данная клетка занята\n";
            continue;
        }
        break;
    }
}

void add_to_weight(int x, int y, game_field& data, vector <vector<weight_cell>> &weight)
{
    int size = data.field.size();
    for (int i = 0; i < data.win_size; i++)
    {


        if ((x - i > -1 && y - i > -1)) //вектор (-1,1)
        {
            if (data.field[x - i][y - i] != sign::none)
            {
                weight[x - i][y - i] = { 0,0 };
            }
            else if (data.turn == sign::cross)
                weight[x - i][y - i].zero++;
            else if (data.turn == sign::zero)
                weight[x - i][y - i].cross++;
        }


        if ((y - i > -1))
        {
            if (data.field[x][y - i] != sign::none)
            {
                weight[x][y - i] = { 0,0 };
            }
            else  //вектор (0,1)
                if (data.turn == sign::cross)
                    weight[x][y - i].zero++;
                else if (data.turn == sign::zero)
                    weight[x][y - i].cross++;
        }


        if ((x + i < size && y - i > -1))
        {
            if (data.field[x + i][y - i] != sign::none)
            {
                weight[x + i][y - i] = { 0,0 };
            }
            else  //вектор (1,1)
                if (data.turn == sign::cross)
                    weight[x + i][y - i].zero++;
                else if (data.turn == sign::zero)
                    weight[x + i][y - i].cross++;
        }

        if ((x + i < size))
        {
            if (data.field[x + i][y ] != sign::none)
            {
                weight[x + i][y ] = { 0,0 };
            }
            else  //вектор (1,0)
                if (data.turn == sign::cross)
                    weight[x + i][y].zero++;
                else if (data.turn == sign::zero)
                    weight[x + i][y].cross++;
        }

        if ((x + i < size && y + i < size)) //вектор (-1,1)
        {
            if (data.field[x + i][y + i] != sign::none)
            {
                weight[x + i][y + i] = { 0,0 };
            }
            else  //вектор (1,-1)
                if (data.turn == sign::cross)
                    weight[x + i][y + i].zero++;
                else if (data.turn == sign::zero)
                    weight[x + i][y + i].cross++;
        }

        if ((y + i < size))
        {
            if (data.field[x][y + i] != sign::none)
            {
                weight[x][y + i] = { 0,0 };
            }
            else  //вектор (0,-1)
                if (data.turn == sign::cross)
                    weight[x][y + i].zero++;
                else if (data.turn == sign::zero)
                    weight[x][y + i].cross++;
        }

        if ((x - i > -1 && y + i < size))
        {
            if (data.field[x-i][y + i] != sign::none)
            {
                weight[x-i][y + i] = { 0,0 };
            }
            else  //вектор (-1,-1)
                if (data.turn == sign::cross)
                    weight[x - i][y + i].zero++;
                else if (data.turn == sign::zero)
                    weight[x - i][y + i].cross++;
        }


        if ((x - i > -1))
        {
            if (data.field[x - i][y] != sign::none)
            {
                weight[x - i][y] = { 0,0 };
            }
            else //вектор (-1,0)
                if (data.turn == sign::cross)
                    weight[x - i][y].zero++;
                else if (data.turn == sign::zero)
                    weight[x - i][y].cross++;
        }
    }

}

void print_weights(game_field& data, vector <vector<weight_cell>> weight)
{
    bool supreme = 0;
    int sum;
    vector<vector<int>>tmp(data.field.size());

    cout << "cross\n";
    for (int x = 0; x < data.size; x++)
    {
        for (int y = 0; y < data.size; y++)
        {
            cout << weight[x][y].cross << ' ';

        }
        cout << endl;
    }

    cout << "\n\nzero\n";
    for (int x = 0; x < data.size; x++)
    {
        for (int y = 0; y < data.size; y++)
        {
            cout << weight[x][y].zero << ' ';

        }
        cout << endl;
    }
}

bool move(coordinates cords, game_field& data, vector <vector<weight_cell>>weight)
{
    data.field[cords.x][cords.y] = data.turn;
    if (data.AI_turn != sign::none)
        add_to_weight(cords.x, cords.y, data,weight);



    if (check_end(cords.x, cords.y, data,data.field))
        return 1;
    data.next_turn();
    return 0;
}

void print_v(vector<vector<int>>v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}
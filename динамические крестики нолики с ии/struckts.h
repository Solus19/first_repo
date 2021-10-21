#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct weight_cell
{
    int cross = 0;
    int zero = 0;
};



struct coordinates
{
    int x = 0;
    int y = 0;
};

enum class sign
{
    none,
    zero,
    cross
};

struct game_field
{
    vector <vector<sign>> field;
    sign turn = sign::none;
    int win_size = 3;
    int size = 3;
    sign AI_turn = sign::none;

private:
    void init_field()
    {
        vector<sign>tmp(size, sign::none);

        this->field.resize(size, tmp);
    }

public:

    void read_parametrs()
    {
        cout << "¬ведите размер квадратного пол€\n";
        cin >> size;
        this->init_field();
        cout << "¬ведите длинну р€да дл€ выигрыша\n";
        cin >> win_size;
    }

    void next_turn()
    {
        switch (this->turn)
        {
        case sign::cross: this->turn = sign::zero; break;
        case sign::zero: this->turn = sign::cross; break;
        }
    }

    sign get_turn()
    {
        return turn;
    }
};


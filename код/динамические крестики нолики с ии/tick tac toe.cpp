using namespace std;
#include <iostream>
#include <vector>
#include "Header.h"
//vector <vector<weight_cell>> weight;
void game()
{
    vector <vector<weight_cell>> weight;
    game_field data;
    data.read_parametrs();
    coordinates cords;

    weight.resize(data.size);
    for (int i=0;i<data.size;i++)
        weight[i].resize(data.size);

    //выясняем кто первый ходит
    {
        char ctmp;
        cout << "Хотите сыграть с ИИ?\ny/n\n";
        cin >> ctmp;
        
        switch (ctmp)
        {
        case 'n':data.AI_turn = sign::none; break;
        case 'y': 
            while (data.AI_turn==sign::none)
            {

                cout << "Кем будем играть ИИ?\n1. Круг\n2. Крестик\n3. Рандом\n";
                cin >> ctmp;
                switch (ctmp)
                {
                case '1':data.AI_turn = sign::zero;
                    break;

                case '2':data.AI_turn = sign::cross;
                    break;

                case '3':data.AI_turn = sign(rand() % 2 + 1);
                    break;

                default:cout << "Попробуйте ввести целое число между 1 и 3\n";
                    break;
                }
            }
        default:
            break;
        }
            
        while (data.turn == sign::none)
        {


            cout << "Введите, кто ходит первый:\n1. Круг\n2. Крестик\n3. Рандом\n";
            cin >> ctmp;
            switch (ctmp)
            {
            case '1':data.turn = sign::zero;
                break;

            case '2':data.turn = sign::cross;
                break;

            case '3':data.turn = sign(rand() % 2 + 1);
                break;

            default:cout << "Попробуйте ввести целое число между 1 и 3\n";
                break;
            }
        }

    }   
    bool win = 0;
    coordinates AI_move = { 0,0 };

    while (!win)//игровой цикл
    {
        print_UI(data);
        print_weights(data, weight);
        //print_v(weight);
        if (data.AI_turn != sign::none && data.AI_turn==data.turn)
        {

            //count_weights(data);
            AI_move = max_weight(data, weight);
            win=move(AI_move,data,weight);
            add_to_weight(AI_move.x,AI_move.y, data, weight);
            continue;
        }
        read_cords(cords,data.size,data.field);
        win=move( cords ,data,weight);//разбить
        add_to_weight(cords.x, cords.y, data, weight);
    }

    print_UI(data);
    cout << "Congrats, " <<sign_to_char( data.get_turn())<< " won\n";
}

coordinates max_weight(game_field &data, vector <vector<weight_cell>> weight)
{
    coordinates cords_end;
    vector <vector<sign>> tmp;
    int max_cross=0,max_zero = 0;
    coordinates cords_cross,cords_zero;
    for (int x = 0; x < data.size; x++)
    {
        for (int y = 0; y < data.size; y++)
        {
            if (weight[x][y].cross > max_cross)
            {
                if (weight[x][y].cross == data.win_size - 1)//если на грани выигрыша
                {
                    tmp = data.field;
                    tmp[x][y] = sign::cross;
                    if (check_end(x, y, data, tmp))
                    {
                        if (data.AI_turn == sign::cross)
                            return cords_end = { x, y };
                        cords_end={x,y};
                    }
                }
                max_cross = weight[x][y].cross;
                cords_cross.x = x;
                cords_cross.y = y;
            }

            if (weight[x][y].zero > max_zero)
            {

                if (weight[x][y].cross == data.win_size - 1)//если на грани выигрыша
                {
                    tmp = data.field;
                    tmp[x][y] = sign::zero;
                    if (check_end(x, y, data, tmp))
                    {
                        if (data.AI_turn == sign::zero)
                            return cords_end = { x, y };
                        cords_end = { x,y };
                    }
                }

                max_zero = weight[x][y].zero;
                cords_zero.x = x;
                cords_zero.y = y;
            }
            if (max_zero == data.win_size - 1 && data.turn == sign::zero) return cords_zero;

            if (max_cross == data.win_size - 1 && data.turn == sign::cross) return cords_cross;
        }
    }
    return (max_cross>max_zero)?cords_cross:cords_zero;
}

int main()
{
    
    setlocale(LC_ALL, "Russian");
    
    game();
}





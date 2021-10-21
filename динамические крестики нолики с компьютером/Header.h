#pragma once
#include <iostream>
#include <vector>
#include "struckts.h"

bool check_end(int, int, game_field&, vector <vector<sign>>& );
char sign_to_char(sign);
void print_UI(game_field&);
void draw_field(game_field&);
void read_cords(coordinates&, int , vector <vector<sign>> );
void add_to_weight(int , int , game_field&, vector <vector<weight_cell>>&);
bool move(coordinates , game_field&, vector <vector<weight_cell>>);
void print_v(vector<vector<int>>);
void count_weights(game_field&);
coordinates max_weight(game_field&, vector <vector<weight_cell>>);
void print_weights(game_field& , vector <vector<weight_cell>> );
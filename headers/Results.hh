//
// Created by Kévin HURON on 10/04/2017.
//

#ifndef GAME_RESULTS_HH
#define GAME_RESULTS_HH


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
using namespace std;

class Results {
public:
    fstream results;
    string line;
    int best_result;
    bool cheating = false; // We could get if player change his score in score.txt (Not used here)

    int import_file();
    bool check(int actuall_result);
    void save();
    string return_points();
};

#endif //GAME_RESULTS_HH

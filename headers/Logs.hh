//
// Created by Kévin HURON on 02/05/2017.
//

#ifndef GAME_LOGS_HH
#define GAME_LOGS_HH

#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

class Logs {

public:
    fstream logs;
    void writeLog(string line);
    void writeErrorLog(string line);
};


#endif //GAME_LOGS_HH

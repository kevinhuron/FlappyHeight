//
// Created by Kévin HURON on 02/05/2017.
//

#include "../headers/Logs.hh"

void Logs::writeLog(string line) {
    logs.open("LOGS/logs.txt", ios::app);
    time_t now = time(0);
    char* datenNow = ctime(&now);
    logs << datenNow;
    logs << " --- ";
    logs << line << endl;
    logs.close();
}

void Logs::writeErrorLog(string line) {
    logs.open("LOGS/Error_logs.txt", ios::app);
    time_t now = time(0);
    char* datenNow = ctime(&now);
    logs << datenNow;
    logs << " --- ";
    logs << line << endl;
    logs.close();
}
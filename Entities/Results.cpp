//
// Created by Kévin HURON on 10/04/2017.
//

#include "../headers/Results.hh"
using namespace std;

/**
 * Import score.txt file
 * Check with a 128 division the score to prevent cheating
 * @return
 */
int Results::import_file()
{
    results.open("score.txt", ios::in);
    if (results.good() == false) {
        cout << "Error! With importing score.txt";
        return -1;
    }

    while(getline(results, line)) {
        if (atoi(line.c_str()) % 128 == 0)
            best_result = atoi(line.c_str()) / 128;
        else {
            cout << "Error! CHEATING";
            cheating = true;
            return -1;
        }
    }
    results.close();
    return 1;
}

/**
 * Check the results
 */
bool Results::check(int actuall_result)
{
    if (best_result < actuall_result) {
        best_result = actuall_result;
        return true;
    }
    return false;
}

/**
 * Save the new best score
 */
void Results::save()
{
    results.open("score.txt", ios::out);
    results<<(best_result * 128);
    results.close();
}

/**
 * Return the score
 * @return
 */
string Results::return_points()
{
    stringstream points_ss;
    points_ss << best_result;
    string points_to_view = points_ss.str();
    return points_to_view;
}

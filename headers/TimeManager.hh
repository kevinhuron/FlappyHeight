//
// Created by Kévin HURON on 13/04/2017.
//

#ifndef GAME_TIMEMANAGER_HH
#define GAME_TIMEMANAGER_HH


#include <chrono>

class TimeManager {

private:
    static TimeManager* instance;
    std::chrono::time_point<std::chrono::system_clock> start, update, update2;
    TimeManager();
    TimeManager(const TimeManager&);
    TimeManager& operator=(const TimeManager&);
public:
    ~TimeManager();
    static TimeManager& GetInstance();
    void Start();
    void Update();
    unsigned int GetElapsedTime() const;
    unsigned int GetStartedTime() const;
};


#endif //GAME_TIMEMANAGER_HH

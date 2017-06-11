//
// Created by Kévin HURON on 13/04/2017.
//

#include "../headers/TimeManager.hh"

#include <cstddef>

TimeManager *TimeManager::instance = NULL;

TimeManager::TimeManager(const TimeManager&) {};
TimeManager::TimeManager() {};

TimeManager::~TimeManager() {}

/**
 * Singleton - get an instance of timeManager
 * @return
 */
TimeManager& TimeManager::GetInstance() {
    if(instance == NULL)
        instance = new TimeManager;
    return *instance;
}

/**
 * Start the TimeManager
 */
void TimeManager::Start() {
    this->start = std::chrono::system_clock::now();
    this->update = this->start;
    this->update2 = this->start;
}

/**
 * Update the TimeManager
 */
void TimeManager::Update() {
    if (this->update == this->start) {
        this->update = std::chrono::system_clock::now();
        this->update2 = std::chrono::system_clock::now();
    } else {
        this->update = this->update2;
        this->update2 = std::chrono::system_clock::now();
    }
}

/**
 * Get the Elapased Time between two update
 * @return
 */
unsigned int TimeManager::GetElapsedTime() const {
    if (this->update == this->update2) {
        return 0;
    } else {
        std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(this->update2 - this->update);
        return (unsigned int) ms.count();
    }
}

/**
 * Get the started time between a start and an update
 * @return
 */
unsigned int TimeManager::GetStartedTime() const {
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(this->update2 - this->start);
    return (unsigned int) ms.count();
}
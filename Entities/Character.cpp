//
// Created by Kévin HURON on 11/04/2017.
//

#include "../headers/Character.hh"

Character::Character() {}

Character::~Character() {}

/**
 * Get X position
 * @return
 */
double Character::GetX() const {
    return this->X;
}

/**
 * Set X position
 * @param x
 */
void Character::SetX(double x) {
    this->X = x;
    this->mynotify();
}

/**
 * Get Y position
 * @return
 */
double Character::GetY() const {
    return this->Y;
}

/**
 * Set Y position
 * @param y
 */
void Character::SetY(double y) {
    this->Y = y;
    this->mynotify();
}

/**
 * Update
 */
void Character::Update() {}

/**
 * Draw
 */
void Character::Draw() {}

/**
 * Notify by observer
 */
void Character::mynotify() {
    for (IObserver* one : Observers) {
        one->Notify(this);
    }
}

/**
 * Add observers
 * @param obs
 */
void Character::AddObserver(IObserver *obs) {
    Observers.push_back(obs);
}

/**
 * Remove Observers
 * @param obs
 */
void Character::RemoveObserver(IObserver *obs) {
    Observers.remove(obs);
}
//
// Created by Kévin HURON on 11/04/2017.
//

#ifndef GAME_CHARACTER_HH
#define GAME_CHARACTER_HH

#include <iostream>
#include <list>
#include "AbstractEntity.hh"
#include "../Interfaces/IObservable.hh"

using namespace std;
class Character : public AbstractEntity, public IObservable {

protected:
    double X;
    double Y;
    list<IObserver*> Observers;
public:
    Character();
    virtual ~Character() = 0;
    virtual double GetX() const;
    void SetX(double x);
    virtual double GetY() const;
    void SetY(double y);
    virtual void Draw();
    virtual void Update();
    virtual void AddObserver(IObserver* obs);
    virtual void RemoveObserver(IObserver* obs);
    void mynotify();
};


#endif //GAME_CHARACTER_HH

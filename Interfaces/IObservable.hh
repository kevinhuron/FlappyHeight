//
// Created by Kévin HURON on 11/04/2017.
//

#ifndef GAME_IOBSERVABLE_HH
#define GAME_IOBSERVABLE_HH

#include "IObserver.hh"

class IObservable {

public:
    virtual ~IObservable(){};
    virtual void AddObserver(IObserver*) = 0;
    virtual void RemoveObserver(IObserver*) = 0;
};

#endif //GAME_IOBSERVABLE_HH

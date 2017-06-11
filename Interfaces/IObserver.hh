//
// Created by Kévin HURON on 11/04/2017.
//

#ifndef GAME_IOBSERVER_HH
#define GAME_IOBSERVER_HH

class IObservable;

class IObserver {

public:
    virtual ~IObserver(){};
    virtual void Notify(IObservable*) = 0;
};

#endif //GAME_IOBSERVER_HH

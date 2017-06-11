//
// Created by Kévin HURON on 11/04/2017.
//

#ifndef GAME_ABSTRACTENTITY_HH
#define GAME_ABSTRACTENTITY_HH


class AbstractEntity {

public:
    AbstractEntity();
    virtual ~AbstractEntity();
    virtual void Draw() = 0;
    virtual void Update() = 0;
};


#endif //GAME_ABSTRACTENTITY_HH

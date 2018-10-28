#ifndef ROGUESPELLS_H
#define ROGUESPELLS_H

#include "Spells.h"

class Rogue;

class RogueSpells: public Spells {
public:
    RogueSpells(Rogue *rogue);
    virtual ~RogueSpells() override;

private:
    Rogue* rogue;
};

#endif // ROGUESPELLS_H

#ifndef DOUDIZHU_CARDS_H
#define DOUDIZHU_CARDS_H

#include "card.h"
#include "vector"
#include "algorithm"

using namespace std;

class cards {
private:
    vector<card> crds;

    struct cmp;

public:
    cards();

    vector<card> &get_cards();

    cards &operator=(cards &&c1) noexcept ;
};

#endif //DOUDIZHU_CARDS_H

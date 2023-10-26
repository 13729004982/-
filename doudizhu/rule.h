#ifndef DOUDIZHU_RULE_H
#define DOUDIZHU_RULE_H

#include "card.h"
#include "vector"

using namespace std;

struct rule {
    static int is_bomb(const vector<card> &cards);

    static bool is_jokers_bomb(const vector<card> &cards);

    static int is_pair(const vector<card> &cards);

    static int is_three(const vector<card> &cards);

    static int is_three_with_one(const vector<card> &cards);

    static int is_three_with_pair(const vector<card> &cards);

    static pair<int, int> is_plane(const vector<card> &cards);

    static pair<int, int> is_straight(const vector<card> &cards);

    static int is_single(const vector<card> &cards);

    static pair<int,int> is_pairs(const vector<card> &cards);
};

#endif //DOUDIZHU_RULE_H

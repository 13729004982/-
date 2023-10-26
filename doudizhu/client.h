#ifndef DOUDIZHU_CLIENT_H
#define DOUDIZHU_CLIENT_H

#include "vector"
#include "algorithm"
#include "rule.h"
#include "iostream"
#include "cstring"

using namespace std;

class client {
private:
    vector<card> my_card;
public:
    bool dizhu;
    vector<card> cards_to_beat;

    client();

    void get_card(vector<card> &cards);

    int select_dizhu(int pnt);

    void become_dizhu();

    void toss_cards();

    void sort_the_cards();

    bool check_rule(const vector<card> &cards) const;

    void display_card();

    bool discard_cards(vector<card> &cards);


//    暂时
    void select_cards(pair<vector<card> &, int> &pair1);

    bool has_card();

};

#endif //DOUDIZHU_CLIENT_H

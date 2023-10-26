#ifndef DOUDIZHU_TABLE_H
#define DOUDIZHU_TABLE_H
#include "random"
#include "vector"
#include "client.h"
#include "mutex"
#include "cards.h"
#include "round_ptr.h"
#include "client_box.h"
using namespace std;


class table {
private:
    round_ptr cur_ptr;
    pair<vector<card>&,int> pair1 ;
    vector<card> front_cards;

    class cards crds;

    client_box cl1;
    client_box cl2;
    client_box cl3;

private:
    struct cmp;

public:
    table();

    void give_card();

    void give_card_to_dizhu();

    void to_next_person();

    void random_select();

    void restart();

    void reset_cards();

    bool select_dizhu();

    void game_start();
};
#endif //DOUDIZHU_TABLE_H

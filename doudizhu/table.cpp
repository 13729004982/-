#include "table.h"

using namespace std;


struct table::cmp {
    bool operator()(const card &c1, const card &c2) {
        return c1 < c2;
    }
};

table::table() : cl1(client()), cl2(client()), cl3(client()), pair1(front_cards, 0) {
    cl1.point_to(cl2).point_to(cl3).point_to(cl1);
    cur_ptr = &cl1;
}

void table::give_card() {
    vector<card> card_for_c1;
    vector<card> card_for_c2;
    vector<card> card_for_c3;
    default_random_engine e(time(nullptr));
    vector<card> &cards = crds.get_cards();
    while (cards.size() > 3) {
        unsigned int num = cards.size();
        unsigned int which = e() % num;
        auto ptr = cards.begin() + which;
        card card_to_transfer = *ptr;

        if (card_for_c1.size() < 17) {
            card_for_c1.emplace_back(card_to_transfer);
        } else if (card_for_c2.size() < 17) {
            card_for_c2.emplace_back(card_to_transfer);
        } else {
            card_for_c3.emplace_back(card_to_transfer);
        }
        cards.erase(ptr);
    }
    cur_ptr.get_client().get_card(card_for_c1);
    cur_ptr.to_next();
    cur_ptr.get_client().get_card(card_for_c2);
    cur_ptr.to_next();
    cur_ptr.get_client().get_card(card_for_c3);
    cur_ptr.to_next();
}

void table::give_card_to_dizhu() {
    while (true) {
        client &cl = cur_ptr.get_client();
        vector<card> cards = crds.get_cards();
        if (cl.dizhu) {
            cl.get_card(cards);
            cards.clear();
            break;
        }
    }
}

void table::to_next_person() {
    cur_ptr.to_next();
}

void table::random_select() {
    default_random_engine e(time(nullptr));
    int times = e() % 3;
    while (times-- > 0) {
        to_next_person();
    }
}

void table::restart() {
    random_select();
    reset_cards();
    give_card();
}

void table::reset_cards() {
    crds = cards();
    for (int i = 0; i < 3; i++) {
        cur_ptr.get_client().toss_cards();
        to_next_person();
    }
}

bool table::select_dizhu() {
    int ptr = 0;
    int noCall = 0;
    int recNoCall = 0;
    while (true) {
        if (recNoCall > 0) {
            if (--recNoCall == 0) {
                to_next_person();
                continue;
            }
        }
        if (noCall == 2 && ptr != 0) {
            (*cur_ptr).become_dizhu();
            return true;
        }
        int sel = (*cur_ptr).select_dizhu(ptr);
        if (sel != -1) {
            ptr = sel;
            if (noCall == 2) {
                (*cur_ptr).become_dizhu();
                return true;
            }
        } else {
            noCall++;
            recNoCall = (recNoCall == 0) ? 3 : recNoCall;
        }
        if (noCall == 3) {
            restart();
            return false;
        }
        if (ptr == 3) {
            (*cur_ptr).become_dizhu();
            break;
        }
        to_next_person();
    }
}

void table::game_start() {
    give_card();
    bool rec = false;
    while (true) {
        rec = select_dizhu();
        if (rec) {
            break;
        }
        restart();
    }
    give_card_to_dizhu();
    while (true) {
        auto &cl = (*cur_ptr);
        cl.display_card();
        cl.select_cards(pair1);
        if (!cl.has_card()) {
            break;
        }
        to_next_person();
    }
}


int main() {
    table tb;
    tb.game_start();
}


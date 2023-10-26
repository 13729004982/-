#include "rule.h"

using namespace std;

int rule::is_bomb(const vector<card> &cards) {
    if (cards.size() != 4)
        return 0;
    else {
        for (int i = 0; i < cards.size() - 1; i++) {
            if (cards[i] != cards[i + 1])
                return 0;
        }
        return cards[0].ranking;
    }
}

bool rule::is_jokers_bomb(const vector<card> &cards) {
    if (cards.size() == 2 && cards[0] == card("j1") && cards[1] == card("j2"))
        return true;
    return false;
}

int rule::is_pair(const vector<card> &cards) {
    if (cards.size() == 2 && cards[0] == cards[1])
        return cards[0].ranking;
    return 0;
}

int rule::is_three(const vector<card> &cards) {
    if (cards.size() == 3 && cards[0] == cards[1] && cards[1] == cards[2])
        return cards[0].ranking;
    return 0;
}

int rule::is_three_with_one(const vector<card> &cards) {
    if (cards.size() == 4) {
        if (cards[0] == cards[1] && cards[1] == cards[2]) {
            return cards[0].ranking;
        } else {
            if (cards[1] == cards[2] && cards[2] == cards[3]) {
                return cards[1].ranking;
            }
        }
    }
    return 0;
}

int rule::is_three_with_pair(const vector<card> &cards) {
    if (cards.size() == 5) {
        if (cards[0] == cards[1]) {
            if (cards[1] == cards[2]) {
                if (cards[3] == cards[4]) {
                    return cards[0].ranking;
                }
            } else {
                if (cards[2] == cards[3] && cards[3] == cards[4]) {
                    return cards[2].ranking;
                }
            }
        }
    }
    return 0;
}

pair<int, int> rule::is_plane(const vector<card> &cards) {
    auto ptr = cards.begin();
    int threes = 0, pair = 0, single = 0;
    bool end_of_threes = false;
    int rank = 0;
    while (ptr < cards.end()) {
        while (!end_of_threes && ptr < cards.end() - 2 && is_three(vector<card>(ptr, ptr + 2))) {
            threes++;
            ptr += 3;
            if (rank == 0) {
                rank = ptr->ranking;
            }
        }
        if (threes) {
            end_of_threes = true;
        }
        if (single == 0 && ptr < cards.end() - 1 && is_pair(vector<card>(ptr, ptr + 1))) {
            pair++;
            ptr += 2;
        }
        if (pair == 0 && ptr < cards.end()) {
            single++;
            ptr++;
        }
    }
    if (threes > 0 && (pair == threes || single == threes || (pair == 0 && single == 0))) {
        return make_pair(threes, rank);
    }
    return make_pair(0, -1);
}

pair<int, int> rule::is_straight(const vector<card> &cards) {
    auto ptr = cards.begin();
    int rec = cards[0].ranking;
    while (ptr != cards.end() - 1) {
        if (ptr->ranking != (ptr + 1)->ranking + 1) {
            return make_pair(0, -1);
        }
        ptr++;
    }
    return make_pair(cards.size(), rec);
}

int rule::is_single(const vector<card> &cards) {
    if (cards.size() == 1) {
        return cards[0].ranking;
    }
    return -1;
}

pair<int, int> rule::is_pairs(const vector<card> &cards) {
    int rec=0;
    if (cards.size() % 2 != 0 || cards.size() == 2) {
        return make_pair(0, -1);
    } else {
        bool increment = false;
        auto cmp=[&](int n1,int n2)->bool {
            if(increment){
                return cards[n1]<cards[n2];
            } else{
                return cards[n2]<cards[n1];
            }
        };
        if (cards[0] != cards[1]) {
            return make_pair(0, -1);
        } else {
            if (cards[0] < cards[2]) {
                increment = true;
                rec=cards.back().ranking;
            } else{
                rec=cards[0].ranking;
            }
            for(int i=0;i<cards.size();){
                if (cards[i]!=cards[i+1]||!cmp(i,i+2)){
                    return make_pair(0,-1);
                }
                i+=2;
            }
        }
        return make_pair(cards.size(),rec);
    }
}
#include "client.h"

using namespace std;

client::client() {
    dizhu = false;
    cards_to_beat.clear();
}

void client::get_card(vector<card> &cards) {
    my_card.insert(my_card.end(), cards.begin(), cards.end());
    sort_the_cards();
}

int client::select_dizhu(int pnt) {
    int point[3]{1, 2, 3};
    int result;
    cout << "选择: ";
    for (int i = pnt; i < 3; i++) {
        cout << point[i] << " ";
    }
    cout << "不抢(-1)" << endl;

    do {
        cin >> result;
    } while (result == 0 || result > 3 || result < -1);
    cin.get();
    return result;
}

void client::become_dizhu() {
    dizhu = true;
}

void client::toss_cards() {
    my_card.clear();
}

void client::sort_the_cards() {
    sort(my_card.begin(), my_card.end(), greater<card>());
}

bool client::check_rule(const vector<card> &cards) const {
    if (cards_to_beat.empty()) {
        if (!cards.empty() && (rule::is_jokers_bomb(cards) || rule::is_bomb(cards) || rule::is_plane(cards).first ||
                               rule::is_three_with_pair(cards) || rule::is_three_with_one(cards) ||
                               rule::is_three(cards) ||
                               rule::is_straight(cards).first || rule::is_pairs(cards).first ||
                               rule::is_pair(cards) || rule::is_single(cards))) {
            return true;
        } else {
            return false;
        }
    }
    if (rule::is_jokers_bomb(cards)) {
        return true;
    } else if (rule::is_bomb(cards) > rule::is_bomb(cards_to_beat)) {
        return true;
    } else if (rule::is_plane(cards) > rule::is_plane(cards_to_beat)) {
        return true;
    } else if (rule::is_three_with_pair(cards) > rule::is_three_with_pair(cards_to_beat)) {
        return true;
    } else if (rule::is_three_with_one(cards) > rule::is_three_with_one(cards_to_beat)) {
        return true;
    } else if (rule::is_three(cards) > rule::is_three(cards_to_beat)) {
        return true;
    } else if (rule::is_straight(cards) > rule::is_straight(cards_to_beat)) {
        return true;
    } else if (rule::is_pairs(cards) > rule::is_pairs(cards_to_beat)) {
        return true;
    } else if (rule::is_pair(cards) > rule::is_pair(cards_to_beat)) {
        return true;
    } else if (rule::is_single(cards) > rule::is_single(cards_to_beat)) {
        return true;
    }
    return false;
}

void client::display_card() {
    for (auto card: my_card) {
        cout << card << " ";
    }
    cout << endl;
}

bool client::discard_cards(vector<card> &cards) {
    for (const auto &card: cards) {
        auto ptr = std::find(my_card.begin(), my_card.end(), card);
        if (ptr == my_card.end()) {
            return false;
        }
        my_card.erase(ptr);
    }
    return true;
}

void client::select_cards(pair<vector<card> &, int> &pair1) {
    if (pair1.second == 0) {
        pair1.first.clear();
    }
    cards_to_beat = pair1.first;
    cout << "顶端的牌：";
    for (auto i: cards_to_beat) {
        cout << i << " ";
    }
    cout << endl;
    while (true) {
        vector<card> cards;
        cout << "请输入你要出的牌：" << endl;
        char inBuff[21];
        memset(inBuff, 0, 21);
        gets(inBuff);
        if (inBuff[0] == 'p' || inBuff[0] == 'P') {
            pair1.second--;
            return;
        }
        for (int i = 0; i < strlen(inBuff);) {
            if (inBuff[i] == 'j') {
                if (inBuff[++i] == '2') {
                    cards.emplace_back("j2");
                } else {
                    cards.emplace_back("j1");
                }
                i++;
            } else if (inBuff[i] == '1') {
                cards.emplace_back("10");
                i += 2;
            } else {
                cards.emplace_back(string(1, inBuff[i]));
                i++;
            }
        }
        sort(cards.begin(), cards.end(), greater<card>());
        if (check_rule(cards) && discard_cards(cards)) {
            pair1 = make_pair(cards, 2);
            break;
        }
        cout << "出牌非法，请重试。" << endl;
    }
}

bool client::has_card() {
    return !my_card.empty();
}

#include "card.h"
#include "vector"
#include "algorithm"
#include "cards.h"

using namespace std;

struct cards::cmp {
    bool operator()(const card &c1, const card &c2) {
        return c1 < c2;
    }
};

cards::cards() {
    for (int i = 0; i < 4; i++) {
        crds.emplace_back("3");
        crds.emplace_back("4");
        crds.emplace_back("5");
        crds.emplace_back("6");
        crds.emplace_back("7");
        crds.emplace_back("8");
        crds.emplace_back("9");
        crds.emplace_back("10");
        crds.emplace_back("J");
        crds.emplace_back("K");
        crds.emplace_back("Q");
        crds.emplace_back("A");
        crds.emplace_back("2");
    }
    crds.emplace_back("j2");
    crds.emplace_back("j1");
    sort(crds.begin(), crds.end(), cmp());
}

vector<card> &cards::get_cards() {
    return crds;
}

cards &cards::operator=(cards &&c1) noexcept {
    crds.swap(c1.crds);
    return *this;
}


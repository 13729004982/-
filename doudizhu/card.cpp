#include <utility>
#include "card.h"
#include "string"

using namespace std;

card::card(std::string val): value(std::move(val)) {
    if (value == "j1")
        ranking = 15;
    else if (value == "j2")
        ranking = 14;
    else if (value == "2")
        ranking = 13;
    else if (value == "A")
        ranking = 12;
    else if (value == "K")
        ranking = 11;
    else if (value == "Q")
        ranking = 10;
    else if (value == "J")
        ranking = 9;
    else if (value == "10")
        ranking = 8;
    else
        ranking = value[0] - '3' + 1;
}

bool card::operator==(const card &cd) const {
    return ranking == cd.ranking;
}

bool card::operator<(const card &cd) const {
    return ranking < cd.ranking;
}

bool card::operator>(const card &cd) const {
    return ranking > cd.ranking;
}

bool card::operator!=(const card &cd) const {
    return ranking != cd.ranking;
}

int card::operator+(const int a) const {
    return ranking + a;
}

int card::operator-(const int a) const {
    return ranking - a;
}
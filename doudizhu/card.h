#ifndef DOUDIZHU_CARD_H
#define DOUDIZHU_CARD_H

#include "string"
#include "iostream"

using namespace std;

class card {
public:
    string value;
    int ranking;
public:
    explicit card(string val);

    bool operator==(const card &cd) const;

    bool operator<(const card &cd) const;

    bool operator>(const card &cd) const;

    bool operator!=(const card &cd) const;

    int operator+(const int a) const;

    int operator-(const int a) const;

    friend ostream & operator<<(ostream& output,card& cd){
        output<<cd.value;
        return output;
    }
};

#endif //DOUDIZHU_CARD_H

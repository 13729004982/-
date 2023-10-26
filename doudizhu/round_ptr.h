#ifndef DOUDIZHU_ROUND_PTR_H
#define DOUDIZHU_ROUND_PTR_H
#include "client_box.h"
class round_ptr {
private:
    friend class table;

    client_box *cur;

    round_ptr();


    void to_next() ;

    client &get_client();

    round_ptr &operator=(client_box *ptr);

    client &operator*();

};
#endif //DOUDIZHU_ROUND_PTR_H

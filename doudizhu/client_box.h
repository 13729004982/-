#ifndef DOUDIZHU_CLIENT_BOX_H
#define DOUDIZHU_CLIENT_BOX_H
#include "client.h"
class client_box {
private:
    client_box *next;
    client cl;

    friend class round_ptr;

public:
    explicit client_box(client &&client1);


    client_box &point_to(client_box &clientBox);
};
#endif //DOUDIZHU_CLIENT_BOX_H

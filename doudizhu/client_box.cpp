#include "client_box.h"

client_box::client_box(client
                       &&client1) : next(nullptr),

                                    cl(std::move(client1)) {

}


client_box &client_box::point_to(client_box &clientBox) {
    next = &clientBox;
    return clientBox;
}

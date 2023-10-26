cmake_minimum_required(VERSION 3.26)
project(doudizhu)

set(CMAKE_CXX_STANDARD 17)

add_executable(doudizhu
        table.cpp
        card.cpp
        client.cpp
        rule.cpp
        cards.cpp
        card.h
        rule.h
        client.h
        cards.h
        table.h
        client_box.h
        round_ptr.h
        client_box.cpp
        round_ptr.cpp
)

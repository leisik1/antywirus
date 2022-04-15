cmake_minimum_required(VERSION 3.16.3)
project(antywirus C)

set(CMAKE_C_STANDARD 99)

add_executable(antywirus
        file_operator.c
        file_operator.h
        database_operator.c
        database_operator.h
        compare.c
        compare.h
        hasher.c
        hasher.h
        quarantine_cipher.c
        quarantine_cipher.h
        main.c
        )



find_package(OpenSSL REQUIRED)
target_link_libraries(antywirus OpenSSL::SSL)
target_link_libraries(antywirus OpenSSL::Crypto)
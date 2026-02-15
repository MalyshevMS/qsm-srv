#pragma once

#include <string_view>
#include <cstdint>

namespace qsmfs {
    void post(std::string_view username, std::string_view path, uint8_t* block);
}

#ifndef QSM_POST
#   define QSM_POST qsmfs::post
#endif
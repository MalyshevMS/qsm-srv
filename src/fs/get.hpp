#pragma once

#include <stdint.h>
#include <string_view>

namespace qsmfs {
    uint8_t* get(std::string_view username, std::string_view path);
}

#ifndef QSM_GET
#   define QSM_GET qsmfs::get
#endif
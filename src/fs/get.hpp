#pragma once

#include <stdint.h>
#include <string_view>
#include <unordered_map>

namespace qsmfs {
    uint8_t* get(std::string_view path, uint16_t size);
}
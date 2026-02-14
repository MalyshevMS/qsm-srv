#pragma once

#include <openssl/sha.h>
#include <string>
#include <string_view>
#include <sstream>
#include <iomanip>

std::string sha256(std::string_view input);
std::string sha512(std::string_view input);
#include "ssl.hpp"

std::string sha256(std::string_view input) {
    uint8_t hash[SHA256_DIGEST_LENGTH];

    SHA256(reinterpret_cast<const uint8_t*>(input.data()), input.size(), hash);

    std::ostringstream oss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        oss << std::hex \
            << std::setw(2) \
            << std::setfill('0') \
            << static_cast<int>(hash[i]);
    }

    return oss.str();
}

std::string sha512(std::string_view input) {
    uint8_t hash[SHA512_DIGEST_LENGTH];

    SHA512(reinterpret_cast<const uint8_t*>(input.data()), input.size(), hash);

    std::ostringstream oss;

    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        oss << std::hex \
            << std::setw(2) \
            << std::setfill('0') \
            << static_cast<int>(hash[i]);
    }

    return oss.str();
}
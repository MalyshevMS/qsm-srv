#include "post.hpp"
#include "../config.txx"
#include "../db/db.hpp"
#include "../ssl/ssl.hpp"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void write_bytes(fs::path path, const uint8_t* data, std::size_t size, std::size_t offset) {
    std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);

    if (path.has_parent_path()) {
        fs::create_directories(path.parent_path());
    }

    if (!file.is_open()) { // Create if not exists
        file.open(path, std::ios::out | std::ios::binary);
        file.close();
        file.open(path, std::ios::in | std::ios::out | std::ios::binary);
    }

    file.seekp(offset, std::ios::beg);

    file.write(reinterpret_cast<const char*>(data), size);

    file.close();
}

void qsmfs::post(std::string_view username, std::string_view path, uint8_t *block) {
    auto hash = sha256(std::string(reinterpret_cast<const char*>(block), QSM_BLOCK_SIZE));

    write_bytes(
        "storage" / fs::path(username) / hash.substr(0, 2) / hash.substr(2, 2) / (hash.substr(4) + ".bin"),
        block, QSM_BLOCK_SIZE,
        0_MB // TODO: Get this from DB
    );
}
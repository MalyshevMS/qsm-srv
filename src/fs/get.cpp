#include "get.hpp"
#include "../config.txx"
#include "../db/db.hpp"
#include "../ssl/ssl.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

uint8_t* read_bytes(fs::path path, std::size_t size, std::size_t offset, std::size_t& out_size) {
    out_size = 0;

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) return nullptr;

    file.seekg(0, std::ios::end);
    std::size_t file_size = file.tellg();

    if (offset >= file_size)
        return nullptr;

    std::size_t readable = file_size - offset;
    std::size_t to_read = (size > readable) ? readable : size;

    file.seekg(offset, std::ios::beg);

    uint8_t* buffer = new uint8_t[to_read];

    file.read(reinterpret_cast<char*>(buffer), to_read);

    out_size = file.gcount();

    if (out_size == 0) {
        delete[] buffer;
        return nullptr;
    }

    return buffer;
}

std::vector<std::string> split(std::string_view str, char sep = ' ') {
    std::vector<std::string> result;
    std::string current;
    bool opened_quot = false;  // ' (single quot)
    bool opened_quot2 = false; // " (double quot)

    for (char c : str) {
        if (c == sep && !opened_quot && !opened_quot2) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else if (c == '\'' && !opened_quot2) {
            opened_quot = !opened_quot;
        } else if (c == '\"' && !opened_quot) {
            opened_quot2 = !opened_quot2;
        } else {
            current += c;
        }
    }

    if (!current.empty()) {
        result.push_back(current);
    }

    return result;
}

uint8_t* qsmfs::get(std::string_view username, std::string_view path) {
    auto res = new uint8_t[QSM_1MB];

    auto parsed_path = split(path, '/');
    auto filename = parsed_path[parsed_path.size() - 1];
    auto hashname = sha512(filename);
    fs::path dirpath;

    for (int i = 0; i < parsed_path.size() - 1; i++) dirpath += parsed_path[i];

    std::size_t fsize = 0;
    auto file = read_bytes("storage" / fs::path(username) / dirpath / hashname.substr(0, 2) / hashname.substr(2, 2) / hashname.substr(4), QSM_1MB, 0, fsize);

    for (int i = 0; i < fsize; i++)  res[i] = file[i];

    return res;
}
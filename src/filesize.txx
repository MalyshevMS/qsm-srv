#pragma once

constexpr unsigned long long operator""_KB(const unsigned long long amount) {
    return amount << 10;
}

constexpr unsigned long long operator""_MB(const unsigned long long amount) {
    return amount << 20;
}

constexpr unsigned long long operator""_GB(const unsigned long long amount) {
    return amount << 30;
}
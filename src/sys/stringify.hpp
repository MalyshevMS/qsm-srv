#pragma once

#include <string>
#include <sstream>

template <class _Tp>
std::string stringify(_Tp&& value) {
    std::ostringstream oss;
    oss << std::forward<_Tp>(value);
    return oss.str();
}
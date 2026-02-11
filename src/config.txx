#pragma once

#include <memory>

template <class _Tp>
using ptr = std::shared_ptr<_Tp>;

#define QSM_PORT                58921
#define QSM_PACKET_SIZE         4096 // bytes
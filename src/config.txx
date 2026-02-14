#pragma once

#include <memory>

template <class _Tp>
using ptr = std::shared_ptr<_Tp>;

#define QSM_PORT                58921
#define QSM_1MB                 (1 << 20)
#define QSM_PACKET_SIZE         (QSM_1MB + (1 << 5)) // bytes (1MB + 32B)
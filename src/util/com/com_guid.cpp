#include "com_guid.h"

#include "../../d3d11/d3d11_interfaces.h"

#include "../../dxgi/dxgi_interfaces.h"

const GUID IDXGIVkAdapter::guid         = {0x907bf281,0xea3c,0x43b4,{0xa8,0xe4,0x9f,0x23,0x11,0x07,0xb4,0xff}};
const GUID IDXGIVkDevice::guid          = {0x7a622cf6,0x627a,0x46b2,{0xb5,0x2f,0x36,0x0e,0xf3,0xda,0x83,0x1c}};
const GUID IDXGIVkBackBuffer::guid      = {0x5679becd,0x8547,0x4d93,{0x96,0xa1,0xe6,0x1a,0x1c,0xe7,0xef,0x37}};
const GUID IDXGIVkPresentDevice::guid   = {0x79352328,0x16f2,0x4f81,{0x97,0x46,0x9c,0x2e,0x2c,0xcd,0x43,0xcf}};
const GUID IDXGIVkInteropDevice::guid   = {0xe2ef5fa5,0xdc21,0x4af7,{0x90,0xc4,0xf6,0x7e,0xf6,0xa0,0x93,0x23}};
const GUID IDXGIVkInteropSurface::guid  = {0x5546cf8c,0x77e7,0x4341,{0xb0,0x5d,0x8d,0x4d,0x50,0x00,0xe7,0x7d}};
const GUID IDXGIVkSwapChain::guid       = {0x104001a6,0x7f36,0x4957,{0xb9,0x32,0x86,0xad,0xe9,0x56,0x7d,0x91}};

std::ostream& operator << (std::ostream& os, REFIID guid) {
  os << std::hex << std::setfill('0')
     << std::setw(8) << guid.Data1 << '-';

  os << std::hex << std::setfill('0')
     << std::setw(4) << guid.Data2 << '-';

  os << std::hex << std::setfill('0')
     << std::setw(4) << guid.Data3 << '-';

  os << std::hex << std::setfill('0')
     << std::setw(2) << static_cast<short>(guid.Data4[0])
     << std::setw(2) << static_cast<short>(guid.Data4[1])
     << '-'
     << std::setw(2) << static_cast<short>(guid.Data4[2])
     << std::setw(2) << static_cast<short>(guid.Data4[3])
     << std::setw(2) << static_cast<short>(guid.Data4[4])
     << std::setw(2) << static_cast<short>(guid.Data4[5])
     << std::setw(2) << static_cast<short>(guid.Data4[6])
     << std::setw(2) << static_cast<short>(guid.Data4[7]);
  return os;
}

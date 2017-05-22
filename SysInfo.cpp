#include "SysInfo.h"

SysInfo::SysInfo(){
  meminfoPath = "/proc/meminfo";
  cpuinfoPath = "/proc/cpuinfo";
  cacheTag = "cache size";
  totalRAMTag = "MemTotal:";
  freeRAMTag = "MemAvailable:";
  totalSwapTag = "SwapTotal:";
  freeSwapTag = "SwapFree:";
}

void SysInfo::fillInfo(){
  
}

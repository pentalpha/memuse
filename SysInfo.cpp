#include "SysInfo.h"

SysInfo::SysInfo(){
  meminfoPath = "/proc/meminfo";
  cpuinfoPath = "/proc/cpuinfo";
  cacheTag = "cache size";
  totalRAMTag = "MemTotal:";
  freeRAMTag = "MemAvailable:";
  totalSwapTag = "SwapTotal:";
  freeSwapTag = "SwapFree:";

  fillInfo();
}

void SysInfo::fillInfo(){
  totalRAM = getValueFromLineWithTagRemovingTag(meminfoPath, totalRAMTag);
  freeRAM = getValueFromLineWithTagRemovingTag(meminfoPath, freeRAMTag);
  totalSwap = getValueFromLineWithTagRemovingTag(meminfoPath, totalSwapTag);
  freeSwap = getValueFromLineWithTagRemovingTag(meminfoPath, freeSwapTag);
  cacheSize = getValueFromLineWithTagRemovingTag(cpuinfoPath, cacheTag);
}

void SysInfo::print(){
  cout << "##### System Memory #####" << endl;
  cout << "Total Mem.:\t" << totalRAM << endl;
  cout << "Free Mem.:\t" << freeRAM << endl;
  cout << "Total Swap:\t" << totalSwap << endl;
  cout << "Free Swap:\t" << freeSwap << endl;
  cout << "Cache size:\t" << cacheSize << endl;
  cout << "#########################" << endl;
}

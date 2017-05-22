#ifndef _SYS_INFO_
#define _SYS_INFO_

#include <string>

using namespace std;

class SysInfo{
public:
  SysInfo();

  void fillInfo();

  int totalRAM, freeRAM;
  int totalSwap, freeSwap;
  int cacheSize;

protected:
  string meminfoPath, cpuinfoPath;
  string cacheTag, totalRAMTag, freeRAMTag, totalSwapTag, freeSwapTag;
};

#endif

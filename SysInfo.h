#ifndef _SYSINFOXX_
#define _SYSINFOXX_

#include <iostream>
#include <string>
#include "Utils.h"

using namespace std;

class SysInfo{
public:
  SysInfo();

  void fillInfo();
  void print();

  string totalRAM, freeRAM;
  string totalSwap, freeSwap;
  string cacheSize;

protected:
  string meminfoPath, cpuinfoPath;
  string cacheTag, totalRAMTag, freeRAMTag, totalSwapTag, freeSwapTag;
};

#endif

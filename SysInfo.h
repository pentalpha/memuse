#ifndef _SYS_INFO_
#define _SYS_INFO_

using namespace std;

class SysInfo{
public:
  SysInfo();

  void fillInfo();
protected:
  int totalRAM, freeRAM;
  int totalSwap, freeSwap;
  int cacheSize;
};

#endif

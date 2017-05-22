#ifndef _PROC_INFO_
#define _PROC_INFO_

#include <string>

using namespace std;

class ProcInfo{
public:
  ProcInfo(string procFolder);

  void fillInfo();
  void print();
protected:
  int memUse;
  int swapUse;
  int majorPageFaults;
  int minorPageFaults;
};

#endif

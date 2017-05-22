#ifndef _PROC_INFO_
#define _PROC_INFO_

using namespace std;

class ProcInfo{
public:
  ProcInfo(int pid);
  ProcInfo(string procFolder);

  void fillInfo();
protected:
  int memUse;
  int swapUse;
  int majorPageFaults;
  int minorPageFaults;
};

#endif

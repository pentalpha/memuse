#include <vector>
#include "Utils.h"
#include "SysInfo.h"
#include "ProcInfo.h"

int main(int argc, char const *argv[]) {
  SysInfo sysInfo;
  sysInfo.print();
  /*vector<string> procDirs = getProcDirs();
  set<ProcInfo> procInfos;
  for(string dir : procDirs){
    ProcInfo procInfo(dir);
    procInfos.add(procInfo);
  }
  for(ProcInfo info : procInfos){
    info.print();
  }*/
  return 0;
}

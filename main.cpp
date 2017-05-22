#include <vector>
#include "Utils.h"
#include "SysInfo.h"
#include "ProcInfo.h"

int main(int argc, char const *argv[]) {
  SysInfo sysInfo;
  vector<string> procDirs = getProcDirs();
  set<string> procInfos;
  for(string dir : procDirs){
    ProcInfo procInfo(dir);
    procInfos.add(procInfo);
  }
  return 0;
}

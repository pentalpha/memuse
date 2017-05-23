#include <vector>
#include <set>
#include <iostream>
#include <iomanip>
#include "Utils.h"
#include "SysInfo.h"
#include "ProcInfo.h"

using namespace std;

int main(int argc, char const *argv[]) {
  std::cout << fixed;
  std::cout << setprecision(3);

  SysInfo sysInfo;
  sysInfo.print();
  vector<string> procDirs = getProcDirs();
  vector<ProcInfo> procInfos;
  for(string dir : procDirs){
    ProcInfo procInfo(dir);
    procInfos.push_back(procInfo);
  }
  ProcInfo::printHeader();
  //ProcInfo procInfo("/proc/1");
  //procInfo.printInLine();
  for(ProcInfo info : procInfos){
    info.printInLine();
  }
  return 0;
}

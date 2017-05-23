#include "ProcInfo.h"

const long ProcInfo::pageSize = getPageSizeInKB();
const string ProcInfo::swapTag = "VmSwap";

ProcInfo::ProcInfo(string procFolder){
  dir = procFolder;
  getIntPidFromFolder(procFolder);
  definePaths();

  memUse = 0;
  majorPageFaults = 0;
  minorPageFaults = 0;

  fillInfo();
}

void ProcInfo::fillInfo(){
  //cout << "Searching for swap usage in " << statusPath << endl;
  swapUse = getValueFromLineWithTagRemovingTag(statusPath,
                                              swapTag);
  //cout << "swapUse " << swapUse << endl;
  int pages = valueXInIntegersFile(statmPath, pagsIndex);
  //cout << "pages " << pages << endl;
  int sharedPages = valueXInIntegersFile(statmPath,
    sharedPagsIndex);
  //cout << "sharedPages " << sharedPages << endl;
  memUse = (pages - sharedPages)*pageSize;

  majorPageFaults = valueXInIntegersFile(statPath,
    majorPageFaultsIndex);
  minorPageFaults = valueXInIntegersFile(statPath,
    minorPageFaultsIndex);
}

void ProcInfo::print(){
  printHeader();
  printInLine();
}

void ProcInfo::printInLine(){
  cout << pid << "\t" << ((float)memUse/1024) << "\t\t"
      << swapUse << "\t\t" << majorPageFaults << "\t\t"
      <<"\t" << minorPageFaults << endl;
}

void ProcInfo::printHeader(){
  cout << "PID\tMEMORY(MB)\tSWAP USE"
      << "\tMAJOR PG. FAULTS\tMINOR PG. FAULTS" << endl;
}

void ProcInfo::getIntPidFromFolder(string procFolder){
  string strPid = procFolder;
  strPid.erase(0,6);
  try{
    pid = stoi(strPid);
  }catch(...){
    pid = -666;
  }
}

void ProcInfo::definePaths(){
  statPath = dir + "/stat";
  statmPath = dir + "/statm";
  statusPath = dir + "/status";
}

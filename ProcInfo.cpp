#include "ProcInfo.h"

const long ProcInfo::pageSize = getPageSizeInKB();
const string ProcInfo::swapTag = "VmSwap";
const string ProcInfo::nameTag = "Name:";
const string ProcInfo::swapTag2 = "Swap:";

ProcInfo::ProcInfo(string procFolder){
  dir = procFolder;
  getIntPidFromFolder(procFolder);
  definePaths();

  memUse = 0;
  name = "no-name";
  majorPageFaults = 0;
  minorPageFaults = 0;

  fillInfo();
}

void ProcInfo::fillInfo(){
  name = getValueFromLineWithTagRemovingTag(statusPath,
                                            nameTag);
  name = fillWithSpacesIfSmallerThan(name, minNameSize);
  //cout << "Searching for swap usage in " << statusPath << endl;
  swapUse = getValueFromLineWithTagRemovingTag(statusPath,
                                              swapTag);
  if(swapUse == "none"){
    swapUse = getValueFromLineWithTagRemovingTag(smapsPath,
                                                swapTag2);
  }
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
  cout << pid << "\t" << name << "\t\t"
      << ((float)memUse/1024) << "\t\t"
      << swapUse << "\t\t"
      << majorPageFaults << "\t"
      << minorPageFaults << endl;
}

void ProcInfo::printHeader(){
  cout << "MJFLT: Major page faults;" << endl
      << "MNFLT: Minor page faults;" << endl;
  cout << "PID\tNAME\t\t\tMEMORY(MB)\tSWAP USE"
      << "\tMJFLT\tMNFLT" << endl;
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
  smapsPath = dir + "/smaps";
}

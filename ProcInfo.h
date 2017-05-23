#ifndef _PROC_INFO_
#define _PROC_INFO_

#include <string>
#include <iostream>
#include "Utils.h"

using namespace std;

class ProcInfo{
public:
  static const int pagsIndex = 2;
  static const int sharedPagsIndex = 3;
  static const int majorPageFaultsIndex = 12;
  static const int minorPageFaultsIndex = 10;
  static const long pageSize;
  static const string swapTag;

  ProcInfo(string procFolder);

  void fillInfo();
  void print();
  void printInLine();
  static void printHeader();
protected:
  int pid;
  string dir;
  int memUse;
  string swapUse;
  int majorPageFaults;
  int minorPageFaults;

  string statmPath, statusPath, statPath;

  void getIntPidFromFolder(string procFolder);
  void definePaths();
};

#endif

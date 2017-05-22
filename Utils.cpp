#include "Utils.h"

string grepLineWith(string path, string contains);

string grepValueXInSequence(string path, int x){
  auto stream = std::fstream(path);
  int i = 1;
  string temp, theValue;
  theValue = "not-found"
  while (i <= x){
    if(i == x){
      stream >> theValue;
    }else{
      stream >> temp;
    }
    i++;
  }
  return theValue;
}

vector<string> getProcDirs(){
  tinydir_dir dir;
  tinydir_open(&dir, "/proc");

  while(dir.has_next){
    tinydir_file file;
    tinydir_readfile(&dir, &file);
    if(file.is_dir){
      string fileName = file.name;
      try{
        int idFound = stoi(fileName);
        if(procs.find(idFound) == procs.end()){
          ProcInfo* info = new ProcInfo;
          info->pid = idFound;
          updateInfo(info, file.path);
          procs[idFound] = info;
        }
      }catch(...){

      }
    }
    tinydir_next(&dir);
  }

  tinydir_close(&dir);
}
}

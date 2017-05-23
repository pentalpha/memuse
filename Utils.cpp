#include "Utils.h"

string grepLineWith(string path, string contains){
  string theLine = "null";
  string tempLine;
  ifstream stream(path);
  while(getline(stream, tempLine)){
    if (tempLine.find(contains) != string::npos) {
      theLine = tempLine;
      break;
    }
  }
  return theLine;
}

int valueXInIntegersFile(string path, int x){
  string xStr = grepValueXInSequence(path, x);
  return stringToInt(xStr, false);
}

string grepValueXInSequence(string path, int x){
  ifstream valuesStream(path);
  //cout << "opening " << path << endl;
  //valuesStream.open(path);
  string temp, theValue;
  //theValue = "not-found";
  for(int i = 1; i < x; i++){
    valuesStream >> temp;
    //cout << "skiping value: " << temp << endl;
  }
  valuesStream >> theValue;
  //cout << "theValue: " << theValue << endl;
  //valuesStream.close();
  return theValue;
}

vector<string> getProcDirs(){
  vector<string> dirs;
  tinydir_dir dir;
  tinydir_open(&dir, "/proc");

  while(dir.has_next){
    tinydir_file file;
    tinydir_readfile(&dir, &file);
    if(file.is_dir){
      string fileName = file.name;
      string filePath = file.path;
      try{
        int idFound = stoi(fileName);
        dirs.push_back(filePath);
      }catch(...){

      }
    }
    tinydir_next(&dir);
  }

  tinydir_close(&dir);
  return dirs;
}

string cleanSpacesAndEtc(string s){
  char chars[] = " :()-;\t";

  for (unsigned int i = 0; i < strlen(chars); ++i)
  {
    char toErase = chars[i];
    while(true){
      int pos = s.find(toErase);
      if(pos >= 0 && pos < s.size()){
        s.erase(pos, 1);
      }else{
        break;
      }
    }
  }

  return s;
}

string removeSubstring(string s, string subs){
  //cout << "Erasing " << subs << " from " << s;
  int start_position_to_erase = s.find(subs);
  if(start_position_to_erase >= 0
    && start_position_to_erase+subs.size() < s.size()){
    s.erase(start_position_to_erase, subs.size());
  }
  //cout << ": " << s << endl;
  return s;
}

int stringToInt(string s, bool formated){
  try{
    int x = stoi(s);
  }catch(...){
    if(formated){
      cout << "[ERROR] Could not convert "
           << s << " to int;" << endl;
      return -666;
    }else{
      return stringToInt(cleanSpacesAndEtc(s), true);
    }
  }
}

string getValueFromLineWithTagRemovingTag(string path, string contains)
{
  string lineRaw = grepLineWith(path, contains);
  string value = cleanSpacesAndEtc(removeSubstring(lineRaw, contains));
  return value;
}

int getPageSizeInKB(){
  return (sysconf(_SC_PAGE_SIZE)/1024);
}

#ifndef _MEMUSE_UTILS_
#define _MEMUSE_UTILS_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include "tinydir.h"

using namespace std;

string grepLineWith(string path, string contains);
string grepValueXInSequence(string path, int x);
vector<string> getProcDirs();
string cleanSpacesAndEtc(string s);
int stringToInt(string s);
string removeSubstring(string s, string subs);
string getValueFromLineWithTagRemovingTag(string path, string contains);

#endif

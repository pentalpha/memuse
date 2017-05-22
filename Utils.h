#ifndef _MEMUSE_UTILS_
#define _MEMUSE_UTILS_

#include <string>
#include <vector>

using namespace std;

string grepLineWith(string path, string contains);
string grepValueXInSequence(string path, int x);
vector<string> getProcDirs();

#endif

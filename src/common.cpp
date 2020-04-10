//
//  common.cpp
//  nier
//
//  Created by Junho on 2020/04/08.
//
#include <nier/common.h>

NIER_NAMESPACE_BEGIN

void split(const std::string& str, std::vector<std::string>* v) {
  std::stringstream ss(str);
  ss >> std::noskipws;
  std::string field;
  char ws_delim;
  while(1) {
    if( ss >> field )
      v->push_back(field);
    else if (ss.eof())
      break;
    else
      v->push_back(std::string());
    ss.clear();
    ss >> ws_delim;
  }
}

NIER_NAMESPACE_END

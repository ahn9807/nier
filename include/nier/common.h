//
//  common.h
//  nier
//
//  Created by Junho on 2020/04/08.
//

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <tinyxml2.h>
#include <string>
#include <iterator>
#include <sstream>
#include <set>

#define NIER_NAMESPACE_BEGIN namespace nier {
#define NIER_NAMESPACE_END }

#define EMPTY "empty"


NIER_NAMESPACE_BEGIN

void split(const std::string& str, std::vector<std::string>* v);

NIER_NAMESPACE_END

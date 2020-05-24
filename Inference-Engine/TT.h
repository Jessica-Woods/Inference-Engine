#pragma once

#include <string>
#include <vector>

#include "KnowledgeBase.h"

class TT {
private:
  KnowledgeBase kb;
public:
  TT(KnowledgeBase kb);

  // if we return a empty vector from here it means 
  // we did not find a solution 
  std::vector<std::string> entails(std::string query);
};

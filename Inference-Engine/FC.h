#pragma once

#include <string>
#include <vector>

#include "KnowledgeBase.h"

class FC {
private:
  KnowledgeBase kb;
public:
  FC(KnowledgeBase kb);

  // if we return a empty vector from here it means 
  // we did not find a solution 
  std::vector<std::string> entails(std::string query);
};

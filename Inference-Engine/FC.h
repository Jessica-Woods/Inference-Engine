#pragma once

#include <string>
#include <vector>

#include "KnowledgeBase.h"

class FC {
private:
  KnowledgeBase kb;
public:
  FC(KnowledgeBase kb);
  std::string entails(std::string query);
};

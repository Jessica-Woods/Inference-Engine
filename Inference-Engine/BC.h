#pragma once

#include <string>
#include <vector>
#include <optional>


#include "KnowledgeBase.h"

class BC {
private:
  KnowledgeBase kb;
public:
  BC(KnowledgeBase kb);

  // if we return a empty vector from here it means 
  // we did not find a solution 
  std::optional<std::vector<std::string>> entails(std::string query);

  std::optional<std::vector<std::string>> orSearch(std::string goal, std::vector<std::string> path);
  std::optional<std::vector<std::string>> andSearch(std::vector<std::string> goals, std::vector<std::string> path);

};

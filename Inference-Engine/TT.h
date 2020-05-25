#pragma once

#include <string>
#include <vector>
#include <optional>

#include "KnowledgeBase.h"

class TT {
private:
  KnowledgeBase kb;
public:
  TT(KnowledgeBase kb);

  std::optional<int> entails(std::string query);
  std::optional<int> checkAll(std::string query, std::set<std::string> symbols, std::map<std::string, bool> model);
};

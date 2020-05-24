#pragma once
#include <vector>
#include <string>
#include <queue>

#include "Clause.h"

class KnowledgeBase {
private:
  std::vector<Clause> clauses;

public:
  KnowledgeBase(std::vector<Clause> clauses);
  std::queue<std::string> createAgenda();
  std::vector<Clause> getClauses(std::string premise);
};

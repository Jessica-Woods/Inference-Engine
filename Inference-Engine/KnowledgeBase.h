#pragma once
#include <vector>
#include <string>
#include <set>

#include "Clause.h"

class KnowledgeBase {
private:
  std::vector<Clause> clauses;

public:
  KnowledgeBase(std::vector<Clause> clauses);
  std::set<std::string> getSymbols();
  const std::vector<Clause>& getClauses();
  std::vector<Clause> getClausesWithPremise(std::string premise);
};

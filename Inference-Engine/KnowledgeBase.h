#pragma once
#include <vector>
#include <string>
#include <set>
#include <map>

#include "Clause.h"

class KnowledgeBase {
private:
  std::vector<Clause> clauses;

public:
  KnowledgeBase(std::vector<Clause> clauses);

  // Return true if this symbol is true with no premise
  bool isTrue(std::string symbol);

  std::set<std::string> getSymbols();
  const std::vector<Clause>& getClauses();
  std::vector<Clause> getClausesWithPremise(std::string premise);
  std::vector<Clause> getClausesWithConclusion(std::string conclusion);

  bool runModel(const std::map<std::string, bool>& model);
};

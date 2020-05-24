#include "KnowledgeBase.h"


KnowledgeBase::KnowledgeBase(std::vector<Clause> clauses) {
  this->clauses = clauses;
}

std::set<std::string> KnowledgeBase::getSymbols() {
  std::set<std::string> symbols;
  for (auto clause : clauses) {
    symbols.insert(clause.getPremise().begin(), clause.getPremise().end());
    symbols.insert(clause.getConclusion());
  }

  return symbols;
}

const std::vector<Clause>& KnowledgeBase::getClauses() {
  return clauses;
}

std::vector<Clause> KnowledgeBase::getClausesWithPremise(std::string symbol) {
  std::vector<Clause> result;
  for (auto clause : clauses) {
    if (clause.premiseContains(symbol)) {
        result.push_back(clause);
    }
  }

  return result;
}



#include "KnowledgeBase.h"


KnowledgeBase::KnowledgeBase(std::vector<Clause> clauses) {
  this->clauses = clauses;
}

bool KnowledgeBase::isTrue(std::string symbol) {
  for (auto clause : clauses) {
    if (clause.getConclusion() == symbol && clause.premiseEmpty()) {
      return true;
    }
  }

  return false;
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

std::vector<Clause> KnowledgeBase::getClausesWithConclusion(std::string symbol) {
  std::vector<Clause> result;
  for (auto clause : clauses) {
    if (clause.getConclusion() == symbol) {
      result.push_back(clause);
    }
  }

  return result;
}

bool KnowledgeBase::runModel(const std::map<std::string, bool>& model) {
  for ( auto clause : clauses ) {
    if ( clause.premiseEmpty() ) {
      if ( model.at(clause.getConclusion()) == false ) { return false; }
    } else {
      bool premiseValue = true;
      for (auto p : clause.getPremise()) {
        premiseValue = premiseValue && model.at(p);
      }
      if (premiseValue && !model.at(clause.getConclusion())) {
        return false;
      }
    }
  }

  return true;
}

#include "KnowledgeBase.h"


KnowledgeBase::KnowledgeBase(std::vector<Clause> clauses) {
  this->clauses = clauses;
}

std::queue<std::string> KnowledgeBase::createAgenda() {
  std::queue<std::string> agenda;
  for (auto clause : clauses) {
    // If the premise vector is empty we add the conclusion to the agenda
    if (clause.premiseEmpty()) {
      agenda.push(clause.getConclusion());
    }
  }

  return agenda;
}

std::vector<Clause> KnowledgeBase::getClauses(std::string symbol) {
  std::vector<Clause> result;
  for (auto clause : clauses) {
    if (clause.premiseContains(symbol)) {
        result.push_back(clause);
    }
  }

  return result;
}



#include "Clause.h"

Clause::Clause(std::vector<std::string> premise, std::string conclusion) {
  this->premise = premise;
  this->conclusion = conclusion;
}

bool Clause::premiseEmpty() {
  for (auto p : premise) {
    if (p.empty()) {
      return true;
    }
  }

  return false;
}

bool Clause::premiseContains(std::string symbol) {
  for (auto p : premise) {
    if ( p == symbol ) {
      return true;
    }
  }

  return false;
}

std::string Clause::getConclusion() {
  return conclusion;
}

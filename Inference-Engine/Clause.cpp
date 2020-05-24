#include "Clause.h"

#include <tuple>

Clause::Clause(std::vector<std::string> premise, std::string conclusion) {
  this->premise = premise;
  this->conclusion = conclusion;
}

bool Clause::premiseEmpty() {
  return premise.empty();
}

bool Clause::premiseContains(std::string symbol) {
  for (auto p : premise) {
    if ( p == symbol ) {
      return true;
    }
  }

  return false;
}

const std::vector<std::string>& Clause::getPremise() { return premise; }
std::string Clause::getConclusion() { return conclusion; }

bool operator<(const Clause& lhs, const Clause& rhs) {
  return std::tie(lhs.premise, lhs.conclusion) < std::tie(rhs.premise, rhs.conclusion);
}

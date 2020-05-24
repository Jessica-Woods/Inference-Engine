#include "BC.h"

#include <map>
#include <stack>
#include <algorithm>

#include "KnowledgeBase.h"
#include "Clause.h"


BC::BC(KnowledgeBase knowledgeBase) : kb(knowledgeBase) {}

std::optional<std::vector<std::string>> BC::entails(std::string query) {
  auto result = orSearch(query, {});
  if (result) {
    std::reverse(result->begin(), result->end());
  }

  return result;
}

std::optional<std::vector<std::string>> BC::orSearch(std::string goal, std::vector<std::string> path) {
  if(kb.isTrue(goal)) { return std::vector<std::string> { goal }; }
  if(std::find(path.begin(), path.end(), goal) != path.end()) { return std::nullopt; }

  for (auto clause : kb.getClausesWithConclusion(goal)) {
    path.push_back(goal);
    auto plan = andSearch(clause.getPremise(), path);
    if (plan) {
      plan->insert(plan->begin(), goal);
      return plan;
    }
  }

  return std::nullopt;
}

std::optional<std::vector<std::string>> BC::andSearch(std::vector<std::string> goals, std::vector<std::string> path) {
  std::vector<std::string> result;
  for (auto goal : goals) {
    auto plan = orSearch(goal, path);
    if(plan) { 
      result.insert(result.end(), plan->begin(), plan->end());
    } else {
      return std::nullopt;
    }
  }

  return result;
}
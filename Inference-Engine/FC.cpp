#include "FC.h"

#include <map>
#include <queue>

#include "KnowledgeBase.h"
#include "Clause.h"


FC::FC(KnowledgeBase knowledgeBase) : kb(knowledgeBase) {}

std::vector<std::string> FC::entails(std::string query) {
  std::vector<std::string> result;

  std::map<Clause, int> count;
  for (auto clause : kb.getClauses()) {
    count[clause] = clause.getPremise().size();
  }

  std::map<std::string, bool> inferred;
  for (auto symbol : kb.getSymbols()) {
    inferred[symbol] = false;
  }

  std::queue<std::string> agenda;
  for (auto clause : kb.getClauses()) {
    if (clause.premiseEmpty()) {
      agenda.push(clause.getConclusion());
    }
  }

  while (!agenda.empty()) {
    auto p = agenda.front();
    agenda.pop();
    result.push_back(p);

    if (p == query) {
      return result;
    }
  
    if (inferred[p] == false) {
      inferred[p] = true;
      for (auto clause : kb.getClausesWithPremise(p)) {
        count[clause] -= 1;
        if (count[clause] == 0) {
          agenda.push(clause.getConclusion());
        }
      }
    }
  }

  // We return an empty vector when we haven't found a solution.
  return std::vector<std::string>{};
}

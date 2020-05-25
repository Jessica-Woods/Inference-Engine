#include "TT.h"
#include <map>

TT::TT(KnowledgeBase knowledgeBase) : kb(knowledgeBase) {}

std::optional<int> TT::entails(std::string q) {
  auto query = q;
  auto symbols = kb.getSymbols();
  std::map<std::string, bool> model;
  
  return checkAll(q, symbols, model);
}

std::optional<int> TT::checkAll(std::string query, std::set<std::string> symbols, std::map<std::string, bool> model) {
  if (symbols.empty()) {
    if (kb.runModel(model)) {
      if (model[query]) {
        // This model matches our knowledge base and does contain our query.
        // This means we have at least one situation where our query _is_ entailed.
        return 1;
      } else {
        // This model matches the knowledge base but doesn't contain our
        // query. This means the knowledge base _does not_ entail our query 
        return std::nullopt;
      }
    } else { 
      // This model doesn't match the knowledge base, we can safely ignore it
      return 0; 
    }
  } else {
    auto firstSymbol = *symbols.begin();
    symbols.erase(symbols.begin());

    std::map <std::string, bool> trueModel = model;
    trueModel[firstSymbol] = true;

    auto falseModel = model;
    falseModel[firstSymbol] = false;
    
    auto trueResult = checkAll(query, symbols, trueModel);
    auto falseResult = checkAll(query, symbols, falseModel);
    if (trueResult && falseResult) {
      return (*trueResult) + (*falseResult);
    } else {
      return std::nullopt;
    }
  }
}
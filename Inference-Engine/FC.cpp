#include "FC.h"
#include "KnowledgeBase.h"
#include "Clause.h"

FC::FC(KnowledgeBase knowledgeBase) : kb(knowledgeBase) {}

std::string FC::entails(std::string query) {
  return query;
}

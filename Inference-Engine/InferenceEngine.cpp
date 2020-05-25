#include "InferenceEngine.h"
#include "util/file.h"
#include "util/vector.h"

#include "KnowledgeBase.h"

#include "TT.h"
#include "FC.h"
#include "BC.h"

std::string InferenceEngine::runMethod(std::string method, std::vector<std::string>& lines) {
  //ProblemFile() class for parsing later

  KnowledgeBase knowledgeBase({
    Clause({"p2"}, "p3"),
    Clause({"p3"}, "p1"),
    Clause({"c"}, "e"),
    Clause({"b", "e"}, "f"),
    Clause({"f", "g"}, "h"),
    Clause({"p1"}, "d"),
    Clause({"p1", "p3"}, "c"),
    Clause({}, "a"),
    Clause({}, "b"),
    Clause({}, "p2"),
  });

  std::string query = "d";

  // Truth Table Checking Algorithm
  if (method == "TT") { 
    auto result = TT(knowledgeBase).entails(query);
    if (result) {
      return "YES: " + std::to_string(*result);
    }
    else {
      return "NO:";
    }
  }
  // Forward Chaining Algorithm
  else if (method == "FC") {
    auto result = FC(knowledgeBase).entails(query);
    if (result) {
      return "YES: " + util::vector::unsplit(*result, ", ");
    } else {
      return "NO:";
    }
  }

  // Backward Chaining Algorithm
  else if (method == "BC") {
    auto result = BC(knowledgeBase).entails(query);
    if (result) {
      return "YES: " + util::vector::unsplit(*result, ", ");
    } else {
      return "NO:";
    }
  }
  else { return "Unknown Method"; } //exception
}

std::string InferenceEngine::runFromFile(std::string filepath, std::string method) {
  std::vector<std::string> lines = util::file::readCleanLines(filepath);
  return run(filepath, lines, method);
}

std::string InferenceEngine::run(std::string filename, std::vector<std::string> lines, std::string method) {
  std::string result = runMethod(method, lines);
  // clean output
  return result;
}
#include "InferenceEngine.h"

#include "util/file.h"

std::string InferenceEngine::runMethod(std::string method, std::vector<std::string>& lines) {
  // Truth Table Checking Algorithm
  if (method == "TT") { return "Truth Table Algorithm"; }
  // Forward Chaining Algorithm
  else if (method == "FC") { return ""; }
  // Backward Chaining Algorithm
  else if (method == "BC") { return ""; }
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

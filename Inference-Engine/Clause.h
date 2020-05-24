#pragma once
#include <string>
#include <vector>

class Clause {
private:
  //lhs of a clause
  std::vector<std::string> premise;

  //rhs of a clause
  std::string conclusion; 

public:
  Clause(std::vector<std::string> premise, std::string conclusion);

  bool premiseEmpty();
  bool premiseContains(std::string premise);

  std::string getConclusion();
};

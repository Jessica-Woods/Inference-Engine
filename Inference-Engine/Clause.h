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

  const std::vector<std::string>& getPremise();
  std::string getConclusion();

  friend bool operator<(const Clause& lhs, const Clause& rhs);
};

bool operator<(const Clause& lhs, const Clause& rhs);
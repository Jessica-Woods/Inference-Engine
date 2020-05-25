#pragma once

#include <string>
#include <vector>

#include "Clause.h"

class ProblemFile {
private:
  std::vector<std::string> lines;

  std::vector<Clause> clauses;
  std::string query;

public:
  ProblemFile(std::vector <std::string> lines);

  std::vector<Clause> getClauses();
  std::string getQuery();
};


#include "ProblemFile.h"

#include "util/string.h"
#include "util/vector.h"

ProblemFile::ProblemFile(std::vector <std::string> lines) {
  this->lines = lines;
  
  auto tell = std::find(lines.begin(), lines.end(), "TELL");
  auto ask = std::find(lines.begin(), lines.end(), "ASK");

  query = *(ask + 1);

  for (auto line = tell + 1; line < ask; ++line) {
    std::vector<std::string> clauseStrings = util::string::split(*line, ';');
    
    for (auto cs : clauseStrings) {
      util::string::strip_whitespace(cs);
      auto split = util::string::split_first(cs, "=>");
      auto lhs = std::get<0>(split);
      auto rhs = std::get<1>(split);
      if (rhs == "") { // Single value clause (i.e. "a")
        clauses.push_back(Clause({}, lhs));
      } else { // Implication (i.e. "a & b => c"
        
        clauses.push_back(Clause(
          util::string::split(lhs, '&'), rhs));
      }
    }
  }
}

std::vector<Clause> ProblemFile::getClauses() { return clauses; }

std::string ProblemFile::getQuery() { return query; }
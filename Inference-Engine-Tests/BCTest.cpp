#include "gtest/gtest.h"

#include "../Inference-Engine/BC.h"

TEST(BC, TestExample) {
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

  auto result = BC(knowledgeBase).entails("d");
  std::vector<std::string> expected = { "p2","p3","p1","d" };

  EXPECT_EQ(*result, expected);
}


TEST(BC, TestWhereAnswerIsNo) {
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

  auto result = BC(knowledgeBase).entails("v");

  EXPECT_EQ(result, std::nullopt);
}

TEST(BC, TestImplicationLoop) {
  KnowledgeBase knowledgeBase({
    Clause({"a"}, "b"),
    Clause({"b"}, "a"),
    Clause({}, "a")
    });

  auto result = BC(knowledgeBase).entails("b");
  std::vector<std::string> expected = { "a","b" };

  EXPECT_EQ(*result, expected);
}

TEST(BC, TestSingleKnownTruth) {
  KnowledgeBase knowledgeBase({
    Clause({}, "a")
    });

  auto result = BC(knowledgeBase).entails("a");
  std::vector<std::string> expected = { "a" };

  EXPECT_EQ(*result, expected);
}

TEST(BC, TestSingleImplication) {
  KnowledgeBase knowledgeBase({
    Clause({"a"}, "b")
    });

  auto result = BC(knowledgeBase).entails("a");

  EXPECT_EQ(result, std::nullopt);
}

TEST(BC, TestNoResultFound) {
  KnowledgeBase knowledgeBase({
    Clause({}, "a")
    });

  auto result = BC(knowledgeBase).entails("b");

  EXPECT_EQ(result, std::nullopt);
}
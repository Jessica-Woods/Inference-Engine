#include "gtest/gtest.h"

#include "../Inference-Engine/FC.h"

TEST(FC, TestExample) {
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

  auto result = FC(knowledgeBase).entails("d");
  std::vector<std::string> expected = { "a","b","p2","p3","p1","d" };

  EXPECT_EQ(*result, expected);
}


TEST(FC, TestWhereAnswerIsNo) {
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

  auto result = FC(knowledgeBase).entails("v");

  EXPECT_EQ(result, std::nullopt);
}

TEST(FC, TestImplicationLoop) {
  KnowledgeBase knowledgeBase({
    Clause({"a"}, "b"),
    Clause({"b"}, "a"),
    Clause({}, "a")
    });

  auto result = FC(knowledgeBase).entails("b");
  std::vector<std::string> expected = { "a","b" };

  EXPECT_EQ(*result, expected);
}

TEST(FC, TestSingleKnownTruth) {
  KnowledgeBase knowledgeBase({
    Clause({}, "a")
    });

  auto result = FC(knowledgeBase).entails("a");
  std::vector<std::string> expected = { "a" };

  EXPECT_EQ(*result, expected);
}

TEST(FC, TestSingleImplication) {
  KnowledgeBase knowledgeBase({
    Clause({"a"}, "b")
    });

  auto result = FC(knowledgeBase).entails("a");

  EXPECT_EQ(result, std::nullopt);
}

TEST(FC, TestNoResultFound) {
  KnowledgeBase knowledgeBase({
    Clause({}, "a")
    });

  auto result = FC(knowledgeBase).entails("b");

  EXPECT_EQ(result, std::nullopt);
}
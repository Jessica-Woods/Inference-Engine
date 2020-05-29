#include "gtest/gtest.h"

#include "../Inference-Engine/TT.h"

TEST(TT, TestExample) {
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

  auto result = TT(knowledgeBase).entails("a");

  EXPECT_EQ(*result, 3);
}
TEST(TT, TestWhereAnswerIsNo) {
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

  auto result = TT(knowledgeBase).entails("v");

  EXPECT_EQ(result, std::nullopt);
}

TEST(TT, TestImplicationLoop) {
  KnowledgeBase knowledgeBase({
    Clause({"a"}, "b"),
    Clause({"b"}, "a"),
    Clause({}, "a")
  });

  auto result = TT(knowledgeBase).entails("b");

  EXPECT_EQ(*result, 1);
}

TEST(TT, TestSingleKnownTruth) {
  KnowledgeBase knowledgeBase({
    Clause({}, "a")
  });

  auto result = TT(knowledgeBase).entails("a");

  EXPECT_EQ(*result, 1);
}

TEST(TT, TestSingleImplication) {
  KnowledgeBase knowledgeBase({
    Clause({"a"}, "b")
  });

  auto result = TT(knowledgeBase).entails("a");

  EXPECT_EQ(result, std::nullopt);
}

TEST(TT, TestNoResultFound) {
  KnowledgeBase knowledgeBase({
    Clause({}, "a")
  });

  auto result = TT(knowledgeBase).entails("b");

  EXPECT_EQ(result, std::nullopt);
}
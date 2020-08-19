#ifndef TST_BASEFIGURE_H
#define TST_BASEFIGURE_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "BaseFigure.h"

using namespace testing;
using namespace Geometry;
using namespace std;

TEST(BaseFigureTests, BaseFigureName) {
  BaseFigure bf("somename", POINT);

  bf.setName("somename2");

  EXPECT_EQ(bf.getName()->compare("somename2"), 0);
  EXPECT_NE(bf.getName()->compare("new name"), 0);
}

TEST(BaseFigureTests, BaseFigureDelNameByPropertry) {
  BaseFigure bf;

  bf.setName("somename");
  bf.delProperty("name");

  EXPECT_EQ(bf.getName(), nullptr);
}

TEST(BaseFigureTests, BaseFigureSetNameByPropertry) {
  BaseFigure bf;

  bf.addProperty("NAmE", "somename");

  EXPECT_EQ(bf.getName()->compare("somename"), 0);
}

TEST(BaseFigureTests, BaseFigureAddPropertries) {
  BaseFigure bf;

  bf.addProperty("noTE1", "soMENote1");
  bf.addProperty("NOTE2", "SOmenote2");

  EXPECT_EQ(bf.getProperty("noTE1")->compare("somenote1"), 0);
  EXPECT_EQ(bf.getProperty("NOTE2")->compare("somenote2"), 0);
  EXPECT_EQ(bf.getProperty("note3"), nullptr);
}

TEST(BaseFigureTests, SetNullPropetry) {
  BaseFigure bf;

  bf.addProperty("noTE1", "soMENote1");
  bf.addProperty("NOTE2", "SOmenote2");

  bf.setNullProperty("NoTE1");
  bf.setNullProperty("note2");

  EXPECT_EQ(bf.getProperty("noTE1"), nullptr);
  EXPECT_EQ(bf.getProperty("NOTE2"), nullptr);
}

TEST(BaseFigureTests, BaseFigureAddEmptyPropertries) {
  BaseFigure bf;

  bf.addProperty("", "");
  bf.addProperty("", "");

  EXPECT_EQ(bf.getProperty("")->compare(""), 0);
}

TEST(BaseFigureTests, BaseFigureDelPropertries) {
  BaseFigure bf;

  bf.addProperty("note1", "somenote1");
  bf.addProperty("note2", "somenote2");
  bf.addProperty("note3", "somenote3");
  bf.addProperty("note4", "somenote4");
  bf.addProperty("note5", "somenote5");

  bf.delProperty("note2");
  bf.delProperty("note5");
  bf.delProperty("note3");

  EXPECT_EQ(bf.getProperty("note1")->compare("somenote1"), 0);
  EXPECT_EQ(bf.getProperty("note4")->compare("somenote4"), 0);
  EXPECT_EQ(bf.getProperty("note2"), nullptr);
}

TEST(BaseFigureTests, BaseFigureGetPropertryByEmptyObj) {
  BaseFigure bf;

  EXPECT_EQ(bf.getProperty("prop"), nullptr);
}

TEST(BaseFigureTests, BaseFigureDefaultConstructor) {
  BaseFigure bf;

  EXPECT_EQ(bf.getName(), nullptr);
  EXPECT_EQ(bf.getType(), UNKNOWN);
}

TEST(BaseFigureTests, BaseFigureInitWithType) {
  BaseFigure bf(LINE_STR);

  EXPECT_EQ(bf.getType(), LINE_STR);
}

TEST(BaseFigureTests, BaseFigureInitWithStr) {
  string name = "new name";

  BaseFigure bf(name);

  EXPECT_EQ(bf.getName()->compare("new name"), 0);
  EXPECT_EQ(bf.getType(), UNKNOWN);
}

TEST(BaseFigureTests, BaseFigureInitWhitChars) {
  char* name = new char[10];
  strcpy(name, "new name");

  BaseFigure bf(name);
  delete[] name;

  EXPECT_EQ(bf.getName()->compare("new name"), 0);
  EXPECT_EQ(bf.getType(), UNKNOWN);
}

TEST(BaseFigureTests, BaseFigureInitWithStrAndFigureType) {
  string name = "new name";

  BaseFigure bf(name, LINE_STR);

  EXPECT_EQ(bf.getName()->compare(name), 0);
  EXPECT_EQ(bf.getType(), LINE_STR);
}

TEST(BaseFigureTests, BaseFigureInitWhitCharsAndFigureType) {
  char* name = new char[10];
  strcpy(name, "new name");

  BaseFigure bf(name, POINT);
  delete[] name;

  EXPECT_EQ(bf.getName()->compare("new name"), 0);
  EXPECT_NE(bf.getName(), nullptr);
  EXPECT_EQ(bf.getType(), POINT);
}

TEST(BaseFigureTests, BaseFigureDefaultConstr) {
  BaseFigure bf;

  EXPECT_EQ(bf.getName(), nullptr);
  EXPECT_EQ(bf.getType(), UNKNOWN);
}

TEST(BaseFigureTests, BaseFigureOperator) {
  BaseFigure bf1;

  {
    BaseFigure bf2;
    bf2.addProperty("prop1", "val1");
    bf2.addProperty("prop2", "val2");
    bf2.addProperty("prop3", "val3");
    bf2.addProperty("prop1", "val123");
    bf1 = bf2;
  }

  EXPECT_EQ(bf1.getProperty("prop1")->compare("val123"), 0);
  EXPECT_EQ(bf1.getProperty("prop2")->compare("val2"), 0);
  EXPECT_EQ(bf1.getProperty("prop3")->compare("val3"), 0);
  EXPECT_EQ(bf1.getType(), UNKNOWN);
}

TEST(BaseFigureTests, BaseFigureCopyConstr1) {
  BaseFigure bf2(LINE_STR);

  bf2.addProperty("prop1", "val1");
  bf2.addProperty("prop2", "val2");
  bf2.addProperty("prop3", "val3");
  bf2.addProperty("prop1", "val123");
  BaseFigure bf1 = bf2;

  EXPECT_EQ(bf1.getProperty("prop1")->compare("val123"), 0);
  EXPECT_EQ(bf1.getProperty("prop2")->compare("val2"), 0);
  EXPECT_EQ(bf1.getProperty("prop3")->compare("val3"), 0);
  EXPECT_EQ(bf1.getType(), LINE_STR);
  EXPECT_TRUE(bf1 == bf2);
  bf2.addProperty("prop1", "val12fvge3");
  EXPECT_EQ(bf1.getProperty("prop1")->compare("val123"), 0);
  EXPECT_FALSE(bf1 == bf2);
}

TEST(BaseFigureTests, BaseFigureCopyConstr2) {
  BaseFigure bf2(LINE_STR);

  bf2.addProperty("prop1", "val1");
  bf2.addProperty("prop2", "val2");
  bf2.addProperty("prop3", "val3");
  bf2.addProperty("prop1", "val123");
  BaseFigure bf1 = bf2;

  EXPECT_EQ(bf1.getProperty("prop1")->compare("val123"), 0);
  EXPECT_EQ(bf1.getProperty("prop2")->compare("val2"), 0);
  EXPECT_EQ(bf1.getProperty("prop3")->compare("val3"), 0);
  EXPECT_EQ(bf1.getType(), LINE_STR);
  EXPECT_TRUE(bf1 == bf2);
  bf2.addProperty("prop3431", "val12fvge3");
  EXPECT_FALSE(bf1 == bf2);
}

TEST(BaseFigureTests, BaseFigureiIsHasPropetry) {
  BaseFigure bf(LINE_STR);
  bf.addProperty("prop1", "val1");
  bf.addProperty("prop2", "val2");
  bf.addProperty("prop3", "val3ee");

  EXPECT_TRUE(bf.isHasProperty("prop1"));
  EXPECT_TRUE(bf.isHasProperty("prop1", "val1"));
  EXPECT_TRUE(bf.isHasProperty("prop3", "val3ee"));
  EXPECT_FALSE(bf.isHasProperty("prop1", "vagfgfl1"));
  EXPECT_FALSE(bf.isHasProperty("propgr1"));
}

#endif  // TST_BASEFIGURE_H

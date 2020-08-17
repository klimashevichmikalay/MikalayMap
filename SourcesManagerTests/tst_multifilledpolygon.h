#ifndef TST_MULTIFILLEDPOLYGON_H
#define TST_MULTIFILLEDPOLYGON_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "MultiFilledPolygon.h"
#include "ParsersAll.h"

using namespace testing;
using namespace Geometry;
using namespace std;

struct MultiFilledPolygonFixture : public testing::Test {
  MultiFilledPolygon mlBefore;
  MultiFilledPolygon mlAfter;
  FilledPolygon line1;
  FilledPolygon line2;
  FilledPolygon line3;
  FilledPolygon line4;
  FilledPolygon line5;
  FilledPolygon line6;

  void SetUp() override {
    line1.addObject(Coordinates(3, 1));
    line1.addObject(Coordinates(2, 3));
    line1.addObject(Coordinates(4, 4));
    line2.addObject(Coordinates(6, 2));
    line2.addObject(Coordinates(6, 0));
    line2.addObject(Coordinates(4, 3));
    line3.addObject(Coordinates(3, 2));

    line4.addObject(Coordinates(2.58579, 0.526613));
    line4.addObject(Coordinates(1.17157, 3.35504));
    line4.addObject(Coordinates(4, 4.76925));
    line5.addObject(Coordinates(6.82843, 1.94083));
    line5.addObject(Coordinates(6.82843, -0.887601));
    line5.addObject(Coordinates(4, 3.355039));
    line6.addObject(Coordinates(2.58579, 1.94083));

    mlBefore.addObject(line1);
    mlBefore.addObject(line2);
    mlBefore.addObject(line3);
    mlAfter.addObject(line4);
    mlAfter.addObject(line5);
    mlAfter.addObject(line6);
  }

  void TearDown() override {
    mlAfter.clear();
    mlBefore.clear();
    line1.clear();
    line2.clear();
    line3.clear();
    line4.clear();
    line5.clear();
    line6.clear();
  }
};

TEST_F(MultiFilledPolygonFixture, TestScalingWhenAreaWill2x) {
  mlBefore.scalingByFactor(sqrt(2), true);

  EXPECT_EQ(mlBefore == mlAfter, true);
  EXPECT_EQ((mlBefore.getScale() - 1.4142) < 0.01, true);
}

TEST_F(MultiFilledPolygonFixture, TestScalingWhithFactor) {
  mlAfter.scalingByFactor(0.707106, true);

  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST_F(MultiFilledPolygonFixture, TestScalingWhenAreaWillMinus2x) {
  mlAfter.scalingByFactor(sqrt(0.5), true);

  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST(MultiFilledPolygonStringTest, TestConstructorsAndTypes) {
  MultiFilledPolygon ml1;
  MultiFilledPolygon ml2("name");

  EXPECT_EQ(ml1.getName(), nullptr);
  EXPECT_EQ(ml2.getName()->compare("name"), 0);
  EXPECT_EQ(ml1.getType(), MULTI_FILLED_POLYGON);
  EXPECT_EQ(ml2.getType(), MULTI_FILLED_POLYGON);
}

TEST(MultiFilledPolygonTest, TestEquals) {
  MultiFilledPolygon ml1;
  MultiFilledPolygon ml2;
  FilledPolygon line1;
  FilledPolygon line2;
  FilledPolygon line3;
  FilledPolygon line4;

  line1.addObject(Coordinates(3, 1));
  line2.addObject(Coordinates(2, 3));
  line1.addObject(Coordinates(4, 4));
  line2.addObject(Coordinates(6, 2));
  line2.addObject(Coordinates(6, 0));
  line3.addObject(Coordinates(3, 1));
  line4.addObject(Coordinates(2, 3));
  line3.addObject(Coordinates(4, 4));
  line4.addObject(Coordinates(6, 2));
  line4.addObject(Coordinates(6, 0));
  ml1.addObject(line1);
  ml1.addObject(line2);
  ml2.addObject(line3);
  ml2.addObject(line4);

  EXPECT_EQ(ml1 == ml2, true);
}
/*
//#include "ParsersAll.h"
TEST_F(MultiFilledPolygonFixture, TestSerializeAndDesirealize) {
  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  mfpToJSON(mlBefore, writer);
  MultiFilledPolygon multLine = jsonToMFP(sb.GetString());

  EXPECT_EQ(mlBefore == multLine, true);
}

TEST_F(MultiFilledPolygonFixture, TestSerializeAndDesirealize2) {
  mlBefore.scalingByArea(2, true);
  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  mfpToJSON(mlBefore, writer);
  MultiFilledPolygon multLine = jsonToMFP(sb.GetString());

  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST_F(MultiFilledPolygonFixture, TestGetFirstByProp) {
  line1.addProperty("prop1", "val1");
  line1.addProperty("prop2", "val2");
  line1.addProperty("prop3", "val3");

  line2.addProperty("prop4", "val4");
  line2.addProperty("prop5", "val5");
  line2.addProperty("prop6", "val6");

  line3.addProperty("prop2", "val2");  // line1

  line4.addProperty("prop7", "val7");
  line4.addProperty("prop6", "val6");  // line2
  line4.addProperty("prop8", "val8");

  line5.addProperty("prop1", "val1");  // line1
  line5.addProperty("prop8", "val8");  // line1
  line5.addProperty("prop9", "val9");

  line6.addProperty("prop10", "val10");

  mlBefore.clear();

  mlBefore.addPolygon(line1);
  mlBefore.addPolygon(line2);
  mlBefore.addPolygon(line3);
  mlBefore.addPolygon(line4);
  mlBefore.addPolygon(line5);
  mlBefore.addPolygon(line6);

  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop1", "val1") == line1, true);
  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop2", "val2") == line1, true);
  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop3", "val3") == line1, true);

  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop6", "val6") == line2, true);
  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop4", "val4") == line2, true);
  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop5", "val5") == line2, true);

  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop7", "val7") == line4, true);
  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop8", "val8") == line4, true);

  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop9", "val9") == line5, true);

  EXPECT_EQ(*mlBefore.getFirstByPropetry("prop10", "val10") == line6, true);

  EXPECT_EQ(
      mlBefore.getFirstByPropetry("propergtrg10", "val1rgrtgr0") == nullptr,
      true);
}
*/
#endif  // TST_MULTIFILLEDPOLYGON_H

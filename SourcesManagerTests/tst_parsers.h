#ifndef TST_PARSERS_H
#define TST_PARSERS_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "Algorithms.h"
#include "ParsersCommand.h"

using namespace testing;
using namespace std;

ParsersCommand pc;

struct PointsFixture : public testing::Test {
  vector<Point> elements;

  void SetUp() override {
    elements.push_back(Point("point1", Coordinates(3, 1)));
    elements.push_back(Point("point1", Coordinates(2, 3)));
    elements.push_back(Point("point1", Coordinates(4, 4)));
    elements.push_back(Point("point1", Coordinates(6, 2)));
    elements.push_back(Point("point1", Coordinates(6, 0)));
    elements.push_back(Point("point1", Coordinates(4, 3)));
    elements.push_back(Point("point1", Coordinates(3, 2)));
  }

  void TearDown() override { elements.clear(); }
};

struct MultiPointsFixture : public testing::Test {
  vector<MultiPoint> elements;

  void SetUp() override {
    MultiPoint mp("mp1");
    MultiPoint mp1("mp2");
    MultiPoint mp2("mp3");

    mp.addPoint(Point("point1", Coordinates(3, 1)));
    mp.addPoint(Point("point1", Coordinates(2, 3)));
    mp.addPoint(Point("point1", Coordinates(4, 4)));
    mp1.addPoint(Point("point1", Coordinates(6, 2)));
    mp1.addPoint(Point("point1", Coordinates(6, 0)));
    mp2.addPoint(Point("point1", Coordinates(4, 3)));
    mp2.addPoint(Point("point1", Coordinates(3, 2)));

    elements.push_back(mp);
    elements.push_back(mp1);
    elements.push_back(mp2);
  }

  void TearDown() override { elements.clear(); }
};

struct LinesFixture : public testing::Test {
  vector<LineString> elements;

  LineString ls1;
  LineString ls2;
  LineString ls3;
  LineString ls4;
  LineString ls5;
  LineString ls6;
  LineString ls7;

  void SetUp() override {
    ls1.addCoordinate(Coordinates(3, 1));
    ls1.addCoordinate(Coordinates(2, 3));
    ls1.addCoordinate(Coordinates(4, 4));
    ls2.addCoordinate(Coordinates(6, 2));
    ls2.addCoordinate(Coordinates(6, 0));
    ls3.addCoordinate(Coordinates(4, 3));
    ls4.addCoordinate(Coordinates(3, 2));

    ls5.addCoordinate(Coordinates(2.58579, 0.526613));
    ls5.addCoordinate(Coordinates(1.17157, 3.35504));
    ls6.addCoordinate(Coordinates(4, 4.76925));
    ls6.addCoordinate(Coordinates(6.82843, 1.94083));
    ls7.addCoordinate(Coordinates(6.82843, -0.887601));
    ls7.addCoordinate(Coordinates(4, 3.355039));
    ls7.addCoordinate(Coordinates(2.58579, 1.94083));

    elements.push_back(ls1);
    elements.push_back(ls2);
    elements.push_back(ls3);
    elements.push_back(ls4);
    elements.push_back(ls5);
    elements.push_back(ls6);
    elements.push_back(ls7);
  }

  void TearDown() override {
    elements.clear();
    ls1.clear();
    ls2.clear();
    ls3.clear();
    ls4.clear();
    ls5.clear();
    ls6.clear();
    ls7.clear();
  }
};

struct MultiLinesFixture : public testing::Test {
  vector<MultiLineString> elements;

  MultiLineString ml1;
  MultiLineString ml2;
  MultiLineString ml3;

  LineString ls1;
  LineString ls2;
  LineString ls3;
  LineString ls4;
  LineString ls5;
  LineString ls6;
  LineString ls7;

  void SetUp() override {
    ls1.addCoordinate(Coordinates(3, 1));
    ls1.addCoordinate(Coordinates(2, 3));
    ls1.addCoordinate(Coordinates(4, 4));
    ls2.addCoordinate(Coordinates(6, 2));
    ls2.addCoordinate(Coordinates(6, 0));
    ls3.addCoordinate(Coordinates(4, 3));
    ls4.addCoordinate(Coordinates(3, 2));

    ls5.addCoordinate(Coordinates(2.58579, 0.526613));
    ls5.addCoordinate(Coordinates(1.17157, 3.35504));
    ls6.addCoordinate(Coordinates(4, 4.76925));
    ls6.addCoordinate(Coordinates(6.82843, 1.94083));
    ls7.addCoordinate(Coordinates(6.82843, -0.887601));
    ls7.addCoordinate(Coordinates(4, 3.355039));
    ls7.addCoordinate(Coordinates(2.58579, 1.94083));

    ml1.addLine(ls1);
    ml1.addLine(ls2);
    ml1.addLine(ls3);
    ml2.addLine(ls4);
    ml2.addLine(ls5);
    ml3.addLine(ls6);
    ml3.addLine(ls7);

    elements.push_back(ml1);
    elements.push_back(ml2);
    elements.push_back(ml3);
  }

  void TearDown() override {
    elements.clear();
    ls1.clear();
    ls2.clear();
    ls3.clear();
    ls4.clear();
    ls5.clear();
    ls6.clear();
    ls7.clear();
  }
};

struct FilledPolygonFixture : public testing::Test {
  vector<FilledPolygon> elements;

  FilledPolygon ls1;
  FilledPolygon ls2;
  FilledPolygon ls3;
  FilledPolygon ls4;
  FilledPolygon ls5;
  FilledPolygon ls6;
  FilledPolygon ls7;

  void SetUp() override {
    ls1.addCoordinate(Coordinates(3, 1));
    ls1.addCoordinate(Coordinates(2, 3));
    ls1.addCoordinate(Coordinates(4, 4));
    ls2.addCoordinate(Coordinates(6, 2));
    ls2.addCoordinate(Coordinates(6, 0));
    ls3.addCoordinate(Coordinates(4, 3));
    ls4.addCoordinate(Coordinates(3, 2));

    ls5.addCoordinate(Coordinates(2.58579, 0.526613));
    ls5.addCoordinate(Coordinates(1.17157, 3.35504));
    ls6.addCoordinate(Coordinates(4, 4.76925));
    ls6.addCoordinate(Coordinates(6.82843, 1.94083));
    ls7.addCoordinate(Coordinates(6.82843, -0.887601));
    ls7.addCoordinate(Coordinates(4, 3.355039));
    ls7.addCoordinate(Coordinates(2.58579, 1.94083));

    elements.push_back(ls1);
    elements.push_back(ls2);
    elements.push_back(ls3);
    elements.push_back(ls4);
    elements.push_back(ls5);
    elements.push_back(ls6);
    elements.push_back(ls7);
  }

  void TearDown() override {
    elements.clear();
    ls1.clear();
    ls2.clear();
    ls3.clear();
    ls4.clear();
    ls5.clear();
    ls6.clear();
    ls7.clear();
  }
};

struct MultiFilledPolygon2Fixture : public testing::Test {
  vector<MultiFilledPolygon> elements;

  MultiFilledPolygon ml1;
  MultiFilledPolygon ml2;
  MultiFilledPolygon ml3;

  FilledPolygon ls1;
  FilledPolygon ls2;
  FilledPolygon ls3;
  FilledPolygon ls4;
  FilledPolygon ls5;
  FilledPolygon ls6;
  FilledPolygon ls7;

  void SetUp() override {
    ls1.addCoordinate(Coordinates(3, 1));
    ls1.addCoordinate(Coordinates(2, 3));
    ls1.addCoordinate(Coordinates(4, 4));
    ls2.addCoordinate(Coordinates(6, 2));
    ls2.addCoordinate(Coordinates(6, 0));
    ls3.addCoordinate(Coordinates(4, 3));
    ls4.addCoordinate(Coordinates(3, 2));

    ls5.addCoordinate(Coordinates(2.58579, 0.526613));
    ls5.addCoordinate(Coordinates(1.17157, 3.35504));
    ls6.addCoordinate(Coordinates(4, 4.76925));
    ls6.addCoordinate(Coordinates(6.82843, 1.94083));
    ls7.addCoordinate(Coordinates(6.82843, -0.887601));
    ls7.addCoordinate(Coordinates(4, 3.355039));
    ls7.addCoordinate(Coordinates(2.58579, 1.94083));

    ml1.addPolygon(ls1);
    ml1.addPolygon(ls2);
    ml1.addPolygon(ls3);
    ml2.addPolygon(ls4);
    ml2.addPolygon(ls5);
    ml3.addPolygon(ls6);
    ml3.addPolygon(ls7);

    elements.push_back(ml1);
    elements.push_back(ml2);
    elements.push_back(ml3);
  }

  void TearDown() override {
    ls1.clear();
    ls2.clear();
    ls3.clear();
    ls4.clear();
    ls5.clear();
    ls6.clear();
    ls7.clear();
    elements.clear();
  }
};

TEST_F(PointsFixture, TestSerializeAndDesirealizeFromFile) {
  pc.getParser(JSON)->savePoints(elements, "testfile");
  vector<Point> deser = pc.getParser(JSON)->getPoints("testfile");

  EXPECT_EQ(deser.size(), 7);
  EXPECT_EQ(isEqual(elements, deser), true);
}

TEST_F(MultiPointsFixture, TestSerializeAndDesirealizeFromFile) {
  pc.getParser(JSON)->saveMultiPoints(elements, "testfile");
  vector<MultiPoint> deser = pc.getParser(JSON)->getMultiPoints("testfile");
  EXPECT_EQ(deser.size(), 3);
  EXPECT_EQ(isEqual(elements, deser), true);
}

TEST_F(LinesFixture, TestSerializeAndDesirealizeFromFile) {
  pc.getParser(JSON)->saveLineStrings(elements, "testfile");
  vector<LineString> deser = pc.getParser(JSON)->getLineStrings("testfile");
  EXPECT_EQ(deser.size(), 7);
  EXPECT_EQ(isEqual(elements, deser), true);
}

TEST_F(MultiLinesFixture, TestSerializeAndDesirealizeFromFile) {
  pc.getParser(JSON)->saveMultiLineStrings(elements, "testfile");
  vector<MultiLineString> deser =
      pc.getParser(JSON)->getMultiLineStrings("testfile");

  EXPECT_EQ(deser.size(), 3);
  EXPECT_EQ(isEqual(elements, deser), true);
}

TEST_F(FilledPolygonFixture, TestSerializeAndDesirealizeFromFile) {
  pc.getParser(JSON)->saveFilledPolygons(elements, "testfile");
  vector<FilledPolygon> deser =
      pc.getParser(JSON)->getFilledPolygons("testfile");
  EXPECT_EQ(deser.size(), 7);
  EXPECT_EQ(isEqual(elements, deser), true);
}

TEST_F(MultiFilledPolygon2Fixture, TestSerializeAndDesirealizeFromFile) {
  pc.getParser(JSON)->saveMultiFilledPolygons(elements, "testfile");
  vector<MultiFilledPolygon> deser =
      pc.getParser(JSON)->getMultiFilledPolygons("testfile");
  EXPECT_EQ(deser.size(), 3);
  EXPECT_EQ(isEqual(elements, deser), true);
}

#endif  // TST_PARSERS_H

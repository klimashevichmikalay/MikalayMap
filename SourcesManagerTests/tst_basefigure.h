#ifndef TST_BASEFIGURE_H
#define TST_BASEFIGURE_H

#include "BaseFigure.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace figureTypes;
using namespace std;

TEST(BaseFigureTests, BaseFigureTypeInvalidParameter)
{
    BaseFigure bf("somename", POINT);

    EXPECT_THROW(bf.setType(static_cast<FigureType>(22)),
                 invalid_argument);
}

TEST(BaseFigureTests, BaseFigureType)
{

    BaseFigure bf("somename", POINT);
    bf.setType(LINE_STR);

    EXPECT_EQ(bf.getType(), LINE_STR);
    EXPECT_NE(bf.getType(), POINT);
}

TEST(BaseFigureTests, BaseFigureName)
{

    BaseFigure bf("somename", POINT);

    bf.setName("somename2");

    EXPECT_EQ(bf.getName(), "somename2");
    EXPECT_NE(bf.getName(), "new name");
}

TEST(BaseFigureTests, BaseFigureDelNameByPropertry)
{

    BaseFigure bf;

    bf.setName("somename");
    bf.delProperty("name");

    EXPECT_EQ(bf.getName(), "");
    EXPECT_NE(bf.getName(), "new name");
}

TEST(BaseFigureTests, BaseFigureSetNameByPropertry)
{

    BaseFigure bf;

    bf.addProperty("NAmE", "somename");

    EXPECT_EQ(bf.getName(), "somename");
}

TEST(BaseFigureTests, BaseFigureAddPropertries)
{

    BaseFigure bf;

    bf.addProperty("noTE1", "soMENote1");
    bf.addProperty("NOTE2", "SOmenote2");

    EXPECT_EQ(bf.getProperty("noTE1"), "somenote1");
    EXPECT_EQ(bf.getProperty("NOTE2"), "somenote2");
    EXPECT_EQ(bf.getProperty("note3"), "");
}

TEST(BaseFigureTests, BaseFigureAddEmptyPropertries)
{

    BaseFigure bf;

    bf.addProperty("", "");
    bf.addProperty("", "");

    EXPECT_EQ(bf.getProperty(""), "");
    EXPECT_NE(bf.getProperty(""), "somenote2");
}

TEST(BaseFigureTests, BaseFigureDelPropertries)
{

    BaseFigure bf;

    bf.addProperty("note1", "somenote1");
    bf.addProperty("note2", "somenote2");
    bf.addProperty("note3", "somenote3");
    bf.addProperty("note4", "somenote4");
    bf.addProperty("note5", "somenote5");

    bf.delProperty("note2");
    bf.delProperty("note5");
    bf.delProperty("note3");

    EXPECT_EQ(bf.getProperty("note1"), "somenote1");
    EXPECT_EQ(bf.getProperty("note4"), "somenote4");
    EXPECT_EQ(bf.getProperty("note2"), "");
}

TEST(BaseFigureTests, BaseFigureGetPropertryByEmptyObj)
{

    BaseFigure bf;

    EXPECT_EQ(bf.getProperty("prop"), "");
}


TEST(BaseFigureTests, BaseFigureDefaultConstructor)
{

    BaseFigure bf;

    EXPECT_EQ(bf.getName(), "");
    EXPECT_EQ(bf.getType(), UNKNOWN);
}

TEST(BaseFigureTests, BaseFigureInitWithStr)
{

    string name = "new name";

    BaseFigure bf(name);

    EXPECT_EQ(bf.getName(), "new name");
    EXPECT_EQ(bf.getType(), UNKNOWN);
}

TEST(BaseFigureTests, BaseFigureInitWhitChars)
{

    char *name = new char[10];
    strcpy(name, "new name");

    BaseFigure bf(name);
    delete[] name;

    EXPECT_EQ(bf.getName(), "new name");
    EXPECT_EQ(bf.getType(), UNKNOWN);
}

TEST(BaseFigureTests, BaseFigureInitWithStrAndFigureType)
{

    string name = "new name";

    BaseFigure bf(name, LINE_STR);

    EXPECT_EQ(bf.getName(), name);
    EXPECT_EQ(bf.getType(), LINE_STR);
}

TEST(BaseFigureTests, BaseFigureInitWhitCharsAndFigureType)
{

    char *name = new char[10];
    strcpy(name, "new name");

    BaseFigure bf(name, POINT);
    delete[] name;

    EXPECT_EQ(bf.getName(), "new name");
    EXPECT_NE(bf.getName(), " ");
    EXPECT_EQ(bf.getType(), POINT);
}


#endif // TST_BASEFIGURE_H

#include <gtest/gtest.h>

#include "tst_basefigure.h"
#include "tst_coordinates.h"
#include "tst_filledpolygon.h"
#include "tst_linestring.h"
#include "tst_multifilledpolygon.h"
#include "tst_multilinestring.h"
#include "tst_multipoint.h"
#include "tst_point.h"

/*#include "tst_entitiesalgorithms.h"

#include "tst_parsers.h"
#include "tst_triangle.h"*/

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

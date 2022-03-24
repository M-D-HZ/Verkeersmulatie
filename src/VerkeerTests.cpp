#include "gtest/gtest.h"
#include "VerkeerSituatie.h"
#include "Baan.h"
#include "Voertuig.h"
#include "VerkeersLicht.h"

class VerkeerTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    VerkeerSituatie verkeer;
};

//TEST_F(VerkeerTest, Readfile){
//    EXPECT_TRUE(verkeer.GetBanen().empty());
//    EXPECT_FALSE( verkeer.properlyInitialized());
//    verkeer.read("Banen.xml",verkeer);
//    EXPECT_FALSE(verkeer.GetBanen().empty());
//}
//
//TEST_F(VerkeerTest, EveryoneLeaving){
//}

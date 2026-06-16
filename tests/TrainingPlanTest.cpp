#include <gtest/gtest.h>
#include "trainingplan.h"
#include "InvalidDataException.h"

TEST(TrainingPlanTest, ValidTrainingPlan) {

    bool flag = true;


    try {
        TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);
    } catch (InvalidDataException& e) {
        flag = false;
    }


    EXPECT_TRUE(flag);
}

TEST(TrainingPlanTest, InvalidName) {

    bool flag = false;


    try {
        TrainingPlan plan(1, "Mu", "Ganhar massa muscular", 12);
    } catch (InvalidDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(TrainingPlanTest, InvalidObjective) {

    bool flag = false;


    try {
        TrainingPlan plan(1, "Musculacao", "GM", 12);
    } catch (InvalidDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(TrainingPlanTest, InvalidDurationWeeks) {

    bool flag = false;


    try {
        TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 0);
    } catch (InvalidDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(TrainingPlanTest, Getters) {

    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);


    EXPECT_EQ(1, plan.getId());
    EXPECT_EQ("Musculacao", plan.getName());
    EXPECT_EQ("Ganhar massa muscular", plan.getObjective());
    EXPECT_EQ(12, plan.getDurationWeeks());
}

TEST(TrainingPlanTest, OperatorEqualsById) {

    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);


    EXPECT_TRUE(plan == 1);
    EXPECT_FALSE(plan == 2);
}
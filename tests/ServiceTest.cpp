#include <gtest/gtest.h>
#include "studentcontainer.h"
#include "trainingplancontainer.h"
#include "MatriculaContainer.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"

TEST(StudentContainerTest, AddValidStudent) {

    StudentContainer container;
    bool flag = true;


    try {
        container.add(1, "Miguel", "912345678", "miguel@email.com");
    } catch (InvalidDataException& e) {
        flag = false;
    }


    EXPECT_TRUE(flag);
}

TEST(StudentContainerTest, AddDuplicatedStudent) {

    StudentContainer container;
    bool flag = false;


    try {
        container.add(1, "Miguel", "912345678", "miguel@email.com");
        container.add(1, "Joao", "912345679", "joao@email.com");
    } catch (DuplicatedDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(StudentContainerTest, GetStudent) {

    StudentContainer container;
    container.add(1, "Miguel", "912345678", "miguel@email.com");


    Student* student = container.get(1);


    EXPECT_NE(nullptr, student);
    EXPECT_EQ("Miguel", student->getName());
}

TEST(TrainingPlanContainerTest, AddValidTrainingPlan) {

    TrainingPlanContainer container;
    bool flag = true;


    try {
        container.add(1, "Musculacao", "Ganhar massa muscular", 12);
    } catch (InvalidDataException& e) {
        flag = false;
    }


    EXPECT_TRUE(flag);
}

TEST(TrainingPlanContainerTest, AddDuplicatedTrainingPlan) {

    TrainingPlanContainer container;
    bool flag = false;


    try {
        container.add(1, "Musculacao", "Ganhar massa muscular", 12);
        container.add(1, "Cardio", "Perder peso", 8);
    } catch (DuplicatedDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(MatriculaContainerTest, AddValidMatricula) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");
    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);
    MatriculaContainer container;
    bool flag = true;


    try {
        container.add(1, &student, &plan, 5, 6, 2026);
    } catch (InvalidDataException& e) {
        flag = false;
    }


    EXPECT_TRUE(flag);
}

TEST(MatriculaContainerTest, AddDuplicatedMatricula) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");
    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);
    MatriculaContainer container;
    bool flag = false;


    try {
        container.add(1, &student, &plan, 5, 6, 2026);
        container.add(2, &student, &plan, 6, 6, 2026);
    } catch (DuplicatedDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}
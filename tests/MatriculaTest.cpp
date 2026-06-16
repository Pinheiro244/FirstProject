#include <gtest/gtest.h>
#include "student.h"
#include "trainingplan.h"
#include "Matricula.h"
#include "InvalidDataException.h"

TEST(MatriculaTest, ValidMatricula) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");
    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);
    bool flag = true;


    try {
        Matricula matricula(1, &student, &plan, 5, 6, 2026);
    } catch (InvalidDataException& e) {
        flag = false;
    }


    EXPECT_TRUE(flag);
}

TEST(MatriculaTest, InvalidDate) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");
    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);
    bool flag = false;


    try {
        Matricula matricula(1, &student, &plan, 31, 2, 2026);
    } catch (InvalidDataException& e) {
        flag = true;
    }

    EXPECT_TRUE(flag);
}

TEST(MatriculaTest, NullStudent) {

    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);
    bool flag = false;


    try {
        Matricula matricula(1, nullptr, &plan, 5, 6, 2026);
    } catch (InvalidDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(MatriculaTest, NullTrainingPlan) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");
    bool flag = false;


    try {
        Matricula matricula(1, &student, nullptr, 5, 6, 2026);
    } catch (InvalidDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(MatriculaTest, Getters) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");
    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);
    Matricula matricula(1, &student, &plan, 5, 6, 2026);


    EXPECT_EQ(1, matricula.getId());
    EXPECT_EQ(5, matricula.getDay());
    EXPECT_EQ(6, matricula.getMonth());
    EXPECT_EQ(2026, matricula.getYear());
    EXPECT_EQ(&student, matricula.getStudent());
    EXPECT_EQ(&plan, matricula.getTrainingPlan());
}

TEST(MatriculaTest, OperatorEqualsById) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");
    TrainingPlan plan(1, "Musculacao", "Ganhar massa muscular", 12);
    Matricula matricula(1, &student, &plan, 5, 6, 2026);


    EXPECT_TRUE(matricula == 1);
    EXPECT_FALSE(matricula == 2);
}
#include <gtest/gtest.h>
#include "student.h"
#include "InvalidDataException.h"

TEST(StudentTest, ValidStudent) {
    // Arrange
    bool flag = true;

    // Act
    try {
        Student student(1, "Miguel", "912345678", "miguel@email.com");
    } catch (InvalidDataException& e) {
        flag = false;
    }

    // Assert
    EXPECT_TRUE(flag);
}

TEST(StudentTest, InvalidName) {

    bool flag = false;


    try {
        Student student(1, "Mi", "912345678", "miguel@email.com");
    } catch (InvalidDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(StudentTest, InvalidPhoneNumber) {

    bool flag = false;


    try {
        Student student(1, "Miguel", "912", "miguel@email.com");
    } catch (InvalidDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(StudentTest, InvalidEmail) {

    bool flag = false;


    try {
        Student student(1, "Miguel", "912345678", "miguelmail.com");
    } catch (InvalidDataException& e) {
        flag = true;
    }


    EXPECT_TRUE(flag);
}

TEST(StudentTest, Getters) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");


    EXPECT_EQ(1, student.getId());
    EXPECT_EQ("Miguel", student.getName());
    EXPECT_EQ("912345678", student.getPhoneNumber());
    EXPECT_EQ("miguel@email.com", student.getEmail());
}

TEST(StudentTest, OperatorEqualsById) {

    Student student(1, "Miguel", "912345678", "miguel@email.com");


    EXPECT_TRUE(student == 1);
    EXPECT_FALSE(student == 2);
}
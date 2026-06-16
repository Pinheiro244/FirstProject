#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
using namespace std;

class Exercise {
private:
    int id;
    string name;
    string description;

    bool isNameValid(const string& name) const;

public:
    Exercise(int id, const string& name, const string& description);

    int getId() const;
    string getName() const;
    string getDescription() const;

    bool operator==(int id) const;
};

#endif
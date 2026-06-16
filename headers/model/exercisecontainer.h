#ifndef EXERCISECONTAINER_H
#define EXERCISECONTAINER_H

#include <list>
#include "exercise.h"

using namespace std;

class ExerciseContainer {
private:
    list<Exercise*> exercises;

    Exercise* search(int id);

public:
    ~ExerciseContainer();

    void add(int id, const string& name, const string& description);
    Exercise* get(int id);
    list<Exercise*> getAll() const;
};

#endif

cmake_minimum_required(VERSION 3.20)
project(fsoft2026_1DE_3)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        headers
        headers/controller
        headers/controllers
        headers/dto
        headers/exceptions
        headers/mappers
        headers/model
        headers/repo
        headers/service
        headers/view
)

add_executable(fsoft2026_1DE_3
        main.cpp

        Sources/controllers/controllers.cpp

        Sources/model/person.cpp
        Sources/model/student.cpp
        Sources/model/studentcontainer.cpp
        Sources/model/trainingplan.cpp
        Sources/model/trainingplancontainer.cpp
        Sources/model/Matricula.cpp
        Sources/model/MatriculaContainer.cpp
        Sources/model/school.cpp

        Sources/service/StudentService.cpp
        Sources/service/TrainingPlanService.cpp
        Sources/service/MatriculaService.cpp

        Sources/mappers/StudentMapper.cpp
        Sources/mappers/TrainingPlanMapper.cpp
        Sources/mappers/MatriculaMapper.cpp

        Sources/repo/SchoolMemoryRepository.cpp

        Sources/view/view.cpp
        Sources/view/StudentView.cpp
        Sources/view/trainingPlanView.cpp
        Sources/view/MatriculaView.cpp
        Sources/view/utils.cpp

        Sources/exceptions/ApplicationException.cpp
        Sources/exceptions/DataConsistencyException.cpp
        Sources/exceptions/DuplicatedDataException.cpp
        Sources/exceptions/InvalidDataException.cpp
        Sources/exceptions/NoDataException.cpp
        Sources/exceptions/NotFoundException.cpp
        headers/model/exercise.h
        Sources/model/exercise.cpp
        Sources/model/exercisecontainer.cpp
        headers/model/exercisecontainer.h
)

add_executable(ProjectTester
        ProjectTester/main.cpp

        Sources/model/person.cpp
        Sources/model/student.cpp
        Sources/model/studentcontainer.cpp
        Sources/model/trainingplan.cpp
        Sources/model/trainingplancontainer.cpp
        Sources/model/Matricula.cpp
        Sources/model/MatriculaContainer.cpp

        Sources/exceptions/ApplicationException.cpp
        Sources/exceptions/DataConsistencyException.cpp
        Sources/exceptions/DuplicatedDataException.cpp
        Sources/exceptions/InvalidDataException.cpp
        Sources/exceptions/NoDataException.cpp
        Sources/exceptions/NotFoundException.cpp
)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(runTests
        tests/StudentTest.cpp
        tests/TrainingPlanTest.cpp
        tests/MatriculaTest.cpp
        tests/ServiceTest.cpp

        Sources/model/exercise.cpp
        Sources/model/exercisecontainer.cpp
        Sources/model/person.cpp
        Sources/model/student.cpp
        Sources/model/studentcontainer.cpp
        Sources/model/trainingplan.cpp
        Sources/model/trainingplancontainer.cpp
        Sources/model/Matricula.cpp
        Sources/model/MatriculaContainer.cpp
        Sources/model/school.cpp

        Sources/repo/SchoolMemoryRepository.cpp

        Sources/service/StudentService.cpp
        Sources/service/TrainingPlanService.cpp
        Sources/service/MatriculaService.cpp

        Sources/mappers/StudentMapper.cpp
        Sources/mappers/TrainingPlanMapper.cpp
        Sources/mappers/MatriculaMapper.cpp

        Sources/exceptions/ApplicationException.cpp
        Sources/exceptions/DataConsistencyException.cpp
        Sources/exceptions/DuplicatedDataException.cpp
        Sources/exceptions/InvalidDataException.cpp
        Sources/exceptions/NotFoundException.cpp
)

target_link_libraries(runTests gtest gtest_main)

add_test(NAME runTests COMMAND runTests)


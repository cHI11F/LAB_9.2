#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_9.2/LAB_9.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCompareBySurname)
        {
            Student student1{ "Ivanov", 1, "Programming", 85, 90, 80 };
            Student student2{ "Petrov", 2, "Mathematics", 75, 80, 85 };

            Assert::IsTrue(compareBySurname(student1, student2));
        }

        TEST_METHOD(TestCompareByCourseSpecialtySurname)
        {
            Student student1{ "Ivanov", 1, "Programming", 85, 90, 80 };
            Student student2{ "Petrov", 1, "Programming", 75, 80, 85 };

            Assert::IsFalse(compareByCourseSpecialtySurname(student1, student2));
        }

        TEST_METHOD(TestBinarySearch)
        {
            vector<Student> students;
            Student student1{ "Ivanov", 1, "Programming", 85, 90, 80 };
            Student student2{ "Petrov", 2, "Mathematics", 75, 80, 85 };
            students.push_back(student1);
            students.push_back(student2);

            Assert::IsTrue(binarySearch(students, "Ivanov", 1, "Programming"));
            Assert::IsFalse(binarySearch(students, "Petrov", 1, "Programming"));
        }
    };
}

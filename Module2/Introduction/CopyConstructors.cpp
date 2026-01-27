//
// Created by AbhishekJalkhare on 27-01-2026.

//

class Student {
    int * marks;
public:
    Student() {
       marks = new int(10);
    }

    Student(const Student & other) {
        marks = new int(*other.marks);
    }

};


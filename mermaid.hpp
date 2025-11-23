classDiagram
    class User {
        -userID: String
        -name: String
        -email: String
        +login()
        +logout()
    }

    class Student {
        -studentID: String
        -courses: List~Course~
        +registerCourse(course: Course)
        +viewGrades()
        +payFee(amount: Float)
    }

    class Professor {
        -professorID: String
        -courses: List~Course~
        +enterGrades(course: Course, grade: String)
        +viewCourseLoad()
    }

    class Course {
        -courseID: String
        -courseName: String
        -instructor: Professor
        -enrolledStudents: List~Student~
        +addStudent(student: Student)
        +removeStudent(student: Student)
    }

    class Enrollment {
        -student: Student
        -course: Course
        -grade: String
        +assignGrade(grade: String)
    }

    class Payment {
        -student: Student
        -amount: Float
        -status: String
        +processPayment()
    }

    %% Inheritance
    User <|-- Student
    User <|-- Professor

    %% Associations
    Student "0..*" -- "0..*" Course : enrolls
    Course "1" o-- "0..*" Enrollment : contains
    Student "1" o-- "0..*" Enrollment : has
    Student "1" -- "0..*" Payment : pays
    Professor "1" -- "0..*" Course : teaches

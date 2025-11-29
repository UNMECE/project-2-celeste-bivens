#include <iostream> 
#include <fstream> 
#include <vector>

class Student
{
private:
    std::string firstName;
    std::string lastName;
    double GPA;

    int enrolledYear;
    int gradYear;

    std::string enrolledSem;
    std::string gradSem;

    std::string level;

public:
    //Default constructor
    Student()
    {
        firstName = " ";
        lastName = " ";

        GPA = 0;

        enrolledYear = 0;
        gradYear = 0;
        
        enrolledSem = " "; 
        gradSem = " ";
        level = " ";

    }

    //Getters and Setters
    void set_name(const std::string &first, const std::string &last)
    {
        firstName = first;
        lastName = last;
    }
    std::string getFirst() const { return firstName; }
    std::string getLast() const { return lastName; }

    void set_GPA(double g) {GPA = g; }
    double getGPA() const {return GPA; }

    void set_grad_year(int y) { gradYear = y; }
    int getGradYear() const { return gradYear; }

    void set_grad_sem(const std::string &sem) { gradSem = sem; }
    std::string getGradSem() const { return gradSem; }

    void set_enroll_year(int y) { enrolledYear = y; }
    int getEnrollYear() const { return enrolledYear; }

    void set_enroll_sem(const std::string &sem) { enrolledSem = sem; }
    std::string getEnrollSem() const { return enrolledSem; }

    void set_level(const std::string &lvl) { level = lvl; }
    std::string getLevel() const { return level; }
     

    // VIRTUAL print function
    void printInfo(std::ofstream &out) const
    {
        out << "Name: " << firstName << " " << lastName << "\n";
        out << "GPA: " << GPA << "\n";
        out << "Graduation: " << gradSem << " " << gradYear << "\n";
        out << "Enrolled: " << enrolledSem << " " << enrolledYear << "\n";
        out << "Level: " << level << "\n";
    }

    //Destructor
    ~Student(){}
};

class Art_Student : public Student
{
private:
    std::string art_emphasis;
public:
    Art_Student() : Student()
    {
        art_emphasis = "Art Studio";
    }

    void set_art_emphasis(const std::string &art) {art_emphasis = art;}
    std::string get_art_emphasis() const {return art_emphasis;}
    
    
    void printInfo(std::ofstream &out)//overloading '<<'
    {
        Student::printInfo(out);
        out << "Art emphasis: " << art_emphasis;
        out << "\n------------------------\n";
    } 

};

class Physics_Student : public Student
{
private:
    std::string concentration;
public:

    Physics_Student() : Student() 
    {
        concentration = " "; 
    }

    void set_concentration(std::string c) {concentration = c;}
    std::string get_concentration(){return concentration;}

    void printInfo(std::ofstream &out)
    {
        Student::printInfo(out);
        out << "Concentration: " << concentration;
        out << "\n------------------\n"; 
    }
};

int main()
{
    //==========================ART STUDENTS=============================
    //Vector for art students
    std::vector<Art_Student *> art_students;
    art_students.push_back(new Art_Student);

    art_students[0]->set_name("Celeste","Bivens");
    art_students[0]->set_GPA(3.9);
    art_students[0]->set_grad_year(2026);
    art_students[0]->set_grad_sem("Spring");
    art_students[0]->set_enroll_year(2022);
    art_students[0]->set_enroll_sem("Fall");
    art_students[0]->set_level("Undergraduate");
    art_students[0]->set_art_emphasis("Art History");

    //-----------------Adding 5 more objects (students) to art_student vector--------------------
    //Using pointers, and allocating memory for those pointers

    Art_Student *a1 = new Art_Student;
    a1->set_name("Georgia", "O'Keeffe");
        a1->set_GPA(3.9);
        a1->set_grad_year(1910);
        a1->set_grad_sem("Spring");
        a1->set_enroll_year(1905);
        a1->set_enroll_sem("Fall");
        a1->set_level("Undergraduate");
        a1->set_art_emphasis("Art History");
    art_students.push_back(a1);

    Art_Student *a2 = new Art_Student;
        a2->set_name("Andy", "Warhol");
        a2->set_GPA(2.4);
        a2->set_grad_year(1949);
        a2->set_grad_sem("Fall");
        a2->set_enroll_year(1945);
        a2->set_enroll_sem("Spring");
        a2->set_level("Undergraduate");
        a2->set_art_emphasis("Commercial Art");
    art_students.push_back(a2);

    Art_Student *a3 = new Art_Student;
        a3->set_name("Chuck", "Close");
        a3->set_GPA(3.2);
        a3->set_grad_year(1959);
        a3->set_grad_sem("Winter");
        a3->set_enroll_year(1954);
        a3->set_enroll_sem("Fall");
        a3->set_level("Undergraduate");
        a3->set_art_emphasis("Painting");
    art_students.push_back(a3);

    Art_Student *a4 = new Art_Student;
        a4->set_name("David", "Hockney");
        a4->set_GPA(3.7);
        a4->set_grad_year(1962);
        a4->set_grad_sem("Spring");
        a4->set_enroll_year(1958);
        a4->set_enroll_sem("Fall");
        a4->set_level("Graduate");
        a4->set_art_emphasis("Painting/ Printmaking");
    art_students.push_back(a4);

    Art_Student *a5 = new Art_Student;
        a5->set_name("Kehinde", "Wiley");
        a5->set_GPA(3.8);
        a5->set_grad_year(1999);
        a5->set_grad_sem("Spring");
        a5->set_enroll_year(1995);
        a5->set_enroll_sem("Spring");
        a5->set_level("Undergraduate");
        a5->set_art_emphasis("Fine Arts");
    art_students.push_back(a5);

    //==========================PHYSICS STUDENTS=============================
    std::vector<Physics_Student *> physics_students;
    physics_students.push_back(new Physics_Student);

    physics_students[0]->set_name("Albert","Einstein");
    physics_students[0]->set_GPA(2.5);
    physics_students[0]->set_grad_year(1900);
    physics_students[0]->set_grad_sem("Spring");
    physics_students[0]->set_enroll_year(1896);
    physics_students[0]->set_enroll_sem("Fall");
    physics_students[0]->set_level("Undergraduate/Graduate");
    physics_students[0]->set_concentration("Physics & Mathematics");

    //-----------------Adding 5 more objects (students) to physics_student vector--------------------
    //Using pointers, and allocating memory for those pointers

    Physics_Student *p1 = new Physics_Student;
        p1->set_name("Niels", "Bohr");
        p1->set_GPA(3.5);
        p1->set_grad_year(1907);
        p1->set_grad_sem("Fall");
        p1->set_enroll_year(1903);
        p1->set_enroll_sem("Fall");
        p1->set_level("Undergraduate");
        p1->set_concentration("Astrophysics");
    physics_students.push_back(p1);

    Physics_Student *p2 = new Physics_Student;
        p2->set_name("Marie", "Curie");
        p2->set_GPA(3.6);
        p2->set_grad_year(1894);
        p2->set_grad_sem("Fall");
        p2->set_enroll_year(1891);
        p2->set_enroll_sem("Fall");
        p2->set_level("Undergraduate");
        p2->set_concentration("Mathematics");
    physics_students.push_back(p2);
        
    Physics_Student *p3 = new Physics_Student;
        p3->set_name("Werner", "Heisenberg");
        p3->set_GPA(4.0);
        p3->set_grad_year(2025);
        p3->set_grad_sem("Fall");
        p3->set_enroll_year(2021);
        p3->set_enroll_sem("Fall");
        p3->set_level("Undergraduate");
        p3->set_concentration("Chemistry");
    physics_students.push_back(p3);

    Physics_Student *p4 = new Physics_Student;
        p4->set_name("Richard", "Feynman");
        p4->set_GPA(4.5);
        p4->set_grad_year(1939);
        p4->set_grad_sem("Fall");
        p4->set_enroll_year(1935);
        p4->set_enroll_sem("Fall");
        p4->set_level("Undergraduate");
        p4->set_concentration("Biophysics");
    physics_students.push_back(p4);

    Physics_Student *p5 = new Physics_Student;
        p5->set_name("Isaac", "Newton");
        p5->set_GPA(1.5);
        p5->set_grad_year(2008);
        p5->set_grad_sem("Fall");
        p5->set_enroll_year(2005);
        p5->set_enroll_sem("Fall");
        p5->set_level("Undergraduate");
        p5->set_concentration("Calculus-Based Phyics");
    physics_students.push_back(p5);


    //Opening and writing to file
    std::ofstream writefile;
    writefile.open("student_info.dat",std::ios::out);

    if(!writefile.is_open())
    {
        std::cout << "Error opening file." << std::endl;
    }

    writefile << "===========ART STUDENTS=============\n";
    for(int i = 0; i < art_students.size(); i++)
    {
        art_students[i]->printInfo(writefile);
    }

    writefile << "===========PHYSICS STUDENTS=============\n";
    for(int i = 0; i < physics_students.size(); i++)
    {
        physics_students[i]->printInfo(writefile);
    }

    //Dynamically deallocating memory for pointers 
    for(int i = 0; i < art_students.size(); i++)
    {
        delete art_students[i];
        art_students[i] = nullptr;   
    }    
    
    for(int i = 0; i < physics_students.size(); i++)
    {
        delete physics_students[i];
        physics_students[i] = nullptr;    
    }

    return 0;
}
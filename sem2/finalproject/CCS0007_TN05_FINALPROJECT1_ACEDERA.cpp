#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string studentName;
    int studentNumber;
    string section;

    float *lec_rawScores = nullptr;
    float *lec_points = nullptr;
    int lec_numAssessments = 0;

    float *lab_rawScores = nullptr;
    float *lab_points = nullptr;
    int lab_numAssessments = 0;
};

void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].studentName > students[j + 1].studentName) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

int displayMenu(){
    int choice;
    do {
        cout << setfill('=') << setw(55) << "" << endl;
        cout << "CCS0007/CCS0007L Course Grading Computation Menu" << endl;
        cout << setfill('=') << setw(55) << "" << endl;
        cout << setfill(' ');
        cout << "[1] - Input Lecture Data" << endl;
        cout << "[2] - Input Laboratory Data" << endl;
        cout << "[3] - Get student Lecture, Laboratory, and Course Grade" << endl;
        cout << "[4] - Get Number of Students Listed" << endl;
        cout << "[5] - Get Posted Lecture Grades of Listed Students" << endl;
        cout << "[6] - Get Posted Laboratory Grades of Listed Students" << endl;
        cout << "[7] - Exit" << endl;
        cout << "\n";
        cout << "Choose your option: ";
        cin >> choice;
        cout << "\n";
        if (choice >= 1 && choice <= 7) {
            return choice;
        } else {
            if (!cin >> choice){
                cin.clear();
                cin.ignore();
            }
            cout << "INVALID INPUT!. PLEASE ENTER AN INTEGER WITHIN THE VALID RANGE" << endl;
            cout << "\n";
        }
    } while (true);
}

void lec_inputData(Student& data) {
    cout << "Please Input CCS0007 Lecture Grades\n";
    cout << "Student Name (SN, FM, MI): ";
    cin.ignore();
    getline(cin, data.studentName);

    cout << "Student ID Number: ";
    cin >> data.studentNumber;
    cin.ignore();

    cout << "Section: ";
    getline(cin, data.section);

    cout << "Enter number of Summative Assessments: ";
    cin >> data.lec_numAssessments;

    //test
    delete[] data.lec_rawScores;
    data.lec_rawScores = nullptr;
    delete[] data.lec_points;
    data.lec_points = nullptr;

    data.lec_rawScores = new float[data.lec_numAssessments + 4]();
    data.lec_points = new float[data.lec_numAssessments + 4]();

    for (int j = 0; j < data.lec_numAssessments; j++) {
        cout << "Summative Assessment " << j + 1 << " Points: ";
        cin >> data.lec_points[j];

        cout << "Summative Assessment " << j + 1 << " Score: ";
        cin >> data.lec_rawScores[j];
    }

    string exams[] = {"Midterm Project", "Midterm Exam", "Final Project", "Final Exam"};
    for (int i = 0; i < 4; i++) {
        cout << exams[i] << " Points: ";
        cin >> data.lec_points[data.lec_numAssessments + i];

        cout << exams[i] << " Score: ";
        cin >> data.lec_rawScores[data.lec_numAssessments + i];
    }
    cout << "\n";

ofstream file("lec_data.txt", ios::app );
    if (!file.is_open()) {
        cout << "Unable to open file for writing.\n";
        return;
    }

    file << data.studentName << "\n" 
         << data.studentNumber << " " 
         << data.section << " " 
         << data.lec_numAssessments;

    for (int i = 0; i < data.lec_numAssessments + 4; i++) {
        file << " " << data.lec_rawScores[i] << " " << data.lec_points[i];
    }

    file << endl;
    file.close();
    cout << "Data saved to file.\n";
}

void lab_inputData(Student& data) {
    cout << "Please Input CCS0007L Laboratory Grades\n";
    cout << "Student Name (SN, FM, MI): ";
    cin.ignore();
    getline(cin, data.studentName);

    cout << "Student ID Number: ";
    cin >> data.studentNumber;
    cin.ignore();

    cout << "Section: ";
    getline(cin, data.section);

    cout << "Enter number of Technical Assessments: ";
    cin >> data.lab_numAssessments;

    //test 
    delete[] data.lab_rawScores;
    data.lab_rawScores = nullptr;
    delete[] data.lab_points;
    data.lab_points = nullptr;

    data.lab_rawScores = new float[data.lab_numAssessments + 2]();
    data.lab_points = new float[data.lab_numAssessments + 2]();

    for (int j = 0; j < data.lab_numAssessments; j++) {
        cout << "Technical Assessment " << j + 1 << " Points: ";
        cin >> data.lab_points[j];

        cout << "Technical Assessment " << j + 1 << " Score: ";
        cin >> data.lab_rawScores[j];
    }

    string exams[] = {"Midterm Lab Exam", "Final Lab Exam"};
    for (int i = 0; i < 2; i++) {
        cout << exams[i] << " Points: ";
        cin >> data.lab_points[data.lab_numAssessments + i];

        cout << exams[i] << " Score: ";
        cin >> data.lab_rawScores[data.lab_numAssessments + i];
    }
    cout << "\n";

ofstream file("lab_data.txt", ios::app );
    if (!file.is_open()) {
        cout << "Unable to open file for writing.\n";
        return;
    }

    file << data.studentName << "\n" 
         << data.studentNumber << " " 
         << data.section << " " 
         << data.lab_numAssessments;
            
    for (int i = 0; i < data.lab_numAssessments + 2; i++) {
        file << " " << data.lab_rawScores[i] << " " << data.lab_points[i];
    }

    file << endl;
    file.close();
    cout << "Data saved to file.\n";
}

void courseGrade() {
string name,id;
cout << "Please input name and ID." << endl;
cin.ignore();

cout << "Student Name (SN, FM, MI): ";
getline(cin,name);
cout << "Student ID Number: ";
cin >> id;
cout << endl;
    
string tempName, tempSection;
int tempID, numAssessments;

ifstream lec_file("lec_data.txt");
if (!lec_file) {
    cout << "No student records available in the file.\n";
    return;
}

float lec_MG = 0, lec_FG = 0;

bool inLecture = false;

while(true) {
    if (!getline(lec_file, tempName))break;
    
    if (!(lec_file >> tempID >> tempSection >> numAssessments))break;
    
    float lec_SA = 0;
    float score, points;

    for (int i = 0; i < numAssessments; i++) {  
        if (!(lec_file >> score >> points))break;
        lec_SA += (points != 0 ? (score * 100 / points) : 0);
    }

    float lec_MPscore, lec_MEscore, lec_FPscore, lec_FEscore;
    float lec_MPpoints, lec_MEpoints, lec_FPpoints, lec_FEpoints;

    if (!(lec_file >> lec_MPscore >> lec_MPpoints 
        >> lec_MEscore >> lec_MEpoints 
        >> lec_FPscore >> lec_FPpoints 
        >> lec_FEscore >> lec_FEpoints)) break;

    lec_SA = lec_SA/numAssessments;
    float lec_MP = lec_MPscore * 100 / lec_MPpoints;
    float lec_ME = lec_MEscore * 100 / lec_MEpoints;
    float lec_FP = lec_FPscore * 100 / lec_FPpoints;
    float lec_FE = lec_FEscore * 100 / lec_FEpoints;
    lec_MG = (lec_SA*0.8 + lec_MP*0.2)*0.6 + lec_ME*0.40;
    lec_FG = (lec_SA*0.8 + lec_MP*0.2)*0.6 + lec_ME*0.15 + lec_FE*0.25;
    
    
    if (name == tempName) {
        inLecture = true;
        cout << "Lecture Grade" << endl;
        for (int i = 0; i < numAssessments; i++) {
        cout << "SA" << i + 1 << "   "; }
        cout << "MP    ME    FP    FE    MLEC  FLEC" << endl;
        for (int i = 0; i < numAssessments + 6; i++) {
        cout << "=====" << " ";}
        cout << endl;
        for (int i = 0; i < numAssessments; i++) {
        cout << setw(5) << left << lec_SA << " ";} 
        cout << setw(5) << left << lec_MP << " ";
        cout << setw(5) << left << lec_ME << " ";
        cout << setw(5) << left << lec_FP << " ";
        cout << setw(5) << left << lec_FE << " ";
        cout << setw(5) << left << lec_MG << " ";
        cout << setw(5) << left << lec_FG << " ";
        cout << endl;
    }lec_file.ignore();
}if (!inLecture) 
cout << "Data doesnt exist in the Lecture database.\n" <<endl;

ifstream lab_file("lab_data.txt");
if (!lab_file) {
    cout << "No student records available in the file.\n";
    return;
}

float lab_MG = 0, lab_FG = 0;

bool inLab = false;
while (true) {
    if (!getline(lab_file, tempName))break;
    
    if (!(lab_file >> tempID >> tempSection >> numAssessments))break;
    lab_file.ignore();

    float lab_TA = 0;
    float score, points;
    for (int i = 0; i < numAssessments; i++) {  
        if (!(lab_file >> score >> points)) break;
        lab_TA += (points != 0 ? (score * 100 / points) : 0);
    }
    
    float lab_MEscore, lab_FEscore;
    float lab_MEpoints, lab_FEpoints;
    lab_file >> lab_MEscore >> lab_MEpoints;
    lab_file >> lab_FEscore >> lab_FEpoints;


    lab_TA = lab_TA/numAssessments;
    float lab_ME = lab_MEscore * 100 / lab_MEpoints;
    float lab_FE = lab_FEscore * 100 / lab_FEpoints;
    lab_MG = lab_TA*0.6 + lab_ME*0.4;
    lab_FG = lab_TA*0.6 + lab_ME*0.15 + lab_FE*0.25;

    if (name == tempName) {
        inLab = true;    
        cout << "\nLaboratory Grade" << endl;
        for (int i = 0; i < numAssessments; i++) {
        cout << "TA" << i + 1 << "   "; }
        cout << "ME    FE    MLEC  FLEC" << endl;
        for (int i = 0; i < numAssessments + 4; i++) {
        cout << "=====" << " ";}
        cout << endl;
        for (int i = 0; i < numAssessments; i++) {
        cout << setw(5) << left << lab_TA << " ";} 
        cout << setw(5) << left << lab_ME << " ";
        cout << setw(5) << left << lab_FE << " ";
        cout << setw(5) << left << lab_MG << " ";
        cout << setw(5) << left << lab_FG << " ";
        cout << endl;
    }lab_file.ignore();
}if (!inLab) 
cout << "Data doesnt exist in the Laboratory database.\n" <<endl;

float MCG = lec_MG*0.7 + lab_MG*0.3;
float FCG = lec_FG*0.7 + lab_FG*0.3;

if (inLecture && inLab) {
    cout << "\nCourse Grade" << endl;
    cout << "MCG   FCG   EQV   REMARKS" << endl;
    cout << "===== ===== ===== ========" << endl;
    cout << fixed << setprecision(2);
    cout << setw(5) << MCG << " " << setw(5) << FCG << " ";
    if (FCG >= 97 && FCG <= 100){
        cout << setw(5) << "4.0" << " Excellent\n" << endl;
    } else if (FCG >= 93 && FCG < 97){
        cout << setw(5) << "3.5" << " Superior\n" << endl;
    } else if (FCG >= 89 && FCG < 93){
        cout << setw(5) << "3.0" << " Very Good\n" << endl;
    } else if (FCG >= 85 && FCG < 89){
        cout << setw(5) << "2.5" << " Good\n" << endl;
    } else if (FCG >= 80 && FCG < 85){
        cout << setw(5) << "2.0" << " Satisfactory\n" << endl;
    } else if (FCG >= 75 && FCG < 80){
        cout << setw(5) << "1.5" << " Fair\n" << endl;
    } else if (FCG >= 70 && FCG < 75){
        cout << setw(5) << "1.0" << " Passed\n" << endl;
    } else if (FCG >= 0 && FCG < 70){
        cout << setw(5) << "0.5" << " Fail\n" << endl;
    }
}
}

void get_numList() {
ifstream lec_file("lec_data.txt");
ifstream lab_file("lab_data.txt");

if (!lec_file && !lab_file) {
    cout << "No student records available in either file.\n";
    return;
}

int maxStudents = 10; // Initial capacity
Student* students = new Student[maxStudents];
int studentCount = 0;

//Resize the array
if (studentCount == maxStudents) {
    maxStudents *= 2;
    Student* newStudents = new Student[maxStudents];
    for (int i = 0; i < studentCount; i++) {
        newStudents[i] = students[i];
    }
    delete[] students;
    students = newStudents;
}

if (lec_file) {
string name;
int number;
string section;
int numAssessments;
while (getline(lec_file, name)) {
    lec_file >> number >> section >> numAssessments;
    lec_file.ignore();

    bool exists = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentName == name && students[i].studentNumber == number) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        // Resize
        if (studentCount == maxStudents) {
            maxStudents *= 2;
            Student* newStudents = new Student[maxStudents];
            for (int i = 0; i < studentCount; i++) {
                newStudents[i] = students[i];
            }
            delete[] students; 
            students = newStudents;
        }

        // Addnew student
        students[studentCount].studentName = name;
        students[studentCount].studentNumber = number;
        studentCount++;
    }

    // Skip(assess data)
    string dummy;
    getline(lec_file, dummy);
}
} else {
    cout << "lec_data.txt not found or could not be opened.\n";
}

if (lab_file) {
string name;
int number;
string section;
int numAssessments;
while (getline(lab_file, name)) {
    lab_file >> number >> section >> numAssessments;
    lab_file.ignore();

    bool exists = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentName == name && students[i].studentNumber == number) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        // Resize
        if (studentCount == maxStudents) {
            maxStudents *= 2;
            Student* newStudents = new Student[maxStudents];
            for (int i = 0; i < studentCount; i++) {
                newStudents[i] = students[i];
            }
            delete[] students;
            students = newStudents;
        }

        
        students[studentCount].studentName = name;
        students[studentCount].studentNumber = number;
        studentCount++;
    }

   
    string dummy;
    getline(lab_file, dummy);
}
} else {
cout << "lab_data.txt not found or could not be opened.\n";
}

bubbleSort(students, studentCount);

cout << "Total Number of Students Listed: " << studentCount << endl;
cout << "Course: CCS0007/CCS0007L" << endl;
cout << left;
cout << "\nNo." << " | " << setw(35) << "Student Name (SN, FN MI.)" 
     << " | "   << "Student ID No. |" << endl;
cout << setfill('=') << setw(60) << "" << endl;
cout << setfill(' ');

for (int i = 0; i < studentCount; i++) {
    cout << setw(3) << i + 1 << " | " << setw(35) << students[i].studentName 
         << " | " << setw(14) << students[i].studentNumber << " |" << endl;
} cout << endl;

delete[] students;
}

void lec_postedGrades() {
ifstream file("lec_data.txt");
if (!file) {
    cout << "No student records available in the file.\n";
    return;
}

int maxStudents = 10;
Student* students = new Student[maxStudents];
int studentCount = 0;

    while (getline(file, students[studentCount].studentName)) {
        file >> students[studentCount].studentNumber >> students[studentCount].section >> students[studentCount].lec_numAssessments;
        students[studentCount].lec_rawScores = new float[students[studentCount].lec_numAssessments + 4];
        students[studentCount].lec_points = new float[students[studentCount].lec_numAssessments + 4];

        for (int j = 0; j < students[studentCount].lec_numAssessments + 4; j++) {
            file >> students[studentCount].lec_rawScores[j] >> students[studentCount].lec_points[j];
        }
        file.ignore();
        studentCount++;
 
        if (studentCount == maxStudents) {
            maxStudents *= 2; 
            Student* newStudents = new Student[maxStudents];
            for (int i = 0; i < studentCount; i++) {
                newStudents[i] = students[i];
            }
            delete[] students;
            students = newStudents;
        }
    }

    bubbleSort(students, studentCount);

    cout << "Lecture Grades of Listed Students" << endl;
    cout << "Course: CCS0007" << endl;
    cout << left;
    cout << "\nNo." << " | " << setw(35) << "Student Name (SN, FN MI.)" 
         << " | "   << "Student ID No. | Section";

    int lec_numAssessments = students[0].lec_numAssessments;
    for (int i = 0; i < lec_numAssessments; i++) {
        cout << " | SA" << i + 1 << "   ";
    }
    cout << " | ME     | FE     | MP     | FP     |" << endl;
    cout << setfill('=') << setw(106 + 9 * lec_numAssessments) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < studentCount; i++) {
        cout << setw(3) << i + 1 << " | " << setw(35) << students[i].studentName 
             << " | " << setw(14) << students[i].studentNumber << " | " << setw(7) << students[i].section;

        for (int j = 0; j < students[i].lec_numAssessments + 4; j++) {
            cout << " | " << setw(6) << left << fixed << setprecision(2) << students[i].lec_rawScores[j] / students[i].lec_points[j] * 100;
        }
        cout << " |" << endl;

        delete[] students[i].lec_rawScores;
        delete[] students[i].lec_points;
    }

    delete[] students;

    cout << endl;
    file.close();
}

void lab_postedGrades() {
    ifstream file("lab_data.txt");
    if (!file) {
        cout << "No student records available in the file.\n";
        return;
    }

    int maxStudents = 10; 
    Student* students = new Student[maxStudents];
    int studentCount = 0;

    while (getline(file, students[studentCount].studentName)) {
        file >> students[studentCount].studentNumber >> students[studentCount].section >> students[studentCount].lab_numAssessments;
        students[studentCount].lab_rawScores = new float[students[studentCount].lab_numAssessments + 2];
        students[studentCount].lab_points = new float[students[studentCount].lab_numAssessments + 2];

        for (int j = 0; j < students[studentCount].lab_numAssessments + 2; j++) {
            file >> students[studentCount].lab_rawScores[j] >> students[studentCount].lab_points[j];
        }
        file.ignore();
        studentCount++;

        if (studentCount == maxStudents) {
        maxStudents *= 2;
        Student* newStudents = new Student[maxStudents];
        for (int i = 0; i < studentCount; i++) {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
        }
    }

    bubbleSort(students, studentCount);

    cout << "Lab Grades of Listed Students" << endl;
    cout << "Course: CCS0007L" << endl;
    cout << left;
    cout << "\nNo." << " | " << setw(35) << "Student Name (SN, FN MI.)" 
         << " | "   << "Student ID No. | Section";

    int lab_numAssessments = students[0].lab_numAssessments;
    for (int i = 0; i < lab_numAssessments; i++) {
        cout << " | TA" << i + 1 << "   ";
    }
    cout << " | ME     | FE     |" << endl;
    cout << setfill('=') << setw(88 + 9 * lab_numAssessments) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < studentCount; i++) {
        cout << setw(3) << i + 1 << " | " << setw(35) << students[i].studentName 
             << " | " << setw(14) << students[i].studentNumber << " | " << setw(7) << students[i].section;

        for (int j = 0; j < students[i].lab_numAssessments + 2; j++) {
            cout << " | " << setw(6) << left << students[i].lab_rawScores[j]*100/students[i].lab_points[j];
        }
        cout << " |" << endl;

        delete[] students[i].lab_rawScores;
        delete[] students[i].lab_points;
    }
    delete[] students;

    cout << endl;
    file.close();
}

int main() {    
    int choice;
    Student data;

    do {
        choice = displayMenu();
        switch (choice) {
            case 1:
                lec_inputData(data);
                break;
            case 2:                                
                lab_inputData(data);        
                break;
            case 3:
                courseGrade();            
                break;
            case 4:
                get_numList();
                break;
            case 5:
                lec_postedGrades();
                break;
            case 6:
                lab_postedGrades();
                break;
            case 7:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (true);

    return 0;
}

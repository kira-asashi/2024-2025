#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

//structure for all data of the student
struct dataList{
string studentName[30];
string section[30];
int studentNumber[30];
float lec_rawScores[30][8];
float lec_points[30][8];
float lab_rawScores[30][10];
float lab_points[30][10];
int studentCounter = 0;
};

//note to self(separated lec and lab to independently view option 10 and 11 without needing to have equal number of students and name
//atleast thats what im thinking of when i wrote this
dataList lec;
dataList lab;

int displayMenu(){
    int choice;
    do {
        
        cout << setfill('=') << setw(55) << "" << endl;
        cout << "CCS0007/CCS0007L Course Grading Computation Menu" << endl;
        cout << setfill('=') << setw(55) << "" << endl;
        cout << "[1] - Input Lecture Data" << endl;
        cout << "[2] - Input Laboratory Data" << endl;
        cout << "[3] - Get Midterm Lecture Grade" << endl;
        cout << "[4] - Get Midterm Laboratory Grade" << endl;
        cout << "[5] - Get Final Lecture Grade" << endl;
        cout << "[6] - Get Final Laboratory Grade" << endl;
        cout << "[7] - Get Midterm Course Grade" << endl;
        cout << "[8] - Get Final Course Grade" << endl;
        cout << "[9] - Get Number of Students Listed" << endl;
        cout << "[10] - Get Posted Lecture Grades of Listed Students" << endl;
        cout << "[11] - Get Posted Laboratory Grades of Listed Students" << endl;
        cout << "[12] - Exit" << endl;
        cout << "\n";
        cout << "Choose your option: ";
        cin >> choice;
        cout << "\n";
        if (choice >= 1 && choice <= 12) {
            return choice;
        } else {
            cout << "INVALID INPUT!. PLEASE ENTER AN INTEGER WITHIN THE VALID RANGE" << endl;
            cout << "\n";
        }
    } while (true);
}

int lec_inputData(int studentCounter){

cout << "Please Input CCS0007 Lecture Grades" << endl;
cin.ignore();
cout << "Student Name (SN, FM, MI): ";
getline(cin,lec.studentName[lec.studentCounter]);

cout << "Student ID Number: ";
cin >> lec.studentNumber[lec.studentCounter];
cin.ignore();

cout << "Section: ";
getline(cin,lec.section[lec.studentCounter]);

for(int j=0; j<4; j++){
cout << "Summative Assessment " << j+1 << " Points: ";
cin >> lec.lec_points[lec.studentCounter][j];
cout << "Summative Assessment " << j+1 << " Score: ";
cin >> lec.lec_rawScores[lec.studentCounter][j];
}
cout << "Midterm Project Points: ";
cin >> lec.lec_points[lec.studentCounter][4];
cout << "Midterm Project Score: ";
cin >> lec.lec_rawScores[lec.studentCounter][4];
cout << "Midterm Exam Points: ";
cin >> lec.lec_points[lec.studentCounter][5];
cout << "Midterm Exam Score: ";
cin >> lec.lec_rawScores[lec.studentCounter][5];
cout << "Final Project Points: ";
cin >> lec.lec_points[lec.studentCounter][6];
cout << "Final Project Score: ";
cin >> lec.lec_rawScores[lec.studentCounter][6];
cout << "Final Exam Points: ";
cin >> lec.lec_points[lec.studentCounter][7];
cout << "Final Exam Score: ";
cin >> lec.lec_rawScores[lec.studentCounter][7];

lec.studentCounter++;//increments the student counter for lecture only
return lec.studentCounter;
}

int lab_inputData(int studentCounter){

cout << "Please Input CCS0007L Laboratory Grades" << endl;
cin.ignore();
cout << "Student Name (SN, FM, MI): ";
getline(cin,lab.studentName[lab.studentCounter]);

cout << "Student ID Number: ";
cin >> lab.studentNumber[lab.studentCounter];
cin.ignore();

cout << "Section: ";
getline(cin,lab.section[lab.studentCounter]);

for(int j=0; j<8; j++){
cout << "Technical Assessment " << j+1 << " Points: ";
cin >> lab.lab_points[lab.studentCounter][j];
cout << "Technical Assessment " << j+1 << " Score: ";
cin >> lab.lab_rawScores[lab.studentCounter][j];
}
cout << "Midterm Lab Exam Points: ";
cin >> lab.lab_points[lab.studentCounter][8];
cout << "Midterm Lab Exam Score: ";
cin >> lab.lab_rawScores[lab.studentCounter][8];
cout << "Final Lab Exam Points: ";
cin >> lab.lab_points[lab.studentCounter][9];
cout << "Final Lab Exam Score: ";
cin >> lab.lab_rawScores[lab.studentCounter][9];

lab.studentCounter++;//increments the student counter for lab only
return lab.studentCounter;
}

void sortData(int studentCounter){
//sorts name alphabetically ascending in bubble sort
//if data is empty places it at the end
for (int i = 0; i < lec.studentCounter - 1; ++i){
    for (int j = 0; j < lec.studentCounter - i - 1; ++j ){
        if (lec.studentName[j].empty() || 
           (!lec.studentName[j + 1].empty() && lec.studentName[j] > lec.studentName[j + 1])) {
            swap(lec.studentName[j], lec.studentName[j + 1]);
            swap(lec.studentNumber[j], lec.studentNumber[j + 1]);
            swap(lec.section[j], lec.section[j + 1]);
            for (int k = 0; k < 8; ++k) {
                swap(lec.lec_rawScores[j][k], lec.lec_rawScores[j + 1][k]);
                swap(lec.lec_points[j][k], lec.lec_points[j + 1][k]);
            }
        }
    }
}

for (int i = 0; i < lab.studentCounter - 1; ++i){
    for (int j = 0; j < lab.studentCounter - i - 1; ++j ){
        if (lab.studentName[j].empty() || 
           (!lab.studentName[j + 1].empty() && lab.studentName[j] > lab.studentName[j + 1])) {
            swap(lab.studentName[j], lab.studentName[j + 1]);
            swap(lab.studentNumber[j], lab.studentNumber[j + 1]);
            swap(lab.section[j], lab.section[j + 1]);
            for (int k = 0; k < 10; ++k) {
                swap(lab.lab_rawScores[j][k], lab.lab_rawScores[j + 1][k]);
                swap(lab.lab_points[j][k], lab.lab_points[j + 1][k]);
            }
        }
    }
}
}

void lec_midtermGrade(int studentCounter){
string name, id;
cout << "Please input name and ID." << endl;
cin.ignore();

cout << "Student Name (SN, FN MI.): ";
getline(cin, name);
cout << "Student ID Number: ";
getline(cin, id);

//checks if name is in the database then computes 
bool isSame = false;
for (int i = 0; i < lec.studentCounter; i++){
    if (name == lec.studentName[i]){
        isSame = true;
        float SA = (lec.lec_rawScores[i][0] + lec.lec_rawScores[i][1]) * 100 / (lec.lec_points[i][0] + lec.lec_points[i][1]);
        float MP = lec.lec_rawScores[i][4] * 100 / lec.lec_points[i][4];
        float ME = lec.lec_rawScores[i][5] * 100 / lec.lec_points[i][5];
        float MG = SA*0.5 + MP*0.1 + ME*0.4;
        cout << "\nCourse: CCS0007" << endl;
        cout << "Section: " << lec.section[0] << endl;
        cout << "Midterm Lecture Grade" << endl;
        cout << "Midterm Summative Assessment (50%): " << SA << endl;
        cout << "Midterm Project (10%): " << MP << endl;
        cout << "Midterm Exam (40%): " << ME << endl;
        cout << "Midterm Lecture Grade: " << MG << endl;
        cout << "\n";
        break;
        
    }
}
if (!isSame)
cout << "Name doesnt exist in the database.\n" <<endl;
}

void lab_midtermGrade(int studentCounter){
string name, id;
cout << "Please input name and ID." << endl;
cin.ignore();

cout << "Student Name (SN, FN MI.): ";
getline(cin, name);
cout << "Student ID Number: ";
getline(cin, id);

//checks if name is in the database then computes 
bool isSame = false;
for (int i = 0; i < lab.studentCounter; i++){
    if (name == lab.studentName[i]){
        isSame = true;
        float TA = (lab.lab_rawScores[i][0] + lab.lab_rawScores[i][1] + lab.lab_rawScores[i][2] + lab.lab_rawScores[i][3]) * 100 / (lab.lab_points[i][0] + lab.lab_points[i][1] + lab.lab_points[i][2] + lab.lab_points[i][3]); 
        float ME = lab.lab_rawScores[i][8] * 100 / lab.lab_points[i][8];
        float MG = TA*0.6 + ME*0.4;
        cout << "\nCourse: CCS0007L" << endl;
        cout << "Section: " << lab.section[0] << endl;
        cout << "Midterm Laboratory Grade" << endl;
        cout << "Midterm Technical Assessment (60%): " << TA << endl;
        cout << "Midterm Lab Exam (40%): " << ME << endl;
        cout << "Midterm Lab Grade: " << MG << endl;
        cout << "\n";
        break; 
    }
}
if (!isSame)
cout << "Name doesnt exist in the database.\n" <<endl;
}

void lec_finalGrade(int studentCounter){
string name, id;
cout << "Please input name and ID." << endl;
cin.ignore();

cout << "Student Name (SN, FM, MI): ";
getline(cin, name);
cout << "Student ID Number: ";  
getline(cin, id);

//checks if name is in the database then computes 
bool isSame = false;
for (int i = 0; i < lec.studentCounter; i++){
    if (name == lec.studentName[i]){
        isSame = true;
        float SA = (lec.lec_rawScores[i][0] + lec.lec_rawScores[i][1] + lec.lec_rawScores[i][2] + lec.lec_rawScores[i][3]) * 100 / (lec.lec_points[i][0] + lec.lec_points[i][1] + lec.lec_points[i][2] + lec.lec_points[i][3]);
        float FP = (lec.lec_rawScores[i][4] + lec.lec_rawScores[i][6]) * 100 / (lec.lec_points[i][4] + lec.lec_rawScores[i][6]);
        float ME = lec.lec_rawScores[i][5] * 100 / lec.lec_points[i][5];
        float FE = lec.lec_rawScores[i][7] * 100 / lec.lec_points[i][7];
        float FG = SA*0.5 + FP*0.1 + ME*0.15 + FE*0.25;
        cout << "\nCourse: CCS0007" << endl;
        cout << "Section: " << lec.section[i] << endl;
        cout << "Final Lecture Grade" << endl;
        cout << "Final Summative Assessment (50%): " << SA << endl;
        cout << "Final Project Grade (10%): " << FP << endl;
        cout << "Midterm Exam (15%): " << ME << endl;
        cout << "Final Exam (25%): " << FE << endl;
        cout << "Final Lecture Grade: " << FG << endl;
        cout << "\n";
        break; 
    }
}
if (!isSame)
cout << "Name doesnt exist in the database.\n" <<endl;
}

void lab_finalGrade(int studentCounter){
string name, id;
cout << "Please input name and ID." << endl;
cin.ignore();

cout << "Student Name (SN, FM, MI): ";
getline(cin, name);
cout << "Student ID Number: ";  
getline(cin, id);

//checks if name is in the database then computes 
bool isSame = false;
for (int i = 0; i < lab.studentCounter; i++){
    if (name == lab.studentName[i]){
        isSame = true;
        float TA = (lab.lab_rawScores[i][0] + lab.lab_rawScores[i][1] + lab.lab_rawScores[i][2] + lab.lab_rawScores[i][3] + lab.lab_rawScores[i][4] + lab.lab_rawScores[i][5] + lab.lab_rawScores[i][6] + lab.lab_rawScores[i][7]) * 100 / (lab.lab_points[i][0] + lab.lab_points[i][1] + lab.lab_points[i][2] + lab.lab_points[i][3] + lab.lab_points[i][4] + lab.lab_points[i][5] + lab.lab_points[i][6] + lab.lab_points[i][7]);
        float ME = lab.lab_rawScores[i][8] * 100 / lab.lab_points[i][8];
        float FE = lab.lab_rawScores[i][9] * 100 / lab.lab_points[i][9];
        float FG = TA*0.6 + ME*0.15 + FE*0.25;
        cout << "\nCourse: CCS0007L" << endl;
        cout << "Section: " << lab.section[i] << endl;
        cout << "Final Laboratory Grade" << endl;
        cout << "Final Technical Assessment (60%): " << TA << endl;
        cout << "Midterm Lab Exam (15%): " << ME << endl;
        cout << "Final Lab Exam (25%): " << FE << endl;
        cout << "Final Lab Grade: " << FG << endl;
        cout << "\n";
        break; 
    }
}
if (!isSame)
cout << "Name doesnt exist in the database.\n" <<endl;
}

void midtermCourseGrade(int studentCounter){
string name, id;
cout << "Please input name and ID." << endl;
cin.ignore();

cout << "Student Name (SN, FM, MI): ";
getline(cin, name);
cout << "Student ID Number: ";  
getline(cin, id);
cout << "\n";

//checks if name is both in lec and lab then computes grade
bool isSame = false;
for (int i = 0; i<lec.studentCounter; i++){
    for (int j = 0; j<lab.studentCounter; j++){
        if (name == lec.studentName[i] && name == lab.studentName[j]){
            isSame = true;
            
            float lec_SA = (lec.lec_rawScores[i][0] + lec.lec_rawScores[i][1]) * 100 / (lec.lec_points[i][0] + lec.lec_points[i][1]);
            float lec_MP = lec.lec_rawScores[i][4] * 100 / lec.lec_points[i][4];
            float lec_ME = lec.lec_rawScores[i][5] * 100 / lec.lec_points[i][5];
            float lec_MG = lec_SA*0.5 + lec_MP*0.1 + lec_ME*0.4;

            float lab_TA = (lab.lab_rawScores[j][0] + lab.lab_rawScores[j][1] + lab.lab_rawScores[j][2] + lab.lab_rawScores[j][3]) * 100 / (lab.lab_points[j][0] + lab.lab_points[j][1] + lab.lab_points[j][2] + lab.lab_points[j][3]); 
            float lab_ME = lab.lab_rawScores[j][8] * 100 / lab.lab_points[j][8];
            float lab_MG = lab_TA*0.6 + lab_ME*0.4;

            float courseGrade = lec_MG*0.7 + lab_MG*0.3;

            cout << "Course: CCS0007/CCS0007L" << endl;
            cout << "Section: " << lec.section[i] << endl;
            cout << "Midterm Lecture Grade: " << lec_MG << endl;
            cout << "Midterm Laboratory Grade: " << lab_MG << endl;
            cout << "Midterm Course Grade: " << courseGrade << endl;

            if (courseGrade >= 97 && courseGrade <= 100){
                cout << "Midterm Equivalent Course Grade: 4.0 Excellent\n" << endl;
            } else if (courseGrade >= 93 && courseGrade <= 96){
                cout << "Midterm Equivalent Course Grade: 3.5 Superior\n" << endl;
            } else if (courseGrade >= 89 && courseGrade <= 92){
                cout << "Midterm Equivalent Course Grade: 3.0 Very Good\n" << endl;
            } else if (courseGrade >= 85 && courseGrade <= 88){
                cout << "Midterm Equivalent Course Grade: 2.5 Good\n" << endl;
            } else if (courseGrade >= 80 && courseGrade <= 84){
                cout << "Midterm Equivalent Course Grade: 2.00 Satisfactory\n" << endl;
            } else if (courseGrade >= 75 && courseGrade <= 79){
                cout << "Midterm Equivalent Course Grade: 1.5 Fair\n" << endl;
            } else if (courseGrade >= 70 && courseGrade <= 74){
                cout << "Midterm Equivalent Course Grade: 1.0 Passed\n" << endl;
            } else if (courseGrade >= 0 && courseGrade <= 69){
                cout << "Midterm Equivalent Course Grade: 0.5 Fail\n" << endl;
            break;
            }
        }
    }
}
if (!isSame)
cout << "Name doesnt exist in the database.\n" <<endl; 
}

void finalCourseGrade(int studentCounter){
string name, id;
cout << "Please input name and ID." << endl;
cin.ignore();

cout << "Student Name (SN, FM, MI): ";
getline(cin, name);
cout << "Student ID Number: ";  
getline(cin, id);
cout << "\n";
//checks if name is both in lec and lab then computes grade
bool isSame = false;
for (int i = 0; i<lec.studentCounter; i++){
    for (int j = 0; j<lab.studentCounter; j++){
        if (name == lec.studentName[i] && name == lab.studentName[j]){
            isSame = true;
            
            float lec_SA = (lec.lec_rawScores[i][0] + lec.lec_rawScores[i][1] + lec.lec_rawScores[i][2] + lec.lec_rawScores[i][3]) * 100 / (lec.lec_points[i][0] + lec.lec_points[i][1] + lec.lec_points[i][2] + lec.lec_points[i][3]);
            float lec_FP = (lec.lec_rawScores[i][4] + lec.lec_rawScores[i][6]) * 100 / (lec.lec_points[i][4] + lec.lec_rawScores[i][6]);
            float lec_ME = lec.lec_rawScores[i][5] * 100 / lec.lec_points[i][5];
            float lec_FE = lec.lec_rawScores[i][7] * 100 / lec.lec_points[i][7];
            float lec_FG = lec_SA*0.5 + lec_FP*0.1 + lec_ME*0.15 + lec_FE*0.25;

            float lab_TA = (lab.lab_rawScores[j][0] + lab.lab_rawScores[j][1] + lab.lab_rawScores[j][2] + lab.lab_rawScores[j][3] + lab.lab_rawScores[j][4] + lab.lab_rawScores[j][5] + lab.lab_rawScores[j][6] + lab.lab_rawScores[j][7]) * 100 / (lab.lab_points[j][0] + lab.lab_points[j][1] + lab.lab_points[j][2] + lab.lab_points[j][3] + lab.lab_points[j][4] + lab.lab_points[j][5] + lab.lab_points[j][6] + lab.lab_points[j][7]);
            float lab_ME = lab.lab_rawScores[j][8] * 100 / lab.lab_points[j][8];
            float lab_FE = lab.lab_rawScores[j][9] * 100 / lab.lab_points[j][9];
            float lab_FG = lab_TA*0.6 + lab_ME*0.15 + lab_FE*0.25;

            float courseGrade = lec_FG*0.7 + lab_FG*0.3;

            cout << "Course: CCS0007/CCS0007L" << endl;
            cout << "Section: " << lec.section[i] << endl;
            cout << "Final Lecture Grade: " << lec_FG << endl;
            cout << "Final Laboratory Grade: " << lab_FG << endl;
            cout << "Final Course Grade: " << courseGrade << endl;

            if (courseGrade >= 97 && courseGrade <= 100){
                cout << "Final Equivalent Course Grade: 4.0 Excellent\n" << endl;
            } else if (courseGrade >= 93 && courseGrade <= 96){
                cout << "Final Equivalent Course Grade: 3.5 Superior\n" << endl;
            } else if (courseGrade >= 89 && courseGrade <= 92){
                cout << "Final Equivalent Course Grade: 3.0 Very Good\n" << endl;
            } else if (courseGrade >= 85 && courseGrade <= 88){
                cout << "Final Equivalent Course Grade: 2.5 Good\n" << endl;
            } else if (courseGrade >= 80 && courseGrade <= 84){
                cout << "Final Equivalent Course Grade: 2.00 Satisfactory\n" << endl;
            } else if (courseGrade >= 75 && courseGrade <= 79){
                cout << "Final Equivalent Course Grade: 1.5 Fair\n" << endl;
            } else if (courseGrade >= 70 && courseGrade <= 74){
                cout << "Final Equivalent Course Grade: 1.0 Passed\n" << endl;
            } else if (courseGrade >= 0 && courseGrade <= 69){
                cout << "Final Equivalent Course Grade: 0.5 Fail\n" << endl;
            break;
            }
        }
    }
}
if (!isSame)
cout << "Name doesnt exist in the database.\n" <<endl; 
}

void get_numList(int lec_studentCounter, int lab_studentCounter){
sortData(lec.studentCounter);
sortData(lab.studentCounter);
int listedinBoth = 0;
cout << "Number of Students Listed in Both Lecture and Laboratory: " << endl;
for (int i = 0; i < lec.studentCounter; i++){
    for (int j = 0; j < lab.studentCounter; j++){
        if (lec.studentName[i] == lab.studentName[j]){
            listedinBoth++;            
        }
    }
}
cout << "Course: CCS0007/CCS0007L" << endl;
cout << "Section: " << lec.section[0] << endl;
cout << "No. | Student Name (SN, FN MI.) | Student ID No." << endl;
cout << setfill('=') << setw(40) << "" << endl;
cout << setfill(' ');
cout << left;
for (int i = 0; i < lec.studentCounter; i++){
    for (int j = 0; j < lab.studentCounter; j++){
        if (lec.studentName[i] == lab.studentName[j]){
            cout << listedinBoth << "    | " << setw(25) << lec.studentName[i] << " | " << setw(14) << lec.studentNumber[i] << endl;            
        }
    }
}

cout << "\n";
}

void lec_postedGrades(int studentCounter){
sortData(lec.studentCounter);
cout << "Lecture Grades of Listed Students" << endl;
cout << "Course: CCS0007" << endl;
cout << lec.section[0] << endl;
cout << "No. | Student Name (SN, FN MI.) | Student ID No. | Section | SA1 | SA2 | SA3 | SA4 | ME  | FE  | MP  | FP  |" << endl;
cout << setfill('=') << setw(108) << "" << endl;
cout << setfill(' ');
cout << left;
for(int i = 0; i < lec.studentCounter ; i++){
if(lec.studentName[i].empty()) continue; //skips empty data   
cout << i+1 << "   | " << setw(25) << lec.studentName[i] << " | " << setw(14) << lec.studentNumber[i] << " | " << setw(7) << lec.section[i];
for(int j = 0; j < 8; j++){cout << " | "  << setw(3) << lec.lec_rawScores[i][j];}
cout << " | " << endl;
}
cout << setfill('=') << setw(108) << "" << endl;
cout << setfill(' ');
cout << "\n";
}

void lab_postedGrades(int studentCounter){
sortData(lab.studentCounter);
cout << "Laboratory Grades of Listed Students" << endl;
cout << "Course: CCS0007L" << endl;
cout << lab.section[0] << endl;
cout << "No. | Student Name (SN, FN MI.) | Student ID No. | Section | TA1 | TA2 | TA3 | TA4 | TA5 | TA6 | TA7 | TA8 | ME  | FE  |" << endl;
cout << setfill('=') << setw(120) << "" << endl;
cout << setfill(' ');
cout << left;
for(int i = 0; i < lab.studentCounter ; i++){
if(lab.studentName[i].empty()) continue;//skips empty data
cout << i+1 << "   | " << setw(25) << lab.studentName[i] << " | " << setw(14) << lab.studentNumber[i] << " | " << setw(7) << lab.section[i];
for(int j = 0; j < 10; j++){cout << " | "  << setw(3) << lab.lab_rawScores[i][j];}
cout << " | " << endl;
}
cout << setfill('=') << setw(120) << "" << endl;
cout << setfill(' ');
cout << "\n";
}

int main(){
int choice;

    do {
        choice = displayMenu();   
        switch (choice) {
            case 1:
                lec.studentCounter = lec_inputData(lec.studentCounter);
                break; 
            case 2:
                lab.studentCounter = lab_inputData(lab.studentCounter);
                break; 
            case 3:
                lec_midtermGrade(lec.studentCounter);
                break;
            case 4:
                lab_midtermGrade(lab.studentCounter);
                break;
            case 5:
                lec_finalGrade(lec.studentCounter);
                break;              
            case 6:
                lab_finalGrade(lab.studentCounter);
                break;
            case 7:
                midtermCourseGrade(lec.studentCounter);
                break;
            case 8:
                finalCourseGrade(lab.studentCounter);
                break;
            case 9:
                get_numList(lec.studentCounter,lab.studentCounter);
                break;
            case 10:
                lec_postedGrades(lec.studentCounter);
                break; 
            case 11:
                lab_postedGrades(lab.studentCounter);
                break; }
    }while (choice != 12);

return 0;
}

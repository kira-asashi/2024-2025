#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

//Function Prototype
void getMidtermGrade(bool hasLab);  //computing midterm
void getFinalGrade(bool hasLab); //computing final

//Function for displaying menu
char displayMenu() {
    
    char choice;

    do {
        std::string line = "*********************************************************************";
        cout << line << endl;
        cout << std::setw(43) << "GRADE COMPUTATION" << endl;
        cout << line << endl;
        cout << "[A] - Midterm Grade\n";
        cout << "[B] - Final Grade\n";
        cout << "[X] - Exit\n";
        cout << line << endl;
        cout << "Choose your option: ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'A' || choice == 'B' || choice == 'X') {
            return choice;
        } else {
            cout << "INVALID INPUT!. PLEASE ENTER 'A', 'B', or 'X'." << endl;
            cout << "\n";
        }
    } while (true);
}

//Function for asking user if hasLab
bool displayHasLab() {

    char labInput;
    char hasLab;

    do {
        cout << "Does the course have a lab component? (Y/N): ";
        cin >> labInput;
        cout << "*********************************************************************" <<endl;
        labInput = toupper(labInput);
        if (labInput == 'Y' || labInput == 'N') {
            return (labInput == 'Y');
        } else {
            cout << "INVALID INPUT!. PLEASE ENTER 'Y' or 'N'." << endl;
            cout << "*********************************************************************" <<endl;
        }
    } while (true);
}

//Main Function
int main(){

    char choice;

    //Actual Menu
    do {
        choice = displayMenu();   
        switch (choice) {
            case 'A':
                getMidtermGrade(displayHasLab());
                break;
            case 'B':
                getFinalGrade(displayHasLab());
                break;
            case 'X':
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid option, please try again." << endl;
        }
    } while (choice != 'X');

    return 0;
}

// Recursive function for validating exam score input
double getValidatedScore(const std::string& prompt) {
    double score;
    cout << prompt;

    while (!(cin >> score)) {
        cout << "ERROR: Please enter a valid number.\n";
        cin.clear(); // Clear the error flag on cin
        cin.ignore(10000, '\n'); // Discard invalid input
        cout << prompt; // Re-prompt the user
    }

    if (score < 0 || score > 100) {
        cout << "ERROR. ENTER A NUMBER BETWEEN 0 AND 100.\n";
        return getValidatedScore(prompt); // Recursion if input is invalid
    }
    return score; // Valid input
}

//Function for calculating Midterm Grade
void getMidtermGrade(bool hasLab) {
    int numLQ_lec, numSQ_lec;
    double lqLec, sqLec, totalLQ_lec = 0.0, totalSQ_lec = 0.0, meLec;
    double class_standing_lec, Midterm_Grade = 0;
    
    //Long Quiz (LECTURE)
    cout << "Enter the NUMBER of Long Quizzes for lecture: ";
    cin >> numLQ_lec;
     for (int i = 1; i <= numLQ_lec; ++i) {
        totalLQ_lec += getValidatedScore("Enter SCORE for Long Quiz " + std::to_string(i) + " (LECTURE): ");
    }
    
    
    //Short Quiz (LECTURE)
    cout << "Enter the NUMBER of Short Quizzes for lecture: ";
    cin >> numSQ_lec;
    for (int i = 1; i <= numSQ_lec; ++i) {
        totalSQ_lec += getValidatedScore("Enter SCORE for Short Quiz " + std::to_string(i) + " (LECTURE): ");
    }

    //Midterm Exam (LECTURE)
    meLec = getValidatedScore("Enter SCORE for Midterm Exam (LECTURE): ");

    //Calculate average short quiz as an additional long quiz & Increment the number of Long Quizzes by 1 if there's atleast 1 SQ
    if (numSQ_lec>0){
        double avgSQ_lec = totalSQ_lec / numSQ_lec;
        totalLQ_lec += avgSQ_lec;
        numLQ_lec++; 
    }

    //Class Standing Lec
    class_standing_lec = totalLQ_lec / numLQ_lec; 

    //If lab exists
    if (hasLab){
    int numLQ_lab, numSQ_lab;
    double lqLab, sqLab, totalLQ_lab = 0.0, totalSQ_lab = 0.0, meLab;
    double class_standing_lab;

    //Long Quiz (LABORATORY)
    cout << "\n";
    cout << "Enter the NUMBER of Long Quizzes for laboratory: ";
    cin >> numLQ_lab;
     for (int i = 1; i <= numLQ_lab; ++i) {
            totalLQ_lab += getValidatedScore("Enter SCORE for Long Quiz " + std::to_string(i) + " (LABORATORY): ");
        }
    
    //Short Quiz (LABORATORY)
    cout << "Enter the NUMBER of Short Quizzes for laboratory: ";
    cin >> numSQ_lab;
    for (int i = 1; i <= numSQ_lab; ++i) {
            totalSQ_lab += getValidatedScore("Enter SCORE for Short Quiz " + std::to_string(i) + " (LABORATORY): ");
        }

    //Midterm Exam (LABORATORY)
    meLab = getValidatedScore("Enter SCORE for Midterm Exam (LABORATORY): ");

    //Calculate average short quiz as an additional long quiz & Increment the number of Long Quizzes by 1 if there's atleast 1 SQ
    if (numSQ_lab>0){
        double avgSQ_lab = totalSQ_lab / numSQ_lab;
        totalLQ_lab += avgSQ_lab;
        numLQ_lab++; 
    }

    //Class Standing Lab
    class_standing_lab = totalLQ_lab / numLQ_lab; 
    //Compute final Midterm Grade considering both lecture and lab
    Midterm_Grade = 0.7 * (class_standing_lec * 0.6 + meLec * 0.4) + 
                    0.3 * (class_standing_lab * 0.6 + meLab * 0.4);

    } else {
      Midterm_Grade = class_standing_lec * 0.6 + meLec * 0.4;  
    }

    // Output results
    cout << std::fixed << std::setprecision(4);
    cout << "\nMidterm Grade: " << Midterm_Grade << endl;
    cout << "\n";
}

//Function for calculating Final Grade    
void getFinalGrade(bool hasLab) {
    int numLQ_lec, numSQ_lec;
    double lqLec, sqLec, totalLQ_lec = 0.0, totalSQ_lec = 0.0;
    double meLec, feLec, class_standing_lec, finalGrade = 0;
    
    //Long Quiz (LECTURE)
    cout << "Enter the NUMBER of Long Quizzes for lecture: ";
    cin >> numLQ_lec;
    for (int i = 1; i <= numLQ_lec; ++i) {
            totalLQ_lec += getValidatedScore("Enter SCORE for Long Quiz " + std::to_string(i) + " (LECTURE): ");
        }
    
    //Short Quiz (LECTURE)
    cout << "Enter the NUMBER of Short Quizzes for lecture: ";
    cin >> numSQ_lec;
    for (int i =1; i<=numSQ_lec; i++){
        totalSQ_lec += getValidatedScore("Enter SCORE for Short Quiz" + std::to_string(i) + " (LECTURE): ");
        }

    // Midterm Exam (LABORATORY)
        meLec = getValidatedScore("Enter SCORE for Midterm Exam (LECTURE): ");
        
    // Final Exam (LABORATORY)
        feLec = getValidatedScore("Enter SCORE for Final Exam (LECTURE): ");

    //Calculate average short quiz as an additional long quiz & Increment the number of Long Quizzes by 1 if there's atleast 1 SQ
    if (numSQ_lec>0){
        double avgSQ_lec = totalSQ_lec / numSQ_lec;
        totalLQ_lec += avgSQ_lec;
        numLQ_lec++; 
    }

    //Class Standing Lec
    class_standing_lec = totalLQ_lec / numLQ_lec; 

    //If lab exists
    if (hasLab){
    int numLQ_lab, numSQ_lab;
    double lqLab, sqLab, totalLQ_lab = 0.0, totalSQ_lab = 0.0;
    double meLab, feLab, class_standing_lab;

    // Long Quiz (LABORATORY)
        cout << "\nEnter the NUMBER of Long Quizzes for laboratory: ";
        cin >> numLQ_lab;
        for (int i = 1; i <= numLQ_lab; ++i) {
            totalLQ_lab += getValidatedScore("Enter SCORE for Long Quiz " + std::to_string(i) + " (LABORATORY): ");
        }
        
    // Short Quiz (LABORATORY)
        cout << "Enter the NUMBER of Short Quizzes for laboratory: ";
        cin >> numSQ_lab;
        for (int i = 1; i <= numSQ_lab; ++i) {
            totalSQ_lab += getValidatedScore("Enter SCORE for Short Quiz " + std::to_string(i) + " (LABORATORY): ");
        }

    // Midterm Exam (LABORATORY)
        meLab = getValidatedScore("Enter SCORE for Midterm Exam (LABORATORY): ");
        
    // Final Exam (LABORATORY)
        feLab = getValidatedScore("Enter SCORE for Final Exam (LABORATORY): ");

    //Calculate average short quiz as an additional long quiz & Increment the number of Long Quizzes by 1 if there's atleast 1 SQ
    if (numSQ_lab>0){
        double avgSQ_lab = totalSQ_lab / numSQ_lab;
        totalLQ_lab += avgSQ_lab;
        numLQ_lab++; 
    }

    //Class Standing Lab
    class_standing_lab = totalLQ_lab / numLQ_lab; 

    //Compute final Midterm Grade considering both lecture and lab
    finalGrade = 0.7 * (class_standing_lec * 0.6 + meLec * 0.15 + feLec * 0.25) + 
                 0.3 * (class_standing_lab * 0.6 + meLab * 0.15 + feLab * 0.25);
    } else {
    finalGrade = class_standing_lec * 0.6 + meLec * 0.15 + feLec * 0.25;
    }

    // Output results
    cout << std::fixed << std::setprecision(4);
    cout << "\nFinal Grade: " << finalGrade << endl;
    cout << "\n";

    
}

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Student {
    string name;
    string college;
    string branch;
    int semester;
};

struct Subject {
    string name;
    int attendance;
    int marks ;
    int target ;
};

struct CodingSkill {
    string language;
    int hours;
    int goal;
};

double calculateAverageMarks (Subject subject[],int size){
    double total = 0;
    for ( int i = 0; i < size ; i++){
        total += subject[i].marks;
    }
    double average = total / size;
    return average;
}

string calculateBestSubject (Subject subjects[],int size){
    int largest = subjects[0].marks;
    string best = subjects[0].name;
    for ( int i = 0 ; i < size ; i++){
        if ( subjects[i].marks > largest){
            largest = subjects[i].marks;
            best = subjects[i].name;
        }
    }
    return best;
}

double calculateAverageAttendance (Subject subject[],int size){
    double total = 0;
    for ( int i = 0; i < size ; i++){
        total += subject[i].attendance;
    }
    double average = total / size;
    return average;
}

string bestSubjectAttendance (Subject subjects[],int size){
    int largest = subjects[0].attendance;
    string best = subjects[0].name;
    for ( int i = 0 ; i < size ; i++){
        if ( subjects[i].attendance > largest){
            largest = subjects[i].attendance;
            best = subjects[i].name;
        }
    }
    return best;
}

double skillProgress (CodingSkill skills[], int index){
    double percent = ( double(skills[index].hours) / skills[index].goal ) * 100;
    return percent;
}

double targetDifference (Subject subjects[], int index){
    return subjects[index].marks - subjects[index].target;
}

string calculateWeakSubject (Subject subjects[],int size){
    int smallest = subjects[0].marks;
    string weak = subjects[0].name;
    for ( int i = 0 ; i < size ; i++){
        if ( subjects[i].marks < smallest){
            smallest = subjects[i].marks;
            weak = subjects[i].name;
        }
    }
    return weak;
}

double academicScore(double marks , double attendance){
       return (marks*0.75) + (attendance*0.25);
}

double calculateCodingHours (CodingSkill skills[],int size){
    double total = 0;
    for ( int i = 0 ; i < size ; i++){
        total += skills[i].hours;
    }
    return total;
}

string calculateBestSkill (CodingSkill skills[] , int size){
    int largest = skills[0].hours;
    string best = skills[0].language;
    for ( int i = 0 ; i < size ; i++){
        if ( skills[i].hours > largest){
            largest = skills[i].hours;
            best = skills[i].language;
        }
    }
    return best;
}

string calculateGrade (int marks){
    if ( marks >= 90){
        return "A+";
    }
    else if ( marks >= 80){
        return "A";
    }
    else if ( marks >= 70){
        return "B";
    }
    else if ( marks >= 61){
        return "C";
    }
    else {
        return "F";
    }
}

void progressBar(ostream &out, double progress){
    if (progress > 100)
    progress = 100;
    int bars = progress / 10;
    out << "[";
    for(int i = 0 ; i < bars ; i++)
    {
        out << "#";
    }
    for(int i = bars ; i < 10 ; i++)
    {
        out << "-";
    }
    out << "]";
}

int main () {
    Student s;
    cout << "Enter your name: ";
    getline(cin,s.name);
    cout <<endl;
    cout << "Enter your college: ";
    getline(cin,s.college);
    cout <<endl;
    cout << "Enter your branch: ";
    getline(cin,s.branch);
    cout <<endl;
    cout << "Enter your semester: ";
    cin >> s.semester;
    cout <<endl;
    cout << endl;
    
    int num;
    cout << "Enter the number of subjects you have opted for: ";
    cin >> num;
    cin.ignore();
    cout << endl;

    Subject subjects[num];
    for(int i=0;i<num;i++){
    cout <<endl;
    cout << "Enter subject name: ";
    getline(cin, subjects[i].name);
    cout << endl;

    cout << "Enter marks: ";
    cin >> subjects[i].marks;
    cout << endl;

    cout << "Enter attendance: ";
    cin >> subjects[i].attendance;
    cout << endl;

    cout << "Enter target marks: ";
    cin >> subjects[i].target;
    cout << endl;

    cin.ignore();
}
    cout << endl;
    int num1;
    cout << "Enter the number of coding skills you wish to develop: ";
    cin >> num1;
    cin.ignore();
    cout<<endl;

    CodingSkill skills[num1];
    for(int i=0;i<num1;i++){
    cout << endl;
    cout << "Enter language: ";
    getline(cin, skills[i].language);
    cout << endl;

    cout << "Enter the number of hours invested: ";
    cin >> skills[i].hours;
    cout << endl;

    cout << "Enter your target hours: ";
    cin >> skills[i].goal;
    cout << endl;

    cin.ignore();
}
    ofstream report ("Academic_Report.txt");
    if (!report){
        cout << "Error creating report file";
        return 1;
    }
    cout << fixed << setprecision(2);
    report << fixed << setprecision(2);
    cout << endl;
    report << endl;
    cout << " ============================================================ " << endl;
    report << " ============================================================ " << endl;
    cout << "                     ACADEMIC PULSE" << endl;
    report << "                     ACADEMIC PULSE" << endl;
    cout << " ============================================================ " << endl;
    report << " ============================================================ " << endl;
    cout << "                Student Performance Dashboard" << endl;
    report << "                 Student Performance Dashboard" << endl;
    cout << " ============================================================ " << endl;
    report << " ============================================================ " << endl;
    cout << endl;
    report << endl;

    cout << "Name     : " << s.name << endl;
    report << "Name     : " << s.name << endl;
    cout << "College  : " << s.college << endl;
    report << "College  : " << s.college << endl;
    cout << "Branch   : " << s.branch << endl;
    report << "Branch   : " << s.branch << endl;
    cout << "Semester : " << s.semester << endl;
    report << "Semester : " << s.semester << endl;
    cout << endl;
    cout << "\n=====================================\n";
    report << "\n=====================================\n";
    cout << "              SUBJECTS\n";
    report << "              SUBJECTS\n";
    cout << "=====================================\n";
    report << "=====================================\n";
    cout << endl;
    report << endl;

    for ( int i = 0 ; i < num;i++){
        cout << i+1 << ". " << subjects[i].name << endl;
        report << i+1 << ". " << subjects[i].name << endl;
    }

    cout << endl;
    report << endl;
    cout << "\n=====================================\n";
    report << "\n=====================================\n";
    cout << "            CODING SKILLS\n";
    report << "            CODING SKILLS\n";
    cout << "=====================================\n";
    report << "=====================================\n";
    cout << endl;
    report << endl;
    for ( int i = 0 ; i < num1;i++){
        cout << i+1 << ". " << skills[i].language << endl;
        report << i+1 << ". " << skills[i].language << endl;
    }
    double averageMarks = calculateAverageMarks(subjects,num);
    double averageAttendance = calculateAverageAttendance(subjects,num);
    double score = academicScore(averageMarks,averageAttendance);
    string bestSubject = calculateBestSubject(subjects,num);
    string weakSubject = calculateWeakSubject(subjects,num);
    double codingHours = calculateCodingHours(skills,num1);
    string bestSkill = calculateBestSkill(skills,num1);
    string bestAttendance = bestSubjectAttendance(subjects,num);
    cout << endl;
    report << endl;
    cout << endl;
    report << endl;
    cout << "\n=====================================\n";
    report << "\n=====================================\n";
    cout << "               GRADES\n";
    report << "               GRADES\n";
    cout << "=====================================\n";
    report << "=====================================\n";
    cout << endl;
    report << endl;
    for ( int i = 0 ; i < num ; i++){
        cout << i+1 << ". " << subjects[i].name << " : " << calculateGrade(subjects[i].marks) << endl;
        report << i+1 << ". " << subjects[i].name << " : " << calculateGrade(subjects[i].marks) << endl;
    }
    cout << endl;
    report << endl;

    Subject rankedSubjects[num];
    for (int i = 0 ; i < num ; i++){
        rankedSubjects[i] = subjects[i];
    }

    for (int i = 0; i < num-1 ; i++){
        for ( int j = i +1 ; j < num ; j++){
            if (rankedSubjects[j].marks > rankedSubjects[i].marks){
                Subject temp = rankedSubjects[i];
                rankedSubjects[i] = rankedSubjects[j];
                rankedSubjects[j] = temp;
            }
        }
    }
    cout << "\n=====================================\n";
    report << "\n=====================================\n";
    cout << "            SUBJECT RANKINGS\n";
    report << "            SUBJECT RANKINGS\n";
    cout << "=====================================\n";
    report << "=====================================\n";

    for (int i = 0; i < num ; i++){
        cout << i+1 << ". " << rankedSubjects[i].name << " - " << rankedSubjects[i].marks << endl;
        report << i+1 << ". " << rankedSubjects[i].name << " - " << rankedSubjects[i].marks << endl;
    }

    cout << "\n=====================================\n";
    report << "\n=====================================\n";
    cout << "              INSIGHTS\n";
    report << "              INSIGHTS\n";
    cout << "=====================================\n";
    report << "=====================================\n";
    cout << endl;
    report << endl;
    cout << "AVERAGE MARKS          : " << averageMarks << endl;
    report << "AVERAGE MARKS          : " << averageMarks << endl;
    cout << "AVERAGE ATTENDANCE     : " << averageAttendance << "%" << endl;
    report << "AVERAGE ATTENDANCE     : " << averageAttendance << "%" << endl;
    cout << "MOST ATTENDED SUBJECT  : " << bestAttendance << endl;
    report << "MOST ATTENDED SUBJECT  : " << bestAttendance << endl;
    for ( int i = 0; i < num;i++){
        if (subjects[i].attendance < 70){
            cout << "NOTE :- LOW ATTENDANCE WARNING  : " << subjects[i].name << endl;
            report << "NOTE :- LOW ATTENDANCE WARNING  : " << subjects[i].name << endl;
        }
    }
    cout << "BEST SUBJECT           : " << bestSubject << endl;
    report << "BEST SUBJECT           : " << bestSubject << endl;
    cout << "WEAKEST SUBJECT        : " << weakSubject << endl;
    report << "WEAKEST SUBJECT        : " << weakSubject << endl;
    cout << "TOTAL CODING HOURS     : " << codingHours <<endl;
    report << "TOTAL CODING HOURS     : " << codingHours <<endl;
    if (codingHours > 100){
        cout << "Okay so now that deserves a praise keep it up ! "<<endl;
        report << "Okay so now that deserves a praise keep it up ! "<<endl;
    }
    cout << "MOST DEVELOPED SKILL   : " << bestSkill << endl;
    report << "MOST DEVELOPED SKILL   : " << bestSkill << endl;
    cout << "ACADEMIC SCORE         : " << score << endl;
    report << "ACADEMIC SCORE         : " << score << endl;
    if (score >= 90){
        cout << "Status                 : Outstanding performance. " ;
        report << "Status                 : Outstanding performance. " ;
    }
    else if ( score >= 80){
        cout << "Status                 : Strong performance with room for further growth. ";
        report << "Status                 : Strong performance with room for further growth. ";
    }
    else if ( score >= 70){
        cout << "Status                 : Commendable efforts but not quite there yet. ";
        report << "Status                 : Commendable efforts but not quite there yet. ";
    }
    else{
        cout << "Status                 : Consistent effort will lead to improvement. ";
        report << "Status                 : Consistent effort will lead to improvement. ";
    }

    cout << endl;
    cout << endl;
    report << endl;
    report << endl;
    cout << "\n=====================================\n";
    report << "\n=====================================\n";
    cout << "           TARGET ANALYSIS\n";
    report << "           TARGET ANALYSIS\n";
    cout << "=====================================\n";
    report << "=====================================\n";
    cout << endl;
    report << endl;
    for (int i = 0; i < num ; i++){
        cout << subjects[i].name << " : " << targetDifference(subjects, i) << endl;
        report << subjects[i].name << " : " << targetDifference(subjects, i) << endl;
        if (targetDifference(subjects,i) > 15){
            cout << "OUTSTANDING performance! Time to raise the bar " << endl;
            report << "OUTSTANDING performance! Time to raise the bar " << endl;
        }
        else if (targetDifference(subjects,i) >= 0){
            cout << "Stay consistent and you'll achieve your goal!" << endl;
            report << "Stay consistent and you'll achieve your goal!" << endl;
        }
        else{
            cout << "More effort is required to reach the target " << endl;
            report << "More effort is required to reach the target " << endl;
        }
    }
    cout << endl;
    report << endl;
    cout << "\n=====================================\n";
    report << "\n=====================================\n";
    cout << "           SKILL PROGRESS\n";
    report << "           SKILL PROGRESS\n";
    cout << "=====================================\n";
    report << "=====================================\n";
    cout << endl;
    report << endl;

    for(int i=0;i<num1;i++){
    double progress = skillProgress(skills,i);
    cout << skills[i].language << " : ";
    progressBar(cout, progress);
    cout << " " << progress << "%" << endl;
    report << skills[i].language << " : ";
    progressBar(report, progress);
    report << " " << progress << "%" << endl;
}

    cout << endl;
    report << endl;
    cout << "\n=====================================\n";
    report << "\n=====================================\n";
    cout << "           SKILL RANKING\n";
    report << "           SKILL RANKING\n";
    cout << "=====================================\n";
    report << "=====================================\n";

    CodingSkill rankedSkills[num1];
    for (int i = 0 ; i < num1 ; i++){
        rankedSkills[i] = skills[i];
    }

    for ( int i = 0 ;  i < num1 - 1 ; i++){
        for (int j = i + 1 ; j < num1 ; j++){
            if (rankedSkills[j].hours > rankedSkills[i].hours){
                CodingSkill temp = rankedSkills[i];
                rankedSkills[i] = rankedSkills[j];
                rankedSkills[j] = temp;
            }
        }
    }

    for (int i = 0; i < num1 ; i++){
        cout << i+1 << ". " << rankedSkills[i].language << " - " << rankedSkills[i].hours << " Hours " << endl;
        report << i+1 << ". " << rankedSkills[i].language << " - " << rankedSkills[i].hours << " Hours " << endl;
    }
    cout << endl;
    report << endl;

    cout << "\n======================================\n";
    report << "\n======================================\n";
    cout << "        END OF ACADEMIC REPORT\n";
    report << "        END OF ACADEMIC REPORT\n";
    cout << "======================================\n";
    report << "======================================\n";
    cout << endl;
    report << endl;
    cout << " ============================================================ " << endl;
    report << " ============================================================ " << endl;
    cout << " Generated by Academic Pulse " << endl;
    report << " Generated by Academic Pulse " << endl;
    cout << " Developed by Suyash Sreenath Kumar "<< endl;
    report << " Developed by Suyash Sreenath Kumar "<< endl;
    cout << " ============================================================ " << endl;
    report << " ============================================================ " << endl;
    report.close();
    cout << endl;
    cout << "Academic report generated successfully!" << endl;
    cout << endl;
    cout << "File saved as : Academic_Report.txt";
    cout << endl;
}
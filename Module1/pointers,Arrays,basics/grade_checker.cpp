#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{   
    char check = 'y';
    do{
        int student_id ; 
        cout<<"Enter Student Id between 101 and 999" <<endl;
        do{
            cin>>student_id;
            if(student_id < 101 || student_id > 999 ){
                cout<< "Invalid Student ID. Must be between 101 and 999. Please re-enter."<<endl;
                continue;
            }
            break;
        }while(true);
        cout<<"How many assignments does Student [" <<student_id<<"] have? "<<endl;
        int assingment;
        cin>>assingment;
        int total_grades = 0;
        int total_assingments = 0;
        for (int i = 0; i < assingment; i++)
        {
            cout<<"Enter grade for Assignment #[ "<<i<<" ] (0-100): "<<endl;
            int grade;
            cin>>grade;
            if(grade >100 && grade < 0){
                cout<< "Invalid grade. Must be between 0 and 100. Skipping this assignment."<<endl;
                continue;
            }
            total_grades += grade;
            total_assingments++;
            
        }
        if(total_assingments == 0){
            cout<<"No valid grades entered for Student [" <<student_id<<" ]"<<endl;

        }

        else{
            double average = (double)total_grades /total_assingments;
            cout<<"Student[ "<< student_id <<" ]- Average Grade: [ "<<average<<"]%"<<endl;
            if (average >= 90) cout<<"Excellent!"<<endl;
            else if (average >= 70) cout<<"Good job!"<<endl;
            else if (average >= 50) cout<<"Needs improvement."<<endl;
            else cout<<"At risk" <<endl;
            
        }

        cout<<"Process another student? (Y/N): ";
        cin>>check;


        


    }while (check == 'y' || check == 'Y');

    cout<<"Exiting Grade Analyzer. Goodbye!"<<endl;
   
    
    return 0;
}

#include <iostream>
#include <string>
using namespace std;


// Structure to store student information
struct Student
{
    int rollno;
    string name;
    float marks;
// Structure to store student information
};

// Maximum number students
const int MAX = 100;

// Function to insert a new Student
void insertStudent(Student Students[],int &count)
{
    if (count>=MAX)
    {
        cout<<"Student lists is full!\n";
        return;
    }
    cout<<"\nEnter Roll Number: ";
    cin>> Students[count].rollno;

    cout<<"Enter Name: ";
    cin.ignore();
    getline(cin,Students[count].name);

    cout<<"Enter Marks: ";
    cin>>Students[count].marks;

    count++;

    cout<<"Student added successfully!\n";
}

// function to display all students 
void displayStudents(Student students[], int count)
{
    if (count ==0)
    {
        cout<<"\n No student records found!\n"; 
        return;
    }

    cout<< "\n===== Student Records=====\n";

    for(int i=0; i<count; i++)
    {
        cout<<"\nRoll Number:" <<students[i].rollno;
        cout<<"\nName:" <<students[i].name;
        cout<<"\nMarks:" <<students[i].marks;
        cout<<"\n--------------\n";
    }
}   

// Function to delete a Student
void deleteStudent(Student students[], int &count)
{
    if(count==0)
    {
        cout<<"\nNo student records found!\n";
        return;
    }
    int rollno;
    cout<<"\nEnter Roll Number to delete: ";
    cin>> rollno;

    int position= -1;

    // Find the Student
    for(int i=0; i< count; i++)
    {
        if(students[i].rollno == rollno)
        {
            position = i;
            break;
        }
    }
    if(position == -1)
    {
        cout<<"Student not found!\n";
        return;
    }

    // Shift elements to the left
    for(int i= position; i< count - 1;i++)
    {
        students[i] = students[i + 1];
    }
    count--;

    cout<<"Student deleted successfully!\n";
}

// Linear search
void linearsearch(Student students[], int count)
{
    int rollno;

    cout<<"\nEnter Roll Number to search: ";
    cin>> rollno;

    for (int i=0; i < count; i++)
    {
        if(students[i].rollno == rollno)
        {
        cout<<"\nStudent Found!\n";
        cout<<"Location (index):" <<i <<endl;
        cout<<"Roll Number : " <<students[i].rollno<< endl;
        cout<<"Name :" <<students[i].name<< endl;
        cout<<"Marks :"<<students[i].marks<<endl;
        return;
        }
    }

cout<<"Student not found!\n";
}

// Sort students according to Roll Number
void sortStudents(Student students[], int count)
{
    cout<<"\nStudents sorted by Roll Number!\n";
}

// Binary Search
void binarysearch(Student students[], int count)
{
    int rollno;

    cout<<"\nEnter Roll Number to search: ";
    cin>> rollno;

    int low = 0;
    int high = count - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if(students[mid].rollno == rollno)
        {
            cout<<"\nStudent Found!\n";
            cout<<"location (index):"<<mid<<endl;
            cout<<"Roll Number : "<< students[mid].rollno << endl;
            cout<<"Name: "<< students[mid].name << endl;
            cout<<"Marks: "<< students[mid].marks << endl;
            return;
        }
        else if (students[mid].rollno < rollno)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<"Student not found!\n";
}


// Main Function
int main()
{
    Student students[MAX];

    int count = 0;
    int choice;

    do
    { 
     cout<<"\n\n===== STUDENT RECORD MANAGER =====\n";
     cout<<"1. Insert New Student\n";
     cout<<"2. Display All Student\n";
     cout<<"3. Delete Student\n";
     cout<<"4. Linera Search\n";
     cout<<"5. Sort Students\n";
     cout<<"6. Binary Search\n";
     cout<<"7. Exit\n";
    
     cout<<"\nEnter your choice:";

     cin>> choice;

     switch(choice)
     {
        case 1 :

        insertStudent(students, count);
        break;

         case 2 :

        displayStudents(students, count);
        break;

         case 3 :

        deleteStudent(students, count);
        break;
        
        case 4 :
        linearsearch(students, count);
        break;

        case 5 :
        sortStudents(students, count);
        break;

        case 6 :
        binarysearch(students, count);
        break;

        case 7 :
        cout<<"\nThank You for using Student Record Manager!\n";
     }
    }
    while (choice !=7);
    return 0;
}
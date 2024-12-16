//  Create a structure for 200 student , print all student name whose fees remains more than 20000 rs. 
//  using structure and array of structure.and random name of student from defined 200 student.and random fees of student.
//  dont include time function to reset the rand function to get the random number.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Define structure for a student
struct Student {
    char name[50];
    float fees;
};

// Array of unique random names
const char *names[] = {
    "Aarav", "Vivaan", "Aditya", "Vihaan", "Aryan", "Arjun", "Krishna", "Rohan", "Rudra", "Kabir",
    "Aditi", "Ananya", "Isha", "Myra", "Avni", "Diya", "Saanvi", "Meera", "Ira", "Riya",
    "Raj", "Kartik", "Om", "Shiv", "Yash", "Rishi", "Harsh", "Dhruv", "Kunal", "Nikhil",
    "Sara", "Pooja", "Simran", "Tara", "Priya", "Anjali", "Radha", "Neha", "Shreya", "Kavya",
    "Vikram", "Siddharth", "Aman", "Jay", "Varun", "Rajat", "Gautam", "Abhishek", "Manish", "Akash",
    "Sneha", "Madhuri", "Nisha", "Deepika", "Rekha", "Payal", "Shalini", "Jyoti", "Sunita", "Rupali",
    "Sameer", "Tarun", "Vikas", "Aakash", "Ravi", "Pradeep", "Naveen", "Chetan", "Sachin", "Ajay",
    "Pooja", "Komal", "Sheetal", "Megha", "Preeti", "Swati", "Ruchi", "Rashmi", "Divya", "Priti",
    "Suresh", "Mukesh", "Vivek", "Mahesh", "Pawan", "Ramesh", "Amit", "Anil", "Ashok", "Arvind",
    "Seema", "Anuradha", "Mona", "Geeta", "Anita", "Pallavi", "Kusum", "Sarita", "Kiran", "Jaya",
    "Harshita", "Chitra", "Asha", "Leela", "Padmini", "Kajal", "Sanjana", "Snehal", "Nikita", "Tanvi",
    "Apoorva", "Ritika", "Gayatri", "Bhavya", "Navya", "Sonia", "Ruchi", "Neetu", "Alka", "Reema",
    "Amrita", "Namrata", "Surbhi", "Monika", "Bharti", "Mamta", "Shweta", "Purnima", "Charu", "Naina",
    "Lavanya", "Pia", "Aditi", "Ankita", "Sonia", "Avani", "Ishita", "Vani", "Kripa", "Riddhi",
    "Trisha", "Anushka", "Pia", "Rashi", "Shraddha", "Tanisha", "Mitali", "Niharika", "Devika", "Tanya"
};

#define TOTAL_STUDENTS 200
#define NAME_COUNT (sizeof(names) / sizeof(names[0]))

void main() {
    struct Student students[TOTAL_STUDENTS];

    // Randomly generate student data
    for (int i = 0; i < TOTAL_STUDENTS; i++) {
        strcpy(students[i].name, names[i % NAME_COUNT]); // Unique names
        students[i].fees = (rand() % 30000) + 10000; // Random fees between 10000 and 40000
    }

    // Print students with fees > 20000'/
    printf("Students whose fees exceed 20000:\n");
    for (int i = 0; i < TOTAL_STUDENTS; i++) {
        if (students[i].fees > 20000) {
            printf("Name: %s\n", students[i].name);
            printf("Fees: %.2f\n\n", students[i].fees);
        }
    }

    getch(); // Wait for user input
}

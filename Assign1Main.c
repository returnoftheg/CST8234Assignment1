#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "helper.c"


int * studentInitializer(int numStud){
    int i;
    int input, intLength = 0;
    int *array;
    array = malloc(numStud*sizeof(int));

    for (i = 0; i < numStud; ++i) {

        printf("Enter the 5-digit student ID for student #%d: ",i+1);
        scanf("%d",&input);
        intLength = log10(input) + 1;

        while (intLength != 5){

            printf("The ID entered is not 5-digits long, try again: ");
            scanf("%d",&input);
            intLength = log10(input) + 1;
        }

        array[i] = input;
    }

    return array;

}

char** courseInitializer(int numofCourses){
    int i;
    int length;
    char** courseId;

    courseId = malloc(numofCourses * sizeof(char*));

    for (i=0; i<numofCourses; ++i){
        courseId[i] = malloc(sizeof(char) * 8);
    }


    for (i = 0; i < numofCourses ; ++i) {

        printf("Enter the 7-digit course ID for course #%d: ",i+1);
        scanf("%s",courseId[i]);
        length = strlen(courseId[i]);

        while (length != 7){
            printf("The ID entered is not 7-digits long, try again: ");
            scanf("%s",courseId[i]);
            length = strlen(courseId[i]);
        }
    }
    return courseId;
}

int *startArray(int numberOfStudents, int numberOfCourses) {
	int * array = (int *) malloc(numberOfStudents * (numberOfCourses * sizeof(int)));
	initilaize2DArray(array, numberOfStudents, numberOfCourses);
    return array;

}

void printRegTable(int* studentArr, char** courseArr, int* registrationArr, int numOfCourses, int numOfStudents){
    int i,j,temp;
    printf("Legend:  Y = Student is registered in course\n");
    printf("         N = Student is not registered in course\n\n");
    printf("Student ID      |        ");
    for (i = 0; i < numOfCourses ; ++i) {
        printf("%s",courseArr[i]);
        if (i != numOfCourses-1){
            printf("      |        ");
        }
    }

    printf("\n");
    for (i = 0; i < numOfStudents ; ++i) {
        printf("%d           |           ",studentArr[i]);
        for (j = 0; j < numOfCourses; j++) {
            temp = *(registrationArr + i * numOfCourses + j);
            if (temp == 1){
                printf("Y");
            } else if (temp == 0){
                printf("N");
            }
            if (j < numOfCourses - 1 ){
                printf("         |          ");
            }
        }
        printf("\n");
    }

    printf("\n");
}

/*void registerStudent(int* registrationArr, int CourseIndex, int studentIndex){

}*/

int intIterator(int input, int* array, int arrLength){
    int control = 0;
    int i,position = 0;
    for (i = 0; i < arrLength ; ++i) {
        if(array[i] == input){
            position = i;
            return position;
        }
    }
    while (control != 1){
        printf("The ID you entered does not belong to a student. Please enter a valid ID: ",i+1);
        scanf("%d",&input);
        for (i = 0; i < arrLength ; ++i) {
            if(array[i] == input){
                position = i;
                return position;
            }
        }
    }
}

int charIterator(char input[], char** array, int arrLength){
    int control = 0;
    int i,position = 0;
    for (i = 0; i < arrLength ; ++i) {
        if(array[i] == input){
            position = i;
            control = 1;
        }
    }
    while (control != 1){
        printf("The ID you entered is not a course. Please enter a valid ID: ",i+1);
        scanf("%s",input);
        for (i = 0; i < arrLength ; ++i) {
            if(array[i] == input){
                position = i;
                control = 1;
            }
        }
    }
    return position;
}

int main() {

    int numStudents, numCourses, studentRegInput, studentRegIndex = 0;
    int courseRegIndex =0;
    int option = 0;
    char courseRegInput[15];
    int* studentId;
    char** courses;
    int* regTable;

    printf("****************************************************************\n");
    printf("***********Welcome to the Student Registration System***********\n");
    printf("**************************Assignment 1**************************\n");
    printf("****************************************************************\n");
    printf("\n");


    printf("Please enter the number of students you would like to register: ");
    scanf("%d", &numStudents);
    studentId = studentInitializer(numStudents);
    printf("Students enrolled\n\n");

    printf("Please enter the number of courses offered: ");
    scanf("%d", &numCourses);
    courses = courseInitializer(numCourses);
    printf("Courses registered\n\n");

    regTable = startArray(numStudents, numCourses);



    while (option != 4) {
        printf("Please choose an option: \n");

        printf("1. Register a student in a course \n");
        printf("2. Drop a student from a course \n");
        printf("3. See registration table \n");
        printf("4. Exit program \n");
        printf("Please enter your choice: ");

        scanf("%d", &option);

		switch (option) {

		case 1:
			printf("You chose option 1: Register a student \n");
			printf("Enter the 5-digit student id: ");
			scanf("%d",&studentRegInput);
			studentRegIndex = intIterator(studentRegInput,studentId,numStudents);
			printf("\n");

			printf("Enter the 7-digit course id: \n");
			scanf("%s",courseRegInput);
			courseRegIndex = charIterator(courseRegInput,courses,numCourses);
			printf("id index %d",courseRegIndex);


			break;

		case 2:
			printf("You chose option 2: Drop a student \n");
			printf("Enter the 5-digit student id: \n");

			printf("Enter the 7-digit course id: \n");

			break;

		case 3:
			printf("You chose option 3: See registration table \n");

			printRegTable(studentId,courses,regTable,numCourses,numStudents);

			break;

		case 4:
			printf("You chose option 4: Exit program. Goodbye \n");
			break;

        }
    }
    return 0;
}
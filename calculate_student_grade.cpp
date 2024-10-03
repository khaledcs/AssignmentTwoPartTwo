/*
 *  File Name: calculate_student_grade.cpp
 *
 *  Created on: Oct 2, 2024
 *  Author: Md Khaled Hossain
 *  Description: This module provides the implementation for student grade calculation, student grade average,
 *  			student minimum score and maximum score calculation.
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

ifstream inData;//For read file information

int noOfStudent;//Store the global variable for the no of student
int noOfSubject; //Store the global variable for the no of subject

/*
 * Function Name: readNoOfStudentAndSubject
 * Purpose: This function is the interface returning the number of student and the number of subject
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Return: This function return No of Student and subject information
 * Side Effect: N/A
 */
void readNoOfStudentAndSubject()
{
	ifstream file("grade2.txt");  // Path to the uploaded file
	string line;
	//int sub[1];
	if (file.is_open())
	{
		// Reading the file line by line
	   file>>noOfStudent>>noOfSubject;
	   file.close();
		//cout << "No Student: " <<noOfStudent <<" No Of Subject: "<<noOfSubject<<endl;
	}
	else
	{
		std::cerr << "Unable to open the file" << std::endl;
	}
	file.close();
}

/*
 * Function Name: studentExamMarkingGrading
 * Purpose: This function used for returning the grade information according to the average score.
 * Parameter(s): This function entry parameter is the average exam score
 * Precondition(s): N/A
 * Returns: This function return the grade against the student average score.
 * Side Effect: N/A
 */
string studentExamMarkingGrading(double AverageScore,int examMark)
{
/*
 * Uses the average score for each exam to determine and display the student’s grade. If the
student’s score is within ±5 points of the average, assign a grade of C.
If the score is more than 5 points above or below the average, assign a grade of B or D, respectively.
If the score is more than 15 points above or below the average, assign a grade of A or F, respectively. We
assume the average upper bound to be 85.
 * */
	if (examMark>85)
		return "A";
	else if (examMark>AverageScore+15)
		return "A";
	else if (examMark<AverageScore-15)
		return "F";
	else if (examMark>AverageScore+5)
		return "B";
	else if (examMark>=AverageScore -5 && examMark<=AverageScore+5 )
		return "C";
	else if (examMark<AverageScore-5)
		return "D";
	else
		return "X";

}

/*
 * Function Name: studentExamMarking
 * Purpose: This function is the interface read the student result file and prepare the program output
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Return: This function return No of Student information
 * Side Effect: N/A
 */

void studentExamMarking(double averageScore[noOfSubject],int** arra)
{

	double average;
	double sumation;

	for (int sub=0;sub<noOfSubject;sub++)
	{
		sumation=0;
		for (int stu=0;stu<noOfStudent;stu++)
		{
			sumation=sumation+arra[stu][sub];
		}
		average=sumation/noOfStudent;
		averageScore[sub]=average;

	}

}

/*
 *examAverageScoreMarkingrageScoreMarking
 * Purpose: This function is the interface read the student result file and prepare the program output
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Return: This function return No of Student information
 * Side Effect: N/A
 */

void examAverageScoreMarking(double averageScore[noOfSubject],int** arra)
{
	double average;
	double sumation;


	for (int sub=0;sub<noOfSubject;sub++)
	{
		sumation=0;
		for (int stu=0;stu<noOfStudent;stu++)
		{
			sumation=sumation+arra[stu][sub];
		}
		average=sumation/noOfStudent;
		if (average>85)
			average=85;
		averageScore[sub]=average;
	}
}

/*
 * Function Name: prepareAndOutputResultFile
 * Purpose: This function is the interface read the student result file and prepare the program output
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Return: This function return No of Student information
 * Side Effect: N/A
 */
void prepareAndOutputResultFile()
{
	readNoOfStudentAndSubject();

	int iFirstData;
	int jSecondData;

	int studentResutlInfo[noOfStudent][noOfSubject+1];
	string studenResultInfoWithGrade[noOfStudent][noOfSubject*2];

	double examAverageScore[noOfSubject];

	inData.open("grade2.txt");
	inData>>iFirstData;
	inData>>jSecondData;

	// Allocate memory for the 2D array
	int** arr = new int*[noOfStudent];
	for (int i = 0; i < noOfStudent; ++i)
	{
		arr[i] = new int[noOfSubject];
	}

	// Initialize the array
	for (int i = 0; i < noOfSubject; ++i)
	{
		for (int j = 0; j < noOfSubject; ++j)
		{
			arr[i][j] = i * noOfSubject + j;
		}
	}

	// Allocate memory for the 2D array
	string** arrResult = new string*[noOfStudent];
	for (int i = 0; i < noOfStudent; ++i)
	{
		arrResult[i] = new string[noOfSubject];
	}

	// Initialize the array
	for (int i = 0; i < noOfSubject*2; ++i)
	{
		for (int j = 0; j < noOfSubject*2; ++j)
		{
			arrResult[i][j] = i * noOfSubject + j;
		}
	}

	for (int student=0; student<noOfStudent; student++)
	{
		for (int result=0; result<noOfSubject+1; result++)
		{
			inData>> studentResutlInfo[student][result];
			arr[student][result-1]=studentResutlInfo[student][result];
		}
	}

	inData.close();

	examAverageScoreMarking(examAverageScore,arr);

	ofstream MyFile;
	MyFile.open("StudentResultOutput2.txt");
	MyFile<<right<<setw(20)<<"Student ID";

	for(int product=0; product<noOfSubject;product++)
	{
		MyFile<<right<<setw(19)<<"Exam ID: "<<product+1<<setw(19)<<" Exam Grade: " <<product+1;
	}
	MyFile<<endl;

	string grade;
	int resultAdd=1;
	int resultGrade=2;
	for (int student=0; student<noOfStudent; student++)
	{
		resultAdd=1;
		resultGrade=2;
		for (int result=0; result<noOfSubject+1; result++)
		{
			if (result==0)
			{
				studenResultInfoWithGrade[student][result]=to_string(studentResutlInfo[student][result]);
				arrResult[student][result]=to_string(studentResutlInfo[student][result]);
				MyFile<<right<<setw(20)<<studenResultInfoWithGrade[student][result];
			}
			else
			{
				studenResultInfoWithGrade[student][resultAdd]=to_string(studentResutlInfo[student][result]);
				arrResult[student][resultAdd]=to_string(studentResutlInfo[student][result]);
				studenResultInfoWithGrade[student][resultGrade]=studentExamMarkingGrading(examAverageScore[result-1],studentResutlInfo[student][result]);
				arrResult[student][resultGrade]=studentExamMarkingGrading(examAverageScore[result-1],studentResutlInfo[student][result]);
				MyFile<<right<<setw(20)<<studenResultInfoWithGrade[student][resultAdd]<<right<<setw(20)<<studenResultInfoWithGrade[student][resultGrade];
				resultAdd=resultAdd+1;
				resultGrade=resultGrade+1;
			}
		}
		MyFile<<endl;
	}
	MyFile.close();
}

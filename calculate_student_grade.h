/*
 *  File Name: calculate_student_grade.h
 *
 *  Created on: Oct 2, 2024
 *  Author: Md Khaled Hossain
 *  Description: This module provides the interface for student grade calculation, student grade average,
 *  			student minimum score and maximum score calculation.
 *
 */

using namespace std;


/*
 * Function Name: calulcateGradeFromAverageNumber
 * Purpose: This function used for returning the grade information according to the average score.
 * Parameter(s): This function entry parameter is the average exam score
 * Precondition(s): N/A
 * Returns: This function return the grade against the student average score.
 * Side Effect: N/A
 */
string studentExamMarkingGrading(double AverageScore,int examMark);

/*
 * Function Name: studentExamMarking
 * Purpose: This function is the interface read the student result file and prepare the program output
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Return: This function return No of Student information
 * Side Effect: N/A
 */

void studentExamMarking(double averageScore[],int** arra);

/*
 * Function Name: readNoOfStudentAndSubject
 * Purpose: This function is the interface returning the number of student and the number of subject
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Return: This function return No of Student and subject information
 * Side Effect: N/A
 */
void readNoOfStudentAndSubject();

/*
 * Function Name: prepareAndOutputResultFile
 * Purpose: This function is the interface read the student result file and prepare the program output
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Return: This function return No of Student information
 * Side Effect: N/A
 */
void prepareAndOutputResultFile();




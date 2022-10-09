#ifndef SMS_FUN_H_INCLUDED
#define SMS_FUN_H_INCLUDED
#define DT uint32
typedef struct BirthDay
{
    DT day;
    DT month;
    DT year;
}B_D;
typedef struct PhoneNumber
{
    DT x;
    DT y;
    DT z;
}P_N;
typedef struct Student
{
    struct Student *next;
    uint8 s_name[50];
    DT ID;
    DT Score;
    P_N pho;
    B_D date;

}SN;
typedef struct S
{
    SN *top;
}S;
/********************************************************************************/
/********************************************************************************/
/*********************************** __BODY__ ***********************************/

void Main_Manu (void);
void Admin_Mode (void);
void Teacher_Mode (void);

/*****************************************************************************************/
/*****************************************************************************************/

/*********************** __ STUDENT__FUNCTIONS__ ****************************/
void Create_Student_List (S *ps);
void Add_Student (S *ps,DT ID);
void Delete_Student (S *ps,DT ID);
uint32 Display_student (S *ps,DT ID);
void Display_All_Students (S *ps);
void Edit_Student_Name(S *ps,DT ID);
void Edit_Student_DOT(S *ps,DT ID);
void Edit_Student_Pho(S *ps,DT ID);
void Display_student_score (S *ps,DT ID);
void Edit_Student_Score(S *ps,DT ID);
void Swap_Students_By_ID (S *ps);
void Swap_Students_By_Name (S *ps);
void Swap_Students_By_Score (S *ps);
/*******************************************/
/*void CreateHeap (S *ps);
void PushNode (S *ps , DT e);
void PopNode (S *ps , DT *pd);
DT HeapEmpty (S *ps);
DT HeapFull (S *ps);
void ClearHeap (S *ps);
uint32 NumberOfNodes(S *ps);
void DisplayCertainNode (S *ps, DT e);
void DeleteCertainNode (S *ps,DT e);
void DisplayAllNodes (S *ps);*/


#endif // SMS_FUN_H_INCLUDED

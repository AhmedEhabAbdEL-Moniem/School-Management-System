#include "STD_TYPES.h"
#include "SMS_FUN.h"
/****************************************************************************/
/****************************************************************************/
/*********************************** __BODY__ ***********************************/
void Main_Manu (void)
{
    printf("//************************/ __WELCOME TO SCHOOL MANAGEMENT SYSTEM__ /************************// \n");
    printf("        //*****************************/ __MAIN MANU__ /*****************************// \n");
    printf("Please select user.\n");
    printf("1) Admin mode.\n");
    printf("2) teacher mode.\n");
    printf("3) Exit.\n");
    printf("your Choice is :  ");
}
void Admin_Mode (void)
{
    printf("         //********************/ __Admin_mode__  /********************// \n");
    printf("Choose an operation\n");
    printf("1) Show students list.\n");
    printf("2) Add a new student.\n");
    printf("3) Delete student.\n");
    printf("4) Update student information.\n");
    printf("5) Exit admin mode.\n");
    printf("your Choice is :  ");

}
void Teacher_Mode (void)
{
    printf("         //********************/ __Teacher_mode__ /********************// \n");
    printf("Choose an operation\n");
    printf("1) Edit student score.\n");
    printf("2) Sort by score.\n");
    printf("3) Exit teacher mode.\n");
    printf("your Choice is :  ");

}

/****************************************************************************/
/****************************************************************************/

/*********************** __ STUDENT__FUNCTIONS__ ****************************/

void Create_Student_List (S *ps)
{
    ps->top = NULL;
}
/**********************************/
void Add_Student (S *ps,DT ID)
{
   SN *pn=(SN*)malloc(sizeof(SN));
   printf(" Enter The Student Name :");
   fflush(stdin);
   gets(pn->s_name);
   //scanf("%[^]s",pn->s_name);
   //printf("Enter Student ID :\n");
   //scanf("%d",&pn->ID);
   pn->ID=ID;
   printf("Enter Student Phone Number[xxx]xxxx xxxx\n");
   scanf("%d",&pn->pho.x);
   scanf("%d",&pn->pho.y);
   scanf("%d",&pn->pho.z);
   printf("Enter Student BirthDay\n");
   printf("Day : \n");
   scanf("%d",&pn->date.day);
   printf("Month : \n");
   scanf("%d",&pn->date.month);
   printf("Year : \n");
   scanf("%d",&pn->date.year);
   pn->Score=0;
   printf("Student Added Succesfully..........\n");
   printf("----------------------------------------------------------------------------------------- \n");
   printf("|  Name        |    ID     |         Date_Of_Birth     |    Score   |   Phone_Number     | \n");
   printf("|  %s          |    %d     |         %d / %d / %d      |     %d     |    [%d] %d %d      |  \n",pn->s_name,pn->ID,pn->date.day,pn->date.month,pn->date.year,pn->Score,pn->pho.x,pn->pho.y,pn->pho.z);
   printf("----------------------------------------------------------------------------------------- \n");
   pn->next=ps->top;
   ps->top=pn;
}
/**********************************/
void Delete_Student (S *ps,DT ID)
{
    SN *pn=ps->top;
    SN *ptemp1=NULL , *ptemp2 =NULL ;
    while (ID != pn->ID && pn->next!=NULL)
    {
        ptemp1 = pn;
        pn=ptemp1->next;
    }
    if (ID==pn->ID && pn==ps->top)
    {
        ps->top=pn->next;
        free(pn);
        printf("Student Deleted Successfully");
    }
    else if(ID==pn->ID)
    {
     ptemp2=pn->next;
     ptemp1=pn;
     ptemp1->next=ptemp2;
     free(pn);
     printf("Student Deleted Successfully");
    }
    else
    {
        printf("\n Invaled ID \n");
    }

}
/**********************************/
void Display_All_Students (S *ps)
{
  uint32 v=1;
  SN *pn=ps->top;
  printf("\n N     Name             ID          Score        Date_Of_Birth         Phone_Number      \n");
  while (pn)
  {
    printf(" %d   %s         %d         %d              %d/%d/%d            [%d] %d %d \n",v, pn->s_name,pn->ID,pn->Score,pn->date.day,pn->date.month,pn->date.year, pn->pho.x,pn->pho.y,pn->pho.z);
    pn=pn->next;
    v++;
  }
}
/***************************************/
uint32 Display_student (S *ps,DT ID )
{
    DT edit;
    SN *pn=ps->top;
    if(pn !=NULL)
    {

      while (ID != pn->ID && pn->next != NULL)
      {
          pn=pn->next;
      }
      if(ID==pn->ID)
      {
       printf("\n     Name             ID          Score        Date_Of_Birth         Phone_Number      \n");
       printf("   %s         %d         %d              %d/%d/%d            [%d] %d %d \n", pn->s_name,pn->ID,pn->Score,pn->date.day,pn->date.month,pn->date.year, pn->pho.x,pn->pho.y,pn->pho.z);

                     return edit=0;
    }
      else
      {
          printf("\n Invaled ID , Try Again \n");
          return edit=4;
      }
    }
    else
    {
          printf("\n Invaled ID , Try Again \n");
          return edit=4;
    }


}
/***************************************/
void Display_student_score (S *ps,DT ID)
{
    SN *pn=ps->top;;
    while (ID != pn->ID && pn->next!=NULL)
    {
        pn=pn->next;
    }
    if(ID==pn->ID)
    {
     printf("\nName             ID          Score\n");
     printf("%s                 %d           %d  \n", pn->s_name,pn->ID,pn->Score);
    }
    else
    {
        printf("\n Invaled ID \n");
    }

}
/*************************************************/
void Edit_Student_Name(S *ps,DT ID)
{
    SN *pn=ps->top;
    while (ID != pn->ID && pn->next!=NULL)
    {
        pn=pn->next;
    }
    if(ID==pn->ID)
    {
      printf(" Enter The Student Name :");
      fflush(stdin);
      gets(pn->s_name);
    }
}
/*************************************************/
void Edit_Student_DOT(S *ps,DT ID)
{
    SN *pn=ps->top;
    while (ID != pn->ID && pn->next!=NULL)
    {
        pn=pn->next;
    }
    if(ID==pn->ID)
    {
      printf("Enter Student BirthDay\n");
      printf("Day : \n");
      scanf("%d",&pn->date.day);
      printf("Month : \n");
      scanf("%d",&pn->date.month);
      printf("Year : \n");
      scanf("%d",&pn->date.year);
    }
}
/*************************************************/
void Edit_Student_Pho(S *ps,DT ID)
{
    SN *pn=ps->top;
    while (ID != pn->ID && pn->next!=NULL)
    {
        pn=pn->next;
    }
    if(ID==pn->ID)
    {
      printf("Enter Student Phone Number[xxx]xxxx xxxx\n");
      scanf("%d",&pn->pho.x);
      scanf("%d",&pn->pho.y);
      scanf("%d",&pn->pho.z);
    }
}
/*************************************************/
void Edit_Student_Score(S *ps,DT ID)
{
    SN *pn=ps->top;
    while (ID != pn->ID && pn->next!=NULL)
    {
        pn=pn->next;
    }
    if(ID==pn->ID)
    {
      printf("Enter Student Score\n");
      scanf("%d",&pn->Score);
    }
}
/**********************************************/
void Swap_Students_By_ID (S *ps)
{
   SN *Pend=NULL ,*PN=NULL,*CR=NULL,*NN=NULL,*Ptemp=NULL;
   while(Pend!=ps->top)
   //for(Pend=NULL;Pend!=ps->top;Pend=CR)
   {
       for(PN=CR=ps->top; CR->next!=Pend ; PN=CR,CR=CR->next)
       {
           NN=CR->next;
           if(CR->ID > NN->ID)
           {
               CR->next=NN->next;
               NN->next=CR;
               if(CR!=ps->top)
               {
                   PN->next=NN;
               }
               else
               {
                   ps->top=NN;
               }
               Ptemp=CR;
               CR=NN;
               NN=Ptemp;
           }
       }Pend=CR;
   }
}
/**********************************************/
void Swap_Students_By_Name (S *ps)
{
   SN *Pend=NULL ,*PN=NULL,*CR=NULL,*NN=NULL,*Ptemp=NULL;
   while(Pend!=ps->top)
  // for(Pend=NULL;Pend!=ps->top;Pend=CR)
   {
       for(PN=CR=ps->top; CR->next!=Pend ; PN=CR,CR=CR->next)
       {
           NN=CR->next;
           if(strcmp(CR->s_name , NN->s_name)>0)
           {
               CR->next=NN->next;
               NN->next=CR;
               if(CR!=ps->top)
               {
                   PN->next=NN;
               }
               else
               {
                   ps->top=NN;
               }
               Ptemp=CR;
               CR=NN;
               NN=Ptemp;
           }
       }
     Pend=CR;
   }
}
/************************************************/
void Swap_Students_By_Score (S *ps)
{
   SN *Pend=NULL ,*PN=NULL,*CR=NULL,*NN=NULL,*Ptemp=NULL;
   while(Pend!=ps->top)
  // for(Pend=NULL;Pend!=ps->top;Pend=CR)
   {
       for(PN=CR=ps->top; CR->next!=Pend ; PN=CR,CR=CR->next)
       {
           NN=CR->next;
           if(CR->Score < NN->Score)
           {
               CR->next=NN->next;
               NN->next=CR;
               if(CR!=ps->top)
               {
                   PN->next=NN;
               }
               else
               {
                   ps->top=NN;
               }
               Ptemp=CR;
               CR=NN;
               NN=Ptemp;
           }
       }Pend=CR;
   }
}
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/*
void CreateHeap (S *ps)
{
    ps->top = NULL;
}

void PushNode (S *ps , DT e)
{
   SN *pn=(SN*)malloc(sizeof(SN));
   pn->data=e;
   pn->next=ps->top;
   ps->top=pn;
}
void PopNode (S *ps , DT *pd)
{
   SN *pn;
   *pd=ps->top->data;
   pn=ps->top;
   ps->top=ps->top->next;
   free(pn);
}
DT HeapEmpty (S *ps)
{
   return ps->top==NULL;
}
DT HeapFull (S *ps)
{
    return 0;
}
void ClearHeap (S *ps)
{
    SN *pn=ps->top;
    while (pn)
    {
        pn=pn->next;
        free(ps->top);
        ps->top=pn;

    }
}
uint32 HeapSize (S *ps)
{
    uint32 x;
    SN *pn = ps->top;
    for(x=0;pn;x++)
    {
        pn=pn->next;
        return x ;
    }
}
uint32 NumberOfNodes(S *ps)
{
    SN *pn=ps->top;
    uint32 x=0;
    while (pn)
    {
        x++;
        pn=pn->next;
    }
    return x;
}
void DisplayCertainNode (S *ps, DT e)
{
    SN *pn=ps->top;
    while (e != pn->data)
    {
        pn=pn->next;
    }
    printf("\n%d",pn->data);
}
void DeleteCertainNode (S *ps,DT e)
{
    SN *pn=ps->top;
    SN *ptemp1 , *ptemp2 ;
    while (e != pn->data)
    {
        ptemp1 = pn;
        pn=ptemp1->next;
    }
    ptemp2=pn->next;
    ptemp1->next=ptemp2;
    free(pn);
}
void DisplayAllNodes (S *ps)
{
    SN *pn=ps->top;
    while (pn)
    {
        printf("\n%d", pn->data);
        pn=pn->next;
    }
}*/

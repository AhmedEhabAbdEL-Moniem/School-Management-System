/***************************School_management_system**********************************/
/*
        Auther  : AHmed Ehab Abd El-Moniem
        Date    : 31/5/2022
        Project : School Management System
*/
/*************************************************************************************/
#include "STD_TYPES.h"
#include "SMS_FUN.h"
int main(void)
{
    DT Exit_Flag=1,x=1,y=1,a=0,e=0,edit;
    S s;
    DT ID=202201,ID_delete=0,ID_edit=0 ;
    Create_Student_List (&s);
    while (Exit_Flag!=3)
    {
        edit=1;
       Main_Manu();
       scanf("%d",&Exit_Flag);
       switch (Exit_Flag)
       {
        case 1 :
           while(x!=5)
           {
             Admin_Mode();
             scanf("%d",&x);
             switch (x)
             {
              case 1 :
                  if (s.top!=NULL)
                  {
                    printf("1) Sorting By Name. \n");
                    printf("2) Sorting By ID. \n");
                    scanf("%d",&a);
                    switch (a)
                    {
                     case 1 :
                         Swap_Students_By_Name(&s);
                         Display_All_Students(&s);
                         break;
                     case 2 :
                         Swap_Students_By_ID (&s);
                         Display_All_Students(&s);
                         break;
                    }
                  }
                  else
                  {
                      printf("There Is No Students Added yet\n");
                  }
                  break;

              case 2 :
                   Add_Student (&s,ID);
                   ID++;
                   break;
              case 3 :
                  printf("Enter The Student ID :\n");
                  scanf("%d",&ID_delete);
                  Delete_Student(&s,ID_delete);
                  break;
              case 4 :
                    printf("Enter The Student ID\n");
                    scanf("%d",&ID_edit);
                    edit = Display_student(&s,ID_edit);
                    while(edit!=4)
                    {
                      printf("\nChoose Operation\n");
                      printf("1) Edit Name.\n");
                      printf("2) Edit Date OF Birth. \n");
                      printf("3) Edit Phone number. \n");
                      printf("4) Exit  \n");
                      printf("your Choice is: ");
                      scanf("%d",&e);
                      switch(e)
                      {
                       case 1 :
                           Edit_Student_Name(&s,ID_edit);
                           printf("\nStudent Edited sucsessfully\n");
                           break;
                       case 2 :
                           Edit_Student_DOT(&s,ID_edit);
                           printf("\nStudent Edited sucsessfully\n");
                           break;
                       case 3 :
                           Edit_Student_Pho(&s,ID_edit);
                           printf("\nStudent Edited sucsessfully\n");
                           break;
                       case 4 :
                           printf("\nExiting Editing ......\n");
                           edit=4;
                           break;
                       default :
                           printf("\n invalid input try again\n");
                           break;
                      }
                    }
                    printf("\n Go_Back\n");

                  break;
              case 5 :
                printf("exiting admin mode ......\n");
                break;
              default :
                printf("invalid input try again\n");
                break;
             }
           }
            x=1;
            break;
         case 2 :
            while(y!=3)
            {
                Teacher_Mode();
                scanf("%d",&y);
                switch(y)
                {
                 case 1 :
                    printf("Enter The Student ID\n");
                    scanf("%d\n",&ID_edit);
                    Display_student_score (&s,ID_edit);
                    Edit_Student_Score(&s,ID_edit);
                    printf("Student Edited sucsessfully");
                    Display_student_score (&s,ID_edit);
                     break;
                 case 2 :
                     Swap_Students_By_Score (&s);
                     Display_All_Students(&s);
                     break;
                 case 3 :
                   printf("exiting teacher mode ......\n");
                   break;
                 default :
                   printf("invalid input try again\n");
                   break;
                }
            }
              y=1;
              break;
       }
    }
    return 0;

}

#include <stdio.h>
#include <string.h>

struct sdata
{
    long long id, Phone, Alternate;
    char name[10],position[10], Email[20],filename[15];
    
};

int main(){
    int x, y, a, b, opt, choice, attempts = 0;
    char  filename[20],  u[30], p[20], username[30], password[20], password2[20], email[50];

    FILE *data;

    printf("\n\t 1. Sign Up\n\t 2. Log In");
    printf("\n\t Choose an option: ");
    scanf("%d", &opt);
    fgetc(stdin);

    switch(opt){
        case 1:{
            struct sdata usr;
            printf("\n\t\t\t\tREGISTER HERE");

            data = fopen("username.txt", "a+");
            printf("\n\t Enter Your Name: ");
            scanf("%s", &username);
            fflush(stdin);
            fprintf(data, "\n\t Username: %s", username);

            printf("\n\t Enter email: ");
            scanf("%d", &email);
            fflush(stdin);

            printf("\n\t Enter a password: ");
            scanf("%s", &password);
            fflush(stdin);
            fprintf(data, "\n\t Password: %s", password);
            fclose(data);

            printf("\n\t Confirm password: ");
            scanf("%s", &password2);
            fflush(stdin);

            if(strcmp(password,password2) == 0){
                printf("\n\t Successfully registered, Your username is: %s, Please run again to log in.", username);
            }else{
                printf("\n\t Please enter password again.");
            }
            break;
        }

        case 2:{
            printf("\n\t\t\t\t LOG IN HERE");

            do{
                attempts++;

                data = fopen("username.txt", "a+");
                data = fopen("username.txt", "r");
                printf("\n\n\t Enter username: ");
                scanf("%s", u);
                fprintf(data, "%s", u);
                printf("\n\n\t Enter password: ");
                scanf("%s", p);
                fprintf(data, "%s", p);

                
                a = strcmp(u, username);
                b = strcmp(p, password);
                fclose(data);
                fclose(data);

                if (a != 0 && b != 0){
                    printf("\n\t\t\t\t WELCOME, %s\n", u);

                    do{
                        printf("\n\t 1. Add New Employee");  
                        printf("\n\t 2. View All Employee ID");
                        printf("\n\t 3. Search Employee Details");
                        printf("\n\t 4. Logout");
                        printf("\n\t --------------------------");
                        printf("\n\t Choose an option: ");
                        scanf("%d", &choice);

                        switch (choice){
                        case 1:{
                            struct sdata a;

                            printf("\n\t\t\t\tAdd new Employee Data");
                            printf("\n\t\t\t\t---------------------");

                            printf("\n\t Enter ID: ");
                            scanf("%lld", &a.id);
                            fflush(stdin);

                            printf("\n\t Enter name: ");
                            scanf(" %s", a.name);
                            fflush(stdin);

                            printf("\n\t Enter Position: ");
                            scanf("%s", &a.position);
                            fflush(stdin);

                            printf("\n\t Enter Email: ");
                            scanf("%s", &a.Email);
                            fflush(stdin);

                            printf("\n\t Enter Phone: ");
                            scanf("%lld", &a.Phone);
                            fflush(stdin);

                            printf("\n\t Enter Alternate Phone: ");
                            scanf("%lld", &a.Alternate);
                            fflush(stdin);

                            sprintf(filename,"%lld.txt",a.id);

                            FILE *data;
                            data = fopen(filename, "w");

                            fprintf(data, "\n\t EMPLOYEE DATA  \n");
                            fprintf(data, "\n\t Enter ID: %lld", a.id);
                            fprintf(data, "\n\t Name: %s", a.name);
                            fprintf(data, "\n\t Enter Position: %s", a.position);
                            fprintf(data, "\n\t Enter Email: %s", a.Email);
                            fprintf(data, "\n\t Enter Phone: %lld", a.Phone);
                            fprintf(data, "\n\t Enter Alternate Phone: %lld\n", a.Alternate);

                            fclose(data);

                            printf("\n\t\t\t\tData Saved Successfully.\n");
                            data=fopen("database.txt","a");
                            fprintf(data,"%lld \n",a.id);
                            fclose(data);

                            break;
                        }
                        case 2:
                            printf("\n");
                            FILE *data;

                            char ch;

                            if(data = fopen("database.txt","r")){
                                do{
                                    ch = fgetc(data);
                                    printf("%c",ch);
                                }
                                while(ch != EOF);

                                fclose(data);
                            }
                            else
                                printf("\n\t File does not exist \n");
                            break;
                        case 3:
                            printf("\n\t Enter employee id: ");
                            scanf("%s",filename);
                            strcat(filename,".txt");

                            if(data = fopen(filename,"r")){
                                do{
                                    ch = fgetc(data);
                                    printf("%c",ch);
                                }
                                while(ch != EOF);

                                fclose(data);
                            }
                            else
                                printf("\n\t File does not exist \n");

                                break;
                            case 4:
                                printf("\n\t\t\t\tTHANK YOU.");
                                break;

                            default:
                                printf("\n\t Invalid option. Please choose again.\n");
                                break;
                        }
                    } while (choice != 4);
                    break;
                }else{
                    printf("\n\t Login Failed. Attempts remaining: %d\n", 3 - attempts);
                    if (attempts == 3){
                        printf("\n\t You've exceeded the maximum number of attempts. Login failed.\n");
                        break;
                    }
                }
            } while (attempts < 3);
        }
    }
    return 0;
}
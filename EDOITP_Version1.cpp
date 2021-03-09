#include <iostream>
#include <list>
#include <string>
#include <iterator>


using namespace std;

struct  EPIC_
{
    string name[4];
    int value[10][10];
    int ideal_value[10][10];

};

int hammingDist(int str1[10][10], int str2[10][10],int nr_tasks, int idx)
{
    int i = 1, count = 0;
    while(i <= nr_tasks)
    {
        if (str1[idx][i] != str2[idx][i])
            count++;
        i++;
    }
    return count;
}

class GET
{
public:
    virtual string getUsername()=0;
    virtual string getPassword()=0;
    virtual string getFirstName()=0;
    virtual string getLastName()=0;
    virtual int getProject_ID()=0;
    virtual int getUser_ID()=0;
};


class Setup_User: public GET
{
private:
    string Username;
    string Password;
    string LastName;
    string FirstName;
    int Nr_of_projects;
    int project_ID,user_ID; //identificarea echipei dupa ID-user_ID e un numar de la 1 la 6 in functie de pozitia in echipa
public:

    Setup_User(string fname, string lname, string username, string password,int pproject_ID,int uuser_ID)
    {
        this->Username = username;
        this->Password = password;
        this->FirstName = fname;
        this->LastName = lname;
        this->project_ID=pproject_ID;
        this->user_ID=uuser_ID;
    }


    string getUsername()
    {
        return this->Username;
    }
    string getPassword()
    {
        return this->Password;
    }
    string getFirstName()
    {
        return this->FirstName;
    }
    string getLastName()
    {
        return this->LastName;
    }
    int getProject_ID()
    {
        return this->user_ID;
    }
    int getUser_ID()
    {
        return this->project_ID;
    }

    ~Setup_User() {}

};

class Analysis
{
public:
    string output_indicator[20]; // masoara rezltatele proiectului
    string result_indicator[20]; //masoara indeplinirea scopului proiectului

    float start_value[20];

    float end_ideal_value_out[20];
    float end_ideal_value_res[20];

    float end_value_out[20];
    float end_value_res[20];
};

class Epic
{
public:
    EPIC_ epic;
    int i,j;
    Epic()
    {
        for(i = 1; i <=6; i++)
        {
            for(j=1; j<=5; j++)
            {
                epic.ideal_value[i][j]=1;
                epic.value[i][j]=0;
            }
        }

        //Setam numele pt fiecare task;
        epic.name[0] = "Stabilirea agendei de lucru";
        epic.name[1] = "Research";
        epic.name[2] = "Programare";
        epic.name[3] = "Testare";
    }

    void User_Story()
    {
        for(int i = 0; i < 4; i++)
        {
            cout<<epic.name[i]<<endl;

        }
    }
};


class Project: public Analysis
{
public:
    string nameProject;
    string start_date,deadline;
    string task_manager[10],task_researcher[10],task_pro1[10],task_pro2[10],task_test1[10],task_test2[10];
    string efficiency[10][10]; //vector de comentarii
    float status[4],weekly_stage_status[4],weekly_status[4];
    Project()
    {
        start_date="01/01/2021";
        deadline="31/01/2021";
        nameProject="proiectel";

        for(int i=1; i<=16; i++)
        {
            start_value[i]=0;
            end_value_res[i]=0;
            end_value_out[i]=0;
        }
        output_indicator[1]="Nr participanti la Sedinta 1 de proiect";//
        end_ideal_value_out[1]=6;
        output_indicator[2]="Nr participant Sedinta 2 de proiect";//
        end_ideal_value_out[2]=6;
        output_indicator[3]="Nr participanti Sedinta 3 de proiect";//
        end_ideal_value_out[3]=6;
        output_indicator[4]="Nr ore pentru Sesiunea 1 de instruire";//
        end_ideal_value_out[4]=4;
        output_indicator[5]="Nr ore pentru Sesiunea 2 de instruire";//
        end_ideal_value_out[5]=6;
        output_indicator[6]="Nr ore pentru Sesiunea 3 de instruire";//
        end_ideal_value_out[6]=4;
        output_indicator[7]="Nr total task-uri";//
        end_ideal_value_out[7]=30;
        output_indicator[8]="Stabilirea unui buget";//
        end_ideal_value_out[8]=1000;
        output_indicator[9]="Abordarea mai multor strategii";//
        end_ideal_value_out[9]=3;
        output_indicator[10]="Realizarea unei agende de lucru";//
        end_ideal_value_out[10]=1;
        output_indicator[11]="Realizarea implementarii";
        end_ideal_value_out[11]=1;
        output_indicator[12]="Realizarea testarii"; //
        end_ideal_value_out[12]=1;

        result_indicator[1]="Realizarea unui Roadmap"; //
        end_ideal_value_res[1]=1;
        result_indicator[2]="Indeplinirea Etapelor";//
        end_ideal_value_res[2]=4;
        result_indicator[3]="Punctualitate"; //avand in vedere ca sunt 6 oameni si 4 saptamani ne asumam ca a fi punctual inseamna a avea cate 4 pct fiecare pt fiecare saptamana deci ieal ar trebui sa avem 24de pct
        end_ideal_value_res[3]=24;
        result_indicator[4]="Eficienta"; //
        end_ideal_value_res[4]=24;


        task_manager[1]="Intocmirea agendei de lucru";
        task_manager[2]="Organizarea de sedinte";
        task_manager[3]="Supervizarea tuturor activitatilor";
        task_manager[4]="Impartirea rolurilor";
        task_manager[5]="Identificarea cerintelor clientilor";

        task_researcher[1]="Colectare date";
        task_researcher[2]="Organizare date";
        task_researcher[3]="Redactarea unei documentatii";
        task_researcher[4]="Analiza SWOT a aplicatiei";
        task_researcher[5]="Cercetare de oportunitati noi";


        task_pro1[1]="Stabilirea scheletului programului";
        task_pro1[2]="Gasirea celor mai eficienti algoritmi";
        task_pro1[3]="Programare partea personalizata de cod";
        task_pro1[4]="Inventarierea conceptelor teoretice";
        task_pro1[5]="Corelarea cu documentatia";

        task_pro2[1]="Stabilirea scheletului programului";
        task_pro2[2]="Gasirea celor mai eficienti algoritmi";
        task_pro2[3]="Programare partea personalizata de cod";
        task_pro2[4]="Inventarierea conceptelor teoretice";
        task_pro2[5]="Corelarea cu documentatia";

        task_test1[1]="Intelegerea codului";
        task_test1[2]="Analizat performanta si eficienta codului";
        task_test1[3]="Testare cod";
        task_test1[4]="Rezolvare bug-uri";
        task_test1[5]="Adaugiri";

        task_test2[1]="Intelegerea codului";
        task_test2[2]="Analizat performanta si eficienta codului";
        task_test2[3]="Testare cod";
        task_test2[4]="Rezolvare bug-uri";
        task_test2[5]="Adaugiri";

    }
    void addProgress(int idx, Epic e)
    {
        float val;
        float dist[4];
        int day;
        int i,j;
        int s=100;
        status[idx]=0;
        int contor;

        string msg;

        for(i=1; i<=4; i++)
        {
            weekly_status[i]=0;
            dist[i]=0;
                cout<<"---Week "<<i<<"---"<<endl;
                cout<<"Doriti sa efectuati o activitate saptamana aceasta? Da/Nu ";
                cin>>msg;
                if(msg=="Da")
                {
                    contor=0;
                    cout<<"\t"<<". . .[ORE DE LUCRU] . . ."<<endl;
                    for(int k=1; k<=5; k++)
                    {
                        if(e.epic.value[idx][k]==1)
                        {
                            cout<<"[Task"<<k<<" complet!]"<<endl;


                        }
                        else
                        {
                            cout<<"[Task"<<k<<"...in progress]      Adauga coeficientul de lucru: "<<endl; //1 complet  sau 0 necompletat
                            cin>>val;
                            e.epic.value[idx][k]=val;
                            if(val==1)
                            {
                                contor++;
                                end_value_out[7]++; //task
                            }

                        }
                        weekly_status[i]=contor*100/5;
                    }
                    dist[i]=hammingDist(e.epic.value,e.epic.ideal_value,5,idx);

                    weekly_stage_status[i]=100*(1-(dist[i]/5));

                    status[idx]=weekly_status[1]+weekly_status[2]+weekly_status[3]+weekly_status[4];

                    cout<<"    Ziua la care s-au incheiat activitatile:"<<endl;
                    cout<<"Interval ideal: ";
                    if(i==1)
                        cout<<"01.01-08.01 ";
                    if(i==2)
                        cout<<"08.01-15.01 ";
                    if(i==3)
                        cout<<"15.01-22.01 ";
                    if(i==4)
                        cout<<"22.01-31.01 ";
                    cin>>day;
                    if(((i==1)&&(day<=8)&&(1<=day))||((i==2)&&(day<=15)&&(8<day))||((i==3)&&(day<=22)&&(15<day))||((i==4)&&(day<=31)&&(22<day)))
                    {
                        cout<<"+Felicitari! Ai terminat treaba la timp!"<<endl;
                        end_value_res[3]++; //punctualitate
                        cout<<"     Indicatorul de punctualitate: "<<end_value_res[3]<<endl;
                        cout<<"Statusul etapei in saptamana "<<i<<": "<<weekly_stage_status[i]<<"%"<<endl;
                    }
                    else
                    {
                        cout<<"*Se pare ca activitatile programate pentru saptamana nu au fost terminate in timpul estimat"<<endl;
                        cout<<"Statusul etapei in saptamana "<<i<<": "<<weekly_stage_status[i]<<"%"<<endl;
                    }

                }
                else
                {
                    cout<<"[Warning] Eficienta Task-ului a scazut--> Cauza: saptamana aceasta nu s-a lucrat --> flux discontinuu de lucru";
                    s=s-(100/24);
                    cout<<"Indicatorul de eficienta: "<<s<<"%"<<endl;
                    end_value_res[4]=end_value_res[4]+1; //eficienta

                }
            }
        if(status[idx]==100)
        {
            if(idx==1||idx==2)
                end_value_res[2]++; //realizarea etapelor
            else
                end_value_res[2]=end_value_res[2]+0.5;
        }


    }


};

int verify_login(string u1, string u2,string p1, string p2) //functie de verificare a login-ului
{
    int idx2;
    try
    {
        idx2=0;
        while((u1!=u2)||(p1!=p2))
        {
            throw "     User sau parola incorecte! Incearca din nou!";
        }

    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
        idx2=-1;
        return idx2;
    }


}

void SELECT(list<Setup_User>&users, Project P, Epic epic) //functie pentru creearea meniului
{
    int nr1=-1,nr2=-1,nr3=-1,nr4=-1,nr5=-1,nr6=-1,numar,nr=-1;
    float status_proiect=0,status34=0,status56=0;
    string Fname,Lname,uname,password;
    cout<<"Project ID: "<<100<<endl;
    cout<<"Add MANAGER's account: \n";
    cout<<"First name: ";
    cin>>Fname;
    cout<<"Last name: ";
    cin>>Lname;
    cout<<"Username: ";
    cin>>uname;
    cout<<"Password: ";
    cin>>password;
    Setup_User u1(Fname,Lname,uname,password,100,1);
    users.push_back(u1);

    cout<<"Add RESEARCHER's account: \n";
    cout<<"First name: ";
    cin>>Fname;
    cout<<"Last name: ";
    cin>>Lname;
    cout<<"Username: ";
    cin>>uname;
    cout<<"Password: ";
    cin>>password;
    Setup_User u2(Fname,Lname,uname,password,100,2);
    users.push_back(u2);

    cout<<"Add first PROGRAMMER's account: \n";
    cout<<"First name: ";
    cin>>Fname;
    cout<<"Last name: ";
    cin>>Lname;
    cout<<"Username: ";
    cin>>uname;
    cout<<"Password: ";
    cin>>password;
    Setup_User u3(Fname,Lname,uname,password,100,3);
    users.push_back(u3);

    cout<<"Add second PROGRAMMER's account: \n";
    cout<<"First name: ";
    cin>>Fname;
    cout<<"Last name: ";
    cin>>Lname;
    cout<<"Username: ";
    cin>>uname;
    cout<<"Password: ";
    cin>>password;
    Setup_User u4(Fname,Lname,uname,password,100,4);
    users.push_back(u4);

    cout<<"Add first TESTER's account: \n";
    cout<<"First name: ";
    cin>>Fname;
    cout<<"Last name: ";
    cin>>Lname;
    cout<<"Username: ";
    cin>>uname;
    cout<<"Password: ";
    cin>>password;
    Setup_User u5(Fname,Lname,uname,password,100,5);
    users.push_back(u5);

    cout<<"Add second TESTER's account: \n";
    cout<<"First name: ";
    cin>>Fname;
    cout<<"Last name: ";
    cin>>Lname;
    cout<<"Username: ";
    cin>>uname;
    cout<<"Password: ";
    cin>>password;
    Setup_User u6(Fname,Lname,uname,password,100,6);
    users.push_back(u6);

    while(nr!=0)
    {
        cout<<"Ipostazele disponibile"<<endl<<"     1.MANAGER"<<endl<<"     2.RESEARCH"<<endl<<"     3.PROGRAMMER1"<<endl<<"     4.PROGRAMMER2"<<endl<<"     5.TESTER1"<<endl<<"     6.TESTER2"<<endl<<"     7.Vizualizare indicatori"<<endl<<"     0.IESIRE"<<endl;
        cout<<"Alege numarul corespunzator ipostazei in care doresti sa te afli: ";
        cin>>nr;
        if(nr==1)
        {
            string username_testare,password_testare;
            // Setup_User u1("Maria","Popescu","popescu.maria","maria123",100,1);
            cout<<"(se executa actiuni in ipostaza de MANAGER)"<<endl;
            do
            {
                // users.push_back(u1);
                //user.login();
                cout<<"--Autentificare--"<<endl;
                cout<<"Username: ";
                cin>>username_testare;
                cout<<"Password: ";
                cin>>password_testare;
            }
            while(verify_login(u1.getUsername(),username_testare,u1.getPassword(),password_testare)==-1);

            cout<<"Autentificare facuta cu succes!"<<endl;
            while(nr1!=0)
            {
                cout<<"Alegeti o actiune: "<<endl;
                cout<<"     1.Vizualizare Task-uri"<<endl<<"     2.Adaugare progres"<<endl<<"     3.Vizualizare status personal"<<endl<<"     4.Vizualizare status proiect"<<endl<<"     5.Meeting"<<endl<<"     6.Sesiune de instruire"<<endl<<"     0.Iesire"<<endl;
                cin>>nr1;
                if(nr1==1)
                {
                    int i;
                    for(i=1; i<=5; i++)
                    {
                        cout<<P.task_manager[i]<<endl;
                    }

                }
                if(nr1==2)
                {
                    P.addProgress(nr,epic);
                }
                if(nr1==3)
                {
                    for(int i=1; i<=4; i++)
                    {
                        cout<<"Status saptamana"<<i<<":"<<P.weekly_status[i]<<"%"<<endl;
                    }
                    cout<<"Status etapa de["<<epic.epic.name[0]<<"]-->"<<P.status[nr]<<"%"<<endl;
                    cout<<"Valoarea indicatorului de realizare al etapelor: "<<P.end_value_res[2]<<endl;
                    if(P.end_value_res[2]==1)
                        P.end_value_out[10]=1;
                    status_proiect=status_proiect+P.status[nr]/4;
                    cout<<"Status proiect:"<<status_proiect<<"%"<<endl;
                }
                if(nr1==4)
                {
                    cout<<"Status proiect: "<<status_proiect<<"%"<<endl;
                }
                if(nr1==5)
                {
                    cout<<"[MEETING]"<<endl<<endl;
                    int nr_pers,nr_strategii;
                    float buget;
                    for(int i=1; i<=3; i++)
                    {
                        cout<<"Sedinta"<<i<<endl<<"Cate persoane au participat la sedinta?"<<endl;
                        cin>>nr_pers;
                        P.end_value_out[i]=nr_pers;
                    }
                    cout<<"Roadmap:"<<endl;
                    epic.User_Story();
                    P.end_value_res[1]=1;
                    cout<<"Bugetul folosit: "<<endl;
                    cin>>buget;
                    P.end_value_out[8]=buget;


                }
                if(nr1==6)
                {
                    cout<<"[WORKSHOP]"<<endl<<endl;
                    int nr_ore,nr_strategii;
                    for(int i=4; i<=6; i++)
                    {
                        cout<<"Cate ore au fost alocate Sesiunii "<<i-3<<" de instruire?"<<endl;
                        cin>>nr_ore;
                        P.end_value_out[i]=nr_ore;
                    }
                    cout<<"Cate strategii s-au abordat in realizarea proiectului?"<<endl;
                    cin>>nr_strategii;
                    P.end_value_out[9]=nr_strategii;
                }
            }
            nr1--;

        }
        if(nr==2)
        {
            string username_testare,password_testare;
            // Setup_User u2("Elena","Radu","elena_radu22","alabala00",100,2);
            cout<<"(se executa actiuni in ipostaza de RESEARCHER)"<<endl;
            do
            {
                // users.push_back(u2);
                //user.login();
                cout<<"--Autentificare--"<<endl;
                cout<<"Username: ";
                cin>>username_testare;
                cout<<"Password: ";
                cin>>password_testare;
            }
            while(verify_login(u2.getUsername(),username_testare,u2.getPassword(),password_testare)==-1);

            cout<<"Autentificare facuta cu succes!"<<endl;
            while(nr2!=0)
            {
                cout<<"Actiuni disponibile: "<<endl;
                cout<<"     1.Vizualizare Task-uri"<<endl<<"     2.Adaugare progres"<<endl<<"     3.Vizualizare status"<<endl<<"     0.Iesire"<<endl;
                cin>>nr2;
                if(nr2==1)
                {
                    int i;
                    for(i=1; i<=5; i++)
                    {
                        cout<<P.task_researcher[i]<<endl;
                    }
                }
                if(nr2==2)
                {
                    P.addProgress(nr,epic);
                }
                if(nr2==3)
                {
                    for(int i=1; i<=4; i++)
                    {
                        cout<<"Status saptamana"<<i<<":"<<P.weekly_status[i]<<"%"<<endl;
                    }
                    cout<<"Status etapa de["<<epic.epic.name[1]<<"]-->"<<P.status[nr]<<"%"<<endl;
                    cout<<"Valoarea indicatorului de realizare al etapelor: "<<P.end_value_res[2]<<endl;
                    status_proiect=status_proiect+P.status[nr]/4;
                    cout<<"Status proiect:"<<status_proiect<<"%"<<endl;
                }

            }
            nr2--;
        }
        if(nr==3)
        {
            string username_testare,password_testare;
            // Setup_User u3("Larisa","Stefania","larisa_stefania","ana.are.mere",100,3);
            cout<<"(se executa actiuni in ipostaza de PROGRAMMER1)"<<endl;
            do
            {
                // users.push_back(u3);
                //user.login();
                cout<<"--Autentificare--"<<endl;
                cout<<"Username: ";
                cin>>username_testare;
                cout<<"Password: ";
                cin>>password_testare;
            }
            while(verify_login(u3.getUsername(),username_testare,u3.getPassword(),password_testare)==-1);

            cout<<"Autentificare facuta cu succes!"<<endl;
            while(nr3!=0)
            {
                cout<<"Actiuni disponibila: "<<endl;
                cout<<"     1.Vizualizare Task-uri"<<endl<<"     2.Adaugare progres"<<endl<<"     3.Vizualizare status"<<endl<<"     0.Iesire"<<endl;
                cin>>nr3;
                if(nr3==1)
                {
                    int i;
                    for(i=1; i<=5; i++)
                    {
                        cout<<P.task_pro1[i]<<endl;
                    }
                }
                if(nr3==2)
                {
                    P.addProgress(nr,epic);
                }
                if(nr3==3)
                {
                    for(int i=1; i<=4; i++)
                    {
                        cout<<"Status saptamana"<<i<<":"<<P.weekly_status[i]<<"%"<<endl;
                    }
                    cout<<"Status etapa de["<<epic.epic.name[2]<<"][PART1]-->"<<P.status[nr]<<"%"<<endl;
                    status34=status34+P.status[nr]/2;
                    cout<<"Status etapa de["<<epic.epic.name[2]<<"]-->"<<status34<<"%"<<endl;
                    cout<<"Valoarea indicatorului de realizare al etapelor: "<<P.end_value_res[2]<<endl;
                    status_proiect=status_proiect+P.status[nr]/8;
                    cout<<"Status proiect:"<<status_proiect<<"%"<<endl;
                }
            }
            nr3--;
        }
        if(nr==4)
        {
            string username_testare,password_testare;
            // Setup_User u4("Bianca", "Maria","bianca.maria","123sdse",100,4);
            cout<<"(se executa actiuni in ipostaza de PROGRAMMER2)"<<endl;
            do
            {
                //users.push_back(u4);
                //user.login();
                cout<<"--Autentificare--"<<endl;
                cout<<"Username: ";
                cin>>username_testare;
                cout<<"Password: ";
                cin>>password_testare;
            }
            while(verify_login(u4.getUsername(),username_testare,u4.getPassword(),password_testare)==-1);

            cout<<"Autentificare facuta cu succes!"<<endl;
            while(nr4!=0)
            {
                cout<<"Actiuni disponibile: "<<endl;
                cout<<"     1.Vizualizare Task-uri"<<endl<<"     2.Adaugare progres"<<endl<<"     3.Vizualizare status"<<endl<<"     0.Iesire"<<endl;
                cin>>nr4;
                if(nr4==1)
                {
                    int i;
                    for(i=1; i<=5; i++)
                    {
                        cout<<P.task_pro2[i]<<endl;
                    }
                }
                if(nr4==2)
                {
                    P.addProgress(nr,epic);
                }
                if(nr4==3)
                {
                    for(int i=1; i<=4; i++)
                    {
                        cout<<"Status saptamana"<<i<<":"<<P.weekly_status[i]<<"%"<<endl;
                    }
                    cout<<"Status etapa de["<<epic.epic.name[2]<<"][PART2]-->"<<P.status[nr]<<"%"<<endl;
                    status34=status34+P.status[nr]/2;
                    cout<<"Status etapa de["<<epic.epic.name[2]<<"]-->"<<status34<<"%"<<endl;
                    cout<<"Valoarea indicatorului de realizare al etapelor: "<<P.end_value_res[2]<<endl;
                    status_proiect=status_proiect+P.status[nr]/8;
                    cout<<"Status proiect:"<<status_proiect<<"%"<<endl;
                }
            }
            nr4--;
        }
        if(nr==5)
        {
            string username_testare,password_testare;
            //Setup_User u5("Teodora","Ioana","teodora_ioana","parolaaaa123",100,5);
            cout<<"(se executa actiuni in ipostaza de TESTER1)"<<endl;
            do
            {
                //users.push_back(u5);
                //user.login();
                cout<<"--Autentificare--"<<endl;
                cout<<"Username: ";
                cin>>username_testare;
                cout<<"Password: ";
                cin>>password_testare;
            }
            while(verify_login(u5.getUsername(),username_testare,u5.getPassword(),password_testare)==-1);

            cout<<"Autentificare facuta cu succes!"<<endl;
            while(nr5!=0)
            {
                cout<<"Actiuni disponibila: "<<endl;
                cout<<"     1.Vizualizare Task-uri"<<endl<<"     2.Adaugare progres"<<endl<<"     3.Vizualizare status"<<endl<<"     0.Iesire"<<endl;
                cin>>nr5;
                if(nr5==1)
                {
                    int i;
                    for(i=1; i<=5; i++)
                    {
                        cout<<P.task_test1[i]<<endl;
                    }
                }
                if(nr5==2)
                {
                    P.addProgress(nr,epic);
                }
                if(nr5==3)
                {
                    for(int i=1; i<=4; i++)
                    {
                        cout<<"Status saptamana"<<i<<":"<<P.weekly_status[i]<<"%"<<endl;
                    }
                    cout<<"Status etapa de["<<epic.epic.name[3]<<"][PART1]-->"<<P.status[nr]<<"%"<<endl;
                    status56=status56+P.status[nr]/2;
                    cout<<"Status etapa de["<<epic.epic.name[3]<<"]-->"<<status56<<"%"<<endl;
                    cout<<"Valoarea indicatorului de realizare al etapelor: "<<P.end_value_res[2]<<endl;
                    status_proiect=status_proiect+P.status[nr]/8;
                    cout<<"Status proiect:"<<status_proiect<<"%"<<endl;
                }
            }
            nr5--;
        }
        if(nr==6)
        {
            string username_testare,password_testare;
            // Setup_User u6("Bogdan","Florea","bogdan.florea15","123!@#",100,6);
            cout<<"(se executa actiuni in ipostaza de TESTER2)"<<endl;
            do
            {
                // users.push_back(u6);
                //user.login();
                cout<<"--Autentificare--"<<endl;
                cout<<"Username: ";
                cin>>username_testare;
                cout<<"Password: ";
                cin>>password_testare;
            }
            while(verify_login(u6.getUsername(),username_testare,u6.getPassword(),password_testare)==-1);

            cout<<"Autentificare facuta cu succes!"<<endl;
            while(nr6!=0)
            {
                cout<<"Actiuni disponibile: "<<endl;
                cout<<"     1.Vizualizare Task-uri"<<endl<<"     2.Adaugare progres"<<endl<<"     3.Vizualizare status"<<endl<<"     0.Iesire"<<endl;
                cin>>nr6;
                if(nr6==1)
                {
                    int i;
                    for(i=1; i<=5; i++)
                    {
                        cout<<P.task_test2[i]<<endl;
                    }
                }
                if(nr6==2)
                {
                    P.addProgress(nr,epic);
                }
                if(nr6==3)
                {
                    for(int i=1; i<=4; i++)
                    {
                        cout<<"Status saptamana"<<i<<":"<<P.weekly_status[i]<<"%"<<endl;
                    }
                    cout<<"Status etapa de["<<epic.epic.name[3]<<"][PART2]-->"<<P.status[nr]<<"%"<<endl;
                    if(P.status[nr]==100)
                        P.end_value_out[12]=1; //indicator testare
                    status56=status56+P.status[nr]/2;
                    cout<<"Status etapa de["<<epic.epic.name[3]<<"]-->"<<status56<<"%"<<endl;
                    cout<<"Valoarea indicatorului de realizare al etapelor: "<<P.end_value_res[2]<<endl;
                    status_proiect=status_proiect+P.status[nr]/8;
                    cout<<"Status proiect:"<<status_proiect<<"%"<<endl;
                }

            }
            nr6--;
        }
        if(P.end_value_res[2]==1)
            P.end_value_out[11]=1; //indicator implementare
        if(nr==7)
        {
            int i;
            cout<<"INDICATORII DE PROIECT"<<endl;
            cout<<"Indicatorii de output"<<endl<<endl;
            cout<<"\t\t\t\t        Start Value"<<"\t"<<"   Ideal Value"<<"\t"<<"      Value"<<"\t"<<"      Indice"<<endl;
            for(i=1; i<=6; i++)
            {
                cout<<P.output_indicator[i]<<"\t\t"<<P.start_value[i]<<"\t\t"<<P.end_ideal_value_out[i]<<"\t\t"<<P.end_value_out[i]<<"\t\t"<<P.end_ideal_value_out[i]-P.end_value_out[i]<<endl;
            }

            cout<<P.output_indicator[7]<<"\t\t\t\t"<<P.start_value[7]<<"\t\t"<<P.end_ideal_value_out[7]<<"\t\t"<<P.end_value_out[7]<<"\t\t"<<P.end_ideal_value_out[7]-P.end_value_out[7]<<endl;
            cout<<P.output_indicator[8]<<"\t\t\t\t"<<P.start_value[8]<<"\t\t"<<P.end_ideal_value_out[8]<<"\t\t"<<P.end_value_out[8]<<"\t\t"<<P.end_ideal_value_out[8]-P.end_value_out[8]<<endl;
            cout<<P.output_indicator[9]<<"\t\t\t"<<P.start_value[9]<<"\t\t"<<P.end_ideal_value_out[9]<<"\t\t"<<P.end_value_out[9]<<"\t\t"<<P.end_ideal_value_out[9]-P.end_value_out[9]<<endl;
            cout<<P.output_indicator[10]<<"\t\t\t"<<P.start_value[10]<<"\t\t"<<P.end_ideal_value_out[10]<<"\t\t"<<P.end_value_out[10]<<"\t\t"<<P.end_ideal_value_out[10]-P.end_value_out[10]<<endl;
            cout<<P.output_indicator[11]<<"\t\t\t"<<P.start_value[11]<<"\t\t"<<P.end_ideal_value_out[11]<<"\t\t"<<P.end_value_out[11]<<"\t\t"<<P.end_ideal_value_out[11]-P.end_value_out[11]<<endl;
            cout<<P.output_indicator[12]<<"\t\t\t\t"<<P.start_value[12]<<"\t\t"<<P.end_ideal_value_out[12]<<"\t\t"<<P.end_value_out[12]<<"\t\t"<<P.end_ideal_value_out[12]-P.end_value_out[12]<<endl;
            cout<<endl<<endl<<"Idicatorii de rezultat"<<endl<<endl;
            cout<<P.result_indicator[1]<<"\t\t\t\t"<<P.start_value[1]<<"\t\t"<<P.end_ideal_value_res[1]<<"\t\t"<<P.end_value_res[1]<<"\t\t"<<P.end_ideal_value_res[1]-P.end_value_res[1]<<endl;
            cout<<P.result_indicator[2]<<"\t\t\t\t"<<P.start_value[2]<<"\t\t"<<P.end_ideal_value_res[2]<<"\t\t"<<P.end_value_res[2]<<"\t\t"<<P.end_ideal_value_res[2]-P.end_value_res[2]<<endl;
            cout<<P.result_indicator[3]<<"\t\t\t\t\t"<<P.start_value[3]<<"\t\t"<<P.end_ideal_value_res[3]<<"\t\t"<<P.end_value_res[3]<<"\t\t"<<P.end_ideal_value_res[3]-P.end_value_res[3]<<endl;
            cout<<P.result_indicator[4]<<"\t\t\t\t\t"<<P.start_value[4]<<"\t\t"<<P.end_ideal_value_res[4]<<"\t\t"<<P.end_value_res[4]<<"\t\t"<<P.end_ideal_value_res[4]-P.end_value_res[4]<<endl;


        }

    }

}


int main()
{

    list<Setup_User>users;
    //User user;
    Project Pro;
    Epic ep;
    SELECT(users,Pro,ep);

    return 0;
}

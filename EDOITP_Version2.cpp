#include <iostream>
#include<math.h>
#include <time.h>

using namespace std;
/*
In SELECT()
1. ADD PROJECT DETAILS - adauga de la tastatura detalii despre proiect: numele proiectului, numarul de membrii din echipa + ce face membrul respectiv(de ex programator,manager,tester etc), nr task-uri pentru fiecare membru, data de incepere a proiectului si data cand se doreste sa se incheie proiectul;
2. ADD TASKS - se adauga pentru fiecare membru numele task-urilor;
3. ADD PERFORMANCE INDICATORS - se afiseaza o lista numerotata cu toate task-urile proiectului, se citeste de la tastatura numele indicatorului si se aleg din lista task-urile care contribuie la realizarea indicatorului respectiv;
4. ADD PROGRESS - pentru fiecare indicator se calculeaza distanta hamming dintre vectorii ideali(definiti in ADD PROJECT DETAILS) si vectorii adaugati aici de la tastatura;
5. SHOW PROGRESS - afiseaza gradul de "implementare" al indicatorilor de performanta pe baza vectorului de distante hamming de la ADD PROGRESS.
*/

int hammingDist(int str1[100][100], int str2[100][100],int nr_tasks, int idx)
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
int hammingDist2(int str1[100], int str2[100],int nr_tasks, int idx)
{
    int i = 1, count = 0;
    while(i <= nr_tasks)
    {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}


class Project
{
private:
        string name_project;
        int start_day;
        int start_month;
        int start_year;
        int end_day;
        int end_month;
        int end_year;
        int nr_members;
        string status_member[100];
        int nr_tasks[100];

public:
      Project(string name_project, int sday, int smonth,int syear, int eday, int emonth, int eyear, int nr_mb,string status_mb[100],int nr_tasks[100])
      {
        this->name_project=name_project;
        this->end_day = eday;
        this->end_month = emonth;
        this->end_year = eyear;
        this->start_day=sday;
        this->start_month=smonth;
        this->start_year=syear;
        this->nr_members=nr_mb;
        for( int i = 1; i <= nr_mb; i++ )
        {
          this->status_member[i] = status_mb[i];
          this->nr_tasks[i] = nr_tasks[i];
        }

      }
};
class Data_curenta
{
public:

    Data_curenta();
    ~Data_curenta(){};
};

Data_curenta::Data_curenta()
{
    time_t now = time(0);
    struct tm timp;
    timp = *localtime(&now);
    cout<<1+timp.tm_mon<<"/"<<timp.tm_mday<<"/"<<1900+timp.tm_year<<endl;

}
void SELECT()
{
    int nr=-1;
    int dist[100];
     string name_project;
            int sday;
            int smonth;
            int syear;
            int eday;
            int emonth;
            int eyear;
            int nr_mb;
            int nr_tasks[100];
            int ideal_task[100][100];
            string status_mb[100];
            string task[100][100];
            int day[10],month[10],year[10];
            int task_value[100][100];
            int idx[100][100],i,j,n,x;
            string indicator[100];
            int v[100],v2[100][100],idx_indicator,ind[100][100],indice[2],c,ideal_indicator[100],indicator_value[100],distH[100],cif2,t;
            float proportia;




    while(nr!=0)
    {
        cout<<"MENU"<<endl<<"     1.ADD PROJECT DETAILS"<<endl<<"     2.ADD PERFORMANCE INDICATORS"<<endl<<"     3.ADD TASKS"<<endl<<"     4.ADD PROGRESS"<<endl<<"     5.SHOW PROGRESS"<<endl<<"     6.SHOW INDICATORS"<<endl<<"     0.EXIT"<<endl;
        cout<<"Option: ";
        cin>>nr;
        if(nr==1)
        {
            cout<<"Project name: "; cin>>name_project;
            cout<<"Start date: ";
            cout<<"Day: "; cin>>sday;
            cout<<"Month: "; cin>>smonth;
            cout<<"Year: "; cin>>syear;
            cout<<"End date: ";
            cout<<"Day: "; cin>>eday;
            cout<<"Month: "; cin>>emonth;
            cout<<"Year: "; cin>>eyear;
            cout<<"Number of members: "; cin>>nr_mb;
            for(int i = 1; i <= nr_mb; i++)
                {cout<<"Member's status: \n";
                  cin>>status_mb[i];
                  cout<<"Number of tasks: ";
                  cin>>nr_tasks[i];
                  getchar();
                  for(int j = 1; j <= nr_tasks[i]; j++)
                    {
                      ideal_task[i][j] = 1;
                    }
                }
            Project p(name_project, sday,smonth,syear,eday,emonth,eyear,nr_mb,status_mb,nr_tasks);
        }

        if(nr==2) //add indicators
        {
          cout<<"List of performance indicators"<<endl;
          cout<<"Number of indicators: ";
          cin>>n; //nr de indicatori
          for(i=1;i<=n;i++)
         {
           cout<<"["<<i<<"]"<<"Indicator: ";
           cin>>indicator[i]; //citim numele indicatorului
           ideal_indicator[i]=1;
         }

        }
        if(nr==3) //add tasks
        {
          for(int k=1;k<=n;k++)
          {
            cout<<"["<<k<<"]"<<"Indicator: "<<indicator[k]<<endl;
          }
          cout<<"Add tasks"<<endl;
            for(int i = 1; i <= nr_mb; i++)
                {
                  cout<<"["<<i<<"]"<<"Member: "<<endl;
                  cout<<"Status: "<<status_mb[i]<<endl;
                  for( j = 1; j <= nr_tasks[i]; j++)
                    {
                      cout<<"  ["<<j<<"]"<<"Task: "<<endl;
                      string s;
                      cin>>s;
                      task[i][j]=s;
                      cout<<"How many performance indicators are related to this task?"<<endl;
                      cin>>x;
                      c=x-1;
                      cout<<"What are the related performance indicators?"<<endl;
                      for(int k = 1; k <= x; k++)
                      {
                        cout<<"Indicator"<<k<<endl;
                        cin>>idx_indicator;
                        ind[i][j]=ind[i][j]+pow(10,c)*idx_indicator;
                        c--; //mat alcatuita din numerele formate de indicii indicatorilor la care contribuie de ex daca taskul1 contribuie la indicatorii cu numarul 1,2 --> ind va fi 12
                      }
                    }
                }
                /*for(i=1;i<=nr_mb;i++)
                {
                  for(j=1;j<= nr_tasks[i];j++)
                  {
                    cout<<"mat"<<ind[i][j]<<endl;
                  }
                }*/

                for(i=1;i<=nr_mb;i++)
                {
                  for(j=1;j<= nr_tasks[i];j++)
                  {
                    while(ind[i][j]!=0)
                    {
                      int cif = ind[i][j] %10;
                      ind[i][j] /=10;
                      v[cif]++; //contorizam aparitiile fiecrui indicator in matricea speciala de mai sus
                      v2[cif][v[cif]]=10*i+j;
                     // cout<<"v2"<<i<<j<<v2[cif][v[cif]]<<endl;
                       //formam un numar din indicii pozitiei la care avem o aparitie a indicatorului de ex: am gasit pe pozitia [1][2]-->v2=12

                    } //SCOP: dorim gasirea relatiilor dintre indicatori si taskuri, astfel ca am abordat aceasta strategie de alcatuire a unei matrici in care sa retinem numarul format de indicii numerici ai indicatorilor, urmata de gasirea numarului de aparitii al fiecarui indicator pentru a putea verifica de cate taskuri e nevoie ca acel indicator sa fie realizat 100%
                  }
                }
        }
        if(nr==4)
        {
            for(int i = 1; i <= nr_mb; i++)
                {
                  cout<<"["<<i<<"]"<<"Member: "<<endl;
                  cout<<"Status: "<<status_mb[i];
                  for(int j = 1; j <= nr_tasks[i]; j++)
                    {
                      string ch;
                      cout<<"   ["<<j<<"]"<<"Task: \n"<<endl;
                      cout<<task[i][j]<<endl;
                      cout<<"Finished?(Yes/No)"<<endl;
                      cin>>ch;
                      if( ch == "Yes")
                        {
                          task_value[i][j] = 1;
                          cout<<"Task"<<"["<<j<<"]"<<"completed!"<<endl;

                        }
                      if( ch == "No")
                      {
                        task_value[i][j] = 0;
                      }

                    }
                  //dist[i] = hammingDist(task_value,ideal_task,nr_tasks[i],i);

                }
        }
        if(nr==5)
        {
          for(i=1;i<=n;i++)
          {proportia=0;
            cout<<"How many tasks are related to indicator"<<i<<"?  ";
            cout<<v[i]<<endl;//nr de aparitii
            for(j=1;j<=v[i];j++)
            {
              t=2;
              cout<<v2[v[i]][j];
              while(v2[v[i]][j]!=0)
              {
                cif2 = v2[v[i]][j]%10;
                v2[v[i]][j]/=10;
                indice[t]=cif2;
                t--;
              }
              if(task_value[indice[1]][indice[2]]==1)
              {
                proportia=proportia+100/v[i];
                cout<<"Indicator"<<i<<"-->"<<proportia<<"%"<<endl;
              }
          }
           if(proportia==100)
                {
                  indicator_value[i]=1;
                }
                else indicator_value[i]=0;

          distH[i]=hammingDist2(indicator_value, ideal_indicator, n,i);
        }
        }
        if(nr==6)
        {
          cout<<"PERFORMANCE INDICATORS"<<endl;
          for(i=1;i<=n;i++)
          {
            cout<<"Indicator"<<i<<": "<<indicator[i]<<endl;
            cout<<"Hamming Distance: "<<distH[i]<<endl;
            if(distH[i]==0)
            {
              cout<<"This indicator is completed"<<endl;
            }
            else
            {
              cout<<"This indicator is not completed ;("<<endl;
            }

          }
          cout<<"Work progress until: ";
          Data_curenta Obiect;
          cout<<"Deadline: ";
          cout<<eday<<"/"<<emonth<<"/"<<eyear<<endl<<endl;
        }

    }
}


int main()
{
  SELECT();
}

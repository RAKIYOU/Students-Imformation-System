#include "iostream"
#include "string"

using namespace std;

class student{
public:
    friend class list;
    student *next;
    char name[50];
    int num;
    char gender[50];
    int year;
    int month;
    int day;
    int c_plus_plus ;
    int java;
    int python;
    student()       {   }
    ~student()      {   }
    student * goto_next ()   {return next;}
    void input();
    void output();
};

void student::input( ){
    cout<<"please input the student's name"<<std::endl;
    cin>>name;
    cout<<"please input the student's number"<<std::endl;
    cin>>num;
    cout<<"please input the student's gender"<<std::endl;
    cin>>gender;
    cout<<"please input the student's birth year"<<std::endl;
    cin>>year;
    cout<<"please input the studebt's birth month"<<std::endl;
    cin>>month;
    cout<<"please input the student's birth day"<<std::endl;
    cin>>day;
    cout<<"please input the student's c++ grade"<<std::endl;
    cin>>c_plus_plus;
    cout<<"please input the student's python grade "<<std::endl;
    cin>>python;
    cout<<"please input the student's java grade"<<std::endl;
    cin>>java;
}

void student::output(){   
    cout<<"name:"<<name<<"\n";
    cout<<"number:"<<num<<"\n";
    cout<<"gender:"<<gender<<"\n";
    cout<<"birth:"<<year<<"/"<<month<<"/"<<day<<"\n";
    cout<<"c_puls_puls:"<<c_plus_plus<<"\n";
    cout<<"java:"<<java<<"\n";
    cout<<"python:"<<python<<"\n";
}

class slist{
public:
    student *first;
    student *last;
    slist()    {first=last=new student;}
    slist & insert(const  student  &);    // 表尾巴插入一个student结点
    slist & emitname(char *);             //从单链表中删除一个指定的姓名的结点
    slist & emitnum(int );                //从单链表中删除指定学号的节点
    void   searchname(char *);            //通过姓名来查找当前节点的信息
    void   searchnum(int );               //通过学号来查找当前节点的信息
    bool display();                       //显示最高分和最低分
    int count();                          // 显示链表的当前节点数目
};

slist & slist::insert(const student & A){
    student * pointer=last;
    *pointer=A;
    last=new student;
    pointer->next=last;
    return *this;  
}

slist & slist::emitname(char * name1){
    student * pointer;
    if(first==last){
        cout<<" this list is already empty!!"<<endl;
        return *this;
    }
    else
    {
        if(strcmp(first->name,name1)==0)
        {
            pointer=first;
            first=first->next;
            delete pointer;
            cout<<"successfully delete!\n";
            return *this;
        }
        else
        {
            for(pointer=first;pointer==last;pointer=pointer->next)
            {
                student *q=pointer->next;
                if(strcmp(q->name,name1)==0)
                {
                    pointer->next=q->next;
                    cout<<"successfully delete!\n";
                }
            }
            return *this;
        }
    }
    
}
slist & slist::emitnum(int num1){
    student * pointer;
    if(first==last)
    {
        cout<<" this list is already empty!!"<<endl;
        return *this;
    }
    else
    {
        if(first->num==num1)
        {
            pointer=first;
            first=first->next;
            delete pointer;
            cout<<"successfully delete!\n";
            return *this;
        }
        else
        {
            for(pointer=first;pointer==last;pointer=pointer->next)
            {
                student *q=pointer->next;
                if(q->num==num1)
                {
                    pointer->next=q->next;
                    cout<<"successfully delete!\n";
                }
            }
            return *this;
        }
    }
}

void  slist::searchname(char * name1){
    student *pointer=first;
    if(first==last)
         cout<<"there is no data"<<endl;
    
    else
    {
       while (pointer!=last)
      {
        if(strcmp(pointer->name,name1)==0)
            pointer->output();
        pointer=pointer->next;       
      }    
    }
}

void  slist::searchnum(int num1){
    student *pointer=first;
    if(first==last)
        cout<<"there is no data"<<endl;
    else
    {
       while (pointer!=last)
       {
        if(pointer->num==num1)
            pointer->output();
        pointer=pointer->next;        
       }
    }    
}

bool slist::display(){
    student * pointer, *q, *r;
    int max=0,min=300;
    pointer=first;
    if(first==last)
        cout<<"no data!"<<endl;
    else
    {
        while(pointer!=last)
      {
          int now=pointer->python+pointer->c_plus_plus+pointer->java;
      
        if(now>max)
        { max=now;
            q=pointer;}
        if(min>now)
        {min=now;
            r=pointer;}
          pointer=pointer->next;   
       }
        cout<<"highest points:"<<max<<endl;
        q->output();
        cout<<"lestest points:"<<min<<endl;
        r->output();  
    }
        return true;   
}

int slist::count(){       
    int counter=0;
    student * pointer=first;
    while(pointer!=last)     
    {
        counter++;
        pointer=pointer->next;      
    }  
    cout<<"the number  of students  is:"<<counter<<endl;
    return 0;  
}

int  main()
{
    char data[20];
    int  answer;
    slist  thislist;
    while(1)
    {
        std::cout<<"-------insert-------1\n";
        std::cout<<"-------search-------2\n";
        std::cout<<"-------delete-------3\n";
        std::cout<<"-------display------4\n";
        std::cout<<"-------counter------5\n";
        std::cout<<"-------out--------- 6\n";
        
        std::cin>>answer;
        switch (answer)
        {
            case 1:    
            { cout<<"from now please input 5 data  inorder \n";
                student A;
                A.input();
                thislist.insert(A);
                cout<<"sucessfully interted!"<<endl;
                break;}
            case 2:
                
            {
                cout<<"please input the data's name or number that you want know\n";
                cin>>data;
                if(data[0]>'0'&&data[0]<'9')
                {
                    int x=0,i=0;
                    while(data[i]!='\0')
                    {
                        x=x*10+(data[i]-'0');
                        i++;
                    }
                    thislist.searchnum(x);
                
                }
                else
                    thislist.searchname(data);
                    
               
                
                break;
            }
                
            case 3:
                
            {  cout << "please input the student's name or num which you want to  delete \n";
                cin>>data;
                
                if(data[0]>'0'&&data[0]<'9')
                {
                    int x=0,i=0;
                    while(data[i]!='\0')
                    {
                        x=x*10+(data[i]-'0');
                        i++;
                    }
                    thislist.emitnum(x);
                    
                }
                else
                    thislist.emitname(data);
                
                break;
            }
                
            case  4:
            { thislist.display();
                
                
                break;
            }
                
            case 5:
                
            {
                thislist.count();
                
                break;
            }
            case 6:
            {
                cout<<"thanks for using our software!!";
                return 0;
                break;
            }
        }
        
    }
    
}

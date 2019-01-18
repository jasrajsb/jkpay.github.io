#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>

int menuentities = 0;
int menuindex = 0;
char currscreen = 'm';
char currtype = 'n';
int currind = 0;
int opchanged=0;
int indep = 0;
int indepv = 0;
int indepleft = 1;
int horlines = 0;
char  list[20][20] = {"","","","","","","","","","","","","","","","","","","",""};
char selclas[20];
char selsec[20];
char indepfor='0';
int deleteflag = 0;

struct clas{
  char clas[10];
  char section[10];
  int totmarks;
  int totstuds;
  clas* next;
};

void resetdata(){
  for(int i=0;i<20;i++){
    strcpy(list[i], "");
  }
}
int doesntc(char list[20][20], char* str){
  int flag = 1;
  for(int i=0; i<20; i++){
    if(strcmp(list[i], str)==0){
      flag = 0;
      break;
    }
  }
  return(flag);
}

void swap(char &a, char &b ){
  char t;
  t=a;a=b;b=t;
}

int thisopno =0;
int opt=0,field=0;
char side='l';

void tempmenu(char title[]){
  cout<<title;
  getch();
  getch();
}
void enablebluebg(){
  textbackground(BLUE);
  textcolor(15);
}
void disablebluebg(){
  textbackground(15);

  textcolor(0);
}

void jkcprint(char* leftstring, char * rightstring);




class Student{
  public:
  char name[50], roll[10], clas[10], section[10];
  int mp,mc,mm,perc;
  char grade;

  Student(){
    strcpy(name,"test");
    strcpy(roll,"test");
    strcpy(clas,"test");
    strcpy(section,"test");
  }
  void display(){
    cout<<name<<roll<<clas<<section;
  }
  void marks(int mpa,int mca,int mma, perca){
    mp=mpa;
    mc=mca;
    mm=mma;
    perc = perca
  }
  void assignvals(char*,char*,char*,char*);
  void savetodisc(int);
  void savemarks();
  int getdatafromfile(char* ops[]);
} S1;

Student current;

void Student::savetodisc(int m=1){
  ofstream fout;
  Student temp;
  if(!m)
  fout.open("DATA.DAT", ios::app);
  else
  fout.open("MARKS.DAT", ios::app);
  fout.write((char*)this, sizeof(*this));
  fout.close();
}
/*int Student::getdatafromfile(char* ops[]){
  ifstream fout;
  Student temp;

  fout.open("DATA.DAT");
  int i=0;
  while(!fout.eof()){
  fout.read((char*)this, sizeof(*this));


    strcpy(*ops[i],temp.clas) ;
    i++;
  }

  fout.close();
  return i;
}*/
void Student::assignvals(char* n, char* c, char* s, char* r){
  strcpy(name,n);
  strcpy(roll,r);
  strcpy(clas,c);
  strcpy(section,s);
}


char* convcol1(char*);

char* grabhash(){
  ifstream fout;
  char str[20];
  fout.open("passes.txt");
  fout>>str;
  fout.close();
  return (str);
}

void savepass(char* str){
  ofstream fout;
  fout.open("passes.txt");
  fout<<str;
  fout.close();
}

char s4val1[100] = "Current Password   : ";
char s4val2[100] = "New Password       : ";
char s4val3[100] = "Confirm Password   : ";

char s1val1[100] = "Student's Name     : ";
char s1val2[100] = "Class              : ";
char s1val3[100] = "Section            : ";
char s1val4[100] = "Roll Number        : ";

char stval1[100] = "Mathematics        : ";
char stval2[100] = "Physics            : ";
char stval3[100] = "Chemistry          : ";
char stval4[100] = "Percentage : ";


char s2val1[100] = "Select Class : ";
char s2val2[100] = "Select Section : ";
char s2val3[100] = "Enter Roll Number  : ";
char s2val4[100] = "Student Name : ";
Student tbd;
void getname(){
  char* roll;
  roll = &s2val3[21];
  if(strcmp(selsec,"")!=0&&strcmp(selclas,"")!=0&&strcmp(roll,"")!=0){
    ifstream fout;
    Student temp;

    fout.open("DATA.DAT");
    while(fout){
    fout.read((char*)&temp, sizeof(temp));
    if(strcmp(selsec,temp.section)==0&&strcmp(selclas,temp.clas)==0&&strcmp(roll,temp.roll)==0){
      strcpy(s2val4, "Student: ");
      strcat(s2val4, temp.name);
      tbd = temp;
      deleteflag = 1;
      break;
    } else{
      //strcpy(s2val4, "Student not Found");

      strcpy(s2val4, "Student does not exists");
      deleteflag = 0;
    }

  }

}
}
void registerstudent(){
  char* str1 = &s1val1[21];
  char* str2 = &s1val2[21];
  char* str3 = &s1val3[21];
  char* str4 = &s1val4[21];
  S1.assignvals(str1,str2,str3,str4);
  S1.savetodisc(0);
}

int savepassword(){
  char* str1 = &s4val1[21];
  char* str2 = &s4val2[21];
  char* str3 = &s4val3[21];
  if(strcmp(str2,str3)==0&&strcmp(str1,grabhash())==0){
    savepass(str2);
    return 1;
  }
  else return 0;
}

class JKToolkit {
  int verpos;
  int vermax;

 public:
  void handlescreen();

  void print(char [], int, char);
  int getchars(char []);
  void toggleup(){
    if(indep){
      if(indepv>0){
        indepv--;
      }


    }
    opchanged=1;
    menuindex--;
    handlescreen();

    handlescreen();
  }
  void toggleright(){
    opchanged=1;
    side='r';
    indepleft=0;
    handlescreen();
  }
  void toggleleft(){
    indepleft=1;
    opchanged=1;
    opt=0;
    side='l';
    handlescreen();
  }
  void one(){
    currscreen = '1';
    handlescreen();
  }
  void two(){


    currscreen = '2';

    handlescreen();
  }
  void three(){
    currscreen = '3';
    handlescreen();
  }
  void four(){
      menuindex = 0;
      menuentities = 0;
    currscreen = '4';
    handlescreen();
  }
  void five(){

    clrscr();
    exit(0);
  }
  void toggledown(){
    opchanged=1;
    menuindex++;
    if(indep){
      indepv++;
    }



    handlescreen();
  }
  void initialgap(){
    cout<<"\n\n                 ";
  }
  void rightcontent(char* str,int activeh, int left){
    if(!left&&activeh){
      if(indepfor == 'c')
      strcpy(selclas, str);
      if(indepfor == 's')
      strcpy(selsec, str);
      enablebluebg();
    }
    cprintf(" ");
    cprintf(str);
    cprintf(" ");
    if(!left&&activeh){disablebluebg();}
  }
  void leftcontent(char* str, int activeh, int left){
    if(left&&activeh){
      if(indepfor == 'c')
      strcpy(selclas, str);
      if(indepfor == 's')
      strcpy(selsec, str);
      enablebluebg();
    }
    cprintf(" ");
    cprintf(str);
    cprintf(" ");
    if(left&&activeh){disablebluebg();}
  }
  void intermidiategap(int gaps){
    for (int i=0;i<gaps;i++){
      cout<<" ";
    }
  }
  void deletestudent(){
    ifstream fin;
    ofstream fout;
    Student temp;

    fin.open("DATA.DAT");
    fout.open("MARK.DAT");
    int i=0;
    while(fin){
    fin.read((char*)&temp, sizeof(temp));
    if(temp.roll != tbd.roll){
      fout.write((char*)&temp, sizeof(temp));
    }

  }
  fin.close();
  fout.close();
  remove("DATA.DAT");
  rename("DAT.DAT", "DATA.DAT")
}
    void select(){
      if(currscreen == 't'&&menuindex%menuentities==4 ){
        char* pstr = &stval1[21];
        char* cstr = &stval2[21];
        char* mstr = &stval3[21];
        int p = atoi(pstr);
        int c = atoi(cstr);
        int m = atoi(mstr);
        current.marks(p, c, m, (p+c+m)/3);
        current.savetodisc(1);
        clrscr();
        cout<<"Succesfully saved Records to disc. Press any key to continue";
        getch();
        indep = 0;
        currscreen = 'm';
        JK.handlescreen();
        strcpy(s1val1 , "Student's Name     : ");
        strcpy(s1val2 , "Class              : ");
        strcpy(s1val3 , "Section            : ");
        strcpy(s1val4 , "Roll Number        : ");
        strcpy(s4val1 , "Current Password   : ");
        strcpy(s4val2 , "New Password       : ");
        strcpy(s4val3 , "Confirm Password   : ");
        strcpy(s2val3 , "Enter Roll Number  : ");
      }
      else if(currscreen == '2' && indep){
        if(indepfor == 'c'){
          strcpy(s2val1, "Class : ");
          strcat(s2val1, selclas);
        }
        if(indepfor == 's'){
          strcpy(s2val2, "Section : ");
          strcat(s2val2, selsec);
        }
        indep=0;
        JK.handlescreen();
      }
      else if(currscreen=='2'&&menuindex%menuentities==4){
        if(deleteflag&&!indep){
          menuindex = 0;
          currscreen = 't';
          current = tbd;
          JK.handlescreen();

        }
      }


    else if(menuindex%menuentities==0&&currscreen=='m'){
      one();
    }
    else if(menuindex%menuentities==1&&currscreen=='m'){
      menuindex = 0;
      menuentities = 0;
      two();
    }
    else if(menuindex%menuentities==2&&currscreen=='m'){

      three();
    }
    else if(menuindex%menuentities==3&&currscreen=='m'){
      four();
    }
    else if(menuindex%menuentities==4&&currscreen=='m'){
      five();
    }
    else if(menuindex%menuentities==4&&currscreen=='1'){
      registerstudent();
      clrscr();
      cout<<"\n\tRegistered Student Succesfully. Press any key to return to main menu";
      getch();
       strcpy(s1val1 , "Student's Name     : ");
       strcpy(s1val2 , "Class              : ");
       strcpy(s1val3 , "Section            : ");
       strcpy(s1val4 , "Roll Number        : ");
      currscreen = 'm';
      handlescreen();
    }
    else if(menuindex%menuentities==3&&currscreen=='4'){
      clrscr();
      if (savepassword()==1)
      cout<<"\n\tChanges Saved Succesfully. You must login again to Continue\n\n\tPress any key to exit...";
      else
            cout<<"\n\tValidation Error! You will be logged out for Security Purposes\n\n\tPress any key to exit...";
      getch();

      clrscr();


      exit(0);

    }
    else if(currscreen=='2' && menuindex%menuentities==0){
      resetdata();

      cout<<"Flow of Control Caught";
      clrscr();
      if(menuindex%menuentities==0){
        indepfor = 'c';
        //int horlines = 10;

        ifstream fout;
        Student temp;

        fout.open("DATA.DAT");
        int i=0;
        while(fout){
        fout.read((char*)&temp, sizeof(temp));
        //temp.display();
        if(doesntc(list,temp.clas)){
          strcpy(list[i], temp.clas );
        }

          i++;
        }
        strcpy(list[i-1], " " );
        strcpy(list[i], " " );
        i--;
        if(i==-1){
          cout<<"Records do not Exist. Press any key to Exit";
          getch();
          exit(0);

        }

        fout.close();
        horlines = (i+1)/2;

        //char list[20][20] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
      }
        indep =1;
        handlescreen();
        //cout<<"display list here";




    }
    else if(currscreen=='2' && menuindex%menuentities==1){
      resetdata();
      indepfor = 's';
      cout<<"Flow of Control Caught";
      clrscr();
      if(menuindex%menuentities==1){
        //int horlines = 10;

        ifstream fout;
        Student temp;

        fout.open("DATA.DAT");
        int i=0;
        while(fout){
        fout.read((char*)&temp, sizeof(temp));
        //temp.display();
        char* tempst;
        tempst = &s2val1[8];
        if(strcmp(temp.clas, tempst)==0){
          if(doesntc(list,temp.section)){
            strcpy(list[i], temp.section );
          }

            i++;
        }

        }
        strcpy(list[i-1], " " );
        i--;
        if(i==-1){
          cout<<"Records do not Exist. Press any key to Exit";
          getch();
          exit(0);

        }

        fout.close();
        horlines = (i+1)/2;

        //char list[20][20] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
      }
        indep =1;
        handlescreen();
        //cout<<"display list here";




    }


  }
  void error(){}
  int absol(int &a, int b){
    if(a>=0){
      return (a%b);
    } else {
      a=0;
      return 0;

    }
  }
  void printheader(){
    cout<<"\n\t\n\t\t\t";
    cprintf("JK Marksheet Management System");
    cout<<"\n";
  }
  void rendermain(char inp[], char a[] = NULL,char b[] = NULL,char c[] = NULL,char d[] = NULL,char e[] = NULL){
    int index = 0;
    int lent = 0;
    menuentities = 0;
    if (e != NULL) {
       lent = 5;
    } else{
      if (d != NULL) {
         lent = 4;
      } else{
        if (c != NULL) {
          lent = 3;
        } else{
          if (b != NULL) {
             lent = 2;
          } else{
            lent = 1;
          }
        }
      }
    }


    if(a)
    menuoption(a,30,lent,inp[0]);
    if(b)
    menuoption(b,30,lent,inp[1]);
    if(c)
    menuoption(c,30,lent,inp[2]);
    if(d)
    menuoption(d,30,lent,inp[3]);
    if(e)
    menuoption(e,30,lent,inp[4]);
  }
  void menuoption(char a[], int w, int len=5, int type='n'){

    int flag =0;
    if (menuentities == absol(menuindex,len)){
      textbackground(BLUE);
      textcolor(15);
      flag =1;
      currind = menuentities;
      currtype = type;
    }
    menuentities++;
    if(type == 'i'){
      w=75;
    }
    print(a, w, type);

    if (flag==1){
      textbackground(15);

      textcolor(0);
      flag =0;
    }
  }
} JK;
char* chartostr(char a){
  char str[2];
  str[0] = a;
  str[1] = '\0';
  return(str);
}
void calcper(){
  char* pstr = &stval1[21];
  char* cstr = &stval2[21];
  char* mstr = &stval3[21];
  int p = atoi(pstr);
  int c = atoi(cstr);
  int m = atoi(mstr);


  int percint = (p+c+m)/3;
  char str[5] = "";
  itoa(percint,str,10);
  char tstr[25] = "Percentage : ";
  strcat(tstr, str);
  strcpy(stval4 ,tstr);
}
int JKToolkit::getchars(char str[]){
  int i=0;
  while(str[i]!='\0'){
    i++;
  }
  return (i+1);
}
int twoindex = 0;
int twoopindex = 0;
int twoflag=0;
char twoside = 'l';
void concat(char* str1, char* str2){

  int i=1;
  while(*str1 != '\0' || *str1 != 124){
    str1++;

    if(int(*str1) == 124)
    break;

  }

  *str1 = '|';
  while(*str2!='\0'){

    str1++;
    str2++;
    *str1=*str2;
  }

  //JK.handlescreen();
}
char* selop;
char* selfield;
void JKToolkit::handlescreen(){

  clrscr();
  printheader();
  if(currscreen == 'm'){
    char temparr[5] = {'b','b','b','b','b'};
    rendermain(temparr,"Student Registration","Assign Marks","Statistics","Change Password","Exit");
  }
  if(currscreen == '4'){
    char temparr[5] = {'i','i','i','b','n'};
    rendermain(temparr,s4val1,s4val2,s4val3, "Change Password");
  }
  if(currscreen == '1'){
    char temparr[5] = {'i','i','i','i','b'};
    rendermain(temparr,s1val1,s1val2,s1val3,s1val4, "Save Student Details");
  }
  if(currscreen == 'a'){
    cout<<"done";
    getch();
  }
  if(currscreen == '3'){
    ifstream fout;
    Student temp;
    Student topper;
    Student loser;
    clas init
    int flagfr =0;

    fout.open("MARKS.DAT");
    while(fout){
      fout.read((char*)&temp, sizeof(temp));


      if(flagfr == 0){
        init.clas = temp.clas;
        init.section = temp.section;
        init.totmarks += temp.perc;
        init.totstuds++;
        topper = temp;
        loser = temp;
        flagfr = 1;
      }else{
        
        if(temp.perc>topper.perc){
          topper = temp;
        }
        if(temp.perc<loser.perc){
          loser = temp;
        }
      }

      //cout<<" "<<temp.name<<"       "<<temp.clas<<" "<<temp.section<<"    "<<temp.roll<<"   "<<temp.mp<<"   "<<temp.mc<<"   "<<temp.mm<<"  "<<temp.perc;
    }
    if(strcmp(temp.name,"test")==0){
      cout<<"Insuficient Records. Press any key to exit";
      getch();
      exit(0);
    }

    fout.close();
    cout<<"\n ";
    enablebluebg();
    cprintf("  SUMMARY  ");
    cout<<"\n\n ";
    cprintf("  Hall of Fame  ");
    disablebluebg();
    cout<<"\n\n Best Performer : "<<topper.name<<"("<<topper.perc<< "%)";
    cout<<"\n\n Best Class : ";
    cout<<"\n ";
    enablebluebg();

    cout<<"\n\n ";
    cprintf("  Hall of Shame  ");
    disablebluebg();

    cout<<"\n\n Worst Performer : "<<loser.name<<"("<<loser.perc<< "%)";
    cout<<"\n\n Worst Class : ";
    //cout<<" "<<"Name"<<"       "<<"Class"<<"    "<<"Roll Number"<<"   "<<"Physics"<<"   "<<"Chemistry"<<"   "<<"Mathematics"<<"  "<<"Percentage";

    getch();
  }

/*  if(currscreen == '2'){
    char field1[50] = " Class : |";
    selfield = field1;
    char field2[50] = " Section : |";
    char field3[50] = " Roll Number : |";
    char field4[50] = " Name : |";
    jkcprint(field1,"1WORLD");
    jkcprint(field2,"2WORLD");
    jkcprint(field3,"3WORLD");
    jkcprint(field4,"4WORLD");
    //jkcprint("","5WORLD");
    //jkcprint("","6WORLD");
    //jkcprint("","7WORLD");
    //jkcprint("","8WORLD");
    if(opchanged){
      concat(selfield, selop);
      opchanged =0;
    }


  }*/
  if(currscreen == '2'){
    getname();
    if(!indep){

      char temparr[5] = {'b','b','i','b','b'};
      rendermain(temparr,s2val1,s2val2,s2val3,s2val4, "Select Student");
    } else{

      for(int i=0;i<10;i++){
        initialgap();
        leftcontent(list[(2*i)+0], (indepv%horlines==i), indepleft);
        intermidiategap(35-JK.getchars(list[(2*i)+0]));
        rightcontent(list[(2*i)+1], (indepv%horlines==i), indepleft);
      }
    }


  }
  if(currscreen == 't'){
    calcper();
    clrscr();
    cout<<"\n   Enter Marks For: ";
    cout<<""<<current.name<<"(" <<current.roll<<")"<<"\t Class: "<<current.clas<<" "<<current.section<<"\n";
    char temparr[5] = {'i','i','i','b','b'};
    rendermain(temparr,stval1,stval2,stval3, stval4, "Save Marks");
  }
}









void JKToolkit::print(char str[],int w=0, char t='n'){
  cout<<"\n\n  \t\t";
  int n = getchars(str);
  int s = w-n;
  int k = 2;
  if(t == 'i'&&currscreen!='2'){
    s=-20;

  }
  if(currscreen=='2'&&t=='i'){
    s=6;
  }
  while((s+20)/k>0){
    s-=2;
    cout<<" ";
  }
  cprintf(" ");
  cprintf(str);
  cprintf(" ");


}
class JKScreen{};
class JKMenu{

};
char* encrypt(char a[]){
  char key[7] = {'J','S','B','K','C','S','P'};
  int i=0;
  while(a[i]!='\0'){
    if(i%2==0){
      a[i]+=key[i%7];
    } else{
      a[i]-=key[i%7];
    }
    i++;
  }
  return a;
}

void getspassword(char []);

void authenticate(){

  char inp[25];
  int flag = 0;

  for(int i=0;i<3;i++){
    JK.printheader();
    if(i!=0){
      JK.print("Try Again");
      cprintf("(You have ");
      char chancestr[2] = {char(51-i) ,'\0'};
      cprintf(chancestr);
      cprintf(" Chances left)");
    }
    JK.print("Password");
    getspassword(inp);
    JK.print(inp);

    if(strcmp(inp,grabhash())==0){
      flag = 1;
      break;
    }
    clrscr();
  }

  if(flag != 1&&currscreen!='2'&&currscreen!='1'){

    clrscr();
    cout<<"from authenticate called";

    exit(0);
  }
  clrscr();
}


void getspassword(char str[]){
  int i=0;
  char c = getch();
  while(c != 13){

    str[i] = c;
    cprintf("*");
    c = getch();
    i++;

  }
  str[i] = '\0';
}


void main(){

  textbackground(15);
  clrscr();
  textcolor(0);
  //MENU

  authenticate();
  JK.printheader();
  int endapp=1;
  char c;
  JK.handlescreen();

    while (endapp != 0){
      c = getch();
      if(c == 72 ){
        JK.toggleup();
      }
      else if(c == 75 ){
        JK.toggleleft();
      }
      else if(c == 80){
        JK.toggledown();
      }
      else if(c == 77){
        JK.toggleright();
      }
      else if(c == 13&& currtype == 'b'){
        JK.select();
      }
      else if(c == 27){
        indep = 0;
        currscreen = 'm';
        JK.handlescreen();
        strcpy(s1val1 , "Student's Name     : ");
        strcpy(s1val2 , "Class              : ");
        strcpy(s1val3 , "Section            : ");
        strcpy(s1val4 , "Roll Number        : ");
        strcpy(s4val1 , "Current Password   : ");
        strcpy(s4val2 , "New Password       : ");
        strcpy(s4val3 , "Confirm Password   : ");
        strcpy(s2val3 , "Enter Roll Number  : ");
      }
    else if(currtype == 'i'){
      char* currstr;
      if(currind == 0){
        if(currscreen == '4'){
          currstr = &s4val1[0];
        }
        if(currscreen == '1'){
          currstr = &s1val1[0];
        }
        if(currscreen == 't'){
          currstr = &stval1[0];
        }
      }

      if(currind == 1){
        if(currscreen == '4'){
          currstr = &s4val2[0];
        }
        if(currscreen == '1'){
          currstr = &s1val2[0];
        }
        if(currscreen == 't'){
          currstr = &stval2[0];
        }
      }
      if(currind == 2){
        if(currscreen == '4'){
          currstr = &s4val3[0];
        }
        if(currscreen == '1'){
          currstr = &s1val3[0];
        }
        if(currscreen == '2'){
          currstr = &s2val3[0];
        }
        if(currscreen == 't'){
          currstr = &stval3[0];
        }
      }
      if(currind == 3){
        if(currscreen == '4'){
          ;
        }
        if(currscreen == '1'){
          currstr = &s1val4[0];
        }
      }
      int i=0;
      while(currstr[i] != '\0'){
        i++;
      }
      currstr[i+1] = c;
      if(c == '\b' ){
        if( i>21)
        swap(currstr[i], currstr[i-1]);
        JK.handlescreen();
      } else{
        swap(currstr[i], currstr[i+1]);
        JK.handlescreen();
      }



        //strcat(s4val1 ,chartostr(c));
        ;
      }
      else
      JK.error();
    }


 exit(0);

}

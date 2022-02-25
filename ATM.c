#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//functions prototyping
int Checking(int,int);
void printl(int,int);
int ChecKBalance(int,int);

typedef struct CardNO
{
    char Name[20];
    int pin,accountNo,Balance,cardd;
    int type;
    //1. saving account 
    //2. current account
} Card;

//making card objects global 
Card p1,p2,p3,p4,p5;
int ObjT=5;

//data base function holds name, account no, pin ,card no of person 
//ACCOunt balance is in ffiles
void DATABASE()
{
    //                                                DATABASE                     
    //Name Declaration
    strcpy(p1.Name,"Harsh"); strcpy(p2.Name,"Jatin"); strcpy(p3.Name,"Divyat"); strcpy(p4.Name,"Gauri"); strcpy(p5.Name,"harshit");
     
    //card declartion 
    p1.cardd=4900; p2.cardd=5500; p3.cardd=4400; p4.cardd=4600; p5.cardd=5000;
        
    //PIN DECLARATION
    p1.pin=5544;        p2.pin=7580;        p3.pin=2002;        p4.pin=1234;        p5.pin=3773;   
    
    //account No
    p1.accountNo=901211049; p2.accountNo=901211055; p3.accountNo=901211044; p4.accountNo=901211046; p5.accountNo=901211050;
   
    //types of account
    p1.type=1;   p2.type=2;   p3.type=1;   p4.type=2;   p5.type=1; 
    
    // harsh divyat harshit holds saving account 
    // gauri jatin holds current account
    
}

//function prototype
Card FIND(int);

int main()
{
    // storing variables
    int lan,ID,PI,TY,Action;
    //action type pin card no language
    
    //checking database variables
    int p[5],pin[5],type[5];
    
    //code helper 
    int helpPlease,balanceReq,BCmpResult,NewBalance,RChoice,a=3,TranCHoice;
    
    //recipt generation
    FILE *fp;
    FILE *hb,*jb,*db,*gb,*hsb;
    char balancestr[8];
    //data calling
    DATABASE(); 
  
    // storing cardno and pin and type of function via function
    type[0]=p1.type;          p[0]=p1.cardd;            pin[0]=p1.pin;               
    type[1]=p2.type;          p[1]=p2.cardd;            pin[1]=p2.pin;               
    type[2]=p3.type;          p[2]=p3.cardd;            pin[2]=p3.pin;               
    type[3]=p4.type;          p[3]=p4.cardd;            pin[3]=p4.pin;               
    type[4]=p5.type;          p[4]=p5.cardd;            pin[4]=p5.pin;               


    WRNGlan:
    fflush(stdin);
    //language selection and wrong input handling
    printl(1,5);
    printl(1,18);
    scanf("%d",&lan);
    if (lan!=1&&lan!=2)
    {
        printf("\noh no! wrong choice\nChoose correct option\n");
        goto WRNGlan;
    }
    //welcome
    printl(lan,17);
    printl(lan,1);
    printf("\n");
    ThreeC:
    fflush(stdin);
    //taking card no ,if wrong giving 3 chanccces and card checking
    printl(lan,2);
    scanf("%d",&ID);
    printl(lan,17);
    //Checking Card No
    for (int i = 0; i < ObjT; i++)
    {
        int temp=i;
        while (Checking(ID,p[i]))
        {            
            Card tempst = FIND(temp);
            printf("WELCOME!! \"%s\"\n",tempst.Name);
            printf("Your account no is %d\n",tempst.accountNo);
            helpPlease=i;
            goto shihai;
            break;
        }
    }
    if (a>0)
    {
        printl(lan,22);
        printf("you have %d chances left\n",a);
        a--;
        goto ThreeC;
    }    
    exit(0);
    shihai:
    fflush(stdin);
    //entring pin and checking account type and giving 3 chances
    
    //opeing correction person blance file    
    if (helpPlease==0)
    {
        hb=fopen("HBalance.txt","r");
        fgets(balancestr,sizeof(balancestr),hb);
        p1.Balance=atoi(balancestr);
        fclose(hb);    
    }
    else if (helpPlease==1)
    {
        jb=fopen("jBalance.txt","r");
        fgets(balancestr,sizeof(balancestr),jb);
        p2.Balance=atoi(balancestr);
        fclose(jb);
    }
    else if (helpPlease==2)
    {
        db=fopen("DBalance.txt","r");
        fgets(balancestr,sizeof(balancestr),db);
        p3.Balance=atoi(balancestr);
        fclose(db);
    }
    else if (helpPlease==3)
    {
        gb=fopen("GBalance.txt","r");
        fgets(balancestr,sizeof(balancestr),gb);
        p4.Balance=atoi(balancestr);
        fclose(gb);
    }
    else if (helpPlease==4)
    {
        hsb=fopen("HsBalance.txt","r");
        fgets(balancestr,sizeof(balancestr),hsb);
        p5.Balance=atoi(balancestr);
        fclose(hsb);
    }
    
    
    //checking pin and account type
    a=3;
    ThreeC2:
    fflush(stdin);
    printl(lan,6);
    scanf("%d",&PI);
    printl(lan,17);
    Card last;
    while (Checking(PI,pin[helpPlease]))
    {
        last=FIND(helpPlease);
        printl(lan,7);
        WrongACCtype:
        fflush(stdin);
        printl(lan,4);
        printl(lan,18);
        printl(lan,17);
        scanf("%d",&TY);                        
        while (Checking(TY,type[helpPlease]))
        {
            goto phirshihai;
        }        
        if (TY!=type[helpPlease])
        {
            printf("OH no! wrong choice\n");
            goto WrongACCtype;
        }
        
        break;            
    }  
    if (a>0)
    {
        printl(lan,23);
        printf("you have %d chances left\n",a);
        a--;
        goto ThreeC2;
    }    
    exit(0);
    phirshihai:
    fflush(stdin);
    //mainwork
    anotherTRans: 
    fflush(stdin);
    ReEnter1:
    fflush(stdin);
    //asking to either check balance or have transaction
    printl(lan,8);
    printl(lan,18);
    scanf("%d",&Action);
    printl(lan,17);
    //reacting to request
    switch (Action)
    {
    case 1:// balance check
        printl(lan,9);
        printf("%d\n",last.Balance);
        printl(lan,26);
        break;
    case 2://withdraw cash
        JBKD:
        fflush(stdin);
        printl(lan,10);
        scanf("%d",&balanceReq);
        BCmpResult=ChecKBalance(balanceReq,last.Balance);
            if (BCmpResult==34)
            {
                goto proceed;
            }
            else if(BCmpResult==35)
            {
                printl(lan,11);
                goto JBKD;   
            }        
        break;
    default:
        printl(lan,12);
        goto ReEnter1;
        break;
    }
    exit(0);
    
    proceed:
    fflush(stdin);
    //he asked for transaction
    //part 2 of main action
    NewBalance=last.Balance-balanceReq;
    printl(lan,17);
    printl(lan,13);
    printl(lan,17);
    printl(lan,14);
    printl(1,15);
    printl(lan,16);
    printf("%d",NewBalance);
    printl(lan,17);

    GC:
    fflush(stdin);
    printl(lan,19);
    printl(lan,18);
    scanf("%d",&RChoice);
    //asking to generate recipt
    switch (RChoice)
    {
    case 1:
        printl(lan,20);
        //creating recipt
        fp=fopen("Recipt.txt","w");
        fprintf(fp,"Thank you!! %s for using our ATM\nYou have successfully made the transaction of ₹ %d\nNew balance in your account is ₹ %d\nCash is deducted from your account number- %d",last.Name,balanceReq,NewBalance,last.accountNo);        
        fclose(fp);
        goto GC2;
        break;
    case 2:
        printl(lan,21);
        goto GC2;
        break;
    default:
        printl(lan,12);
        goto GC;
        break;
    }
    //final ending of program by finaaly asking for balance or leave
    
    GC2:
    fflush(stdin);
    printl(lan,24);
    scanf("%d",&TranCHoice);
    printf("\n");
    switch (TranCHoice)
    {
    case 1:
        printl(lan,25);
        printf("%d\n",NewBalance);
        printl(lan,26);
        break;
    case 2:
        printl(lan,26);
        break;
    default:
        printl(lan,12);
        goto GC2;
        break;
    }
    
    //changing database
    if (helpPlease==0)
    {
        hb=fopen("HBalance.txt","w");
        fprintf(hb,"%d",NewBalance);
        fclose(hb);    
    }
    else if (helpPlease==1)
    {
        jb=fopen("jBalance.txt","w");
        fprintf(jb,"%d",NewBalance);
        fclose(jb);
    }
    else if (helpPlease==2)
    {
        db=fopen("DBalance.txt","w");
        fprintf(db,"%d",NewBalance);
        fclose(db);
    }
    else if (helpPlease==3)
    {
        gb=fopen("GBalance.txt","w");
        fprintf(gb,"%d",NewBalance);
        fclose(gb);
    }
    else if (helpPlease==4)
    {
        hsb=fopen("HsBalance.txt","w");
        fprintf(hsb,"%d",NewBalance);
        fclose(hsb);
    }
    
    return 0;
}

int ChecKBalance(int a,int b)
{
    if (a<=b)
    {
        return 34;
    }
    else
    {
        return 35;
    }    
}
Card FIND(int X)
{
    switch (X)
    {
    case 0:
        return p1;
        break;
    case 1:
        return p2;
        break;
    case 2:
        return p3;
        break;
    case 3:
        return p4;
        break;
    case 4:
        return p5;
        break;
    
    }
}
int Checking(int y,int x)
{
    if (y==x)
    {
        return 1;
    }
    else if (y!=x)
    {
        return 0;
    }        
}
void printl(int lan,int N)
{
    if (lan==1)
    {
        switch (N)
        {
        case 1:
            printf("WELCOME!! to MITS Zone ATM\n");break;
        case 2:
            printf("Please! Enter Your Card No.\n");break;
        case 3:
            printf("Enter your PIN\n");break;
        case 4:
            printf("Enter Account type\n1.Saving\n2.Current\n");break;
        case 5://shouldnt be in lang 2
            printf("Choose the language\n1:English\n2.Hinglish\n");break;
        case 6:
            printf("Enter your PIN\n");break;
        case 7:    
            printf("Your pin is correct\n");break;
        case 8:
            printf("Enter What you want to perform\n1.Check Balance\n2.Withdraw cash\n");break;            
        case 9:
            printf("Your Balance is: ");break;
        case 10:
            printf("Enter Amount: ");break;
        case 11:
            printf("Insufficient Balance\n");break;
        case 12:
            printf("OH NO!! Wrong choice\n");break;
        case 13:
            printf("Requesting your transaction............ \n");break;
        case 14:
            printf("withdraw Successful!\n");break;
        case 15:
            printf("💰💰💰💰\n");break;
        case 16:
            printf("Your new balance is:  ");break;
        case 17:
            printf("\n");break;
        case 18:
            printf("Enter your choice: ");break;
        case 19:
            printf("Do you want a receipt\n 1.yes\n 2.no\n");
            break;
        case 20:
            printf("printing out a receipt......\n");
            break;
        case 21:
            printf("Thank you!! for helping us in saving our enviroment\n");
            break;
        case 22:
            printf("Your card Info isn't in database\n");break;
        case 23:
            printf("Your PIN Info isn't in database\n");break;
        case 24:
            printf("Do you want check new balance\n 1.yes\n 2.no\nEnter your choice  ");break;
        case 25:
            printf("your new balance is ");break;
        case 26:
            printf("Thank you, for using our ATM\n");break;
        case 27:
            printf("Do you want another transaction\n1.)Yes   2.)No\nEnter your choice: "); break;
        }
    }
    else if (lan==2)
    {
        switch(N)
        {
        case 1:
        	printf("MITS Zone ATM me aapka swagat hai!!:)\n");break;
		case 2:
        	printf("Apna CARD NUMBER darj karein\n");break;
        case 3:
        	printf("Apna PIN darj karein\n");break;	
       	case 4:
        	printf("Apne Bank khate ka prakar darj karein. \n\t\t 1.SAVING \n\t\t 2.CURRENT\n ");break;
        
		case 6:
        	printf("Apna PIN darj karein: ");break;
		case 7:
        	printf("Aapke dwara darj PIN sahi hai!!\n");break;
	    case 8:
        	printf("Transaction ka chunav karein\n\t\t1.BALANCE ENQUIRY\n\t\t2.WITHDRAWAL\n ");break;
		case 9:
        	printf("Aapka Balance hai:");break;
		case 10:
        	printf("Raashi pravisht karein:");break;
		case 11:
        	printf("Aparyapta sheshrashi!! :(\n");break;
		case 12:
        	printf("OOPS!! \n Galat Vikalp!!\n");break;
        case 13:
        	printf("Apke len-den ka Anurodh kiya ja rha hai...........\n");break;	
        case 14:
        	printf("BHUGTAN SAFAL:)\n");break;
        
		case 16:
        	printf("Aapka naya Baalance hai:");break;
	    case 17:
        	printf("\n");break;
		case 18:
        	printf("Apni pasand darj karein:");break;
		case 19:
        	printf("Kya Aapko RECEIPT chahiye??\n\t\t1.Haan\n\t\t2.Nhi\n");break;
		case 20:
        	printf("RECEIPT print ho rahi hai.........\n");break;
		case 21:
        	printf("DHANYAVAD:)!!\n Aapne Paryavaran Sanrakshan me hamara sahyog kiya..\n");break;
        case 22:
        	printf("Aapke Card ki jankari DATABASE me nhi hai...:(\n");break;	
        case 23:
        	printf("Aapke dwra dala PIN amanya hai..\n");break;
        case 24:
        	printf("Kya aap apne naye BALANCE ki jaanch krna chahenge\n\t\t1.haan\n\t\t2.nhi\nApni pasand darj karein\n");break;
		case 25:
        	printf("Aapka naya BALANCE hai: ");break;
	    case 26:
        	printf("Hamari bank shakha ka upyog krne ke liye DHANYAWAD..!!");break;
		}
    } 
}

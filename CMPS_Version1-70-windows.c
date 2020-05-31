/* Carpark Monitoring and Cashier System for Open Car parks Management Corp */

#include<stdio.h>
#include<math.h>
#include<string.h>

// PIN
char pin[6];
int lockscrn(),loggedin=0,counter=3;
// registering function variables
int regadd(),regdel(),slot=0;
int parkingspace[8]={0,0,0,0,0,0,0,0};
// main section variables
int option=0;
// initial fee section variables
int inpayment();
float incarpay[8]={0,0,0,0,0,0,0,0};
// final amount to be paidsection variable
int fnpayment();
float fnamount[8]={0,0,0,0,0,0,0,0};
float fncarpay[8]={0,0,0,0,0,0,0,0};
// time arrays 
int btime1(),btime2(),btime3(),btime4(),btime5(),btime6(),btime7(),btime8();
int atime1(),atime2(),atime3(),atime4(),atime5(),atime6(),atime7(),atime8();
int bhr[8],bmin[8],ahr[8],amin[8],hrtime_elapsed=0,mintime_elapsed=0;
// Help
int help();

int main(){ // main body
	if(loggedin==0){
	    lockscrn();
	}
	else if(loggedin==1){
		
    do{
	printf("\t\tOpen Carpark Monitoring and Payment System\n\n");
	printf("Guidelines: Initial Parking - P 10.00\n");
	printf("\t\t\t    + P  5.00 Per hour after initial parking.\n");
	printf("\nAvailable slots\nDirections: 1 - Slot is already taken 0  - Slot is Empty\n");
	printf("\t[ %d ]  [ %d ]   [ %d ]   [ %d ]   \n\n",parkingspace[0],parkingspace[1],parkingspace[2],parkingspace[3]);
	printf("\t[%d:%.2d] [%d:%.2d]  [%d:%.2d]  [%d:%.2d] \n\n",bhr[0],bmin[0],bhr[1],bmin[1],bhr[2],bmin[2],bhr[3],bmin[3]);
	printf("\t[ %d ]  [ %d ]   [ %d ]   [ %d ]   \n\n",parkingspace[4],parkingspace[5],parkingspace[6],parkingspace[7],parkingspace[8]);
	printf("\t[%d:%.2d] [%d:%.2d]  [%d:%.2d]  [%d:%.2d] \n\n",bhr[4],bmin[4],bhr[5],bmin[5],bhr[6],bmin[6],bhr[7],bmin[7]);
	printf("Options: [1] - Reserve a Slot [2] - Remove a slot [3] - Lock\n\n");
	printf("\t [4] - Help  [5] - Exit\n");
	printf("\nEnter choice from the options above: "); 
	scanf("%d",&option);
	if (option==1){
		printf("\nSlot Reserve option\n");
		regadd();
	}
	else if(option==2){
	    printf("\nSlot Remove option\n");
		regdel();
	}
	else if(option==3){
	    printf("\nThe Program Will now Lock\n");
		loggedin=0;
		getch();
		system("cls");
		lockscrn();
	}
	else if(option==4){
		help();
		getch();
		system("cls");
		system("color 07");
		main();
	}
	else if(option==5){
	    printf("\nThe Program will now exit..\n");
	    getch();
        exit(0);
	}
	else {
		printf("\nInvalid input.");
		getch();
		system("cls");
	}
}while(option!=3);

	} // end of if loggedin
} // end of main body

regadd(){ //regadd function will handle the available & not available
	printf("\nCarparking Slots:\n\n\t[ 1 ]  [ 2 ]  [ 3 ]  [ 4 ] \n\n");  
	printf("\t[ 5 ]  [ 6 ]  [ 7 ]  [ 8 ] \n\n"); 
	printf("Choose what slot you will reserve: ");
	scanf("%d",&slot);
	if(slot==1){
		if(parkingspace[0]==1){
	    printf("\nThis slot has been taken.\n");
	    getch();
	    system("cls");
	    main();	
		}
		parkingspace[0]=1;
		printf("\nThe slot has been reserved.\n");
		btime1();
		inpayment();
		printf("\nCar parked at exactly %d:%.2d\n",bhr[0],bmin[0]);
		getch();
        system("cls");
        main();
	}
	else if(slot==2){
	     if(parkingspace[1]==1){
		 printf("\nThis slot has been taken.\n");
		 getch();
		 system("cls");
		 main();	
		}
         parkingspace[1]=1;
         printf("\nThe slot has been reserved.\n");
         btime2();
		 inpayment();
		 printf("\nCar parked at exactly %d:%.2d\n",bhr[1],bmin[1]);	
		 getch();
	     system("cls");
	     main();
	}
	
	else if(slot==3){
	     if(parkingspace[2]==1){
		 printf("\nThis slot has been taken.\n");
		 getch();
		 system("cls");
		 main();	
		}
         parkingspace[2]=1;
         printf("\nThe slot has been reserved.\n");
		 btime3();
		 inpayment();
		 printf("\nCar parked at exactly %d:%.2d\n",bhr[2],bmin[2]);
		 getch();
	     system("cls");
	     main();
	}
	
	else if(slot==4){
	     if(parkingspace[3]==1){
		 printf("\nThis slot has been taken.\n");
		 getch();
		 system("cls");
		 main();	
		}
         parkingspace[3]=1;
         printf("\nThe slot has been reserved.\n");
		 btime4();
		 inpayment();
		 printf("\nCar parked at exactly %d:%.2d\n",bhr[3],bmin[3]);
		 getch();
	     system("cls");
	     main();
	}
	
	else if(slot==5){
	     if(parkingspace[4]==1){
		 printf("\nThis slot has been taken.\n");
		 getch();
		 system("cls");
		 main();	
		}
         parkingspace[4]=1;
         printf("\nThe slot has been reserved.\n");
		 btime5();
		 inpayment();
		 printf("\nCar parked at exactly %d:%.2d\n",bhr[4],bmin[4]);
		 getch();
	     system("cls");
	     main();
	}
	
	else if(slot==6){
	     if(parkingspace[5]==1){
		 printf("\nThis slot has been taken.\n");
		 getch();
		 system("cls");
		 main();	
		}
         parkingspace[5]=1;
         printf("\nThe slot has been reserved.\n");
		 btime6();
		 inpayment();
		 printf("\nCar parked at exactly %d:%.2d\n",bhr[5],bmin[5]);
		 getch();
	     system("cls");
	     main();
	}
	
	else if(slot==7){
	     if(parkingspace[6]==1){
		 printf("\nThis slot has been taken.\n");
		 getch();
		 system("cls");
		 main();	
		}
         parkingspace[6]=1;
         printf("\nThe slot has been reserved.\n");
		 btime7();
		 inpayment();
		 printf("\nCar parked at exactly %d:%.2d\n",bhr[6],bmin[6]);
		 getch();
	     system("cls");
	     main();
	}
	
	else if(slot==8){
	     if(parkingspace[7]==1){
		 printf("\nThis slot has been taken.\n");
		 getch();
		 system("cls");
		 main();	
		}
         parkingspace[7]=1;
         printf("\nThe slot has been reserved.\n");
		 btime8();
		 inpayment();
		 printf("\nCar parked at exactly %d:%.2d\n",bhr[7],bmin[7]);
		 getch();
	     system("cls");
	     main();
	}

	else{
		printf("\nInvalid input.\n");
		getch();
        system("cls");
	    main();	
	}
	
	getch();
}

regdel(){ // This function will remove the reservations

 	printf("\nCarparking Slots:\n\n\t[ 1 ]  [ 2 ]  [ 3 ]  [ 4 ] \n\n");  
	printf("\t[ 5 ]  [ 6 ]  [ 7 ]  [ 8 ] \n\n");
	printf("Which parking Slots would you like to remove: ");
	scanf("%d",&slot);
	if(slot==1){
		if(parkingspace[0]==1){
			atime1();
			fnpayment();
		}
		else if(parkingspace[0]==0){
			printf("\nThis slot is empty.\n");
			getch();
	    	system("cls");
	    	main();
			
		}
		parkingspace[0]=0;
		bhr[0]=0;
		bmin[0]=0;
		printf("\nThe slot has been freed up.\n");
		getch();
	    system("cls");
	    main();
	}
	else if(slot==2){
		  if(parkingspace[1]==1){
	  	  atime2();
		  fnpayment();
	       }
          else if(parkingspace[1]==0){
          printf("\nThis slot is empty..\n");
          getch();
   	      system("cls");
   	      main();
			
		}
		parkingspace[1]=0;
		bhr[1]=0;
		bmin[1]=0;
		printf("\nThe slot has been freed up.\n");
		getch();
	    system("cls");
	    main();
	}
	
	else if(slot==3){
		  if(parkingspace[2]==1){
	  	  atime3();
		  fnpayment();
	       }
          else if(parkingspace[2]==0){
          printf("\nThis slot is empty..\n");
          getch();
   	      system("cls");
   	      main();
			
		}
		
		parkingspace[2]=0;
		bhr[2]=0;
		bmin[2]=0;
		printf("\nThe slot has been freed up.\n");
		getch();
	    system("cls");
	    main();
	}
	
	else if(slot==4){
		  if(parkingspace[3]==1){
	  	  atime4();
		  fnpayment();
	       }
          else if(parkingspace[3]==0){
          printf("\nThis slot is empty..\n");
          getch();
   	      system("cls");
   	      main();
			
		}
		
		parkingspace[3]=0;
		bhr[3]=0;
		bmin[3]=0;
		printf("\nThe slot has been freed up.\n");
		getch();
	    system("cls");
	    main();
	}
	
	else if(slot==5){
		  if(parkingspace[4]==1){
	  	  atime5();
		  fnpayment();
	       }
          else if(parkingspace[4]==0){
          printf("\nThis slot is empty..\n");
          getch();
   	      system("cls");
   	      main();
			
		}
		
		parkingspace[4]=0;
		bhr[4]=0;
		bmin[4]=0;
		printf("\nThe slot has been freed up.\n");
		getch();
	    system("cls");
	    main();
	}
	
	else if(slot==6){ // Slot 6 
		  if(parkingspace[5]==1){
	  	  atime6();
		  fnpayment();
	       }
          else if(parkingspace[5]==0){
          printf("\nThis slot is empty..\n");
          getch();
   	      system("cls");
   	      main();
			
		}
		
		parkingspace[5]=0;
		bhr[5]=0;
		bmin[5]=0;
		printf("\nThe slot has been freed up.\n");
		getch();
	    system("cls");
	    main();
	}
	
	else if(slot==7){ // Slot 7 
		  if(parkingspace[6]==1){
	  	  atime7();
		  fnpayment();
	       }
          else if(parkingspace[6]==0){
          printf("\nThis slot is empty..\n");
          getch();
   	      system("cls");
   	      main();
			
		}
		
		parkingspace[6]=0;
		bhr[6]=0;
		bmin[6]=0;
		printf("\nThe slot has been freed up.\n");
		getch();
	    system("cls");
	    main();
	}
	
	else if(slot==8){ // Slot 8 
		  if(parkingspace[7]==1){
	  	  atime8();
		  fnpayment();
	       }
          else if(parkingspace[7]==0){
          printf("\nThis slot is empty..\n");
          getch();
   	      system("cls");
   	      main();
			
		}
		
		parkingspace[7]=0;
		bhr[7]=0;
		bmin[7]=0;
		printf("\nThe slot has been freed up.\n");
		getch();
	    system("cls");
	    main();
	}
	
	else{
		printf("\nInvalid input.\n");
		getch();
        system("cls");
	    main();	
	}
		
}

inpayment(){
	if(parkingspace[0]==1){
		incarpay[0]=10.00;
	}
	else if(parkingspace[1]==1){
		incarpay[1]=10.00;
	}
	else if(parkingspace[2]==1){
		incarpay[2]=10.00;
	}
	else if(parkingspace[3]==1){
		incarpay[3]=10.00;
	}
	else if(parkingspace[4]==1){
		incarpay[4]=10.00;
	}
	else if(parkingspace[5]==1){
		incarpay[5]=10.00;
	}
	else if(parkingspace[6]==1){
		incarpay[6]=10.00;
	}
	else if(parkingspace[7]==1){
		incarpay[7]=10.00;
	}

}

fnpayment(){
	if(parkingspace[0]==1){ // if slot 1 
	    
		fncarpay[0]=incarpay[0]+(hrtime_elapsed*5); // total amount to be paid
do{
		printf("\nYou have a balance of P%.2f to be paid",fncarpay[0]);
		printf("\nHow much will you pay: ");
		scanf("%f",&fnamount[0]);
        if(fnamount[0]<fncarpay[0]){
        printf("\nThe Amount you paid is lower than what needs to be paid.");
        }
}while(fnamount[0]<fncarpay[0]);
		fncarpay[0]=fnamount[0]-fncarpay[0];
		printf("\nThank you for paying youre change is %.2f",fncarpay[0]);
	}
	
	else if(parkingspace[1]==1){ // if slot 2 
		fncarpay[1]=incarpay[1]+(hrtime_elapsed*5);
do{
		printf("\nYou have a balance of P%.2f to be paid",fncarpay[1]);
		printf("\nHow much will you pay: ");
		scanf("%f",&fnamount[1]);
		if(fnamount[1]<fncarpay[1]){
        printf("\nThe Amount you paid is lower than what needs to be paid.");
        }
}while(fnamount[1]<fncarpay[1]);
		fncarpay[1]=fnamount[1]-fncarpay[1];
		printf("\nThank you for paying youre change is %.2f",fncarpay[1]);
	}
	
	else if(parkingspace[2]==1){ // if slot 3
		fncarpay[2]=incarpay[2]+(hrtime_elapsed*5);
do{
		printf("\nYou have a balance of P%.2f to be paid",fncarpay[2]);
		printf("\nHow much will you pay: ");
		scanf("%f",&fnamount[2]);
		if(fnamount[2]<fncarpay[2]){
        printf("\nThe Amount you paid is lower than what needs to be paid.");
        }
}while(fnamount[2]<fncarpay[2]);
		fncarpay[2]=fnamount[2]-fncarpay[2];
		printf("\nThank you for paying youre change is %.2f",fncarpay[2]);
	} // end of slot 3 
	
	else if(parkingspace[3]==1){ // if slot 4
		fncarpay[3]=incarpay[3]+(hrtime_elapsed*5);
do{
		printf("\nYou have a balance of P%.2f to be paid",fncarpay[3]);
		printf("\nHow much will you pay: ");
		scanf("%f",&fnamount[3]);
		if(fnamount[3]<fncarpay[3]){
        printf("\nThe Amount you paid is lower than what needs to be paid.");
        }
}while(fnamount[3]<fncarpay[3]);
		fncarpay[3]=fnamount[3]-fncarpay[3];
		printf("\nThank you for paying youre change is %.2f",fncarpay[3]);
	} // end of if slot 4
	
	else if(parkingspace[4]==1){ // if slot 5
		fncarpay[4]=incarpay[4]+(hrtime_elapsed*5);
do{
		printf("\nYou have a balance of P%.2f to be paid",fncarpay[4]);
		printf("\nHow much will you pay: ");
		scanf("%f",&fnamount[4]);
		if(fnamount[4]<fncarpay[4]){
        printf("\nThe Amount you paid is lower than what needs to be paid.");
        }
}while(fnamount[4]<fncarpay[4]);
		fncarpay[4]=fnamount[4]-fncarpay[4];
		printf("\nThank you for paying youre change is %.2f",fncarpay[5]);
	} // end of if slot 5

else if(parkingspace[5]==1){ // if slot 6
		fncarpay[5]=incarpay[5]+(hrtime_elapsed*5);
do{
		printf("\nYou have a balance of P%.2f to be paid",fncarpay[5]);
		printf("\nHow much will you pay: ");
		scanf("%f",&fnamount[5]);
		if(fnamount[5]<fncarpay[5]){
        printf("\nThe Amount you paid is lower than what needs to be paid.");
        }
}while(fnamount[5]<fncarpay[5]);
		fncarpay[5]=fnamount[5]-fncarpay[5];
		printf("\nThank you for paying youre change is %.2f",fncarpay[5]);
	} // end of if slot 6
	
	else if(parkingspace[6]==1){ // if slot 7
		fncarpay[6]=incarpay[6]+(hrtime_elapsed*5);
do{
		printf("\nYou have a balance of P%.2f to be paid",fncarpay[6]);
		printf("\nHow much will you pay: ");
		scanf("%f",&fnamount[6]);
		if(fnamount[6]<fncarpay[6]){
        printf("\nThe Amount you paid is lower than what needs to be paid.");
        }
}while(fnamount[6]<fncarpay[6]);
		fncarpay[6]=fnamount[6]-fncarpay[6];
		printf("\nThank you for paying youre change is %.2f",fncarpay[6]);
	} // end of if slot 7
	
	else if(parkingspace[7]==1){ // if slot 8
		fncarpay[7]=incarpay[7]+(hrtime_elapsed*5);
do{
		printf("\nYou have a balance of P%.2f to be paid",fncarpay[7]);
		printf("\nHow much will you pay: ");
		scanf("%f",&fnamount[7]);
		if(fnamount[7]<fncarpay[7]){
        printf("\nThe Amount you paid is lower than what needs to be paid.");
        }
}while(fnamount[7]<fncarpay[7]);
		fncarpay[7]=fnamount[7]-fncarpay[7];
		printf("\nThank you for paying youre change is %.2f",fncarpay[7]);
	} // end of if slot 8
	
} // end of fnpayment 

btime1(){ // manages time for slot 1
	
		if(parkingspace[0]==1){ // if user reserved parking slot 1
do{
		printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&bhr[0]);
		if(bhr[0]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(bhr[0]>24);

do{
		printf("Minutes: ");
		scanf("%d",&bmin[0]);
		if(bmin[0]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  	
}while(bmin[0]>59);
        } // end of if
			
} // end of btime1()

btime2(){ // manages time for slot 2
		if(parkingspace[1]==1){ // if user reserved parking slot 2
do{
		printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&bhr[1]);
		if(bhr[1]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(bhr[1]>24);		
do{
		printf("Minutes: ");
		scanf("%d",&bmin[1]);
		if(bmin[1]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(bmin[1]>59);
        } // end of if

} // end of btime2()
	
btime3(){ // manages time for slot 3
	
		if(parkingspace[2]==1){ // if user reserved parking slot 3
do{
		printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&bhr[2]);
		if(bhr[2]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(bhr[1]>24);	
do{
		printf("Minutes: ");
		scanf("%d",&bmin[2]);
		if(bmin[2]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(bmin[1]>59);
	    } // end of if


	} // end of btime4()
	
btime4(){ // manages time for slot 4
	
		if(parkingspace[3]==1){ // if user reserved parking slot 3
do{
		printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&bhr[3]);
		if(bhr[3]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(bhr[3]>24);	
do{
		printf("Minutes: ");
		scanf("%d",&bmin[3]);
		if(bmin[3]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(bmin[3]>59);
	    } // end of if


	} // end of btime4()
	
btime5(){ // manages time for slot 5
	
		if(parkingspace[4]==1){ // if user reserved parking slot 5
do{
		printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&bhr[4]);
		if(bhr[4]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(bhr[4]>24);	
do{
		printf("Minutes: ");
		scanf("%d",&bmin[4]);
		if(bmin[4]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(bmin[4]>59);
	    } // end of if


	} // end of btime5()
	
btime6(){ // manages time for slot 6
	
		if(parkingspace[5]==1){ // if user reserved parking slot 6
do{
		printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&bhr[5]);
		if(bhr[5]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(bhr[5]>24);	
do{
		printf("Minutes: ");
		scanf("%d",&bmin[5]);
		if(bmin[5]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(bmin[5]>59);
	    } // end of if


	} // end of btime6()
	
btime7(){ // manages time for slot 7
	
		if(parkingspace[6]==1){ // if user reserved parking slot 6
do{
		printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&bhr[6]);
		if(bhr[6]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(bhr[6]>24);	
do{
		printf("Minutes: ");
		scanf("%d",&bmin[6]);
		if(bmin[6]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(bmin[6]>59);
	    } // end of if


	} // end of btime7()

btime8(){ // manages time for slot 8
	
		if(parkingspace[7]==1){ // if user reserved parking slot 6
do{
		printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&bhr[7]);
		if(bhr[7]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(bhr[7]>24);	
do{
		printf("Minutes: ");
		scanf("%d",&bmin[7]);
		if(bmin[7]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(bmin[7]>59);
	    } // end of if


	} // end of btime8()

atime1(){

 		if(parkingspace[0]==1){ // user chose slot 1
do{ // repeat until user enters an hour less than or equal 24
    	printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&ahr[0]);
		if(ahr[0]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(ahr[0]>24);
do{
		printf("Minutes: ");
		scanf("%d",&amin[0]);
		if(amin[0]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(amin[0]>59);		
		if(ahr[0]<bhr[0]){ // if hour reserved is greater than hour remove
		 hrtime_elapsed=(24-bhr[0])+ahr[0];	
		}
		else if(ahr[0]>bhr[0]||ahr[0]==bhr[0]&&amin[0]>bmin[0]){
		 hrtime_elapsed=ahr[0]-bhr[0];	
		}
		else if(ahr[0]==bhr[0]&&amin[0]<=bmin[0]){
		 hrtime_elapsed=24;	// Note
		}
    	mintime_elapsed=fabs(amin[0]-bmin[0]); // minutes elapsed
    	if(amin[0]<bmin[0]&&amin[0]!=bmin[0]){
	    hrtime_elapsed=hrtime_elapsed-1;
	    }
    	if (hrtime_elapsed>0){
		printf("\n%d Hour/s and %d mins have elapsed since slot was registed.",hrtime_elapsed,mintime_elapsed);  	
        }
    	else if(hrtime_elapsed==0){
	 	printf("\nCar stay has not exceeded one hour.\n");
	    }
	    
} // end of if
		
  }

atime2(){
	
if(parkingspace[1]==1){ // user chose slot 2
do{
    	printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&ahr[1]);
		if(ahr[1]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(ahr[1]>24);
do{
		printf("min: ");
		scanf("%d",&amin[1]);
		if(amin[1]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(amin[1]>59);	
		if(ahr[1]<bhr[1]){ // if hour reserved is greater than hour remove
		 hrtime_elapsed=(24-bhr[1])+ahr[1];	
		}
		else if(ahr[1]>bhr[1]||ahr[1]==bhr[1]&&amin[1]>bmin[1]){ 
		 hrtime_elapsed=ahr[1]-bhr[1];	
		}
		else if(ahr[1]==bhr[1]&&amin[1]<=bmin[1]){
		 hrtime_elapsed=24;	// Note
		}
    	mintime_elapsed=fabs(amin[1]-bmin[1]);
    	if(amin[1]<bmin[1]&&amin[1]!=bmin[1]){
	    hrtime_elapsed=hrtime_elapsed-1;
	    }
  		if (hrtime_elapsed>0){
		printf("\n%d Hour/s and %d mins have elapsed since slot was registed.",hrtime_elapsed,mintime_elapsed);  	
        }
    	else if(hrtime_elapsed==0){
	 	printf("\nCar stay has not exceeded one hour.\n");
	    }
		} // end of if

}

atime3(){
	
if(parkingspace[2]==1){ // user chose slot 3
do{
    	printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&ahr[2]);
		if(ahr[2]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(ahr[2]>24);
do{
		printf("Minute: ");
		scanf("%d",&amin[2]);
		if(amin[2]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(amin[2]>59);	
		if(ahr[2]<bhr[2]){ // if hour reserved is greater than hour remove
		 hrtime_elapsed=(24-bhr[2])+ahr[2];	
		}
		else if(ahr[2]>bhr[2]||ahr[2]==bhr[2]&&amin[2]>bmin[2]){
		 hrtime_elapsed=ahr[2]-bhr[2];	
		}
		else if(ahr[2]==bhr[2]&&amin[2]<=bmin[2]){
		 hrtime_elapsed=24;	// Note
		}
    	mintime_elapsed=fabs(amin[2]-bmin[2]);
    	if(amin[2]<bmin[2]&&amin[2]!=bmin[2]){
	    hrtime_elapsed=hrtime_elapsed-1;
	    }
    	if (hrtime_elapsed>0){
		printf("\n%d Hour/s and %d mins have elapsed since slot was registed.",hrtime_elapsed,mintime_elapsed);  	
        }
    	else if(hrtime_elapsed==0){
	 	printf("\nCar stay has not exceeded one hour.\n");
	    }
		} // end of if

}

atime4(){
	
if(parkingspace[3]==1){ // user chose slot 4
do{
    	printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&ahr[3]);
		if(ahr[3]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(ahr[3]>24);
do{
		printf("min: ");
		scanf("%d",&amin[3]);
		if(amin[3]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(amin[3]>59);			
		if(ahr[3]<bhr[3]){ // if hour reserved is greater than hour remove
		 hrtime_elapsed=(24-bhr[3])+ahr[3];	
		}
		else if(ahr[3]>bhr[3]||ahr[3]==bhr[3]&&amin[3]>bmin[3]){
		 hrtime_elapsed=ahr[3]-bhr[3];	
		}
		else if(ahr[3]==bhr[3]&&amin[3]<=bmin[3]){
		 hrtime_elapsed=24;	// Note
		}
    	mintime_elapsed=fabs(amin[3]-bmin[3]);
    	if(amin[3]<bmin[3]&&amin[3]!=bmin[3]){
	    hrtime_elapsed=hrtime_elapsed-1;
	    }
    	if (hrtime_elapsed>0){
		printf("\n%d Hour/s and %d mins have elapsed since slot was registed.",hrtime_elapsed,mintime_elapsed);  	
        }
    	else if(hrtime_elapsed==0){
	 	printf("\nCar stay has not exceeded one hour.\n");
	    }
		} // end of if

}

atime5(){
	
if(parkingspace[4]==1){ // user chose slot 5
do{
    	printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&ahr[4]);
		if(ahr[4]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(ahr[4]>24);
do{
		printf("min: ");
		scanf("%d",&amin[4]);
		if(amin[4]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(amin[4]>59);			
		if(ahr[4]<bhr[4]){ // if hour reserved is greater than hour remove
		 hrtime_elapsed=(24-bhr[4])+ahr[4];	
		}
		else if(ahr[4]>bhr[4]||ahr[4]==bhr[4]&&amin[4]>bmin[4]){
		 hrtime_elapsed=ahr[4]-bhr[4];	
		}
		else if(ahr[4]==bhr[4]&&amin[4]<=bmin[4]){
		 hrtime_elapsed=24;	// Note
		}
    	mintime_elapsed=fabs(amin[4]-bmin[4]);
    	if(amin[4]<bmin[4]&&amin[4]!=bmin[4]){
	    hrtime_elapsed=hrtime_elapsed-1;
	    }
    	if (hrtime_elapsed>0){
		printf("\n%d Hour/s and %d mins have elapsed since slot was registed.",hrtime_elapsed,mintime_elapsed);  	
        }
    	else if(hrtime_elapsed==0){
	 	printf("\nCar stay has not exceeded one hour.\n");
	    }
		} // end of if

}

atime6(){
	
if(parkingspace[5]==1){ // user chose slot 5
do{
    	printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&ahr[5]);
		if(ahr[5]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(ahr[5]>24);
do{
		printf("min: ");
		scanf("%d",&amin[5]);
		if(amin[5]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(amin[5]>59);			
		if(ahr[5]<bhr[5]){ // if hour reserved is greater than hour remove
		 hrtime_elapsed=(24-bhr[5])+ahr[5];	
		}
		else if(ahr[5]>bhr[5]||ahr[5]==bhr[5]&&amin[5]>bmin[5]){
		 hrtime_elapsed=ahr[5]-bhr[5];	
		}
		else if(ahr[5]==bhr[5]&&amin[5]<=bmin[5]){
		 hrtime_elapsed=24;	// Note
		}
    	mintime_elapsed=fabs(amin[5]-bmin[5]);
    	if(amin[5]<bmin[5]&&amin[5]!=bmin[5]){
	    hrtime_elapsed=hrtime_elapsed-1;
	    }
    	if (hrtime_elapsed>0){
		printf("\n%d Hour/s and %d mins have elapsed since slot was registed.",hrtime_elapsed,mintime_elapsed);  	
        }
    	else if(hrtime_elapsed==0){
	 	printf("\nCar stay has not exceeded one hour.\n");
	    }
		} // end of if

}

atime7(){
	
if(parkingspace[6]==1){ // user chose slot 7
do{
    	printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&ahr[6]);
		if(ahr[6]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(ahr[6]>24);
do{
		printf("Minutes: ");
		scanf("%d",&amin[6]);
		if(amin[6]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(amin[6]>59);			
		if(ahr[6]<bhr[6]){ // if hour reserved is greater than hour remove
		 hrtime_elapsed=(24-bhr[6])+ahr[6];	
		}
		else if(ahr[6]>bhr[6]||ahr[6]==bhr[6]&&amin[6]>bmin[6]){
		 hrtime_elapsed=ahr[6]-bhr[6];	
		}
		else if(ahr[6]==bhr[6]&&amin[6]<=bmin[6]){
		 hrtime_elapsed=24;	// Note
		}
    	mintime_elapsed=fabs(amin[6]-bmin[6]);
    	if(amin[6]<bmin[6]&&amin[6]!=bmin[6]){
	    hrtime_elapsed=hrtime_elapsed-1;
	    }
    	if (hrtime_elapsed>0){
		printf("\n%d Hour/s and %d mins have elapsed since slot was registed.",hrtime_elapsed,mintime_elapsed);  	
        }
    	else if(hrtime_elapsed==0){
	 	printf("\nCar stay has not exceeded one hour.\n");
	    }
		} // end of if

}

atime8(){
	
if(parkingspace[7]==1){ // user chose slot 8
do{
    	printf("\nEnter the time(24 Hour format):\nHour: ");
		scanf("%d",&ahr[7]);
		if(ahr[7]>24){ // if user entered an hour exceeding 24
		printf("\nThere are only 24 hours available.\n");	
		} // end of if 
}while(ahr[7]>24);
do{
		printf("Minutes: ");
		scanf("%d",&amin[7]);
		if(amin[7]>60){ // if user entered a bminute exceeding 60
		printf("\nThere are only 59 minutes available.\n");	
		}  
}while(amin[7]>59);			
		if(ahr[7]<bhr[7]){ // if hour reserved is greater than hour remove
		 hrtime_elapsed=(24-bhr[7])+ahr[7];	
		}
		else if(ahr[7]>bhr[7]||ahr[7]==bhr[7]&&amin[7]>bmin[7]){
		 hrtime_elapsed=ahr[7]-bhr[7];	
		}
		else if(ahr[7]==bhr[7]&&amin[7]<=bmin[7]){
		 hrtime_elapsed=24;	// Note
		}
    	mintime_elapsed=fabs(amin[7]-bmin[7]);
    	if(amin[7]<bmin[7]&&amin[7]!=bmin[7]){
	    hrtime_elapsed=hrtime_elapsed-1;
	    }
    	if (hrtime_elapsed>0){
		printf("\n%d Hour/s and %d mins have elapsed since slot was registed.",hrtime_elapsed,mintime_elapsed);  	
        }
    	else if(hrtime_elapsed==0){
	 	printf("\nCar stay has not exceeded one hour.\n");
	    }
		} // end of if

}

help(){
system ("cls");
system("color 0E");
printf("\nWelcome to Help Desk!\n");
printf("\n[-] To reserve a slot for the car about to park \nChoose [1] ");
printf("then choose a slot that is available\nthen enter the time car parked.");	
printf("\n\n[-] To remove a slot for the car about to leave the car park\n");
printf("Choose [2] then choose the slot that the parked car came from");
printf("\nthen enter the time car parked.");
printf("\n\n\tThe program will now proceed back to the program.");
printf("\n\t\tPress any key to Continue..");	

}

lockscrn(){
do{
	printf("\n\t\tOpen Carpark Monitoring and Payment System\n\n");
    printf("The Program is Locked\nFor Security Reasons, Please enter the six-digit Master PIN.");
    printf("\n\n[%d] - Chances to Enter PIN",counter);
    printf("\n\nEnter Here: ");
    scanf("%s",&pin);
    if((strcmp(pin,"123456")==0))
	{
	printf("\t\t\nAccess granted!....");
	loggedin=1;
	getch();
	system("cls");
	main();
	}
	else
	{
	printf("\t\t\tWrong PIN!");
	getch();
	system("cls");
	}
	counter--;
	if(counter==0){
 	printf("\n\nThe program will now terminate.");
 	getch();
 	exit(0);	
	}
}while(pin!="123456");
 

}

//
//  main.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include <time.h>
#include <string.h>
#include "smm_object.h"
#include "smm_database.h"
#include "smm_common.h"

#define BOARDFILEPATH "marbleBoardConfig.txt"
#define FOODFILEPATH "marbleFoodConfig.txt"
#define FESTFILEPATH "marbleFestivalConfig.txt"
//player number max indication.. maybe 100 players??
#define MAX_NODE 100

//board configuration parameters
static int board_nr;
static int food_nr;
static int festival_nr;

//plyer information "HOW MANY???" and "CHARACTERSITICS : POSITION ENERGY ETC" 
// 2de
static int player_nr;
static int player_energy[MAX_PLAYER];
static char player_position[MAX_PLAYER];
//inorder to contain the name storage 2d [][] neccessary char ****
static char player_name[MAX_PLAYER][MAX_CHARNAME];

//function prototypes
#if 0
int isGraduated(void); //check if any player is graduated
void generatePlayers(int n, int initEnergy); //generate a new player
void printGrades(int player); //print grade history of the player
void goForward(int player, int step); //make player go "step" steps on the board (check if player is graduated)
void printPlayerStatus(void); //print all player status at the beginning of each turn
float calcAverageGrade(int player); //calculate average grade of the player
smmGrade_e takeLecture(int player, char *lectureName, int credit); //take the lecture (insert a grade of the player)
void* findGrade(int player, char *lectureName); //find the grade from the player's grade history
void printGrades(int player); //print all the grade history of the player
#endif


void generate players(int n, int initEnergy){
	//we assume n number of players are playing inside so n number for loop is neccessary
	int i;
	 
	//input name
	printf();
	scanf("%s",player_name[i]);
	//user number? i indicating 
	
	//set position
	player_position[i]=0;
	//initial position should be 0
	
	//set energy
	plyer_energy[i]=initEnergy ;
}
int rolldie(int player)
{
    char c;
    printf(" Press any key to roll a die (press g to see grade): ");
    c = getchar();
    fflush(stdin);
    
#if 0
    if (c == 'g')
        printGrades(player);
#endif
    
    return (rand()%MAX_DIE + 1);
}


//action code when a player stays at a node
void actionNode(int player)
{
    switch(type)
    {
        //case lecture:
        default:
            break;
    }
}



int main(int argc, const char * argv[]) {
    
    FILE* fp;
    char name[MAX_CHARNAME];
    int type;
    int credit;
    int energy;
    
    board_nr = 0;
    food_nr = 0;
    festival_nr = 0;
    
    srand(time(NULL));
    
    
    //1. import parameters ---------------------------------------------------------------------------------
    //1-1. boardConfig 
    if ((fp = fopen(BOARDFILEPATH,"r")) == NULL)
    {
        printf("[ERROR] failed to open %s. This file should be in the same directory of SMMarble.exe.\n", BOARDFILEPATH);
        getchar();
        return -1;
    }
    
    printf("Reading board component......\n");
    while (fscanf(fp,"%s %i %i %i",name, &type, &credit, &energy)==4) //read a node parameter set 전자기학 # # # / 
	//scanf reads the number of data  ==4
	//int above defined : abstract data..just define a place 
	//so real data name should be stored ; data encapsulation neccessary
    {
        //store the parameter set
        smmObj_genNOode(name, type, credit, energy);
        board_nr++;
    
    }
    fclose(fp);
    printf("Total number of board nodes : %i\n", board_nr);
    
    for (i=0;i<board_nr;i++)
		printf("node %i: %s, %i\n",i,smmObj_getNodeName(i), smmObj_getNodeType(i),smmObj_getTypeName(SMMNODE_TYPE_LECTURE)); 
    
    #if 0 
    //2. food card config 
    if ((fp = fopen(FOODFILEPATH,"r")) == NULL)
    {
        printf("[ERROR] failed to open %s. This file should be in the same directory of SMMarble.exe.\n", FOODFILEPATH);
        return -1;
    }
    
    printf("\n\nReading food card component......\n");
    while () //read a food parameter set
    {
        //store the parameter set
    }
    fclose(fp);
    printf("Total number of food cards : %i\n", food_nr);
    
    
    
    //3. festival card config 
    if ((fp = fopen(FESTFILEPATH,"r")) == NULL)
    {
        printf("[ERROR] failed to open %s. This file should be in the same directory of SMMarble.exe.\n", FESTFILEPATH);
        return -1;
    }
    
    printf("\n\nReading festival card component......\n");
    while () //read a festival card string
    {
        //store the parameter set
    }
    fclose(fp);
    printf("Total number of festival cards : %i\n", festival_nr);
    
    
    
    //2. Player configuration ---------------------------------------------------------------------------------
    
    do
    {
        //input player number to player_nr
            printf("input player number:");
    		scanf("%d",&player_nr);
    		fflush(stdin);
    		//keyboard stream buffer empty process/ since when datas had been input example '\n' input , maybe leftover sth in buffer
    }
    while (player_nr<0 || player>MAX_PLAYER);
    //if player number is sth like a or b (else of number or excess the 100.. sth error should occur)--> condition do while used

    generatePlayers(player_nr, initEnergy);
     
    
    //3. SM Marble game starts ---------------------------------------------------------------------------------
    while () //is anybody graduated?
    {
        int die_result;
        
        //4-1. initial printing
        //printPlayerStatus();
        
        //4-2. die rolling (if not in experiment)
        
        
        //4-3. go forward
        //goForward();

		//4-4. take action at the destination node of the board
        //actionNode();
        
        //4-5. next turn
        
    }
    
    return 0;
}
#endif 

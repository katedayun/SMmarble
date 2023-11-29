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
#include "smm_database.c"
#include "smm_object.c"


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

int isGraduated(void); //check if any player is graduated
void generatePlayers(int n, int initEnergy); //generate a new player
void printGrades(int player); //print grade history of the player
void goForward(int player, int step); //make player go "step" steps on the board (check if player is graduated)
void printPlayerStatus(void); //print all player status at the beginning of each turn
float calcAverageGrade(int player); //calculate average grade of the player
smmGrade_e takeLecture(int player, char *lectureName, int credit); //take the lecture (insert a grade of the player)
void* findGrade(int player, char *lectureName); //find the grade from the player's grade history
void printGrades(int player); //print all the grade history of the player



void generatePlayers(int n, int initEnergy){
	//we assume n number of players are playing inside so n number for loop is neccessary
	int i;
	for(i=0;i<n;i++){
	
	//input name
	printf("Enter player name:");
	scanf("%s",player_name[i]);
	//user number? i indicating 
	
	//set position
	player_position[i]=0;
	//initial position should be 0
	
	//set energy
	player_energy[i]=initEnergy ;
}

}

//error fixed for "for loop" absent,,, maybe lost in the class ...
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
	int nodeType = node_t[player_position[player]].type;
     switch (nodeType) {
        case lecture: {
            // Lecture node logic
            if (player_energy[player] >= energyRequiredForLecture) {
                // Check if the lecture is not already taken
                if (!isLectureTaken(player, lectureName)) {
                    // Option to take the lecture or drop
                    char decision;
                    printf("Player %s at lecture node. Take lecture? (y/n): ", player_name[player]);
                    scanf(" %c", &decision);
                    if (decision == 'y' || decision == 'Y') {
                        smmGrade_e grade = takeLecture(player, lectureName, lectureCredit);
                        printf("Player %s took the lecture and received grade: %d\n", player_name[player], grade);
                    }
                } else {
                    printf("Player %s has already taken this lecture.\n", player_name[player]);
                }
            } else {
                printf("Player %s does not have enough energy to take the lecture.\n", player_name[player]);
            }
            break;
        }
        case RESTAURANT: {
            // Restaurant node logic
            int energyBoost = getRestaurantEnergyBoost(restaurantName); // Implement this function
            player_energy[player] += energyBoost;
            printf("Player %s visited the restaurant and gained %d energy.\n", player_name[player], energyBoost);
            break;
        }
         case LAB:
            // Lab node logic
            if (playerInExperiment[player]) {  // Assuming a flag indicating if the player is in an experiment
                if (rollForExperimentSuccess()) {  // Implement this function for experiment success check
                    printf("Player %s succeeded in the experiment.\n", player_name[player]);
                    playerInExperiment[player] = 0;  // Exit experiment state
                } else {
                    printf("Player %s failed in the experiment and remains in the lab.\n", player_name[player]);
                }
            } else {
                printf("Player %s is in the lab but not in an experiment.\n", player_name[player]);
            }
            break;

        case HOME:
            // Home node logic
            player_energy[player] += homeEnergyBoost;  // Define homeEnergyBoost as needed
            printf("Player %s visited home and gained %d energy.\n", player_name[player], homeEnergyBoost);
            break;

        case GO_TO_LAB:
            // Go to Lab node logic
            playerInExperiment[player] = 1;  // Set the player to be in an experiment state
            printf("Player %s is heading to the lab for an experiment.\n", player_name[player]);
            // Implement logic to move player to the lab
            break;

        case FOOD_CHANCE:
            // Food Chance node logic
            // Implement logic for random food card selection and energy boost
            break;

        case FESTIVAL:
            // Festival node logic
            // Implement logic for random festival card selection and mission execution
            break;

        default:
            printf("Player %s landed on an unrecognized node type.\n", player_name[player]);
            break;
    }
}
        	
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
        //getchar();
        return -1;
    }
    
    printf("Reading board component......\n");
    while (fscanf(fp,"%s %i %i %i",name, &type, &credit, &energy)==4) //read a node parameter set 전자기학 # # # / 
	//scanf reads the number of data  ==4
	//int above defined : abstract data..just define a place 
	//so real data name should be stored ; data encapsulation neccessary
    {
        //store the parameter set
        smmObj_genNode(name, type, credit, energy);
        board_nr++;
    
    }
    fclose(fp);
    printf("Total number of board nodes : %i\n", board_nr);
    
    int i; 
    //integer must be declared...
    for (i=0;i<board_nr;i++){
	
		printf("node %i: %s, %i\n",i,smmObj_getNodeName(i), smmObj_getNodeType(i)); 
		//,smmObj_getTypeName(SMMNODE_TYPE_LECTURE) why is this added:???? some meaning contain definetly...
    
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
	
	int initEnergy=100;
	//define initial energy neccessary
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

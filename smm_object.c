//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODETYPE    7
#define MAX_GRADE       9
#define MAX_NODE 		100




//vary name --> 2dimensional setting : recognizing the name of the route
static char smmNodeName[SMMNODE_TYPE_MAX][MAX_CHARNAME]={
	"LECTURE"
	"restaurant"
	"lab"
	"home"
	"go to lab"
	"food chance"
	"festival"
};
//expected "="
//all letter should be under 200/ so max char name  meaning
// smm node number would be 7 but indicated w/ type max

// Define smmGradeName
static char smmGradeName[SMMGRADE_TYPE_MAX][MAX_CHARNAME] = {
    "A+",
    "A0",
    "A-",
    "B+",
    "B0",
    "B-",
    "C+",
    "C0",
    "C-"
};
typedef enum {
    GRADE_A_PLUS,
    GRADE_A0,
    GRADE_A_MINUS,
    GRADE_B_PLUS,
    GRADE_B0,
    GRADE_B_MINUS,
    GRADE_C_PLUS,
    GRADE_C0,
    GRADE_C_MINUS,
    GRADE_F
} smmGrade_e;

//READING THE TXT FILE
typedef struct {
    char name[MAX_CHARNAME];
    int type;
    int minCredit;
    int maxCredit;
} Lecture;
 
typedef struct {
    char name[MAX_CHARNAME];
    int type;
    int minCredit;
    int maxCredit;
} Node;

extern Node nodes[MAX_NODE];

Node nodes[MAX_NODE];  

#define MAX_LECTURES 100
Lecture lectures[MAX_LECTURES];
int totalLectures = 0;



smmGrade_e takeLecture(int player, char *lectureName, int credit) {
	int i;
    for ( i = 0; i < totalLectures; i++) {
        if (strcmp(lectures[i].name, lectureName) == 0) {
            if (credit >= lectures[i].minCredit && credit <= lectures[i].maxCredit) {
                // Assuming logic to determine grade based on credit
                // Placeholder logic: the higher the credit, the better the grade
                int range = lectures[i].maxCredit - lectures[i].minCredit;
                int gradeIndex = (credit - lectures[i].minCredit) * MAX_GRADE / range;
                return gradeIndex < MAX_GRADE ? gradeIndex : MAX_GRADE - 1;
            } else {
                return GRADE_F; // F grade if credit is outside bounds
            }
        }
    }
    return GRADE_F; // F grade if lecture not found
}









//반환하는 문자열??? 
//char smmObj_getTypeName(int type){
//	return smmNodeName[type];
	// 2dimensional setting but the second one is empty/ only first one is filled [type]
//}
 
static char smmObj_name[MAX_NODE][MAX_CHARNAME];
//character name 2D matrix storage 
static int smmObj_type[MAX_NODE];
static int smmObj_credit[MAX_NODE];
static int smmObj_energy[MAX_NODE];
static int smmObj_noNode=0;//this is right now i am using node number/ maybe origianl size migth be 100 but I am not using all
//main.c my friend. smm_object.c I am using/ both two people workplace should be dividened
//using static block the overlap using
//mainc. c--> object.c sending the data is need "smmObj_genNode"??????????????????????????????
//this smmObj_genNode is also in main.c  

//object generation
void smmObj_genNode(char* name, int type, int credit, int energy)
{
    //storage is 100 but using th enode is 3.. maybe?
    strcpy(smmObj_name[smmObj_noNode],name);
    //since nmae is char we need to use the string copy function
	smmObj_type[smmObj_noNode]=type;
    smmObj_credit[smmObj_noNode]=credit;
	smmObj_energy[smmObj_noNode]=energy;
	//start from noNode = 0 up to number of integers... charging....
	smmObj_noNode++;
}
//READ OUT
char* Obj_getNodeName(int node_nr)
{
	return smmObj_name[smmObj_noNode];
}
//몇번쨰??? 
int smmObj_getNodeType(int node_nr)
{
	return smmObj_type[node_nr];
}
//credit enerrgy similar to right above re make!


//member retrieving



//element to string
char* smmObj_getNodeName(int node_nr)
{
    return smmNodeName[node_nr];
}

char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}
//IS that right to change to node_nr....? istead form smm_e_grade or sth... Iguess not but... 
//-->RETURN TO INTIAL CODE


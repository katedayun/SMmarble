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
static char smmNodeName[SMMNODE_TYPE_MAX][MAX_CHARNAME]{
	"lecture"
	"restaurant"
	"lab"
	"home"
	"go to lab"
	"food chance"
	"festival"
};
//all letter should be under 200/ so max char name  meaning
// smm node number would be 7 but indicated w/ type max

//반환하는 문자열??? 
char smmObj_getTypeName(int type){
	return smmNodeName[type];
	// 2dimensional setting but the second one is empty/ only first one is filled [type]
}
 
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

char* Obj_getNodeName(int node_nr)
{
	retrun smmObj_name[smmObj_noNode];
}
//몇번쨰??? 
int smmObj_getNodeType(int node_nr)
{
	retrun smmObj_type[node_nr];]
}
//credit enerrgy similar to right above re make!


//member retrieving



//element to string
char* smmObj_getNodeName(smmNode_e type)
{
    return smmNodeName[type];
}

char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}


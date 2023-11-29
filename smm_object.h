//
//  smm_object.h
//  SMMarble object
//
//  Created by Juyeop Kim on 2023/11/05.
//#if 0 / #endif

#ifndef smm_object_h
#define smm_object_h

//directly noticing by define 
#define SMMNODE_TYPE_LECTURE 0
#define SMMNODE_TYPE_RESTAURANT 1
#define SMMNODE_TYPE_LABORATORY 2
#define SMMNODE_TYPE_HOME 3
#define SMMNODE_TYPE_GOTOLAB 4
#define SMMNODE_TYPE_FOODCHANCE 5
#define SMMNODE_TYPE_FESTIVAL 6

#define SMMNODE_TYPE_MAX 7
//NAMING CONVENTION : name has to be ruled ... symmetrical 

/* node type :
    lecture,
    restaurant,
    laboratory,
    home,
    experiment,
    foodChance,
    festival
*/
//directly noticing by define 
#define SMMGRADE_TYPE_Aplus 0
#define SMMGRADE_TYPE_A0 1
#define SMMGRADE_TYPE_Aminus 2
#define SMMGRADE_TYPE_Bplus 3
#define SMMGRADE_TYPE_B0 4
#define SMMGRADE_TYPE_Bminus 5
#define SMMGRADE_TYPE_Cplus 6
#define SMMGRADE_TYPE_C0 7
#define SMMGRADE_TYPE_Cminus 8

#define SMMGRADE_TYPE_MAX 9


/* grade :
    A+,
    A0,
    A-,
    B+,
    B0,
    B-,
    C+,
    C0,
    C-
*/



//object generation

void smmObj_genNode(char* name, int type, int credit, int energy);
//member retrieving
char* Obj_getNodeName(int node_nr);
int smmObj_getNodeType(int node_nr);

//element to string

//function prototyping 
char* smmObj_getTypeName();

#endif /* smm_object_h */

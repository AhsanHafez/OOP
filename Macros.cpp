#include<stdio.h>
#include<string>
#include<fstream> 
#define ABS(a) ((a)<0?-(a):(a))
//#define INCLDE_INVENTORY_MODULE
//#define INCLDE_ACCOUNT_MODULE
#define IS_FULL_LEVEL_GAME
//#define IS_TRIAL_LEVEL_GAME
void show_inventory();
void show_account();
void trial_game();
void full_game();

main(){
    #ifdef INCLDE_INVENTORY_MODULE  
     show_inventory();
     #endif
     #ifdef INCLDE_ACCOUNT_MODULE
     show_account();
     #endif
     #ifdef IS_FULL_LEVEL_GAME
     full_game();
     #endif
     #ifdef IS_TRIAL_LEVEL_GAME
     trial_game();
     #endif

}
#ifdef INCLDE_INVENTORY_MODULE
void show_inventory(){
    printf("SHOWING INVENTORY MODULE \n");
}
#endif
#ifdef INCLDE_ACCOUNT_MODULE
void show_account(){
    printf("SHOWING ACCOUNT MODULE \n");
}
#endif
#ifdef IS_TRIAL_LEVEL_GAME
void trial_game(){
    printf("TRIAL VERSION OF GAME IS RUNNING \n");
}
#endif
#ifdef IS_FULL_LEVEL_GAME
void full_game(){
    printf("THIS IS ORIGNAL FULL VERSION OF GAME \n");
}
#endif
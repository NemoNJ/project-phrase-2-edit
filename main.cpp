#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "Player.cpp"
#include "Boss.cpp"
// #include "Weapon.cpp"
using namespace std;

void GameStart();

void GetEnter();
// void CreateBoss();
void AskPlayerName();
void ShowHowToplay();
void ShowMap();
string toUpperStr(string);
void ShowShop(Player);
void ShowFightPhase();
string name;

int level;
char player_action = '\0',BOSS_action = '\0';
bool changeturn = false;
Boss boss;
 Player Player1("");
    Boss Dummy1("Dummy1", rand() % 5 + 100, rand() % 2 + 3, rand() % 2 + 1);
    Boss Dummy2("Dummy2", rand() % 5 + 100, rand() % 2 + 3, rand() % 2 + 1);
    Boss Dummy3("Dummy3", rand() % 5 + 100, rand() % 2 + 3, rand() % 2 + 1);
    Boss Dummy4("Dummy4", rand() % 5 + 100, rand() % 2 + 3, rand() % 2 + 1);


string chooseboss(){
    if(level == 1){
         boss =  Dummy1;
    }
    if(level == 2){
        boss =  Dummy2;
    }
    if(level == 3){
        boss =  Dummy3;
    }
    if(level == 4){
        boss =  Dummy4;
    }
}

void button(char &player_action,char &BOSS_action){
    char click = getch();
    printf("%c\n",click);
    if(click == 'a'){ 
        player_action = 'a';
        BOSS_action = 'a';
        }
    else if(click == 'q'){
        player_action = 'q';
        BOSS_action = 'a';
    } 
    else if(click == 'g'){ 
        player_action = 'g';
        BOSS_action = 'a';
    }
    else if(click == 't'){
        player_action = 't';
            }
    else if(click == 'e') player_action = 'e';
    else cout << "Invalid input\n";
}

int main()
{
    srand(time(0));

    GameStart();
    // CreateBoss();
    AskPlayerName();
    cout << setw(62) << "Hi Player : " << name << endl;
    Player1.setname(name);
    GetEnter();
    ShowHowToplay();
    level = 1;
while(level > 4){ //วนรับค่า boss
    Player1.buyPhase();
    // Modify to read file to save current in future
    ShowMap();
    GetEnter();
    system("cls");
    // FightBoss1(Player1,DUMMY1);
    while(true){
		boss.bossnewturn();	//เปลี่ยน turn
		Player1.playernewturn();			
		ShowFightPhase();	
        //player
        button(player_action,BOSS_action);
        if(player_action == 'a') p = Player1.attack(); 
        
        if(player_action == 'q'){
            if(Player1.medkit > 0) p = Player1.heal();
            else cout << "Emtry\n";
        } 
        if(player_action == 'g'){
            if(level > 1 && Player1.grenade > 0) p = Player1.usegrenade(boss,boss_id);
            else if(level > 1 && Player1.grenade < 0) cout << "Emtry\n";
            else cout << "Your level is too low\n";
        }
        if(player_action == 'e') break;
        //mons
		if(level > 0){
        if(level == 4){
              BOSS_action = atkboss(BOSS_action);
        }
        else{
              BOSS_action = 'a';
        }
        }
        if(BOSS_action == 'a') m = boss.attack(soilder101,boss_id); 
        if(BOSS_action == 'b') m = boss.superattack(soilder101,boss_id);
        
		if(soilder101.playerisDead()){
			ShowFightPhase();
			playerLose();
			break; 
		}
		
		if(boss.bossisDead())){
			ShowFightPhase();//อาจแก้เป็นฉากตาย
			playerWin();
            if(level == 1) money += (500 + rand()%501);//โอกาสเงิน 2 เท่า
            if(level == 2) money += (1000 + rand()%1001);//โอกาสเงิน 2 เท่า
            if(level == 3) money += (1500 + rand()%9501);//โอกาสเกิด jackpot
            playerWin();
            level++;
            break;
        }
    }
}
}


string toUpperStr(string x)
{
    string y = x;
    for (unsigned i = 0; i < x.size(); i++)
        y[i] = toupper(x[i]);
    return y;
}
void AskPlayerName()
{
    cout << setw(62) << "Enter Your Name : ";
    cin.ignore();
    getline(cin, name);
    system("cls");
}
void GameStart()
{
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                            ____________________________________________                                                               |\n");
    printf("|                                                           [                                            ]                                                              |\n");
    printf("|                            *******************************[      WELCOME TO BATTLE BOSS GAME 03        ]*********************************                             |\n");
    printf("|                            *                              [____________________________________________]                                *                             |\n");
    printf("|                            *                                                                                                            *                             |\n");
    printf("|                            *                                          [1] PLAY GAME                                                     *                             |\n");
    printf("|                            *                                                                                                            *                             |\n");
    printf("|                            *                                          [2] HOW TO PLAY                                                   *                             |\n");
    printf("|                            *                                                                                                            *                             |\n");
    printf("|                            *                                          [E] EXIT                                                          *                             |\n");
    printf("|                            *                                                                                                            *                             |\n");
    printf("|                            *                                                                                                            *                             |\n");
    printf("|                            *                                                                                                            *                             |\n");
    printf("|                            *                                                                                                            *                             |\n");
    printf("|                            *                                              ....                                                          *                             |\n");
    printf("|                            *                                            .'    '.                                                        *                             |\n");
    printf("|                            *                                           .   ......  ___       _                                          *                             |\n");
    printf("|                            *                                           . .' I_I_;./___|_____/-|____                                     *                             |\n");
    printf("|                            *                                         .'     |     ____.--;;;;;;;'                                       *                             |\n");
    printf("|                            *                                        .  ...  |____/||  [ ]'''                                            *                             |\n");
    printf("|                            *                                        :     ...   ...'   [_]                                              *                             |\n");
    printf("|                            *                                       .    .     :                                                         *                             |\n");
    printf("|                            *                                       . :  . :  : .                                                        *                             |\n");
    printf("|                            *                                       : : .  :  : :                                                        *                             |\n");
    printf("|                            *                                       :...........:                                                        *                             |\n");
    printf("|                            *                                       :           :                                                        *                             |\n");
    printf("|                            **************************************************************************************************************                             |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
void GetEnter()
{
    cout << setw(70) << "Press Enter To go next";
    cin.get();
    system("cls");
}

void ShowHowToplay()
{
    cout << setw(62) << "Like Lab" << endl;
    GetEnter();
}
void ShowMap()
{
    if (level == 1)
    {
        // map in game stage 1
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                             [ MAP ]                                                                                   |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                 _____                                                                 |\n");
        printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
        printf("|                                                                              /                ( () () )                                                               |\n");
        printf("|                                                                             /                  (  ^  )                                                                |\n");
        printf("|                                                                            /                    |||||                                                                 |\n");
        printf("|                                                                           /                                                                                           |\n");
        printf("|                                                                          /                                                                                            |\n");
        printf("|                                                                         /                                                                                             |\n");
        printf("|                                                                        /                                                                                              |\n");
        printf("|                                                                       /                                                                                               |\n");
        printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
        printf("|                                                       /                                                                                                               |\n");
        printf("|                                                      /                                                                                                                |\n");
        printf("|                                                     /                                                                                                                 |\n");
        printf("|                                                    /                                                                                                                  |\n");
        printf("|                                                   /                                                                                                                   |\n");
        printf("|                                      ____________O ( Stage 2 )                                                                                                        |\n");
        printf("|                                     /                                                                                                                                 |\n");
        printf("|                                    /                                                                                                                                  |\n");
        printf("|                                   /                                                                                                                                   |\n");
        printf("|                                  /                                                                                                                                    |\n");
        printf("|                                 O ( Stage 1 )                                                                                                                         |\n");
        printf("|                          [ You Are Here ]                                                                                                                             |\n");
        printf("|       PRESS [Enter] To continue                                                                                                                                           |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (level == 2)
    {
        // map in game stage 2
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                             [ MAP ]                                                                                   |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                 _____                                                                 |\n");
        printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
        printf("|                                                                              /                ( () () )                                                               |\n");
        printf("|                                                                             /                  (  ^  )                                                                |\n");
        printf("|                                                                            /                    |||||                                                                 |\n");
        printf("|                                                                           /                                                                                           |\n");
        printf("|                                                                          /                                                                                            |\n");
        printf("|                                                                         /                                                                                             |\n");
        printf("|                                                                        /                                                                                              |\n");
        printf("|                                                                       /                                                                                               |\n");
        printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
        printf("|                                                       /                                                                                                               |\n");
        printf("|                                                      /                                                                                                                |\n");
        printf("|                                                     /                                                                                                                 |\n");
        printf("|                                                    /                                                                                                                  |\n");
        printf("|                                                   /                                                                                                                   |\n");
        printf("|                                      ____________O ( Stage 2 )                                                                                                        |\n");
        printf("|                                     /            [ You Are Here ]                                                                                                     |\n");
        printf("|                                    /                                                                                                                                  |\n");
        printf("|                                   /                                                                                                                                   |\n");
        printf("|                                  /                                                                                                                                    |\n");
        printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|       PRESS [Enter] To continue                                                                                                                                           |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (level == 3)
    {
        // map in game stage 3

        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                             [ MAP ]                                                                                   |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                 _____                                                                 |\n");
        printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
        printf("|                                                                              /                ( () () )                                                               |\n");
        printf("|                                                                             /                  (  ^  )                                                                |\n");
        printf("|                                                                            /                    |||||                                                                 |\n");
        printf("|                                                                           /                                                                                           |\n");
        printf("|                                                                          /                                                                                            |\n");
        printf("|                                                                         /                                                                                             |\n");
        printf("|                                                                        /                                                                                              |\n");
        printf("|                                                                       /                                                                                               |\n");
        printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
        printf("|                                                       /               [ You Are Here ]                                                                                |\n");
        printf("|                                                      /                                                                                                                |\n");
        printf("|                                                     /                                                                                                                 |\n");
        printf("|                                                    /                                                                                                                  |\n");
        printf("|                                                   /                                                                                                                   |\n");
        printf("|                                      ____________O ( Stage 2 complete )                                                                                               |\n");
        printf("|                                     /                                                                                                                                 |\n");
        printf("|                                    /                                                                                                                                  |\n");
        printf("|                                   /                                                                                                                                   |\n");
        printf("|                                  /                                                                                                                                    |\n");
        printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|       PRESS [Enter] To continue                                                                                                                                           |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (level == 4)
    {
        // map in game stage 4
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                             [ MAP ]                                                                                   |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|                                                                                                 _____                                                                 |\n");
        printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
        printf("|                                                                              /                ( () () )    [ You Are Here ]                                           |\n");
        printf("|                                                                             /                  (  ^  )                                                                |\n");
        printf("|                                                                            /                    |||||                                                                 |\n");
        printf("|                                                                           /                                                                                           |\n");
        printf("|                                                                          /                                                                                            |\n");
        printf("|                                                                         /                                                                                             |\n");
        printf("|                                                                        /                                                                                              |\n");
        printf("|                                                                       /                                                                                               |\n");
        printf("|                                                        ______________O ( Stage 3 complete )                                                                           |\n");
        printf("|                                                       /                                                                                                               |\n");
        printf("|                                                      /                                                                                                                |\n");
        printf("|                                                     /                                                                                                                 |\n");
        printf("|                                                    /                                                                                                                  |\n");
        printf("|                                                   /                                                                                                                   |\n");
        printf("|                                      ____________O ( Stage 2 complete )                                                                                               |\n");
        printf("|                                     /                                                                                                                                 |\n");
        printf("|                                    /                                                                                                                                  |\n");
        printf("|                                   /                                                                                                                                   |\n");
        printf("|                                  /                                                                                                                                    |\n");
        printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|       PRESS [Enter] To continue                                                                                                                                           |\n");
        printf("|                                                                                                                                                                       |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
}
// void FightBoss1()
// {
//     bool FightPhase = true;
//     while (FightPhase)
//     {
//         ShowFightPhase();
//     }
// }


void  ShowFightPhase(){
   if (level == 1 && !Player1.isAK && !Player1.isPistol && Dummy1) {
           if(Player1.hp < 0)  Player1.hp = 0;
           if(Dummy1.hp < 0) Dummy1.hp = 0;
//battle sence1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 1     |\n");
printf("|                         %s                                                                            The Stick Man LV 1                                              |\n",Player1.name);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       ------        ATK: %d                                      |\n",Player1.atk, Dummy1.atk);
printf("|                      /--------|      /|      HP:  %d                                                #     / -  - |       HP:  %d                                      |\n",Player1.hp, Dummy1.hp);
printf("|                      |/   I I |      ||      DEF: %d                                                #     | o  o |       DEF: %d                                      |\n", Player1.def, Dummy1.def);
printf("|                      ||    -  /      ||                                                             #     |  -   |                                                    |\n");
printf("|                        '------'      +++                                                            #     '-----'                                                     |\n");
printf("|                       /  ------------[]                                                             []----        |                                                   |\n");
printf("|                      /  |      |----/                                                               []------      |                                                   |\n");
printf("|                      |  |      |                                                                    #     |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

   }
   if (level == 2 && !Player1.isAK && !Player1.isPistol && Dummy2) {
           if(Player1.hp < 0)  Player1.hp = 0;
           if(Dummy2.hp < 0) Dummy2.hp = 0;
//battle sence 2-1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 2     |\n");
printf("|                         %s                                                                           The 9mm  LV 10                                                   |\n",Player1.name);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",Player1.atk, Dummy2.atk);
printf("|                      /--------|      /|      HP:  %d                                                    ---------|       HP:  %d                                      |\n",Player1.hp, Dummy2.hp);
printf("|                      |/   I I |      ||      DEF: %d                                                      | =  = |       DEF: %d                                      |\n", Player1.def, Dummy2.def);
printf("|                      ||    -  /      ||                                                                   |  -   |                                                    |\n");
printf("|                        '------'      +++                                                         '====     '-----'                                                    |\n");
printf("|                       /  ------------[]                                                             '[]----       |                                                   |\n");
printf("|                      /  |      |----/                                                                 ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }
   if (level == 2 && !Player1.isAK && Player1.isPistol && Dummy2) {
    if(Player1.hp < 0)  Player1.hp = 0;
           if(Dummy2.hp < 0) Dummy2.hp = 0;
//battle sence2-2
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 2     |\n");
printf("|                         %s                                                                              The 9mm  LV 10                                                |\n",Player1.name);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",Player1.atk, Dummy2.atk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",Player1.hp, Dummy2.hp);
printf("|                      |/   I I |              DEF: %d                                                      | =  = |       DEF: %d                                      |\n", Player1.def, Dummy2.def);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'       ===='                                                      '====     '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                            '[]----       |                                                   |\n");
printf("|                      /  |      |----/                                                                 ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

   }
   if (level == 3 && !Player1.isAK && Player1.isPistol && Dummy3) {
    if(Player1.hp < 0)  Player1.hp = 0;
           if(Dummy3.hp < 0) Dummy3.hp = 0;
//battle sence 3-1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 3     |\n");
printf("|                         %s                                                                             Toxic Timmy LV 25                                              |\n",Player1.name);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",Player1.atk, Dummy3.atk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",Player1.hp, Dummy3.hp);
printf("|                      |/   I I |              DEF: %d                                                      |[]-[] |       DEF: %d                                      |\n", Player1.def, Dummy3.def);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'       ===='                                                  -'=======q    '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                       ||   '[]==---      |                                                   |\n");
printf("|                      /  |      |----/                                                           --    ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }
   if (level == 3 && Player1.isAK && Player1.isPistol && Dummy3) {
    if(Player1.hp < 0)  Player1.hp = 0;
           if(Dummy3.hp < 0) Dummy3.hp = 0;
//battle sence 3-2
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 3     |\n");
printf("|                         %s                                                                             Toxic Timmy LV25                                               |\n",Player1.name);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------       ATK: %d                                      |\n",Player1.atk, Dummy3.atk);
printf("|                      /--------|              HP:  %d                                                    ---------|       HP:  %d                                      |\n",Player1.hp, Dummy3.hp);
printf("|                      |/   I I |              DEF: %d                                                      |[]-[] |       DEF: %d                                      |\n", Player1.def, Dummy3.def);
printf("|                      ||    -  /                                                                           |  -   |                                                    |\n");
printf("|                        '------'-----_==============='                                       -'=======q    '-----'                                                     |\n");
printf("|                       /  --------___/ |[]'-||---/                                              ||   '[]==---      |                                                   |\n");
printf("|                      /  |      ||____/     |_|                                                  --    ------      |                                                   |\n");
printf("|                      |  |      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      |==|      |                                                                          |       |                                                   |\n");
printf("|                      '=====[]=='                                                                          --------                                                    |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }
   if (level == 4 && !Player1.isAK && Player1.isPistol && Dummy4) {
    if(Player1.hp < 0)  Player1.hp = 0;
           if(Dummy4.hp < 0) Dummy4.hp = 0;
//battle sence 4-1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 4     |\n");
printf("|                         %s                                                                            Just_a_teen LV50                                                |\n",Player1.name);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------      ATK: %d                                       |\n",Player1.atk, Dummy4.atk);
printf("|                      /--------|              HP:  %d                                                    __|-------|__   HP:  %d                                       |\n",Player1.hp, Dummy4.hp);
printf("|                      |/   I I |              DEF: %d                                                      | U  U |      DEF: %d                                       |\n", Player1.def, Dummy4.def);
printf("|                      ||    -  /                                                                   |_:     |   ^  |                                                    |\n");
printf("|                        '------'       ===='                                                '==-'======'    '-----'                                                    |\n");
printf("|                       /  ------------[]'                                                       [|   '[]==-/  |_| ||                                                   |\n");
printf("|                      /  |      |----/                                                           [|    ------     ||                                                   |\n");
printf("|                      |  |      |                                                                 [|       |      ||                                                   |\n");
printf("|                      |==|      |                                                                          |[][][]||                                                   |\n");
printf("|                      |==|      |                                                                          | | | |||                                                   |\n");
printf("|                      '=====[]=='                                                                          ===[]====                                                   |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }

   if (level == 4 && Player1.isAK && Player1.isPistol && Dummy4) {
    if(Player1.hp < 0)  Player1.hp = 0;
           if(Dummy4.hp < 0) Dummy4.hp = 0;
//battle sence4-2

printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                           STAGE 4     |\n");
printf("|                         %s                                                                            Just_a_teen LV50                                                |\n",Player1.name);
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        DAMAGE                                                                              DAMAGE                                                     |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                        ------                                                                                                                                         |\n");
printf("|                       /      '               ATK: %d                                                       /------      ATK: %d                                       |\n",Player1.atk, Dummy4.atk);
printf("|                      /--------|              HP:  %d                                                    __|-------|__   HP:  %d                                       |\n",Player1.hp, Dummy4.hp);
printf("|                      |/   I I |              DEF: %d                                                      | U  U |      DEF: %d                                       |\n", Player1.def, Dummy4.def);
printf("|                      ||    -  /                                                                   |_:     |   ^  |                                                    |\n");
printf("|                         '------'-----_==============='                                     '==-'======'    '-----'                                                    |\n");
printf("|                       /  --------___/ |[]'-||---/                                              [|   '[]==-/  |_| ||                                                   |\n");
printf("|                      /  |      ||____/     |_|                                                  [|    ------     ||                                                   |\n");
printf("|                      |  |      |                                                                 [|       |      ||                                                   |\n");
printf("|                      |==|      |                                                                          |[][][]||                                                   |\n");
printf("|                      |==|      |                                                                          | | | |||                                                   |\n");
printf("|                      '=====[]=='                                                                          ===[]====                                                   |\n");
printf("|                      |         |                                                                          |       |                                                   |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|    CHOOSE YOUR ACTION :                                                                                                                                               |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                    [A] Attack          [G] USE_Grenade       [Q] USE_MedKit         [E] Exit                                                          |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
   }
};


void showmap(Unit soilder101){
    if (level == 1){
       //map in game stage 1
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 )                                                                                                        |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 )                                                                                                                         |\n");
printf("|                          [ You Are Here ]                                                                                                                             |\n");
printf("|       PRESS [T] To continue                                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (level == 2){
//map in game stage 2
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 )                                                                                                        |\n");
printf("|                                     /            [ You Are Here ]                                                                                                     |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
printf("|                                                                                                                                                                       |\n");
printf("|       PRESS [T] To continue                                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (level == 3){
//map in game stage 3

printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )                                                               |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 )                                                                                    |\n");
printf("|                                                       /               [ You Are Here ]                                                                                |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 complete )                                                                                               |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
printf("|                                                                                                                                                                       |\n");
printf("|       PRESS [T] To continue                                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
    if (level == 4){
    //map in game stage 4
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                             [ MAP ]                                                                                   |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                                                                                       |\n");
printf("|                                                                                                 _____                                                                 |\n");
printf("|                                                                               _____________O   (     )  ( Stage 4 Final Boss)                                         |\n");
printf("|                                                                              /                ( () () )    [ You Are Here ]                                           |\n");
printf("|                                                                             /                  (  ^  )                                                                |\n");
printf("|                                                                            /                    |||||                                                                 |\n");
printf("|                                                                           /                                                                                           |\n");
printf("|                                                                          /                                                                                            |\n");
printf("|                                                                         /                                                                                             |\n");
printf("|                                                                        /                                                                                              |\n");
printf("|                                                                       /                                                                                               |\n");
printf("|                                                        ______________O ( Stage 3 complete )                                                                           |\n");
printf("|                                                       /                                                                                                               |\n");
printf("|                                                      /                                                                                                                |\n");
printf("|                                                     /                                                                                                                 |\n");
printf("|                                                    /                                                                                                                  |\n");
printf("|                                                   /                                                                                                                   |\n");
printf("|                                      ____________O ( Stage 2 complete )                                                                                               |\n");
printf("|                                     /                                                                                                                                 |\n");
printf("|                                    /                                                                                                                                  |\n");
printf("|                                   /                                                                                                                                   |\n");
printf("|                                  /                                                                                                                                    |\n");
printf("|                                 O ( Stage 1 complete)                                                                                                                 |\n");
printf("|                                                                                                                                                                       |\n");
printf("|       PRESS [T] To continue                                                                                                                                           |\n");
printf("|                                                                                                                                                                       |\n");
printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }
};
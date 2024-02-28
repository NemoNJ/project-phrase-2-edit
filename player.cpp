#include <iostream>
#include <iomanip>
#include <cstdlib> // เพิ่ม include เพื่อใช้งาน rand()
#include "Boss.cpp"
using namespace std;

int PistolPrice = 150;
int ArmourPrice = 300;
int MedkitPrice = 100;
int AKPrice = 1000;
int grenadePrice = 200;

class Player
{
public:
    Player(string name);
    void setname(string);
    int getmoney(); // ระบุประเภทของฟังก์ชัน getmoney()
    void buyPistol();
    void buyArmour();
    void buyMedkit();
    void buyAK();
    void showshop();
    void buyGrenade();
    void buyPhase();
    void GetEnter();
    bool playerisDead();
    bool playernewturn();
    // void attacked(Boss);
    // private:
    string name;
    int hpmax;
    int hp;
    int atk;
    int def;
    int super_atk;
    bool changeturn;
    int money;
    int med = 0;
    int grenade = 0;
    int level = 1;

    bool armor;
    bool isPistol;
    bool isAK;
    bool buyphase = false;
    int playerattack(Boss &,string);
    int playerbeAttacked(int,string);
    int playerusegrenade(Boss &,string);
    int heal();
    int HeroATK();
    int HeroDEF();
    int HeroHP();
};
int Player::HeroATK(){
   int heroatk = atk;
   return  heroatk;
}
int Player::HeroDEF(){
    int herodef = def;
   return  herodef;
}
int Player::HeroHP(){
    int herohp = hp;
    if(herohp <= 0) herohp = 0;
   return  herohp;
}

Player::Player(string name)
{
    this->name = name;
    money = 200;
    hpmax = 120;
    hp = rand() % 20 + 100;
    atk = rand() % 7 + 1;
    def = rand() % 3 + 1;
    armor = false;
    isPistol = false;
    isAK = false;
    med = 0;
    grenade = 0;
    level = 1;
    changeturn = false;
    cout << setw(62) << "Hello Player " << name << endl;
}

void Player::setname(string name)
{
    this->name = name;
}

int Player::getmoney() // ระบุประเภทของฟังก์ชัน getmoney()
{
    return money;
}
void Player::showshop()
{

    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                         [  SHOP  ]                                                                                    |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|                 _______________==                                      ___     ___                                      _______________                               |\n");
    printf("|                q|[[[[ [__]   ___|                                      [ ]_____[ ]]                                    /______________/|                              |\n");
    printf("|                /_____________/_ |                                     |    VEST   ||                                   |      _      | |                              |\n");
    printf("|                |    [|_]'                                             |           ||                                   |   __| |__   | |                              |\n");
    printf("|                | ## |                                                 |___ ___ ___||                                   |  |__   __|  | |                              |\n");
    printf("|                | ## |                                                 |[__][__][__]|                                   |     |_|     | |                              |\n");
    printf("|                |_##_|                                                 |   |   |   ||                                   |  first aid  | |                              |\n");
    printf("|                                                                       |___|___|___|/                                   |_____________|/                               |\n");
    printf("|             Pistol Press[1]                                           Armor1 Press[2]                                  Medkit  Press[3]                               |\n");
    printf("|             PRICE : 150  $                                            PRICE : 300  $                                   PRICE : 100  $                                 |\n");
    printf("|             ATK   :  + 15 - 35 damage                                    DEF   : +10 def                                  HEAL  :  + 25 - 40 hp                       |\n");
    printf("|            Amount : %d                                                Amount : %d                                       Amount : %d                                   |\n", isPistol, armor, med);
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                            __                                                                                         |\n");
    printf("|                                  __:                                     /=||=-o                                                                                      |\n");
    printf("|                         /**********|======.._____    ==                 / [  ]                                                                                        |\n");
    printf("|                --------/  '/-----/ |=[][] !!-----|___/|                / [    ]                                                                                       |\n");
    printf("|               |        __  |_]--|--|=======-----------|               | [______]                                                                                      |\n");
    printf("|               |      _/  |_|     |  |                                    [    ]                                                                                       |\n");
    printf("|               |_____/    ==       |__|                                    [__]                                                                                        |\n");
    printf("|             Rifile  Press[4]                                         Grenade  Press[5]                                                                                |\n");
    printf("|             PRICE : 1000  $                                          PRICE : 200  $ ( 1 used )                                                                        |\n");
    printf("|             ATK   :  + 50 - 100 damage                                  ATK   : + 120 damage                                                                          |\n");
    printf("|             Amount : %d                                               Amount : %d / 2                                                                                 |\n", isAK, grenade);
    printf("|                                                                                                                                                                       |\n");
    printf("|                                                                                                                                                                       |\n");
    printf("|     YOUR MONEY : %d             PRESS [T] To continue                                                                                                                 |\n", getmoney());
    printf("|                                                                                                                                                                       |\n");
    printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

void Player::buyPistol()
{
    if (isPistol)
    {
        cout << setw(62) << "You already have it" << endl;
    }
    else if (money < PistolPrice)
    {
        cout << setw(62) << "You need more " << PistolPrice - money << " $\n";
    }
    else
    {
        money -= PistolPrice;
        isPistol = true;
        atk += 15+rand()%21;
        cout << setw(62) << "Success Buy Pistol" << endl;
    }
}

void Player::buyArmour()
{
    if (money >= ArmourPrice)
    {
        money -= ArmourPrice;
        def += 10;
        cout << setw(62) << "Success Buy Armour" << endl;

    }
    else
    {
        cout << setw(62) << "You need more : " << ArmourPrice - money << " $\n";
    }
}

void Player::buyMedkit()
{
    if (money >= MedkitPrice)
    {
        money -= MedkitPrice;
        med += 1;
        cout << setw(62) << "Success Buy Medkit" << endl;
    }
    else
    {
        cout << setw(62) << "You need more : " << MedkitPrice - money << " $\n";
    }
}

void Player::buyAK()
{
    if (isAK)
    {
        cout << setw(62) << "You already have it" << endl;
    }
    else if (money < AKPrice)
    {
        cout << setw(62) << "You need more " << AKPrice - money << " $\n";
    }
    else
    {
        money -= AKPrice;
        isAK = true;
        atk += 50 + rand()%51;
        cout << setw(62) << "Success Buy AK" << endl;
    }
}

void Player::buyGrenade()
{
    if (grenade >= 2)
    {
        cout << "You Can Have Only 2 grenade" << endl;
    }
    else if (money >= grenadePrice)
    {
        money -= grenadePrice;
        cout << setw(62) << "Success Buy Grenade" << endl;
    }
    else
    {
        cout << setw(62) << "You need more : " << grenadePrice - money << " $\n";
    }
}

void Player::buyPhase()
{

    buyphase = true;
    while (buyphase == true)
    {
        showshop();
        cout << setw(62) << "you choose : ";
        string choice;
        cin >> choice;
        if (choice == "T" || choice == "t")
        {
            buyphase = false;
            cin.ignore();
            GetEnter();
        }
        else if (choice == "1")
        {
            buyPistol();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "2")
        {
            buyArmour();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "3")
        {
            buyMedkit();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "4")
        {
            buyAK();
            cin.ignore();
            GetEnter();
        }
        else if (choice == "5")
        {
            buyGrenade();
            cin.ignore();
            GetEnter();
        }
        else
        {
            cout << "Wrong input" << endl;
            cin.ignore();
            GetEnter();
        }
    }
}

void Player::GetEnter()
{
    cout << setw(62) << "Press Enter To go next";
    cin.get();
    system("cls");
}

bool Player::playerisDead(){
     if(hp > 0) return false;
     else return true;
}
void Player::playernewturn(){
	changeturn = false;
}
 int Player::playerbeAttacked(int oppatk,string type){
    if (type == "Dummy1") {
        if(oppatk  > def){
        oppatk += (rand() % 6);
        hp = hp - (oppatk - def);
        return oppatk - def;
        }
        else{
         return 0;
        }
    } else if (type == "Dummy2") {
         if(oppatk  > def){
        oppatk += (rand() % 11);
        hp = hp - (oppatk - def);
        return oppatk - def;
        }
        else{
         return 0;
        }
    } else if (type == "Dummy3") {
         if(oppatk  > def){
        oppatk += (rand() % 21);
        hp = hp - (oppatk - def);
        return oppatk - def;
       }
        else{
         return 0;
        }
    } else if (type == "Dummy4") {
         if(oppatk  > def){
        oppatk += (rand() % 51);
        hp = hp - (oppatk - def);
        return oppatk - def;
       }
        else{
         return 0;
        }
    return 0; // Default case
}
 }
 int Player::playerattack(Boss &boss,string name){
	return boss.playerbeAttacked(atk,name);

 }
int Player::playerusegrenade(Boss &boss,string name){
         grenade -= 1;// ใช้ระเบิดแล้ว
         return  boss.playerbeAttacked(120,name);
    }
int Player::heal(){//ใช้ med
if(med > 0){
  int healing;
     healing = (25+rand()%16);
    if(healing+hp >= hpmax){
        healing = hpmax-hp ;
        hp = hpmax ;
        return healing ;
    }
     hp += healing;
     return healing;
     med -= 1; //เอากล่องที่ใช้แล้วออก
    }
    else{
        cout << "OUT OF STOCK";
        return 0;
    }
}

// void Player::attacked(Boss Boss1)
// {
//     if (Player1.atk > Boss1.def)
//     {
//         Boss1.beattacked(Player1.atk);
//     }
//     else
//     {
//         Boss1.Beattacked(0);
//     }
// }
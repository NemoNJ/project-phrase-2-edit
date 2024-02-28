#include <iostream>
#include <string>
#include "Player.cpp"
using namespace std;
class Boss
{
public:
    Boss(string Name, int Hpmax, int Attack, int Def);

    string name;
    int hpmax;
    int hp;
    int atk;
    int def;
    int super_atk;
    bool changeturn;
    bool bossisDead();
    bool bossnewturn();
    int bossbeAttacked(int);
    int bossattack();
    int bossbeSuperAttacked(int ,string);
    int bossSuperattack(string);
};

Boss::Boss(string Name, int Hpmax, int Attack, int Def)
{
    this->name = Name;
    this->hpmax = Hpmax;
    this->atk = Attack;
    this->def = Def;
    // cout << setw(62) << " Boss " << name << " Has created" << endl;
}
bool Boss::bossisDead(){
    if(hp > 0) return false;
    else return true;
}
bool Boss::bossnewturn(){
    changeturn = false;
}
int Boss::bossbeAttacked(int oppatk){//ต้องสุ่ม damage ทุกครั้งที่ attack
        if(oppatk  > def){ //แก้bug heal ด้วยเกราะ;
        oppatk += (rand() % 16);
        hp = hp - (oppatk - def);
        return oppatk - def;
        }
        else{
        return 0;
        }
}
int Boss::attack(){
	return player1.bossbeAttacked(atk);
}
int Boss::bossbeSuperAttacked(int oppatk,string boss.name) {//ต้องสุ่ม damage ทุกครั้งที่ attack ดาเมจที่น้อยกว่าเกราะจะถูกเพิ่มเป็นเลือดให้บอส
    int super_oppatk = 3 * oppatk;
    if (type == "Dummy1") {
        if(super_oppatk  > def){
        super_oppatk += (rand() % 6);
        hp = hp - (super_oppatk - def);
        return super_oppatk - def;
        }
        else{
        return 0;
        }
    } else if (type == "Dummy2") {
        if(super_oppatk  > def){
        super_oppatk += (rand() % 11);
        hp = hp - (super_oppatk - def);
        return super_oppatk - def;
        }
        else{
        return 0;
        }
    } else if (type == "Dummy3") {
        if(super_oppatk  > def){
        super_oppatk += (rand() % 21);
        hp = hp - (super_oppatk - def);
        return super_oppatk - def;
        }
        else{
        return 0;
        }
    } else if (type == "Dummy4") {
        if(super_oppatk  > def){
        super_oppatk += (rand() % 51);
        hp = hp - (super_oppatk - def);
        return super_oppatk - def;
        }
        else{
        return 0;
        }
    }
    return 0; // Default case
}
int Boss::bossSuperattack(string name){
	return boss.beSuperAttacked(atk,name);
}
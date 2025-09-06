/*
HEADER FILE
*/

#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Spell {
    string name;
    int spell_cost;
    int spell_damage;
};

class Boss
{
    public:
    Boss();
    Boss(string _type, int _health, int _damage);
    string type;
    int health;
    int damage;
};

class Enemy
{
    public:
    Enemy();
    Enemy(string _type, int _health, int _damage);
    string type;
    int health;
    int damage;

};

class Wizard 
{
    public:
        Wizard();
        void SetPlayerName();
        void SetRace();
        void ManipMoney();
        void CreateSpell();
        void ChangeSpell();
        void PrintWizardInfo();
        void FightEnemy(Enemy _enemy, Wizard& _wizard, string _spell_slot, int _spell_cost, int _spell_damage);
        void FightBoss(Boss& _boss);
        void LevelUp(Wizard& _wizard);
        int GetMagicCost() const;
        int GetHealth() const;
        string GetName() const;
        string GetRace() const;
        string GetSpellName() const;
        Spell spell;
        int level;
        int health;
        double money;
        
        private:
        string name;
        string race;
        string spell_slot;
        int spell_cost;
        int magic_capacity;

};


#endif
/*
CLASS DEFINITIONS
*/
#include "CLASS_H.h"

//Default
Wizard::Wizard()
{
    name = "Unknown";
    race = "Unknown";
    spell_slot = "None";
    spell_cost = -1;
    magic_capacity = -1;
    money = -1.0;
    health = 100;
    level = 1;
}
void Wizard::SetPlayerName()
{
    string player_name;
    cout << "\nEnter Name for wizard: " << endl;
    getline(cin, player_name);
    name = player_name;
}

void Wizard::SetRace()
{
    string player_race;
    short choice;
    cout << endl;
    cout << "Enter the character's Race (Enter 1-3)" << endl;
    cout << "    1) Human" << endl;
    cout << "    2) Elf" << endl;
    cout << "    3) Dwarf" << endl;
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
        case 1:
            player_race = "Human";
            break;
        case 2:
            player_race = "Elf";
            break;
        case 3:
            player_race = "Dwarf";
            break;
    }
    race = player_race;
}

void Wizard::CreateSpell()
{
    short choice;
    cout << endl;
    cout << "Enter the character's spell with the associated cost (Enter 1-3)" << endl;
    cout << "    1) FireBall: 20 Damage, 5 magic" << endl;
    cout << "    2) IceStorm:: 40 Damage, 10 magic" << endl;
    cout << "    3) LightningStrike: 50 Damage, 15 magic" << endl;
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
        case 1:
            spell.name = "FireBall";
            spell.spell_cost = 5;
            spell.spell_damage = 20;
            break;
        case 2:
            spell.name = "IceStorm";
            spell.spell_cost = 10;
            spell.spell_damage = 40;
            break;
        case 3:
            spell.name = "LightningStrike";
            spell.spell_cost = 15;
            spell.spell_damage = 50;
            break;
    }
    spell_slot = spell.name;
    spell_cost = spell.spell_cost;
}

void Wizard::FightEnemy(Enemy _enemy, Wizard& _wizard, string _spell_slot, int _spell_cost, int _spell_damage)
{
    cout << endl;
    cout << "ATTACKING ENEMY OF TYPE: " << _enemy.type << " (" << _enemy.health << " health)" << endl;

    int rand_damage_taken = rand() % 20 + 1;
    cout << "YOU CAST SPELL: " << _spell_slot <<" AND DEALT " << _spell_damage << " DAMAGE" << endl;
    int new_enemy_health = _enemy.health - _spell_damage;
    _wizard.health -= rand_damage_taken;
    if(new_enemy_health <= 0)
    {
        new_enemy_health = 0;
        cout << "   ENEMY DEFEATED" << endl;
    }
    else 
    {
        cout << _enemy.type << " NOW HAS " << new_enemy_health << " HEALTH"  << endl;
    }
    cout << "   YOU TOOK " << rand_damage_taken << " DAMAGE DURING BATTLE" <<
    " YOU NOW HAVE " << _wizard.health << " HEALTH" << endl; 

}

void Wizard::FightBoss(Boss& boss)
{
    cout << "\n\nYOU HAVE BEEN SNEAK ATTACKED BY A BOSS OF TYPE " << boss.type << " ("
    << boss.health << ")" << endl;
    cout << "YOU LOST " << boss.damage << " HEALTH" << endl;
    health -= boss.damage;
    cout << "YOU NOW HAVE " << health << " HEALTH" << endl;
    do
    {
        cout << "\nPRESS ENTER TO CONTINUE" << endl;
        cin.ignore();
        cin.get();

        cout << "YOU ATTACK WITH " << spell.name << " AND DEAL " << spell.spell_damage << " DAMAGE" << endl;
        boss.health -= spell.spell_damage;
        if (boss.health < 0)
            boss.health = 0;
        cout << "BOSS NOW HAS " << boss.health << " HEALTH" << endl;

        if (boss.health == 0)
        {
            cout << "\nBOSS DEFEATED!" << endl;
            break; 
        }

        cout << "\nPRESS ENTER TO CONTINUE" << endl;
        cin.get();

        cout << "BOSS ATTACKS YOU AND DEALS " << boss.damage << " DAMAGE" << endl;
        health -= boss.damage;
        if (health < 0)
            health = 0;
        cout << "YOU NOW HAVE " << health << " HEALTH" << endl;

        if (health == 0)
        {
            cout << "\nYOU HAVE BEEN DEFEATED BY THE BOSS..." << endl;
            break; 
        }
    } while(health > 0 && boss.health > 0);
}

void Wizard::LevelUp(Wizard& _wizard)
{
    _wizard.level += 1;
    cout << "\n\nYOU HAVE A LEVEL UP AVAILABLE! WIZARD IS NOW LEVEL " << _wizard.level << endl;
    cout << "CHOOSE WHICH CATEGORY YOU'D LIKE TO LEVEL UP" << endl;
    cout << "   1) Health" << endl;
    cout << "   2) Spell Damage" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
        case 1:
            _wizard.health += 20;
            cout << "\nYOUR HEALTH IS NOW " << _wizard.health;
            break;
        case 2:
            _wizard.spell.spell_damage += 10;
            cout << "YOUR SPELL: " << _wizard.spell.name << " NOW DEALS " << 
            _wizard.spell.spell_damage << " DAMAGE "; 
            break;
    }
}

void Wizard::ChangeSpell()
{
    int choice;
    cout << "\n\nYOU ARE NOW STRONG ENOUGH TO ACQUIRE A MORE POWERFUL SPELL (Enter 1-3)" << endl;
    cout << "     1) Magic Missile: 50 Damage, 40 Magic" << endl;
    cout << "     2) Poison Cloud: 30 Damage, 20 Magic" << endl;
    cout << "     3) Blizzard: 80 Damage, 60 Magic" << endl;
    cin >> choice;

    switch(choice) 
    {
        case 1:
            spell.name = "Magic Missile";
            spell.spell_damage = 50;
            spell.spell_cost = 40;
            break;
        case 2:
            spell.name = "Poison Cloud";
            spell.spell_damage = 30;
            spell.spell_cost = 20;
            break;
        case 3:
            spell.name = "Blizzard";
            spell.spell_damage = 80;
            spell.spell_cost = 60;
            break;
    }

}

void Wizard::PrintWizardInfo()
{
    cout << "\n\n----- WIZARD -----\n"; 
    cout << endl;
    cout << "\nName: " << GetName();
    cout << "\nRace: " << GetRace();
    cout << "\nSpell: " << spell.name;
    cout << "\nSpell Cost: " << spell.spell_cost;
    cout << "\nSpell Damage: " << spell.spell_damage;
    cout << "\nHealth: " << health;
    cout << "\nLevel: " << level << endl;
}

int Wizard::GetMagicCost() const
{
    return spell_cost;
}

string Wizard::GetName() const
{
    return name;
}

string Wizard::GetRace() const
{
    return race;
}

string Wizard::GetSpellName() const
{
    return spell_slot;
}

// ENEMY

// DEFAULT
Enemy::Enemy()
{
    type = "Unknown";
    health = -1;
    damage = -1;
}

Enemy::Enemy(string _type, int _health, int _damage)
{
    type = _type;
    health = _health;
    damage = _damage;
}

// BOSS
Boss::Boss()
{
    type = "Unknown";
    health = -1;
    damage = -1;
}

Boss::Boss(string _type, int _health, int _damage)
{
    type = _type;
    health = _health;
    damage = _damage;
}



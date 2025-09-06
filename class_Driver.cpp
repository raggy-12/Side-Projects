/*
MAIN FUNCTION
*/
#include "CLASS_H.h"
int main()
{
    srand(time(0));

    cout << "Welcome to wizard simulator. Enter the information for your wizard" << endl;
    Wizard wizard;
    wizard.SetPlayerName();
    wizard.SetRace();
    wizard.CreateSpell();
    cout << endl;
    wizard.PrintWizardInfo();

    cout << "\nENTER THE NUMBER OF ENEMIES YOU'D LIKE TO FIGHT: ";
    int num_enemies;
    cin >> num_enemies;
    Enemy* enemyArr = new Enemy[num_enemies];

    int current_wizard_level = wizard.level;
    for (int i = 0; i < num_enemies; i++)
    {
        enemyArr[i].type = "Goblin";
        enemyArr[i].damage = 10;
        enemyArr[i].health = 20;
        wizard.FightEnemy(enemyArr[i], wizard, wizard.spell.name, wizard.spell.spell_cost, wizard.spell.spell_damage);
        wizard.level += 1;
        cout << "\nYOUR WIZARD IS NOW LEVEL " << wizard.level;
        if(!(i == num_enemies - 1))
        {
            cout << "\nPRESS ENTER TO CONTINUE" << endl;
            cin.ignore();
            cin.get();
        }
    }
    int new_wizard_level = wizard.level;
    for(int i = current_wizard_level; i < new_wizard_level; i++)
        wizard.LevelUp(wizard);
    if(wizard.level >= 3)
    {
        wizard.ChangeSpell();
    } 

    wizard.PrintWizardInfo();
    
    delete [] enemyArr;
    Boss boss = Boss("Orc", 250, 30);
    wizard.FightBoss(boss);

    int rand_num = rand() % 2 + 1;
    cout << "\nYOU RECOVERED A MAGIC STAFF FROM THE BOSS'S CORPSE" << endl;
    
    switch(rand_num)
    {
        case 1:
            cout << "THE STAFF IS OF EPIC RARITY! SPELL DANAGE NOW HAS A 2X DAMAGE MULTIPLIER" << endl;
            wizard.spell.spell_damage *= 2;
            cout << wizard.spell.name << " NOW DEALS " << wizard.spell.spell_damage << " DAMAGE" << endl;
            break;
        case 2:
            cout << "THE STAFF IS OF LEGENDARY RARITY! SPELL DAMAGE NOW HAS A 3X DAMAGE MULTIPLIER" << endl;
            wizard.spell.spell_damage *= 3;
            cout << wizard.spell.name << " NOW DEALS " << wizard.spell.spell_damage << " DAMAGE" << endl;
            break;
    }

}
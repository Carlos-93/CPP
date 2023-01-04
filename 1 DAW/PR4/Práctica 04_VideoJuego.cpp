// (LIBRERIAS)
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

// (ATRIBUTOS DEL BALROG)
string enemyName1 = "Balrog";
int enemyHP1 = 800;
bool enemyIsAlive1 = true;

// (ATRIBUTOS DEL ORCO)
string enemyName2 = "Orco";
int enemyHP2 = 300;
bool enemyIsAlive2 = true;

// (ATRIBUTOS DEL HÉROE)
string heroName;
int heroHP = 700;
bool heroIsAlive = true;

// (ATAQUES DEL HÉROE)
int espada = 150;
int magia = 400;
int flecha = 100;

// (VARIABLES)
int enemySelect;
int ataque;
int enemyDamage1;
int enemyDamage2;

// (BOOLEAN)
bool enemiesDead() {

    if (heroHP > 0 && enemyHP1 <= 0 && enemyHP2 <= 0) {
        PlaySound(TEXT("Final.wav"), NULL, SND_FILENAME | SND_SYNC);
        cout << "----------------------------------------------------------\n";
        cout << "Has matado a las dos criaturas, tus amigos estan a salvo!!\n";
        cout << "----------------------------------------------------------\n";
        return  enemyIsAlive1 = false;
        return  enemyIsAlive2 = false;
    }
    else {
        return  enemyIsAlive1 = true;
        return  enemyIsAlive2 = true;

    }
}
bool heroDead() {

    if (heroHP <= 0) {
        heroHP = 0;
        PlaySound(TEXT("FinalHeroe.wav"), NULL, SND_FILENAME | SND_SYNC);
        cout << "---------------\n";
        cout << "Te han matado!!\n";
        cout << "---------------\n";
        return heroIsAlive = false;
    }
    else {
        return heroIsAlive = true;
    }
}

// (INT)
int selectEnemyAttack() {

    cout << "A que enemigo quieres atacar?\n";
    if (enemyIsAlive1) {
        cout << "[1]: " << enemyName1 << " \n";
    }
    if (enemyIsAlive2) {
        cout << "[2]: " << enemyName2 << " \n";
    }
    cin >> enemySelect;

    while (enemySelect != 1 && enemySelect != 2) {
        cout << "Ese enemigo no existe, por favor introduce [1] o [2]\n";
        cin >> enemySelect;
    }
    return enemySelect;
}

// (VOID)
void introductionGame() {

    cout << "Entre las llamas, un temible " << enemyName1 << " acaba de aparecer, con " << enemyHP1 << " puntos de vida.\n";
    cout << "A su lado tambien se encuentra un " << enemyName2 << ", con " << enemyHP2 << " puntos de vida.\n\n";
    cout << "Tienes que evitar que los enemigos crucen el puente para que no destruyan a tus amigos, eliminalos si es necesario.\n";
    cout << "Como se llama el heroe que va a pelear contra estas dos criaturas?\n";
    cin >> heroName;
    cout << "El heroe se llama " << heroName << "\n";
    system("pause");
    PlaySound(TEXT("Introduccion.wav"), NULL, SND_FILENAME | SND_SYNC);
}
void lifePointsHeroEnemy1Enemy2() {

    cout << "----------------------------\n";
    cout << enemyName1 << "    " << enemyHP1 << " Puntos de vida\n";
    cout << enemyName2 << "      " << enemyHP2 << " Puntos de vida\n";
    cout << heroName << "   " << heroHP << " Puntos de vida\n";
    cout << "----------------------------\n";
}
void lifePointsHeroEnemy(int& enemiesHPS, string& enemiesNames) {

    cout << "----------------------------\n";
    cout << enemiesNames << "    " << enemiesHPS << " Puntos de vida\n";
    cout << heroName << "   " << heroHP << " Puntos de vida\n";
    cout << "----------------------------\n";

    cout << "Ya solamente te queda por matar al " << enemiesNames << "\n";
}
void attackEspada(int& enemiesHPS, bool& enemiesStatus, string& enemiesNames) {

    enemiesHPS = enemiesHPS - espada;
    if (enemiesHPS <= 0) {
        enemiesHPS = 0;
    }
    cout << "Has atacado con la espada\n";
    cout << "-------------------------\n";
    cout << "Le has hecho " << espada << " puntos de danyo\n";
    cout << "Al " << enemiesNames << " le quedan " << enemiesHPS << " puntos de vida\n";
    cout << "--------------------------------------\n";
    if (enemiesHPS <= 0) {
        enemiesHPS = 0;
        enemiesStatus = false;
        cout << "Has matado al " << enemiesNames << "\n";
        cout << "--------------------\n";
    }
}
void attackMagia(int& enemiesHPS, bool& enemiesStatus, string& enemiesNames) {

    enemiesHPS = enemiesHPS - magia;
    if (enemiesHPS <= 0) {
        enemiesHPS = 0;
    }
    cout << "Has atacado con la magia\n";
    cout << "------------------------\n";
    cout << "Le has hecho " << magia << " puntos de danyo\n";
    cout << "Al " << enemiesNames << " le quedan " << enemiesHPS << " puntos de vida\n";
    cout << "--------------------------------------\n";
    if (enemiesHPS <= 0) {
        enemiesHPS = 0;
        enemiesStatus = false;
        cout << "Has matado al " << enemiesNames << "\n";
        cout << "--------------------\n";
    }
}
void attackFlecha(int& enemiesHPS, bool& enemiesStatus, string& enemiesNames) {

    enemiesHPS = enemiesHPS - flecha;
    if (enemiesHPS <= 0) {
        enemiesHPS = 0;
    }
    cout << "Has atacado con la flecha\n";
    cout << "-------------------------\n";
    cout << "Le has hecho " << flecha << " puntos de danyo\n";
    cout << "Al " << enemiesNames << " le quedan " << enemiesHPS << " puntos de vida\n";
    cout << "--------------------------------------\n";
    if (enemiesHPS <= 0) {
        enemiesHPS = 0;
        enemiesStatus = false;
        cout << "Has matado al " << enemiesNames << "\n";
        cout << "--------------------\n";
    }
}
void attackToHero(int& enemiesHPS, int& enemiesDamage, string& enemiesNames) {

    if (enemiesHPS > 0) {
        enemiesDamage = rand() % 200 + 1;
        heroHP = heroHP - enemiesDamage;
        if (heroHP <= 0) {
            heroHP = 0;
            heroIsAlive = false;
        }
        cout << "El " << enemiesNames << " te ha hecho un ataque de " << enemiesDamage << " puntos de danyo\n";
        cout << "Te quedan " << heroHP << " puntos de vida\n";
        cout << "----------------------------\n";
    }
}
void switchToEnemies(int& enemiesHPS, bool& enemiesStatus, string& enemiesNames) {

    switch (ataque) {

    case 1:
        PlaySound(TEXT("Espada.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackEspada(enemiesHPS, enemiesStatus, enemiesNames);
        break;

    case 2:
        PlaySound(TEXT("Magia.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackMagia(enemiesHPS, enemiesStatus, enemiesNames);
        break;

    case 3:
        PlaySound(TEXT("Flecha.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackFlecha(enemiesHPS, enemiesStatus, enemiesNames);
        break;

    default:
        cout << "No dispones de esa habilidad, has perdido el turno\n";
        cout << "--------------------------------------------------\n";
        break;
    }
}
void attackToEnemies(int& enemySelect) {

    if (enemySelect == 1) {
        cout << "---------------------------------------------\n";
        cout << "Que ataque quieres utilizar contra el Balrog?\n";
        cout << "---------------------------------------------\n";
        cout << "[1] Golpe con espada\n";
        cout << "[2] Hechizo de magia\n";
        cout << "[3] Lanzar una flecha\n";
        cout << "---------------------\n";

        cin >> ataque;

        switchToEnemies(enemyHP1, enemyIsAlive1, enemyName1);
        attackToHero(enemyHP1, enemyDamage1, enemyName1);
        attackToHero(enemyHP2, enemyDamage2, enemyName2);

    }
    if (enemySelect == 2) {
        cout << "---------------------------------------------\n";
        cout << "Que ataque quieres utilizar contra el Orco?\n";
        cout << "---------------------------------------------\n";
        cout << "[1] Golpe con espada\n";
        cout << "[2] Hechizo de magia\n";
        cout << "[3] Lanzar una flecha\n";
        cout << "---------------------\n";

        cin >> ataque;

        
        switchToEnemies(enemyHP2, enemyIsAlive2, enemyName2);
        attackToHero(enemyHP1, enemyDamage1, enemyName1);
        attackToHero(enemyHP2, enemyDamage2, enemyName2);

    }
}
void attackToEnemy(int& enemiesHPS, int& enemiesDamages, bool& enemiesStatus, string& enemiesNames) {

    if (enemiesStatus) {

        cout << "Que ataque quieres utilizar?\n";
        cout << "----------------------------\n";
        cout << "[1] Golpe con espada\n";
        cout << "[2] Hechizo de magia\n";
        cout << "[3] Lanzar una flecha\n";
        cout << "---------------------\n";

        cin >> ataque;

        switchToEnemies(enemiesHPS, enemiesStatus, enemiesNames);
        attackToHero(enemiesHPS, enemiesDamages, enemiesNames);
    }
}
void battleToEnemies() {

    lifePointsHeroEnemy1Enemy2();
    selectEnemyAttack();
    attackToEnemies(enemySelect);

    system("pause");
    system("cls");
}
void battleToEnemy(int& enemiesHPS, int& enemiesDamages, bool& enemiesStatus, string& enemiesNames) {

    lifePointsHeroEnemy(enemiesHPS, enemiesNames);
    attackToEnemy(enemiesHPS, enemiesDamages, enemiesStatus, enemiesNames);

    system("pause");
    system("cls");
}
void heroAndEnemiesDead() {

    enemiesDead();
    heroDead();
}

int main() {
    srand((unsigned)time(NULL));
    introductionGame();

    while (heroIsAlive && enemyIsAlive1 && enemyIsAlive2) {
        battleToEnemies();
    }
    while (heroIsAlive && enemyIsAlive1) {
        battleToEnemy(enemyHP1, enemyDamage1, enemyIsAlive1, enemyName1);
    }
    while (heroIsAlive && enemyIsAlive2) {
        battleToEnemy(enemyHP2, enemyDamage2, enemyIsAlive2, enemyName2);
    }
    heroAndEnemiesDead();
}

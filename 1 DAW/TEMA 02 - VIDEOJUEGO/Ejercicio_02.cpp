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
int enemyselect;
int ataque;
int enemyDamage1;
int enemyDamage2;

// INT
int attackEspadaToEnemy1() {
    enemyHP1 = enemyHP1 - espada;
    cout << "Has atacado con la espada.\n";
    cout << "--------------------------\n";
    cout << "Le has hecho " << espada << " puntos de danyo.\n";
    if (enemyHP1 <= 0) {
        enemyHP1 = 0;
        enemyIsAlive1 = false;
    }
    cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";
    cout << "----------------------------------------\n";
    return enemyHP1;
}
int attackEspadaToEnemy2() {
    enemyHP2 = enemyHP2 - espada;
    cout << "Has atacado con la espada.\n";
    cout << "--------------------------\n";
    cout << "Le has hecho " << espada << " puntos de danyo.\n";
    if (enemyHP2 <= 0) {
        enemyHP2 = 0;
        enemyIsAlive2 = false;
    }
    cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";
    cout << "----------------------------------------\n";
    return enemyHP2;
}
int attackMagiaToEnemy1() {
    enemyHP1 = enemyHP1 - magia;
    cout << "Has atacado con la magia.\n";
    cout << "-------------------------\n";
    cout << "Le has hecho " << magia << " puntos de danyo.\n";
    if (enemyHP1 <= 0) {
        enemyHP1 = 0;
        enemyIsAlive1 = false;
    }
    cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";
    cout << "----------------------------------------\n";
    return enemyHP1;
}
int attackMagiaToEnemy2() {
    enemyHP2 = enemyHP2 - magia;
    cout << "Has atacado con la espada.\n";
    cout << "--------------------------\n";
    cout << "Le has hecho " << magia << " puntos de danyo.\n";
    if (enemyHP2 <= 0) {
        enemyHP2 = 0;
        enemyIsAlive2 = false;
    }
    cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";
    cout << "----------------------------------------\n";
    return enemyHP2;
}
int attackFlechaToEnemy1() {
    enemyHP1 = enemyHP1 - flecha;
    cout << "Has atacado con la flecha.\n";
    cout << "--------------------------\n";
    cout << "Le has hecho " << flecha << " puntos de danyo.\n";
    if (enemyHP1 <= 0) {
        enemyHP1 = 0;
        enemyIsAlive1 = false;
    }
    cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";
    cout << "----------------------------------------\n";
    return enemyHP1;
}
int attackFlechaToEnemy2() {
    enemyHP2 = enemyHP2 - flecha;
    cout << "Has atacado con la flecha.\n";
    cout << "--------------------------\n";
    cout << "Le has hecho " << flecha << " puntos de danyo.\n";
    if (enemyHP2 <= 0) {
        enemyHP2 = 0;
        enemyIsAlive2 = false;
    }
    cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";
    cout << "----------------------------------------\n";
    return enemyHP2;
}
int attackEnemy1ToHero() {
    if (enemyHP1 > 0) {
        enemyDamage1 = rand() % 250 + 1;
        heroHP = heroHP - enemyDamage1;
        cout << "El " << enemyName1 << " te ha hecho un ataque de " << enemyDamage1 << " puntos de danyo.\n";
        if (heroHP <= 0) {
            heroHP = 0;
            heroIsAlive = false;
        }
        cout << "Te quedan " << heroHP << " puntos de vida.\n";
        cout << "--------------------------------------\n";      
    }
    return heroHP;
}
int attackEnemy2ToHero() {
    if (enemyHP2 > 0) {
        enemyDamage2 = rand() % 150 + 1;
        heroHP = heroHP - enemyDamage2;
        cout << "El " << enemyName2 << " te ha hecho un ataque de " << enemyDamage2 << " puntos de danyo.\n";
        if (heroHP <= 0) {
            heroHP = 0;
            heroIsAlive = false;
        }
        cout << "Te quedan " << heroHP << " puntos de vida.\n";
        cout << "--------------------------------------\n";
    }
    return heroHP;
}

// BOOLEAN
bool enemy1Dead() {

    if (enemyHP1 <= 0) {
        enemyHP1 = 0;
        cout << "Has matado al " << enemyName1 << ".\n";
        cout << "-----------------------------------\n";
        return enemyIsAlive1 = false;
    }
    else {
        return enemyIsAlive1 =true;
    }
}
bool enemy2Dead() {

    if (enemyHP2 <= 0) {
        enemyHP2 = 0;
        cout << "Has matado al " << enemyName2 << ".\n";
        cout << "-----------------------------------\n";
        return enemyIsAlive2 = false;
    }
    else {
        return enemyIsAlive2 = true;
    }
}
bool enemiesDead() {

    if (heroHP > 0 && enemyHP1 <= 0 && enemyHP2 <= 0) {
        PlaySound(TEXT("Final.wav"), NULL, SND_FILENAME | SND_SYNC);
        cout << "---------------------------------------------------------\n";
        cout << "Has matado a las dos criaturas, tus amigos estan a salvo.\n";
        cout << "---------------------------------------------------------\n";
        return  enemyIsAlive1 = false;
        return  enemyIsAlive2 = false;
    }
    else {
        return  enemyIsAlive1 = true;
        return  enemyIsAlive2 = true;

    }
}

// VOID
void lifePointsHeroEnemy1Enemy2() {

    cout << "----------------------------\n";
    cout << enemyName1 << "    " << enemyHP1 << " Puntos de vida\n";
    cout << enemyName2 << "      " << enemyHP2 << " Puntos de vida\n";
    cout << heroName << "   " << heroHP << " Puntos de vida\n";
    cout << "----------------------------\n";
}
void lifePointsHeroEnemy1() {

    cout << "----------------------------\n";
    cout << enemyName1 << "    " << enemyHP1 << " Puntos de vida\n";
    cout << heroName << "   " << heroHP << " Puntos de vida\n";
    cout << "----------------------------\n";

    cout << "Ya solamente te queda por matar al " << enemyName1 << ".\n";
}
void lifePointsHeroEnemy2() {

    cout << "----------------------------\n";
    cout << enemyName2 << "      " << enemyHP2 << " Puntos de vida\n";
    cout << heroName << "   " << heroHP << " Puntos de vida\n";
    cout << "----------------------------\n";

    cout << "Ya solamente te queda por matar al " << enemyName2 << ".\n";
}
void switchToEnemy1() {
    switch (ataque) {

    case 1:
        PlaySound(TEXT("Espada.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackEspadaToEnemy1();
        break;

    case 2:
        PlaySound(TEXT("Magia.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackMagiaToEnemy1();
        break;

    case 3:
        PlaySound(TEXT("Flecha.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackFlechaToEnemy1();
        break;

    default:
        cout << "No dispones de esa habilidad, has perdido el turno.\n";
        cout << "---------------------------------------------------\n";
        break;
    }
}
void switchToEnemy2() {

    switch (ataque) {

    case 1:
        PlaySound(TEXT("Espada.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackEspadaToEnemy2();
        break;

    case 2:
        PlaySound(TEXT("Magia.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackMagiaToEnemy2();
        break;

    case 3:
        PlaySound(TEXT("Flecha.wav"), NULL, SND_FILENAME | SND_SYNC);
        attackFlechaToEnemy2();
        break;

    default:
        cout << "No dispones de esa habilidad, has perdido el turno.\n";
        cout << "---------------------------------------------------\n";
        break;
    }
}

// OBJETIVOS PRÁCTICA 03
void introductionGame() {

    cout << "Entre las llamas, un temible " << enemyName1 << " acaba de aparecer, con " << enemyHP1 << " puntos de vida.\n";
    cout << "A su lado tambien se encuentra un " << enemyName2 << ", con " << enemyHP2 << " puntos de vida.\n\n";
    cout << "Tienes que evitar que los enemigos crucen el puente para que no destruyan a tus amigos, eliminalos si es necesario.\n\n";
    cout << "Como se llama el heroe que va a pelear contra estas dos criaturas?\n";
    cin >> heroName;
    cout << "El heroe se llama " << heroName << ".\n";
    system("pause");
    PlaySound(TEXT("Introduccion.wav"), NULL, SND_FILENAME | SND_SYNC);
}
bool heroStatus() {

    if (heroHP <= 0) {
        heroHP = 0;
        PlaySound(TEXT("FinalHeroe.wav"), NULL, SND_FILENAME | SND_SYNC);
        cout << "----------------\n";
        cout << "Te han matado!!\n";
        cout << "----------------\n";
        return heroIsAlive = false;
    }
    else {
        return heroIsAlive = true;
    }
}
int selectEnemyAttack() {

    cout << "A que enemigo quieres atacar?\n";
    if (enemyIsAlive1) {
        cout << "[1]: " << enemyName1 << " \n";
    }
    if (enemyIsAlive2) {
        cout << "[2]: " << enemyName2 << " \n";
    }
    cin >> enemyselect;

    while ((enemyselect != (1)) && (enemyselect != (2))) {
        cout << "Ese enemigo no existe, por favor introduce [1] o [2].\n";
        cout << "-----------------------------------------------------\n";
        cin >> enemyselect;
    }
    return enemyselect;
}
void attackToEnemies1() {

    if (enemyselect == 1) {
        cout << "---------------------------------------------\n";
        cout << "Que ataque quieres utilizar contra el Balrog?\n";
        cout << "---------------------------------------------\n";
        cout << "[1] Golpe con espada\n";
        cout << "[2] Hechizo de magia\n";
        cout << "[3] Lanzar una flecha\n";
        cout << "----------------------\n";

        cin >> ataque;

        switchToEnemy1();

        attackEnemy2ToHero();                  
        attackEnemy1ToHero();                   
    }
}
void attackToEnemies2() {

    if (enemyselect == 2) {
        cout << "-------------------------------------------\n";
        cout << "Que ataque quieres utilizar contra el Orco?\n";
        cout << "-------------------------------------------\n";
        cout << "[1] Golpe con espada\n";
        cout << "[2] Hechizo de magia\n";
        cout << "[3] Lanzar una flecha\n";
        cout << "----------------------\n";

        cin >> ataque;

        switchToEnemy2();

        attackEnemy1ToHero();
        attackEnemy2ToHero();
    }
}
void attackToEnemy1() {

    if (enemyIsAlive1) {

        cout << "Que ataque quieres utilizar?\n";
        cout << "----------------------------\n";
        cout << "[1] Golpe con espada\n";
        cout << "[2] Hechizo de magia\n";
        cout << "[3] Lanzar una flecha\n";
        cout << "----------------------\n";

        cin >> ataque;

        switchToEnemy1();

        attackEnemy1ToHero();
    }
}
void attackToEnemy2() {

    if (enemyIsAlive2) {

        cout << "Que ataque quieres utilizar?\n";
        cout << "----------------------------\n";
        cout << "[1] Golpe con espada\n";
        cout << "[2] Hechizo de magia\n";
        cout << "[3] Lanzar una flecha\n";
        cout << "----------------------\n";

        cin >> ataque;

        switchToEnemy2();

        attackEnemy2ToHero();
    }
}

int main() {
    srand((unsigned)time(NULL));
    introductionGame();

    while (heroIsAlive && enemyIsAlive1 && enemyIsAlive2) {

        lifePointsHeroEnemy1Enemy2();
        selectEnemyAttack();

        attackToEnemies1();
        enemy1Dead();

        attackToEnemies2();
        enemy2Dead();

        system("pause");
        system("cls");
    }
    while (heroIsAlive && enemyIsAlive2) {

        lifePointsHeroEnemy2();
        attackToEnemy2();

        system("pause");
        system("cls");
    }
    while (heroIsAlive && enemyIsAlive1) {

        lifePointsHeroEnemy1();
        attackToEnemy1();

        system("pause");
        system("cls");
    }
    enemiesDead();
    heroStatus();
}

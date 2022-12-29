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

int main() {
    srand(time(NULL));

    // (INTRODUCCIÓN)

    cout << "Entre las llamas, un temible " << enemyName1 << " acaba de aparecer, con " << enemyHP1 << " puntos de vida.\n";
    cout << "A su lado tambien se encuentra un " << enemyName2 << ", con " << enemyHP2 << " puntos de vida.\n\n";
    cout << "Tienes que evitar que los enemigos crucen el puente para que no destruyan a tus amigos, eliminalos si es necesario.\n";
    cout << "Como se llama el heroe que va a pelear contra estas dos criaturas?\n";
    cin >> heroName;
    cout << "El heroe se llama " << heroName << ".\n";
    system("pause");
    ////PlaySound(TEXT("Introduccion.wav"), NULL, SND_FILENAME | SND_SYNC);

    // (HEROE, BALROG & ORCO VIVOS)

    while (heroIsAlive && enemyIsAlive1 && enemyIsAlive2) {

        // (PUNTOS DE VIDA DE LOS PERSONAJES)

        cout << "----------------------------\n";
        cout << enemyName1 << "   " << enemyHP1 << " Puntos de vida\n";
        cout << enemyName2 << "     " << enemyHP2 << " Puntos de vida\n";
        cout << heroName << "  " << heroHP << " Puntos de vida\n";
        cout << "----------------------------\n";

        // (SELECCIONAR ENEMIGO AL QUE ATACAR)

        int enemyselect;
        cout << "A que enemigo quieres atacar?\n";

        if (enemyIsAlive1) {
            cout << "[1]: " << enemyName1 << " \n";
        }
        if (enemyIsAlive2) {
            cout << "[2]: " << enemyName2 << " \n";
        }
        cin >> enemyselect;

        // (ERROR EN LA SELECCION DE ENEMIGOS)

        while ((enemyselect != (1)) && (enemyselect != (2))) {
            cout << "Ese enemigo no existe, por favor introduce [1] o [2].\n";
            cin >> enemyselect;
        }

        // (ELEGIR ATAQUE CONTRA EL BALROG)

        if (enemyselect == 1) {
            cout << "---------------------------------------------\n";
            cout << "Que ataque quieres utilizar contra el Balrog?\n";
            cout << "---------------------------------------------\n";
            cout << "[1] Golpe con espada\n";
            cout << "[2] Hechizo de magia\n";
            cout << "[3] Lanzar una flecha\n";
            cout << "----------------------\n";

            int ataque;
            cin >> ataque;

            // (ATACAS AL BALROG)

            switch (ataque) {

            case 1:
                //PlaySound(TEXT("Espada.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP1 = enemyHP1 - espada;
                cout << "Has atacado con la espada.\n";
                cout << "--------------------------\n";
                cout << "Le has hecho " << espada << " puntos de danyo.\n";
                cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";

                if (enemyHP1 <= 0) {
                    enemyHP1 = 0;
                    enemyIsAlive1 = false;
                    cout << "Has matado al " << enemyName1 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            case 2:
                //PlaySound(TEXT("Magia.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP1 = enemyHP1 - magia;
                cout << "Has atacado con la magia.\n";
                cout << "-------------------------\n";
                cout << "Le has hecho " << magia << " puntos de danyo.\n";
                cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";

                if (enemyHP1 <= 0) {
                    enemyHP1 = 0;
                    enemyIsAlive1 = false;
                    cout << "Has matado al " << enemyName1 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            case 3:
                //PlaySound(TEXT("Flecha.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP1 = enemyHP1 - flecha;
                cout << "Has atacado con la flecha.\n";
                cout << "--------------------------\n";
                cout << "Le has hecho " << flecha << " puntos de danyo.\n";
                cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";

                if (enemyHP1 <= 0) {
                    enemyHP1 = 0;
                    enemyIsAlive1 = false;
                    cout << "Has matado al " << enemyName1 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            default:
                cout << "No dispones de esa habilidad, has perdido el turno\n";
                break;
            }

            // (ATAQUE DE AMBOS ENEMIGOS AL HEROE)

            if (enemyHP2 > 0) {
                int enemyDamage2 = rand() % 150 + 1;
                heroHP = heroHP - enemyDamage2;
                cout << "-------------------------------------------------------\n";
                cout << "El " << enemyName2 << " te ha hecho un ataque de " << enemyDamage2 << " puntos de danyo.\n";
                cout << "Te quedan " << heroHP << " puntos de vida.\n";
                cout << "-------------------------------------------------------\n";

                if (heroHP <= 0) {
                    heroHP = 0;
                    heroIsAlive = false;
                    //PlaySound(TEXT("FinalHeroe.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cout << "Te han matado!!.\n";
                    cout << "----------------\n";
                }
            }
            if (enemyHP1 > 0) {
                int enemyDamage1 = rand() % 250 + 1;
                heroHP = heroHP - enemyDamage1;
                cout << "El " << enemyName1 << " te ha hecho un ataque de " << enemyDamage1 << " puntos de danyo.\n";
                cout << "Te quedan " << heroHP << " puntos de vida.\n";
                cout << "-------------------------------------------------------\n";

                if (heroHP <= 0) {
                    heroHP = 0;
                    heroIsAlive = false;
                    //PlaySound(TEXT("FinalHeroe.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cout << "Te han matado!!\n";
                    cout << "----------------\n";
                }
            }
        }

        // (ELEGIR ATAQUE CONTRA EL ORCO)

        if (enemyselect == 2) {
            cout << "-------------------------------------------\n";
            cout << "Que ataque quieres utilizar contra el Orco?\n";
            cout << "-------------------------------------------\n";
            cout << "[1] Golpe con espada\n";
            cout << "[2] Hechizo de magia\n";
            cout << "[3] Lanzar una flecha\n";
            cout << "----------------------\n";

            int ataque;
            cin >> ataque;

            // (ATACAS AL ORCO)

            switch (ataque) {

            case 1:
                //PlaySound(TEXT("Espada.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP2 = enemyHP2 - espada;
                cout << "Has atacado con la espada.\n";
                cout << "--------------------------\n";
                cout << "Le has hecho " << espada << " puntos de danyo.\n";
                cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";

                if (enemyHP2 <= 0) {
                    enemyHP2 = 0;
                    enemyIsAlive2 = false;
                    cout << "Has matado al " << enemyName2 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            case 2:
                //PlaySound(TEXT("Magia.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP2 = enemyHP2 - magia;
                cout << "Has atacado con la magia.\n";
                cout << "-------------------------\n";
                cout << "Le has hecho " << magia << " puntos de danyo.\n";
                cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";

                if (enemyHP2 <= 0) {
                    enemyHP2 = 0;
                    enemyIsAlive2 = false;
                    cout << "Has matado al " << enemyName2 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            case 3:
                //PlaySound(TEXT("Flecha.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP2 = enemyHP2 - flecha;
                cout << "Has atacado con la flecha.\n";
                cout << "--------------------------\n";
                cout << "Le has hecho " << flecha << " puntos de danyo.\n";
                cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";

                if (enemyHP2 <= 0) {
                    enemyHP2 = 0;
                    enemyIsAlive2 = false;
                    cout << "Has matado al " << enemyName2 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            default:
                cout << "No dispones de esa habilidad, has perdido el turno\n";
                break;
            }

            // (ATAQUE DE AMBOS ENEMIGOS AL HEROE)

            if (enemyHP1 > 0) {
                int enemyDamage1 = rand() % 250 + 1;
                heroHP = heroHP - enemyDamage1;
                cout << "El " << enemyName1 << " te ha hecho un ataque de " << enemyDamage1 << " puntos de danyo.\n";
                cout << "Te quedan " << heroHP << " puntos de vida.\n";
                cout << "-------------------------------------------------------\n";

                if (heroHP <= 0) {
                    heroHP = 0;
                    heroIsAlive = false;
                    //PlaySound(TEXT("FinalHeroe.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cout << "Te han matado!!\n";
                    cout << "----------------\n";
                }
            }
            if (enemyHP2 > 0) {
                int enemyDamage2 = rand() % 150 + 1;
                heroHP = heroHP - enemyDamage2;
                cout << "El " << enemyName2 << " te ha hecho un ataque de " << enemyDamage2 << " puntos de danyo.\n";
                cout << "Te quedan " << heroHP << " puntos de vida.\n";
                cout << "-------------------------------------------------------\n";

                if (heroHP <= 0) {
                    heroHP = 0;
                    heroIsAlive = false;
                    //PlaySound(TEXT("FinalHeroe.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cout << "Te han matado!!\n";
                    cout << "----------------\n";
                }
            }
        }
        system("pause");
        system("cls");
    }

    // (HEROE & ORCO VIVOS) (BALROG MUERTO)

    while (heroIsAlive && enemyIsAlive1 == false && enemyIsAlive2) {

        // (PUNTOS DE VIDA DE LOS PERSONAJES)

        cout << "----------------------------\n";
        cout << enemyName2 << "     " << enemyHP2 << " Puntos de vida\n";
        cout << heroName << "  " << heroHP << " Puntos de vida\n";
        cout << "----------------------------\n";

        cout << "Ya solamente te queda por matar al " << enemyName2 << ".\n";

        // (ELEGIR ATAQUE CONTRA EL ORCO)

        if (enemyIsAlive2) {

            cout << "Que ataque quieres utilizar?\n";
            cout << "----------------------------\n";
            cout << "[1] Golpe con espada\n";
            cout << "[2] Hechizo de magia\n";
            cout << "[3] Lanzar una flecha\n";
            cout << "----------------------\n";

            int ataque;
            cin >> ataque;

            // (ATACAS AL ORCO)

            switch (ataque) {

            case 1:
                //PlaySound(TEXT("Espada.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP2 = enemyHP2 - espada;
                cout << "Has atacado con la espada.\n";
                cout << "--------------------------\n";
                cout << "Le has hecho " << espada << " puntos de danyo.\n";
                cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";

                if (enemyHP2 <= 0) {
                    enemyHP2 = 0;
                    enemyIsAlive2 = false;
                    cout << "Has matado al " << enemyName2 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            case 2:
                //PlaySound(TEXT("Magia.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP2 = enemyHP2 - magia;
                cout << "Has atacado con la magia.\n";
                cout << "-------------------------\n";
                cout << "Le has hecho " << magia << " puntos de danyo.\n";
                cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";

                if (enemyHP2 <= 0) {
                    enemyHP2 = 0;
                    enemyIsAlive2 = false;
                    cout << "Has matado al " << enemyName2 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            case 3:
                //PlaySound(TEXT("Flecha.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP2 = enemyHP2 - flecha;
                cout << "Has atacado con la flecha.\n";
                cout << "--------------------------\n";
                cout << "Le has hecho " << flecha << " puntos de danyo.\n";
                cout << "Al " << enemyName2 << " le quedan " << enemyHP2 << " puntos de vida.\n";

                if (enemyHP2 <= 0) {
                    enemyHP2 = 0;
                    enemyIsAlive2 = false;
                    cout << "Has matado al " << enemyName2 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            default:
                cout << "No dispones de esa habilidad, has perdido el turno\n";
                break;
            }

            // (ATAQUE DEL ORCO)

            if (enemyHP2 > 0) {
                int enemyDamage2 = rand() % 150 + 1;
                heroHP = heroHP - enemyDamage2;
                cout << "-------------------------------------------------------\n";
                cout << "El " << enemyName2 << " te ha hecho un ataque de " << enemyDamage2 << " puntos de danyo.\n";
                cout << "Te quedan " << heroHP << " puntos de vida.\n";
                cout << "-------------------------------------------------------\n";

                if (heroHP <= 0) {
                    heroHP = 0;
                    heroIsAlive = false;
                    //PlaySound(TEXT("FinalHeroe.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cout << "Te han matado!!\n";
                    cout << "----------------\n";
                }
            }
        }
        system("pause");
        system("cls");
    }

    // (HEROE & BALROG VIVOS) (ORCO MUERTO)

    while (heroIsAlive && enemyIsAlive1 && enemyIsAlive2 == false) {

        // (PUNTOS DE VIDA DE LOS PERSONAJES)

        cout << "----------------------------\n";
        cout << enemyName1 << "   " << enemyHP1 << " Puntos de vida\n";
        cout << heroName << "  " << heroHP << " Puntos de vida\n";
        cout << "----------------------------\n";

        cout << "Ya solamente te queda por matar al " << enemyName1 << ".\n";

        // (ELEGIR ATAQUE CONTRA EL BALROG)

        if (enemyIsAlive1) {

            cout << "Que ataque quieres utilizar?\n";
            cout << "----------------------------\n";
            cout << "[1] Golpe con espada\n";
            cout << "[2] Hechizo de magia\n";
            cout << "[3] Lanzar una flecha\n";
            cout << "----------------------\n";

            int ataque;
            cin >> ataque;

            // (ATACAS AL BALROG)

            switch (ataque) {

            case 1:
                //PlaySound(TEXT("Espada.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP1 = enemyHP1 - espada;
                cout << "Has atacado con la espada.\n";
                cout << "--------------------------\n";
                cout << "Le has hecho " << espada << " puntos de danyo.\n";
                cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";

                if (enemyHP1 <= 0) {
                    enemyHP1 = 0;
                    enemyIsAlive1 = false;
                    cout << "Has matado al " << enemyName1 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            case 2:
                //PlaySound(TEXT("Magia.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP1 = enemyHP1 - magia;
                cout << "Has atacado con la magia.\n";
                cout << "-------------------------\n";
                cout << "Le has hecho " << magia << " puntos de danyo.\n";
                cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";

                if (enemyHP1 <= 0) {
                    enemyHP1 = 0;
                    enemyIsAlive1 = false;
                    cout << "Has matado al " << enemyName1 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            case 3:
                //PlaySound(TEXT("Flecha.wav"), NULL, SND_FILENAME | SND_SYNC);
                enemyHP1 = enemyHP1 - flecha;
                cout << "Has atacado con la flecha.\n";
                cout << "--------------------------\n";
                cout << "Le has hecho " << flecha << " puntos de danyo.\n";
                cout << "Al " << enemyName1 << " le quedan " << enemyHP1 << " puntos de vida.\n";

                if (enemyHP1 <= 0) {
                    enemyHP1 = 0;
                    enemyIsAlive1 = false;
                    cout << "Has matado al " << enemyName1 << ".\n";
                    cout << "-----------------------------------\n";
                }
                break;

            default:
                cout << "No dispones de esa habilidad, has perdido el turno\n";
                break;
            }

            // (ATAQUE DEL BALROG)

            if (enemyHP1 > 0) {
                int enemyDamage1 = rand() % 250 + 1;
                heroHP = heroHP - enemyDamage1;
                cout << "-------------------------------------------------------\n";
                cout << "El " << enemyName1 << " te ha hecho un ataque de " << enemyDamage1 << " puntos de danyo.\n";
                cout << "Te quedan " << heroHP << " puntos de vida.\n";
                cout << "-------------------------------------------------------\n";

                if (heroHP <= 0) {
                    heroHP = 0;
                    heroIsAlive = false;
                    //PlaySound(TEXT("FinalHeroe.wav"), NULL, SND_FILENAME | SND_SYNC);
                    cout << "Te han matado!!\n";
                    cout << "----------------\n";
                }
            }
        }
        system("pause");
        system("cls");
    }

    // (HEROE VIVO) (BALROG & ORCO MUERTOS)

    if (heroIsAlive && enemyIsAlive1 == false && enemyIsAlive2 == false) {
        //PlaySound(TEXT("Final.wav"), NULL, SND_FILENAME | SND_SYNC);
        cout << "Has matado a las dos criaturas, tus amigos estan a salvo.\n";
        cout << "---------------------------------------------------------\n";
    }
}
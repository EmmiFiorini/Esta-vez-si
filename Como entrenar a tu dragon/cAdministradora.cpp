#include "cAdministradora.h"


cAdministradora::cAdministradora()
{
}

cAdministradora::~cAdministradora()
{
}

int cAdministradora::CantidadEnemigos()
{
	return listaDeEnemigos.size();
}

int cAdministradora::CantidadVikingos()
{
    return listaDeVikingos.size();
}

void cAdministradora::llamarATribu(cDragon* dragonAAtacar) //recorre la lista de vikingos y genera un combate con el mismo drag�n (un combate para c/vikingo)
{
	list <cVikingo*>::iterator it = this->listaDeEnemigos.begin();
	while (it != listaDeEnemigos.end()) {
        combate(dragonAAtacar, (*it));
        it++;
	}
}

void cAdministradora::combate(cDragon* dragon, cVikingo* vikingo)
{
    if (dragon->get_defensa() > vikingo->get_ataque() && dragon->get_ataque() > vikingo->get_defensa()) {
        vikingo->set_salud(vikingo->get_salud() - 50);
    }
    else if (dragon->get_defensa() < vikingo->get_ataque() && dragon->get_ataque() < vikingo->get_defensa()) {
        dragon->set_salud(dragon->get_salud() - 50);
    }
    else {
        dragon->set_salud(dragon->get_salud() - 25);
        vikingo->set_salud(vikingo->get_salud() - 25);
    }
    if (vikingo->get_salud() <= 0)
        throw new exception("muerte de vikingo"); //el try catch se hace en el main. Se llama en el main a la funcion "baja"

    if (dragon->get_salud() <= 0) {
        throw new exception("muerte de dragon"); //se cae el jinte de arriba del dragon y pierde 70 de vida, si sigue vivo tiene q peliar el solo contra los vikingos malos
    }
}

void cAdministradora::historia()
{
    cout << "COMO ENTRENAR A TU DRAGON" << endl;
    getchar();

    cout << "En el a�o 1010, la isla de Berk viv�a en paz y armon�a." << endl;
    cout << "Hasta que un d�a aparecieron los malvados vikingo de la tribu Draugr que atacaron la aldea y asesinaron a muchos aldeanos." << endl;
    cout << "\t" << "     _.-^^---....,,--       " << endl;
    cout << "\t" << " _--                  --_  " << endl;
    cout << "\t" << "<                        >)" << endl;
    cout << "\t" << "|                         | " << endl;
    cout << "\t" << " \._                   _./  " << endl;
    cout << "\t" << "    ```--. . , ; .--'''       " << endl;
    cout << "\t" << "         | |   |             " << endl;
    cout << "\t" << "      .-=||  | |=-.   " << endl;
    cout << "\t" << "      `-=#$%&%$#=-'   " << endl;
    cout << "\t" << "         | ;  :|     " << endl;
    cout << "\t" << "_____.,-#%&$@%#&#~,._____" << endl << endl;
    getchar();


    cout << "Ese mismo dia  Estoico el Vasto, el jefe de la aldea, designo un grupo de j�venes valientes vikingos que domarian dragones" << endl;
    cout << "y si pasan la prueba del jefe de seguridad Bocon, ser�an parte de un grupo de �lite encargado de defender a la aldea de los enemigos." << endl << endl;
    
    cout << "\t" << " <>=======() " << endl;
    cout << "\t" << "(/\___   /|\\          ()==========<>_" << endl;
    cout << "\t" << "      \_/ | \\        //|\   ______/ \)" << endl;
    cout << "\t" << "        \_|  \\      // | \_/" << endl;
    cout << "\t" << "          \|\/|\_   //  /\/" << endl;
    cout << "\t" << "           (oo)\ \_//  /" << endl;
    cout << "\t" << "          //_/\_\/ /  |" << endl;
    cout << "\t" << "         @@/  |=\  \  |" << endl;
    cout << "\t" << "              \_=\_ \ |" << endl;
    cout << "\t" << "                \==\ \|\_ " << endl;
    cout << "\t" << "             __(\===\(  )\ " << endl;
    cout << "\t" << "            (((~) __(_/   |" << endl;
    cout << "\t" << "                 (((~) \  /" << endl;
    cout << "\t" << "                 ______/ /" << endl;
    cout << "\t" << "                 '------'" << endl;
    getchar();
    cout << "Desde ese d�a t�, decidiste  que el quer�as formar parte de aquel grupo, para vengar aquellos hermanos Bercianos muertos en manos de la despiadada Ulf y sus guerreros. " << endl;
    cout << "Comienza tu aventura, domando a un dragon, pasando la prueba de Bocon y luego enfrentarse a todos los vikingos enemigos!" << endl << endl<<endl;
    
    cout << "Presiona enter para comenzar tu aventura:" << endl;
    getchar();
}

void cAdministradora::dragonEliminado(cDragon* dragon_muerto) {
    list<cDragon*> ::iterator it = this->listaDeDragones.begin();
    bool encontrado = false;
    while (it != this->listaDeDragones.end()) {
        if ((*it)->get_nombre() == dragon_muerto->get_nombre()) {
            this->listaDeDragones.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
    if (!encontrado) {
        throw new exception("Error, no se encontr� el drag�n");
    }
}

void cAdministradora::baja_dragon(cDragon* dragon) {
    if (dragon->get_salud() == 0) {
        cout << "El drag�n muri�" << endl;
        dragonEliminado(dragon);
    }
}

void cAdministradora::enemigoEliminado(cVikingo* enemigo) { // va para listaDeEnemigos
    list<cVikingo*> ::iterator it = this->listaDeEnemigos.begin();
    bool encontrado = false;
    while (it != this->listaDeEnemigos.end()) {
        if ((*it)->get_nombre() == enemigo->get_nombre()) {
            this->listaDeEnemigos.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
    if (!encontrado) {
        throw new exception("Error, no se encontr� al enemigo");
    }
}

void cAdministradora::vikingoEliminado(cVikingo* vikingo) { // va para listaDeVikingos
    list<cVikingo*> ::iterator it = this->listaDeVikingos.begin();
    bool encontrado = false;
    while (it != this->listaDeVikingos.end()) {
        if ((*it)->get_nombre() == vikingo->get_nombre()) {
            this->listaDeVikingos.erase(it);
            encontrado = true;
            break;
        }
        it++;
    }
    if (!encontrado) {
        throw new exception("Error, no se encontr� al vikingo");
    }
}

void cAdministradora::AgregarVikingo(cVikingo* vikingo)
{
    this->listaDeVikingos.push_back(vikingo);

}

void cAdministradora :: operator+=(cDragon *drago) {
    listaDeDragones.push_back(drago);
}

ostream&  operator<<(ostream& os, cDragon& dragon) {
    os << "Dragon eliminado : "<< "nombre : "<<dragon.get_nombre() << ", nivel : " << dragon.get_level()<< endl;
    return os;
}

int cAdministradora::buscarDragon(string nombre) {
    int pos = 0;
    bool flag = false;
    list<cDragon*> ::iterator it = this->listaDeDragones.begin();
    while (it != listaDeDragones.end()) {
        if ((*it)->get_nombre() == nombre) {
            flag = true;
            return pos;
        }
        it++;
        pos++;
    }
    if (!flag){
        throw new exception("No se encontr� al dragon");
        return -1;
       }
}


void cAdministradora:: operator-=(string nombre) {
    try {
        list<cDragon*> ::iterator it = this->listaDeDragones.begin();
        int pos = buscarDragon(nombre);
        advance(it, pos);
        listaDeDragones.erase(it);
    }
    catch (const exception* e) {
        cout << e->what() << endl;
    }
}


void cAdministradora::NuevoVikingoM(cVikingo* nuevoVikM)
{
    this->listaDeEnemigos.push_back(nuevoVikM);

}
void cAdministradora::PruebaBocon(cJinete* jinete) {
    cout << "Bienvenido " << jinete->get_nombre() << " a mi prueba, soy Bocon." << endl;
    cout << "Buen dragon el tuyo camarada" << endl << endl;
    cout << "Estas listo para la prueba?" << endl;
    cout << "Recuerda el futuro de nuestra tribu esta en tus manos...." << endl;
    cout << "Solo te lo recuerdo, sin presion..." << endl << endl << endl;

    cout << "\t" << "LA PRUEBA DE BOCON:" << endl << endl << endl;
    char rta;
    float nota = 0;

    cout << "\t" << "Quien es el novio de la dragona en Shrek?" << endl;
    cout << "a) Burro\n \tb)Shrek\n \tc)El Gato con Botas" << endl;
    cout << "Ingresa la letra de tu respuesta: ";
    cin >> rta;
    switch (rta) {
    case 'a':
        nota += 10;
        break;
    case 'A':
        nota += 10;
        break;
    case 'b':
    case 'B':
    case 'c':
    case 'C':
    default:
        nota += 0;
        break;
    }

    cout << endl << "\t" << "Cuantos dragones tiene Daenerys?" << endl;
    cout << " a) 0\n \tb)2\n \tc)3" << endl;
    cout << "Ingresa la letra de tu respuesta: ";
    cin >> rta;
    switch (rta) {
    case 'c':
        nota += 10;
        break;
    case 'C':
        nota += 10;
        break;
    case 'b':
    case 'B':
    case 'a':
    case 'A':
    default:
        nota += 0;
        break;
    }

    cout << endl << "\t" << "En la Bella Durmiente, Quien se trasforma en dragon?" << endl;
    cout << "a) Aurora\n \tb)Malefica\n \tc)Nadie" << endl;
    cout << "Ingresa la letra de tu respuesta: ";
    cin >> rta;
    switch (rta) {
    case 'b':
        nota += 10;
        break;
    case 'B':
        nota += 10;
        break;
    case 'c':
    case 'C':
    case 'a':
    case 'A':
    default:
        nota += 0;
        break;
    }

    cout << endl << endl << "Ya terminaste la prueba" << endl << "\tTu nota es: " << nota << "/30" << endl << "Tu resultado es: " << endl;
    if (nota == 30) // noAsistio = 0, aprobado = 4, desaprobado = 3, primero = 10, ultimo = 1
        jinete->set_result(primero);
    else if (nota == 20)
        jinete->set_result(aprobado);
    else if (nota == 10)
        jinete->set_result(desaprobado);
    else if (nota == 0)
        jinete->set_result(ultimo);

    jinete->printResultado();

    if (nota == 10 || nota == 0) {
        throw exception("Prueba desaprobada");
    }
}


void cAdministradora::PrintPeleaImagen() const
{
    cout << "Imprimir un dibujo!" << endl;
}

void cAdministradora::menu(cJinete* jinete)
{
    cout << "\t MENU:" << endl;
    cout << "1) Buscar Dragon" << endl;
    cout << "2) Prueba Bocon" << endl;
    cout << "3) Entrenar Dragon" << endl;
    cout << "4) Curandero" << endl;
    cout << "5) Pelea contra todos los enemigos" << endl;
    cout << "6) Salir" << endl;
    int option;
    cout << "Ingrese la opcion:" << endl;
    cin >> option;
    getchar();

    do {
        switch (option) {
        case 1: buscarDragon(jinete);
            break;
        case 2: PruebaBocon(jinete);
            break;
        case 3://entrenarDragon(bool habilidadAEntrenar)
            cout << "Ingrese A si quiere entrenar ataque y B si quiere entrenar defensa" << endl;
            char c;
            cin >> c;
            if (c == 'A' || c == 'a') {
                jinete->entrenarDragon(true);
            }
            else if(c == 'B' || c == 'b'){
                jinete->entrenarDragon(false);
            }
            else {
                cout << "Ingrese una opcion valida" << endl; //poner aca palabra q te cierre el programas
            }
                
            break;
        case 4:
            cout << "Ingrese A si quiere curar tu dragon y B si quiere curarse a uno mismo" << endl;
            char f;
            cin >> f;
            if (f == 'A' || f == 'a') {
                jinete->curarDragon();
            }
            else if (f == 'B' || f == 'b') {
                jinete->curandero();
            }
            else {
                cout << "Ingrese una opcion valida" << endl; //poner aca palabra q te cierre el programas
            }

            break;
        case 5://llamarATribu(cDragon* dragonAAtacar)
            llamarATribu(jinete->get_MiDragon());
            break;
        default:
            return; //palabra q te cierra el programa
        
        }
    } while (option != 6);
}



void cAdministradora::buscarDragon(cJinete* jinete) {
    bool flag = false;
    cout << "Con el primer rayo de sol, me adentre al bosque de los Susurros.Camine con cautela, siguiendo el camino que mis ancestros me habian indicado, hasta que se bifurco en dos: uno mostraba huellas peculiares� no podria decir de que animal en especifico.El otro era un camino llano, no mostraba signos de que habia sido recorrido �Cu�l voy a elegir ?" << endl;
    cout << "\t" << "Ingrese A si quiere ir por el camino con huellas; ingrese B si quiere ir por el camino llano" << endl;
    // la respuesta incorrecta es la 2
    char respuesta1;
    cin >> respuesta1;
    getchar();
    if (respuesta1 == 'B'|| respuesta1 == 'b') {
        cout << "Me adentr� por el camino llano, confiado en que mis ancestros me guiarian.Sin embargo, apareci� una niebla densa y el paisaje se torn� confuso.Me encontr� desorientado, rodeado por la niebla" << endl;
        cout << "\t" << "�No llegaste a ning�n drag�n!Presiona enter para volver a la aldea y volver a intentarlo" << endl;
        getchar();
    }
    else {
        cout << "Decid� seguir las huellas, sin saber a qu� criatura pertenec�an.Camin� durante horas siguiendo este rastro.La vegetaci�n se hac�a m�s densa.De repente, las huellas desaparecieron en una zona pantanosa, y frente a m� el camino se divid�a en dos; uno llevaba hacia una colina empinada, cubierta de espinas, y el otro descend�a hacia un valle oscuro.Deb�a decidir : �subir la colina espinosa o descender al valle sombr�o ? " << endl;

        cout << "\t" << "Ingrese A si quiere ir subir por la colina espinosa; ingrese B si quiere descender por el valle sombrio" << endl;
        // la respuesta incorrecta es la 1
        char respuesta2;
        cin >> respuesta2;
        if (respuesta2 == 'A' || respuesta2 == 'a') {
            cout << "Decid� enfrentar la colina espinosa.Sin embargo, las espinas eran m�s traicioneras de lo que imagin�.Cada paso era una lucha, y pronto me encontr� atrapado, con las espinas rasgando mi ropa.Perd� mucho tiempo y, finalmente, tuve que retroceder, herido y frustrado" << endl;
            cout << "\t" << "�No llegaste a ning�n drag�n!Presiona enter para volver a la aldea y volver a intentarlo" << endl;
            getchar();
            return;
        }
        else {
            cout << "Tome el camino hacia el valle sombr�o.La oscuridad era densa.Sin embargo, segui avanzando, sintiendo que estaba en el camino correcto.De repente, el valle se abri� en un claro iluminado por una luz azulada" << endl;
            cout << "En el centro, descansando majestuosamente, estaba el drag�n.Me acerqu� con cautela, recitando las palabras que mis ancestros me habian ense�ado.El dragon levant� su cabeza y se qued� observandome.Debia tomar una decision final: mostrarme respetuoso, esperando que el dragon aceptara mi presencia, o intentar imponerme, demostrando mi fuerza.Sabia que solo una opcion me llevaria a ganarme su confianza" << endl;
            cout << "\t" << "Ingrese A si quiere mostrarse respetuoso con el dragon; ingrese B si quiere imponerse ante al dragon" << endl;
            // la respuesta incorrecta es la 2
            char respuesta3;
            cin >> respuesta3;
            if (respuesta3 == 'B' || respuesta3 == 'b') {
                cout << "Opte por imponer mi fuerza.Me acerque al dragon con firmeza, levantando mi voz y mostrando una postura desafiante.Sin embargo, el dragon no se impresiono.Rugio de tal forma que el suelo temblo bajo mis pies.Luego, lanzo una rafaga de fuego que me obligo a retroceder rapidamente.Tropece y cai al suelo, comprendiendo mi error.La fuerza bruta no era el camino para ganar el respeto de una criatura tan majestuosa.Me retir� hacia mi aldea, sabiendo la oportunidad que habia perdido" << endl;
                cout << "\t" << "�No llegaste a ning�n drag�n!Presiona enter para volver a la aldea y volver a intentarlo" << endl;
                getchar();
                return;
            }
            else {
                flag = true;
                cout << "Me inclin� ante el dragon, mostrando respeto y humildad.El dragon, sorprendentemente, bajo su cabeza y me permitio tocar sus escamas.Con cuidado, subi a su lomo.Juntos, volamos hacia la aldea.Oficialmente, habia domado a mi primer dragon" << endl;
                cout << "\t" << "�Felicitaciones!Domaste a tu dragon.A continuaci�n, ingresa el nombre de tu nuevo dragon : " << endl;
                string nombreD;
                cin >> nombreD;
                cout << "\t" << "�Que caracteristica fisica tiene ?" << endl;
                string caractD;
                cin >> caractD;
                cout << "\t" << "�Qu� color tiene ?" << endl;
                string colorD;
                cin >> colorD;

                cDragon* tuDragon = new cDragon(nombreD, caractD, mediano, colorD, true, "", 0, 0, 100);
                jinete->IncorporarDragon(tuDragon);

                cout << "\t" << "�Dragon creado!Ingresa �enter� para volver a la aldea y seguir con tu aventura " << endl;
                getchar();
            }
        }
    }
    if (!flag) {
        throw new exception("No se encontro el dragon");
        return;
    }
}


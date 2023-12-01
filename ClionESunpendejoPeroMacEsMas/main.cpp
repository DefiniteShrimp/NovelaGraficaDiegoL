#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// Función para leer una matriz desde un archivo
void lectura(int**& arr, int& f, int& c)
{
    // Ruta del archivo
    string archivo = "/Users/diegolizarraga/Desktop/ClionESunpendejoPeroMacEsMas/matriz.txt";
    // Se abre el archivo
    ifstream file(archivo);
    int i = 0;

    // Verifica si el archivo se abrió correctamente
    if(file.is_open())
    {
        string line;
        // Lee línea por línea del archivo
        while(getline(file, line))
        {
            istringstream ss(line);

            // Primera línea: número de filas
            if(i == 0)
            {
                ss >> f;
            }

            // Segunda línea: número de columnas
            if(i == 1)
            {
                ss >> c;
                // Se crea la matriz dinámica con f filas y c columnas
                arr = new int*[f];
                for (int j = 0; j < f; j++)
                {
                    arr[j] = new int[c];
                }
            }

            // Líneas restantes: llenar la matriz con valores
            if (i > 1)
            {
                int k = 0;
                while(ss >> arr[i - 2][k])
                {
                    k++;
                }
            }
            i++;
        }
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo";
    }
}
void imprimirIntroduccion()
{
    cout << "Eres un niño completamente normal, tus padres se mudaron de ciudad y te llevaron con ellos." << endl;
    cout << "(Dibujo de un carro yendo de viaje con maletas en la carretera)" << endl;
    cout << endl;
    cout << "Te ha costado trabajo adaptarte a tu nueva escuela ya que todos en tu escuela son un poco raros y no entiendes porque te observan tan fríamente." << endl;
    cout << "(Imagen de varios alumnos y profesores fijando su mirada en ti)" << endl;
    cout << endl;
    cout << "Últimamente tus padres han discutido mucho y están muy presionados por su trabajo, por lo que decidiste no molestarlos con tus problemas, tus mejores amigos de tu escuela pasada ya no contestan tus mensajes y no quieres pensar lo peor… ¿tal vez los mensajes no les llegan?" << endl;
    cout << "(Imagen del niño en las escaleras viendo su celular, al fondo sus padres gritándose)" << endl;
    cout << endl;
    cout << "Pero bueno, sigues siendo un niño y quieres ver el lado positivo a las cosas, con un gran espíritu aventurero e inquebrantable decides explorar tu nueva ciudad, te hiciste amigo de los gatos callejeros, conociste todas las calles y tiendas," << endl;
    cout << "(Imagen del niño caminando por la calle mientras lo sigue un gatito)" << endl;
    cout << endl;
    cout << "hay un edificio abandonado que nunca te has animado a explorar por la lúgubre fachada, curiosamente siempre pasas por ahí de camino a tu escuela" << endl;
    cout << "(La fachada del edificio)" << endl;
    cout << endl;
    cout << "Un día te despiertas más temprano de lo usual porque hay algo en el aspecto de ese edificio que no te deja tranquilo. Por lo que, lleno de coraje y valentía, decides inspeccionar." << endl;
    cout << "(Niño poniéndose las botas y llevándose su mochila)" << endl;
    cout << endl;
    cout << "Llegas al edificio, y exploras, no hay particularmente aterrador o inusual sobre el edificio, un montón de oficinas abandonadas y claramente el estado deteriorado de los muros y muebles." << endl;
    cout << "(Imagen de un cubículo destrozado)" << endl;
    cout << endl;
    cout << "Decides investigar el sótano para ver si hay algo por ahí, hasta ahora no parece ser aterrador, simplemente curioso… después de un rato de caminar despreocupado, empiezas a darte cuenta que no encuentras la salida, recuerdas que habías caminado hacia la derecha, luego a la izquierda… ¿o era otra vez derecha?..." << endl;
    cout << endl;
}

// Estructura para almacenar aristas
typedef struct {
    int A;
    int B;
    int C;
} aristas;

aristas aristas1;

int main()
{
    imprimirIntroduccion();
    int** matrix; // Matriz leída desde el archivo
    int f, c; // Número de filas y columnas en la matriz
    lectura(matrix, f, c); // Llamada a la función para leer la matriz desde el archivo

    int opciones = 0;
    int nodos[c]; // Arreglo que almacena los nodos

    // Inicialización de nodos
    for (int i = 0; i < c; i++)
    {
        nodos[i] = i;
    }

    int nodosO[c];

    // Inicialización de nodosO
    for (int i = 0; i < c; i++)
    {
        nodosO[i] = 0;
    }

    int escenaI = 0;
    int escenaA = escenaI;
    int escenaF = c;
    int salida = 0;
    int seleccion = 0;
    int i = 0, x = 1;

    while (salida == 0)
    {
        while (escenaA != escenaF)
        {
            // Verifica si hay una conexión entre los nodos
            if (matrix[escenaA][i] == 1)
            {
                opciones++;
                nodosO[i] = x;
                x++;
            }

            // Verifica si se llegó al final de la fila sin opciones
            if (i == c - 1 && opciones == 0)
            {
                i = 0;
                if (escenaA == 10)
                {
                    cout << "(Dibujo de las escaleras hacia abajo)" << endl;
                    cout << "Bajas apresuradamente las escaleras con el puñal en la mano…" << endl;
                    cout << "(Dibujo de una criatura en las escaleras esperándote)" << endl;
                    cout << "No fuiste silencioso, la criatura te escuchó, tratas de defenderte pero es inútil…" << endl;
                    cout << "Sientes como te empieza a masticar las piernas… Todo se vuelve negro y frío…" << endl;
                }
                if (escenaA == 11)
                {
                    cout << "(Dibujo de las escaleras hacia arriba)" << endl;
                    cout << "Subes las escaleras apresuradamente… Ves una luz arriba, es muy brillante." << endl;
                    cout << "(Dibujo de la tapa de la alcantarilla con escaleras en la pared (pasamanos))" << endl;
                    cout << "Tratas de abrir la alcantarilla pero no puedes… escuchas que algo sube las escaleras por las que acabas de correr… Mientras intentas abrir la alcantarilla el ruido se vuelve más intenso… NO ES UNA PERSONA…" << endl;
                    cout << "Con desesperación golpeas la alcantarilla hasta que la logras abrir, sales lo más rápido posible a un callejón que te resulta familiar." << endl;
                    cout << "(Dibujo de un callejón con un bote de basura)" << endl;
                    cout << "Volteas hacia abajo y ves como un ojo te observa desde la oscuridad mientras se cierra la tapa de alcantarilla… Decides regresar a casa…" << endl;
                }
                if (escenaA == 12)
                {
                    cout << "(Dibujo de las paredes casi aplastándote)" << endl;
                    cout << "Te deslizas por el pasillo, estás desesperado por salir… estás apretado, pero hay algo al final del pasadizo…" << endl;
                    cout << "(Dibujo del serafín con letras BE NOT AFRAID)" << endl;
                    cout << "La cosa hace ruido pero no puedes entender, solo sabes que estás tranquilo y cada vez ves más luz y sientes cálido…" << endl;
                    cout << "(Pantalla en blanco)" << endl;
                    cout << "Te despiertas en tu cama, parece que todo fue una pesadilla… pero… ¿qué es eso en tu ventana?" << endl;
                    cout << "(Dibujo de una criatura acechando en la ventana)" << endl;
                }
                if (escenaA == 14)
                {
                    cout << "(Dibujo del pasillo hacia en frente)" << endl;
                    cout << "Caminas lentamente y sin voltear atrás… De pronto escuchas pasos acelerados hacia ti por detrás… Tratas de voltear pero es muy tarde… Sus garras te rodean el cuerpo mientras el puñal que lo atraviesa a él te atraviesa a ti…" << endl;
                    cout << "(Dibujo viendo hacia abajo *se ve como las garras te sostienen y el puñal atravesándote el pecho)" << endl;
                    cout << "No puedes ver nada… estás paralizado completamente por el miedo… sientes que te empieza a masticar el cráneo…" << endl;
                    cout << "(Imagen negra)" << endl;
                }
                if (escenaA == 16)
                {
                    cout << "(Dibujo de la criatura con la cabeza volteando a verte sonriendo, con los ojos sellados y sangrando por los oídos)" << endl;
                    cout << "Decidiste hablarle: “¿Necesitas ayuda? Yo también estoy perdido, salgamos juntos de aquí, tengo un poco de agua si tienes sed.”" << endl;
                    cout << "Haciendo ruido como de respiración colapsada, la cabeza de la criatura voltea a verte… Te das cuenta que no es humano y definitivamente no necesita ayuda…" << endl;
                    cout << "(Dibujo de la criatura abriendo la boca y con sangre en los oídos, con el cuerpo volteando hacia atrás)" << endl;
                    cout << "Te paralizas por el miedo… La criatura se lanza sobre ti y empieza a masticar tu cuello de manera lenta, sientes como te arranca trozos de carne… duele… pero no puedes moverte…" << endl;
                    cout << "(Dibujo del pasillo detrás de él con ojos en la oscuridad)" << endl;
                    cout << "No puedes respirar, empiezas a escupir e inhalar sangre… mueres ahogado mientras la criatura te devora…" << endl;
                }

                    if (escenaA == 17)
                {
                    cout << "Te le acercas a la persona y le dices: “Hola? Necesitas ayuda?”"<< endl;
                    cout <<"(Dibujo de la persona sin rostro, voltea hacia ti y sus intestinos se estiran hacia ti por el suelo)"<< endl;
                    cout << "Cuando te escucha, la criatura voltea hacia ti… No es humano." << endl;
                    cout << "Tratas de correr pero te enredó los pies con sus intestinos, tratas de pelear pero es inútil, sientes como los huesos de tus piernas son triturados con el movimiento de sus intestinos mientras te jalan hacia el…"<< endl;
                    cout << "lentamente sientes que los huesos de tu cadera se trituran…escupes sangre y…."<< endl;
                    cout << "(pantalla negra)"<< endl;
                }
                if (escenaA == 18)
                {
                    cout << "(Dibujo de una criatura acercándose desde la oscuridad)" << endl;
                    cout << "Será mejor quedarse dormido al final…." << endl;
                    cout << "(Pantalla negra)" << endl;
                }
                    if (escenaA == 19)
                {
                    cout << "(Pantalla negra)" << endl;
                    cout << "Estás mareado y desorientado, no sabes que está pasando, sientes cómo te están cargando a algún lugar…" << endl;
                    cout << "(Dibujo de varias personas sonriendo usando túnicas en medio de una sala parecida a la de un cubículo)" << endl;
                    cout << "Estás asustado, gritas ayuda pero nadie hace nada. Todos están sonriendo, reconoces las caras de varios de la escuela, tanto maestros como alumnos, por primera vez están sonriendo, pero no te tranquiliza para nada…" << endl;
                    cout << "(Dibujo del suelo abriéndose debajo de ti)" << endl;
                    cout << "Estás completamente asustado, observas como algo está saliendo del suelo…" << endl;
                    cout << "Eso te está jalando hasta el fondo… Gritas y nadie te puede escuchar, no hay nada que puedas hacer…" << endl;
                    cout << "(Pantalla negra)" << endl;
                }

                break;
            }

            // Verifica si se llegó al final de la fila
            if (i == c - 1)
            {
                //cout << escenaA << endl;
                if (escenaA == 0)
                {
                    cout << "(Dibujo con 3 pasillos)" << endl;
                    cout << "No tienes idea de donde estás, pero empiezas a alterarte un poco, no hay nada en tu mochila que te pueda ayudar, tan solo un suéter que puede ser una cómoda almohada, y una botella de agua casi vacía. Tienes 3 caminos…" << endl;
                    cout << "1: Esperar…" << endl;
                    cout << "2: Ir adelante" << endl;
                    cout << "3: Ir a la izquierda" << endl;
                    cout << "4: Ir a la derecha" << endl;
                    cout << "5: Tomar un descanso" << endl;
                }
                if (escenaA == 1)
                {
                    cout << "(Dibujo con un solo pasillo al frente)" << endl;
                    cout << "Caminaste por un pasillo que te llevó aquí, parece que solo hay un camino al frente…" << endl;
                    cout << "1: Regresar" << endl;
                    cout << "2: Esperar" << endl;
                    cout << "3: Ir adelante" << endl;
                }
                if (escenaA == 2)
                {
                    cout << "(Dibujo con la criatura y un camino a la izquierda)" << endl;
                    cout << "Esa criatura te observa… No entras en pánico, piensas si quisiera hacerte daño ya lo hubiera hecho…" << endl;
                    cout << "1: Regresar" << endl;
                    cout << "2: Esperar" << endl;
                    cout << "3: Acercarte a la criatura…" << endl;
                    cout << "4: Ir a la izquierda" << endl;
                }
                if (escenaA == 3)
                {
                    cout << "(Dibujo con un cuarto sin salida y una persona en la esquina)" << endl;
                    cout << "Caminaste a la izquierda y llegaste aquí. Ves a esa persona en la esquina en este cuarto oscuro… un escalofrío recorre tu espalda… ¿tal vez se perdió como tú?..." << endl;
                    cout << "1: Regresar" << endl;
                    cout << "2: Esperar" << endl;
                    cout << "3: Acercarte un poco y hablar con él…" << endl;
                }
                if (escenaA == 4)
                {
                    cout << "(Dibujo de la criatura abriendo su boca y fusionándose con la pared)" << endl;
                    cout << "(Dibujo de la criatura con la boca totalmente abierta y fusionado casi totalmente con la pared)" << endl;
                    cout << "De forma lenta la criatura abrió su boca y se fundió con la pared, lo que era su boca ahora es una entrada…" << endl;
                    cout << "1: Esperar" << endl;
                    cout << "2: Ir a la izquierda" << endl;
                    cout << "3: Avanzar" << endl;
                }
                if (escenaA == 5)
                {
                    cout << "(Dibujo de un cuarto sin puertas, solo manchas en las paredes y cosas tiradas en el suelo)"
                         << endl;
                    cout << "Callejón sin salida…" << endl;
                    cout << "1: Regresar" << endl;
                }
                if (escenaA == 6)
                {
                    cout << "(Dibujo con una iluminación verde saturada, hay un ser en el lado izquierdo que tiene un puñal en la espalda, hay un pasillo por la derecha)" << endl;
                    cout << "Entraste a un cuarto con una iluminación extraña… ves a un ser que parece estar sufriendo…" << endl;
                    cout << "1: Sacar el puñal que lleva en su espalda…" << endl;
                    cout << "2: Ignorarlo y avanzar al frente" << endl;
                    cout << "3: Hablar con eso…" << endl;
                }
                if (escenaA == 7)
                {
                    cout << "(Es un cuarto con dos pasillos al frente, uno angosto y uno ancho)" << endl;
                    cout << "Caminaste por un pasillo y llegaste aquí…" << endl;
                    cout << "1: Caminar por el camino ancho…" << endl;
                    cout << "2: Regresar…" << endl;
                    cout << "3: Ir por el camino estrecho…" << endl;
                    cout << "4: Esperar" << endl;
                }
                if (escenaA == 8)
                {
                    cout << "(Dibujo del niño con un puñal en la mano y la persona hecha pierda y desbaratándose)" << endl;
                    cout << "Sacas el puñal de su espalda rápidamente porque lo ves sufriendo… La criatura se empieza a hacer piedra y desbaratarse, continuas por el pasillo…" << endl;
                    cout << "(Dibujo de un pasadizo)" << endl;
                    cout << "¿Continuar por el pasadizo?" << endl;
                }
                if (escenaA == 9)
                {
                    cout << "(Dibujo de unas escaleras a la izquierda, se puede subir y bajar, y a la derecha hay un pasillo)" << endl;
                    cout << "Llegas hasta aquí, asustado y confundido con un puñal en la mano, ves que hay una escalera y un pasillo…" << endl;
                    cout << "1: Ir por el pasillo…" << endl;
                    cout << "2: Bajar…" << endl;
                    cout << "3: Subir…" << endl;
                }

                if (escenaA == 13)
                {
                    cout << "(Dibujo de la escena C)" << endl;
                    cout << "1: Regresar" << endl;
                    cout << "2: Acercarte a la criatura" << endl;
                    cout << "3: Esperar" << endl;
                }
                if (escenaA == 15)
                {
                    cout << "(Dibujo de la escena H pero con tono rojizo)" << endl;
                    cout << "Esperaste demasiado y no te puedes mover, no entiendes por qué pero estás demasiado fatigado… Lo mejor será que tomes un descanso" << endl;
                    cout << "1: Descansar…" << endl;
                }

                //cout << "Tienes " << opciones << " opciones, ¿cuál eliges?" << endl;
                cin >> seleccion;

                // Busca el nodo seleccionado en nodosO y actualiza la escenaA
                for (int j = 0; j < c; j++)
                {
                    if (seleccion == nodosO[j])
                    {
                        escenaA = nodos[j];
                    }
                }

                i = 0;
                x = 1;
                opciones = 0;
                seleccion = 0;

                // Reinicializa nodosO
                for (int j = 0; j < c; j++)
                {
                    nodosO[j] = 0;
                }
            }
            else
            {
                i++;
            }
        }

        escenaA = escenaI;
        printf("¿Deseas salir del juego? Presiona 1 para salir\n");
        scanf(" %i", &salida);
    }
    return 0;
}

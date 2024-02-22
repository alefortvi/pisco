
# Clase Pisco

La clase `Pisco` proporciona m�todos est�ticos para interactuar con la consola y realizar operaciones de dibujo y colisi�n.

## M�todos

### `static WORD getCurrentConsoleColor()`
Devuelve el color actual de la consola.

### `static void gotoxy(int x, int y)`
Mueve el cursor de la consola a la posici�n especificada por las coordenadas (x, y).

### `static void textColor(PiscoColor color)`
Establece el color de texto de la consola al color especificado.

### `static void putchxy(int x, int y, const std::string& ch, PiscoColor color)`
Escribe el car�cter especificado en la posici�n (x, y) de la consola con el color especificado.

### `static void putchxy(int x, int y, const std::string& ch)`
Escribe el car�cter especificado en la posici�n (x, y) de la consola.

### `static void draw(PiscoDraw& canvas)`
Dibuja el lienzo especificado en la consola.

### `static void erase(PiscoDraw& canvas)`
Borra el contenido del lienzo especificado en la consola.

### `static int areColliding(PiscoSprite& spriteFrom, PiscoSprite& spriteTo)`
Verifica si hay colisi�n entre dos sprites y devuelve un c�digo indicando el tipo de colisi�n.
- 1 si hay colisi�n izquierda o derecha.
- 2 si hay colisi�n arriba o abajo.
- 5 si hay colisi�n completa.
- 0 si no hay colisi�n.

## Notas
- Para utilizar los colores, se deben usar los valores de la enumeraci�n `PiscoColor`.
- El m�todo `areColliding` requiere sprites para realizar la detecci�n de colisiones.


=======

# Clase PiscoSprite

### `void addSprite(const std::string& key, PiscoDraw& sprite)`
Agrega un nuevo sprite con la clave especificada al mapa de sprites.

### `void setActiveSprite(const std::string& key)`
Establece el sprite activo utilizando la clave proporcionada.

### `PiscoDraw& getActivatedSprite()`
Devuelve una referencia al sprite activo.

### `std::string getActivatedKey() const`
Devuelve la clave del sprite activo.

## Atributos

- `std::map<std::string, PiscoDraw> sprites`: Mapa que almacena los sprites, donde la clave es el identificador �nico del sprite.
- `std::string activeSpriteKey`: Clave del sprite activo.

=======

# Clase PiscoDraw

La clase `PiscoDraw` representa un lienzo o �rea de dibujo bidimensional que contiene una matriz de p�xeles. Permite realizar operaciones como obtener y establecer valores de p�xeles, mover el lienzo y obtener informaci�n sobre sus dimensiones y posici�n.

## Constructor

### `PiscoDraw(int width, int height, int x, int y)`
Crea un nuevo objeto `PiscoDraw` con las dimensiones especificadas (`width` y `height`) y la posici�n (x, y) en el sistema de coordenadas.

### `PiscoDraw()`
Crea un nuevo objeto `PiscoDraw` con dimensiones y posici�n predeterminadas.

## M�todos

### `int getWidth() const`
Devuelve el ancho del lienzo.

### `int getHeight() const`
Devuelve la altura del lienzo.

### `int getX() const`
Devuelve la coordenada x de la posici�n del lienzo en el sistema de coordenadas.

### `int getY() const`
Devuelve la coordenada y de la posici�n del lienzo en el sistema de coordenadas.

### `Pixel getValue(int x, int y)`
Devuelve el p�xel ubicado en la posici�n (x, y) de la matriz del lienzo.

### `void setValue(int x, int y, Pixel& pixel)`
Establece el valor del p�xel en la posici�n (x, y) de la matriz del lienzo con el p�xel proporcionado.

### `void move(int offsetX, int offsetY)`
Mueve el lienzo seg�n el desplazamiento especificado por `offsetX` y `offsetY`.

## Atributos

- `int width`: Ancho del lienzo.
- `int height`: Altura del lienzo.
- `int x`: Coordenada x de la posici�n del lienzo en el sistema de coordenadas.
- `int y`: Coordenada y de la posici�n del lienzo en el sistema de coordenadas.
- `std::vector<std::vector<Pixel>> matrix`: Matriz bidimensional que representa los p�xeles del lienzo.


=======

# Clase Pixel

La clase `Pixel` representa un p�xel en un sistema de coordenadas bidimensional. Cada p�xel tiene una posici�n (x, y), un car�cter para representar su contenido visual y un color.

## Constructor

### `Pixel(int x, int y, const std::string& character, PiscoColor color)`
Crea un nuevo objeto `Pixel` con las coordenadas especificadas (x, y), el car�cter dado y el color proporcionado.

### `Pixel(const std::string& character, PiscoColor color)`
Crea un nuevo objeto `Pixel` con el car�cter dado y el color proporcionado. Las coordenadas por defecto se establecen en (0, 0).

## M�todos

### `int getX() const`
Devuelve la coordenada x del p�xel.

### `int getY() const`
Devuelve la coordenada y del p�xel.

### `const std::string& getCharacter() const`
Devuelve el car�cter asociado al p�xel.

### `PiscoColor getColor() const`
Devuelve el color asociado al p�xel.

## Atributos

- `int x`: Coordenada x del p�xel.
- `int y`: Coordenada y del p�xel.
- `std::string character`: Car�cter asociado al p�xel.
- `PiscoColor color`: Color asociado al p�xel.

=======

# Enumeraci�n PiscoColor

La enumeraci�n `PiscoColor` define los colores disponibles para utilizar en la representaci�n de p�xeles u otros elementos visuales en el proyecto.

- `BLACK`
- `BLUE`
- `GREEN`
- `CYAN`
- `RED`
- `MAGENTA`
- `BROWN`: Equivalente al amarillo en la biblioteca Conio.
- `LIGHTGRAY`: Equivalente al blanco en la biblioteca Conio.
- `DARKGRAY`
- `LIGHTBLUE`
- `LIGHTGREEN`
- `LIGHTCYAN`
- `LIGHTRED`
- `LIGHTMAGENTA`
- `YELLOW`
- `WHITE`

La enumeraci�n proporciona una amplia gama de colores que pueden ser utilizados para personalizar la apariencia de los elementos gr�ficos en el proyecto.


=======

# Ejemplo de uso de la clase Pisco

A continuaci�n se muestra un ejemplo de c�mo usar cada m�todo de la clase `Pisco`.

```cpp
#include <iostream>
#include "Pisco.h" // Incluimos el archivo de encabezado que contiene la clase Pisco

int main() {
    // Ejemplo de uso del m�todo getCurrentConsoleColor
    WORD currentColor = Pisco::getCurrentConsoleColor();
    std::cout << "Color actual de la consola: " << currentColor << std::endl;

    // Ejemplo de uso del m�todo gotoxy
    Pisco::gotoxy(10, 5);
    std::cout << "Esto se imprimir� en la posici�n (10, 5)" << std::endl;

    // Ejemplo de uso del m�todo textColor
    Pisco::textColor(PiscoColor::RED);
    std::cout << "Este texto ser� de color rojo" << std::endl;

    // Ejemplo de uso del m�todo putchxy con color
    Pisco::putchxy(15, 8, "@", PiscoColor::GREEN);
    std::cout << "Imprimiendo un car�cter @ en la posici�n (15, 8) con color verde" << std::endl;

    // Ejemplo de uso del m�todo putchxy sin color
    Pisco::putchxy(20, 10, "#");
    std::cout << "Imprimiendo un car�cter # en la posici�n (20, 10) sin especificar color" << std::endl;

    // Ejemplo de uso del m�todo draw con un PiscoDraw
    PiscoDraw canvas(20, 10, 0, 0); // Creamos un lienzo de 20x10 en la posici�n (0, 0)
    Pisco::draw(canvas);
    std::cout << "Dibujando un lienzo de 20x10 en la posici�n (0, 0)" << std::endl;

    // Ejemplo de uso del m�todo erase con un PiscoDraw
    Pisco::erase(canvas);
    std::cout << "Borrando el lienzo previamente dibujado" << std::endl;

    // Ejemplo de uso del m�todo areColliding con dos PiscoSprite
    PiscoSprite spriteFrom;
    PiscoSprite spriteTo;
    int collisionType = Pisco::areColliding(spriteFrom, spriteTo);
    std::cout << "Tipo de colisi�n entre spriteFrom y spriteTo: " << collisionType << std::endl;

    return 0;
}
=======

---
⌨️ with ❤️ by [alefortvi](https://github.com/alefortvi) 😊

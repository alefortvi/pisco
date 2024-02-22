
# Clase Pisco

La clase `Pisco` proporciona métodos estáticos para interactuar con la consola y realizar operaciones de dibujo y colisión.

## Métodos

### `static WORD getCurrentConsoleColor()`
Devuelve el color actual de la consola.

### `static void gotoxy(int x, int y)`
Mueve el cursor de la consola a la posición especificada por las coordenadas (x, y).

### `static void textColor(PiscoColor color)`
Establece el color de texto de la consola al color especificado.

### `static void putchxy(int x, int y, const std::string& ch, PiscoColor color)`
Escribe el carácter especificado en la posición (x, y) de la consola con el color especificado.

### `static void putchxy(int x, int y, const std::string& ch)`
Escribe el carácter especificado en la posición (x, y) de la consola.

### `static void draw(PiscoDraw& canvas)`
Dibuja el lienzo especificado en la consola.

### `static void erase(PiscoDraw& canvas)`
Borra el contenido del lienzo especificado en la consola.

### `static int areColliding(PiscoSprite& spriteFrom, PiscoSprite& spriteTo)`
Verifica si hay colisión entre dos sprites y devuelve un código indicando el tipo de colisión.
- 1 si hay colisión izquierda o derecha.
- 2 si hay colisión arriba o abajo.
- 5 si hay colisión completa.
- 0 si no hay colisión.

## Notas
- Para utilizar los colores, se deben usar los valores de la enumeración `PiscoColor`.
- El método `areColliding` requiere sprites para realizar la detección de colisiones.


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

- `std::map<std::string, PiscoDraw> sprites`: Mapa que almacena los sprites, donde la clave es el identificador único del sprite.
- `std::string activeSpriteKey`: Clave del sprite activo.

=======

# Clase PiscoDraw

La clase `PiscoDraw` representa un lienzo o área de dibujo bidimensional que contiene una matriz de píxeles. Permite realizar operaciones como obtener y establecer valores de píxeles, mover el lienzo y obtener información sobre sus dimensiones y posición.

## Constructor

### `PiscoDraw(int width, int height, int x, int y)`
Crea un nuevo objeto `PiscoDraw` con las dimensiones especificadas (`width` y `height`) y la posición (x, y) en el sistema de coordenadas.

### `PiscoDraw()`
Crea un nuevo objeto `PiscoDraw` con dimensiones y posición predeterminadas.

## Métodos

### `int getWidth() const`
Devuelve el ancho del lienzo.

### `int getHeight() const`
Devuelve la altura del lienzo.

### `int getX() const`
Devuelve la coordenada x de la posición del lienzo en el sistema de coordenadas.

### `int getY() const`
Devuelve la coordenada y de la posición del lienzo en el sistema de coordenadas.

### `Pixel getValue(int x, int y)`
Devuelve el píxel ubicado en la posición (x, y) de la matriz del lienzo.

### `void setValue(int x, int y, Pixel& pixel)`
Establece el valor del píxel en la posición (x, y) de la matriz del lienzo con el píxel proporcionado.

### `void move(int offsetX, int offsetY)`
Mueve el lienzo según el desplazamiento especificado por `offsetX` y `offsetY`.

## Atributos

- `int width`: Ancho del lienzo.
- `int height`: Altura del lienzo.
- `int x`: Coordenada x de la posición del lienzo en el sistema de coordenadas.
- `int y`: Coordenada y de la posición del lienzo en el sistema de coordenadas.
- `std::vector<std::vector<Pixel>> matrix`: Matriz bidimensional que representa los píxeles del lienzo.


=======

# Clase Pixel

La clase `Pixel` representa un píxel en un sistema de coordenadas bidimensional. Cada píxel tiene una posición (x, y), un carácter para representar su contenido visual y un color.

## Constructor

### `Pixel(int x, int y, const std::string& character, PiscoColor color)`
Crea un nuevo objeto `Pixel` con las coordenadas especificadas (x, y), el carácter dado y el color proporcionado.

### `Pixel(const std::string& character, PiscoColor color)`
Crea un nuevo objeto `Pixel` con el carácter dado y el color proporcionado. Las coordenadas por defecto se establecen en (0, 0).

## Métodos

### `int getX() const`
Devuelve la coordenada x del píxel.

### `int getY() const`
Devuelve la coordenada y del píxel.

### `const std::string& getCharacter() const`
Devuelve el carácter asociado al píxel.

### `PiscoColor getColor() const`
Devuelve el color asociado al píxel.

## Atributos

- `int x`: Coordenada x del píxel.
- `int y`: Coordenada y del píxel.
- `std::string character`: Carácter asociado al píxel.
- `PiscoColor color`: Color asociado al píxel.

=======

# Enumeración PiscoColor

La enumeración `PiscoColor` define los colores disponibles para utilizar en la representación de píxeles u otros elementos visuales en el proyecto.

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

La enumeración proporciona una amplia gama de colores que pueden ser utilizados para personalizar la apariencia de los elementos gráficos en el proyecto.


=======

# Ejemplo de uso de la clase Pisco

A continuación se muestra un ejemplo de cómo usar cada método de la clase `Pisco`.

```cpp
#include <iostream>
#include "Pisco.h" // Incluimos el archivo de encabezado que contiene la clase Pisco

int main() {
    // Ejemplo de uso del método getCurrentConsoleColor
    WORD currentColor = Pisco::getCurrentConsoleColor();
    std::cout << "Color actual de la consola: " << currentColor << std::endl;

    // Ejemplo de uso del método gotoxy
    Pisco::gotoxy(10, 5);
    std::cout << "Esto se imprimirá en la posición (10, 5)" << std::endl;

    // Ejemplo de uso del método textColor
    Pisco::textColor(PiscoColor::RED);
    std::cout << "Este texto será de color rojo" << std::endl;

    // Ejemplo de uso del método putchxy con color
    Pisco::putchxy(15, 8, "@", PiscoColor::GREEN);
    std::cout << "Imprimiendo un carácter @ en la posición (15, 8) con color verde" << std::endl;

    // Ejemplo de uso del método putchxy sin color
    Pisco::putchxy(20, 10, "#");
    std::cout << "Imprimiendo un carácter # en la posición (20, 10) sin especificar color" << std::endl;

    // Ejemplo de uso del método draw con un PiscoDraw
    PiscoDraw canvas(20, 10, 0, 0); // Creamos un lienzo de 20x10 en la posición (0, 0)
    Pisco::draw(canvas);
    std::cout << "Dibujando un lienzo de 20x10 en la posición (0, 0)" << std::endl;

    // Ejemplo de uso del método erase con un PiscoDraw
    Pisco::erase(canvas);
    std::cout << "Borrando el lienzo previamente dibujado" << std::endl;

    // Ejemplo de uso del método areColliding con dos PiscoSprite
    PiscoSprite spriteFrom;
    PiscoSprite spriteTo;
    int collisionType = Pisco::areColliding(spriteFrom, spriteTo);
    std::cout << "Tipo de colisión entre spriteFrom y spriteTo: " << collisionType << std::endl;

    return 0;
}
=======

---
âŒ¨ï¸ with â¤ï¸ by [alefortvi](https://github.com/alefortvi) ðŸ˜Š

#!/bin/bash

# Archivo de salida
output_h="Pisco.h"

# Directorios de archivos de origen
source_include_dir="include"
source_imp_dir="imp"

# Lista de archivos
header_files=("PiscoColor.h" "Pixel.h" "PiscoDraw.h" "PiscoSprite.h" "Pisco.h")
source_files=("Pixel.cpp" "PiscoDraw.cpp" "PiscoSprite.cpp" "Pisco.cpp")

# Encabezados estándar
standard_includes="#include <string>\n#include <vector>\n#include <cmath>\n#include <iostream>\n#include <Windows.h>\n#include <map>\n"

# Encabezado inicial para el archivo .h
echo -e "/*" > $output_h
echo -e "  Archivo generado automáticamente." >> $output_h
echo -e "*/\n" >> $output_h

# Escribir encabezados estándar
echo -e "$standard_includes" >> $output_h

# Combinar archivos .h
for file in "${header_files[@]}"
do
    echo "Combinando $file en $output_h..."
    # Eliminar todas las líneas de inclusión
    sed '/#include/d' "$source_include_dir/$file" >> $output_h
    echo -e "\n" >> $output_h
done

# Combinar archivos .cpp
for file in "${source_files[@]}"
do
    echo "Combinando $file en $output_h..."
    echo -e "\n/* Implementación de $file */\n" >> $output_h
    # Eliminar todas las líneas de inclusión
    sed '/#include/d' "$source_imp_dir/$file" >> $output_h
    echo -e "\n" >> $output_h
done

echo "¡Mezcla de archivos completada!"

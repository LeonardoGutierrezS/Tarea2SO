# Tarea 2 Sistemas Operativos

Integrantes: Leonardo Gutierrez y Eduardo Riquelme.

## Descripción

Esta tarea consiste en convertir una imagen a escala de grises utilizando la librería OpenCV cumpliendo con lo solicitado en el enunciado de la tarea.

## Input
Imagen a color en formato jpg.

## Output
Imagen ingresada en escala de grises.

## Instrucciones de compilación:

1. Navegar al directorio donde se encuentra el código fuente y las imágenes.

   ```bash
   cd <directorio a ejecutar>
   ```

2. Compilar el programa.

   ```bash
   make
   ```

3. Ejecutar el programa proporcionando la imagen a color y el nombre deseado para la imagen en escala de grises.

   ```bash
   ./convertir_a_grises imagen_a_color.jpg imagen_gris.jpg
   ```
   Para los programas que requieren el uso de hilos especificos (ejemplo con 4 hilos).
   
   ```bash
   ./convertir_a_grises imagen_a_color.jpg imagen_gris.jpg 4
   ```
   
   Puedes reemplazar "imagen_a_color" y "imagen_gris" por los nombres de archivos deseados.

5. (Opcional) Para limpiar los archivos generados.

   ```bash
   make clean
   ```

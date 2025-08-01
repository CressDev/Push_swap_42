## Descripción

Push_swap es un proyecto de algoritmos que se divide en dos componentes principales:

1. Parseo y Validación: Procesamiento y validación de argumentos de entrada
2. Algoritmo de Ordenación: Implementación del algoritmo Radix Sort para ordenar usando stacks

El objetivo es ordenar una serie de números enteros usando dos stacks (A y B) con un conjunto limitado de operaciones, en el menor número de movimientos posible.

Características

Parseo y Validación
- Validación de formato: Verificación de que sean números válidos
- Detección de duplicados: Comprobación de números repetidos
- Múltiples formatos: Soporte para argumentos separados o string única
- Gestión de errores: Manejo robusto de entradas inválidas
- Rango de enteros: Validación dentro del rango de int

Algoritmo de Ordenación
- Algoritmo Radix Sort: Implementación optimizada para stacks
- Gestión de memoria robusta: Sin memory leaks
- Optimizaciones específicas: Para 2, 3, 4 y 5 elementos
- Indexación inteligente: Conversión a índices para Radix Sort

Operaciones Permitidas

Stack A y Stack B
- sa/sb: Intercambia los dos primeros elementos del stack
- ss: Ejecuta sa y sb simultáneamente
- pa: Mueve el primer elemento de B hacia A
- pb: Mueve el primer elemento de A hacia B
- ra/rb: Rota el stack hacia arriba (primer elemento al final)
- rr: Ejecuta ra y rb simultáneamente
- rra/rrb: Rota el stack hacia abajo (último elemento al principio)
- rrr: Ejecuta rra y rrb simultáneamente

Algoritmo Radix Sort

El algoritmo Radix Sort ordena los números procesando cada bit de su representación binaria del indice, 
desde el bit menos significativo hasta el más significativo

Implementación
1. Indexación: Convertir valores a índices (0, 1, 2, ..., n-1)
2. Para cada bit: Separar elementos según bit=0 (stack B) o bit=1 (stack A)
3. Reunir todos los elementos de B de vuelta a A
4. Repetir hasta procesar todos los bits

Optimizaciones
- 3 elementos: Algoritmo específico (máximo 2 movimientos)
- 5 elementos: Ordenación parcial optimizada
- Más de 5: Radix Sort completo


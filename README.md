 Taller de Programacion 1 Veiga
## Trabajo Práctico 3 Taller Pages

Alumno: Robinson Fang

Padrón: 97009

Repositorio: https://github.com/fangrobinson/taller-de-programacion-1-veiga-tp3-taller-pages

## Introducción

#### Objetivo

El objetivo de este trabajo práctico es desarrollar una aplicación servidor que atenderá petitorios HTTP, mediante los cuales podrá acceder y dar alta a recursos del mismo.

#### Consideraciones particulares

1. Los métodos soportados serán únicamente GET y POST
2. Se deberá indicar por pantalla en caso que se reciba un método no soportado.
3. Se puede asumir que los petitorios siempre respetan el protocolo HTTP.
4. En el protocolo se cambiaron los saltos de linea “\r\n” por “\n”.

#### Resultados posibles para la ejecución de un Servidor

El servidor devolverá 0 si su ejecución fue exitosa. Si la cantidad de parámetros es incorrecta, se cancela la ejecución y se devuelve 1. 

#### Resultados posibles para la ejecución de un Cliente

El cliente deberá devolver siempre 0.

### Entidades que modelan la solución del trabajo práctico

#### Client

Modela el comportamiento necesario para un usuario que quiere realizar consultas u operaciones sobre un servidor HTTP que soporta los comandos GET y POST. Se leen de entrada estándar tanto los métodos como los contenidos de estos petitorios.

#### Socket

Modelan la entidad socket que permite utilizar los métodos que provee el sistema para el envío y recepción de mensajes. 

#### Command - GetCommand - PostCommand - NullCommand

Command modela la ejecución de un petitorio abstracto. Define la interfaz que deben poder soportar todos los petitorios a futuro. 

Tanto GetCommand, PostCommand y NullCommand resuelven las consultas de manera polimórfica por medio de la sobrecarga del operador paréntesis con los datos que obtuvieron en sus respectivos constructores.

En el caso de NullCommand el comportamiento modelado es el de un petitorio incorrecto.

#### Command Factory

Esta entidad se encarga de la correcta construcción de un petitorio a resolver. 

#### LineParser

Encapsula las tareas de parseo de contenidos de los petitorios HTTP. Que se asumen completos aunque puedan tener contenidos inválidos.

#### Resource Manager

Núclea la responsabilidad de modelar los recursos sobre los cuales se consultarán para responder petitorios de los clientes. 

#### Server

Se encarga de manejar el envío y la recepción de los mensajes de petitorios HTTP que debe resolver, pero delega esta responsabilidad en el ThAccept. En rigor de su comportamiento se queda esperando por entrada estándar el caracter 'q' que indica la interrupción del programa.

#### Thread

Modela el comportamiento abstracto de los hilos que son necesarios para resolver de forma concurrente el trabajo práctico.

#### ThAccept

Sobreescribe el método run() de Thread con la implementación que resuelve la aceptación de nuevos clientes, el purgado de clientes en estado 'zombie' y la correcta interrupción y desalojo de los recursos de los hilos de clientes. 

#### ThClient

Sobreescribe el método run() de Thread con la implementación que resuelve la consulta de un petitorio HTTP de un cliente. 

## Resultado

Todas las pruebas tanto públicas como privadas son ejecutadas satisfactoriamente. 

Fueron realizados los chequeos correspondientes con valgrind, address sanitizer, cppcheck y cpplint.


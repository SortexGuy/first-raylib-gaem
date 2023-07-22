# first-raylib-gaem
Primer juego de la vacas en raylib-cpp

## Instalación de dependencias

### IDE
Lo primero, tener el IDE VSCode, cualquier otro editor se puede usar pero ni idea de como configurarlo.

#### Extensiones
Las que vamos a utilizar por ahora son:
1. [Microsoft C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools): Para autocompletado, debugging y snippets.
2. [Microsoft CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools): Para integracion con el sistema de construcción de CMake.
3. [GitKraken GitLens](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens): Para mejor integracion con Git.

Algunas opcionales pueden ser:
* [Markdown All in One](https://marketplace.visualstudio.com/items?itemName=yzhang.markdown-all-in-one): Para modificar este archivo mejor y leerlo desde el editor.

### Compilador
Vamos a utilizar [MinGW64](https://www.mingw-w64.org/) desde [MSYS2](https://www.msys2.org/) que es como una consola de comandos aparte.

#### Para instalar
Descargan el ejecutable que aparece en la pagina https://www.msys2.org/ y sigan las instrucciones hasta el paso 4, 
yo puse ```C:\Coding\msys64``` como carpeta de instalacion y es lo que recomiendo para que las configuraciones de todos sean iguales.

Una vez finalizada la instalacion les va a abrir una consola de comandos alli vamos a instalar MinGW como tal, 
desde aqui van a seguir los pasos de [esta guia](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain) empezando por el paso 4 para poder instalar el compilador y las herramientas que necesitaremos.
Espero que entiendan como modificar el Path en windows, sino agregare en otro momento fotos de como se hace.

Ahora solo necesitamos una cosa para empezar a configurar:

### Git
Vamos a utilizar [Git](https://git-scm.com/) pelao, nada de interfaz y cosas asi, 
quizas encuentre la manera de instalar [Lazygit](https://github.com/jesseduffield/lazygit) o [GitUI](https://github.com/Extrawurst/gitui) desde MSYS2 pero es lo mismo que utilizar los comandos.
Descargan el instalador desde [aqui](https://git-scm.com/download/win) y pueden utilizar [esta guia](https://phoenixnap.com/kb/how-to-install-git-windows) para instalarlo, solo hay 2 o 3 cosas que deberian cambiar pero cuidado.

De hecho menti con lo de los comandos y la gui, creo que vamos a necesitar la aplicación de [GitHub Desktop](https://desktop.github.com/) para autentificar las actualizaciones del repositorio,
además gracias a vscode y la extension GitLens se puede manejar el repositorio de git desde el mismo IDE sin meternos en la terminal.

## Configuración
### IDE
Esto de abajo es la configuracion relevante del archivo ```settings.json```:
```json
{
    "extensions.ignoreRecommendations": true,
    "editor.formatOnSaveMode": "modificationsIfAvailable",
    "C_Cpp.clang_format_fallbackStyle": "Chromium",
    "terminal.integrated.profiles.windows":
    {
        "MINGW64":
        {
            "path": "C:/Coding/msys64/usr/bin/bash.exe",
            "env":
            {
                "CHERE_INVOKING": "1",
                "MSYSTEM": "MINGW64",
                // THE FOLLOWING IS A HACK TO PLACE THE MSYS PATHS BEFORE THE WINDOWS ONES
                "PATH": "/usr/bin;/mingw64/bin;${env:PATH}"
            },
            "color": "terminal.ansiMagenta"
        }
    },
    "terminal.integrated.defaultProfile.windows": "Git Bash",
    "cmake.configureOnOpen": false,
}
```
Este archivo se puede abrir usando la paleta de comandos (con Ctrl+Shift+P) y escribiendo "settings", 
todas las demas configuraciones del vscode se pueden hacer desde la configuración grafica normal.
Pueden no copiar la opcion ```"terminal.integrated.profiles.windows"``` y lo que esta dentro de sus llaves, 
que es una configuracion que hice por si acaso, como ya tienen la opcion de ```"Git Bash"``` como por defecto cuando abran la terminal integrada (con Ctrl+` ) deberia de aparecer una pantalla similar a la que aparecio cuando instalaron MSYS2
(De hecho deberia decir MINGW64).

### Git
Primero git porque es más facil de explicar.
Para configurar git solo tienen que abrir la terminal integrada (con Ctrl+` o con la paleta de comandos con Ctrl+Shift+P)
y ingresar los siguientes comandos:
```bash
git config --global user.name "TU NOMBRE"
git config --global user.email "TU@GMAIL"
```
En mi caso el nombre es ```"Rubén A"``` y el correo es ```"sortexjuegos@gmail.com"``` que es mi correo de github,
es mejor que coincidan con sus usuarios de github asi no hay problemas al ver quien hizo que.

### CMake tools
Esto solo lo van a hacer la primera vez que entren al proyecto, abajo salen varios botones (cosa que se puede personalizar) y si ponen el mouse encima de el que tiene la x a la izquierda deberia decir *no problems* a la derecha esta el selector de configuraciones de cmake,
por ahora solo hay debug creo, a la derecha de ese está el selector de compilador,
ahi tienen que elegir el que diga **```"GCC (mingw64)"```** (haciendo click abajo lo que abre una lista arriba).

Una vez hecho esto ya pueden compilar dandole al boton **build** y correr dandole al boton con una flechita.


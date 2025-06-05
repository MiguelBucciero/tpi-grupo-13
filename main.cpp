#include <iostream>
#include "rlutil.h"
#include "UsuarioManager.h"
#include "MenuAdministrador.h"
#include "MenuRecepcionista.h"
#include "MenuMedico.h"

using namespace std;



int main(){
    UsuarioManager usuario;
   while(true){
        usuario.login();
   }
return 0;
}


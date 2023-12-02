#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <sstream>


using namespace std;

struct datos{
	int cedula;
	string email, nombre;
	int telefono;
	int contra;
	int saldo;
	int inscripciones[10];
	int pagar[10];
};

//=======================================================APARTADO DE VERIFICACION=============================================================

bool validar_numero (string & cadena){
	
	for (int i=0; i<cadena.size(); i++){
		if (cadena[i]<48 || cadena[i]>57 || cadena[i]==32){
			system ("cls");
			cout<<"ERRROR: DIGITE UNA OPCION NUMERICA\n";
			Beep (800, 100); Beep (800, 100);
			system ("pause");
			return true;
		}
	}
	return false;		
}//Cierre Valid.Menu

bool validar_nombre (string & validacion_email){
	
	if (validacion_email.empty()){
		system ("cls");
		cout<<"ERROR: HA DEJADO EL ESPACIO EN BLANCO\n";
		Beep (800, 100); Beep (800, 100);
		system ("pause");
	return true;
	}
	return false;

}//Cierre Email.Validacion

bool validar_cedula_numeros (string & cadena){
	for (int i=0; i<cadena.size(); i++){
	
		if (cadena[i]<48 || cadena[i]>57 || cadena[i]==32){
			system ("cls");
			cout<<"ERROR: DIGITE NUMEROS PARA SU CEDULA\n";
			Beep (800, 100); Beep (800, 100);
			system ("pause");
			return true;
		}
		else if (cadena.size()<7||cadena.size()>10 || cadena.size()==9){
			system ("cls");
			cout<<"ERROR: LA CEDULA NO CUMPLE CON TODOS SUS DIGITOS\n";
			Beep (800, 100); Beep (800, 100);
			system ("pause");
			return true;
		}
	}
	return false;
}//Cierre Verificacion.Cedula

bool validar_cedula_repetida(datos dato[], int revision, int tam){
    for(int i=0; i<tam; i++){
        if(dato[i].cedula==revision){
        	system ("cls");
            cout<<"ERROR: CEDULA REPETIDA"<<endl;
            Beep (800, 100); Beep (800, 100);
            system ("pause");
            return true;
        }   
    }
    return false;
}//Cierre Cedula.Repetida

bool validar_email (string & validacion_email){
	
	for (int i=0; i<validacion_email.size(); i++){
		if (validacion_email[i]=='@'){
			return false;
		}
	}//For
	if (validacion_email.empty()){
		system ("cls");
		cout<<"ERROR: HA DEJADO EL ESPACIO EN BLANCO\n";
		Beep (800, 100); Beep (800, 100);
		system ("pause");
	return true;
	}
	
	system ("cls");
	cout<<"ERROR: DIGITE UN CORREO VALIDO\n";
	Beep (800, 100); Beep (800, 100);
	system ("pause");
	return true;

}//Cierre Email.Validacion

void esconder_clave_cuenta(datos dato[], int aux2) {
	
int cantidad_letras;
bool comprob=true, respuesta;
char a;
string clave;

system ("cls");
cout<<"DIGITE UNA CONTRASEÑA---> ";
cantidad_letras=1;

	do{
		a=getch();
		cout<<"*";
		clave+=a;
		cantidad_letras++;
		if (cantidad_letras==5){
	    	comprob=(validar_numero(clave)==true); //SE VALIDA QUE LA CADENA SOLO CONTENGA NUMEROS		
	    	if (comprob==true) {
			    cantidad_letras=1;
	    		system("cls");

				cout<<"DIGITE SU CONTRASEÑA NUEVAMENTE---> ";
				clave="";
			}
		}
	}while(cantidad_letras<=4 || comprob==true) ;
	istringstream(clave)>>dato[aux2].contra;
return;
}

bool validar_cedula_consignacion (datos dato[], int cadena, int tam){
	
	for (int i=0; i<tam; i++){		
		if (dato[i].cedula==cadena){
			system ("cls");
			cout<<"CEDULA ENCONTRADA!\n";
			system ("pause");
			return false;
		}
	}
	cout<<"ERROR: NO SE HA ENCONTRADO LA CEDULA\n";
	Beep (800, 100); Beep (800, 100);
	system ("pause");
	return true;
}

bool validar_contra_consignacion (datos dato[], int cadena, int tam, int aux){
	
		if (cadena!=dato[aux].contra){
			system ("cls");
			cout<<"ERROR: CONTRASEÑA INVALIDA\n";
			Beep (800, 100); Beep (800, 100);
			system ("pause");
			return true;
		}
		else if (cadena==dato[aux].contra){
			return false;
		}
}

void esconder_clave_consignacion (datos dato[], int tam, int aux){
		
	int cont_letras=0, clave2=0;
	char temp;
	string clave1;
	
	system ("cls");
	cout<<"DIGITE SU CONTRASEÑA---> ";
	cont_letras=1;
	do {
		do {
			do {
				temp=getch();
				cout<<"*";
				clave1+=temp;
				cont_letras++;
			}while (cont_letras<=4);
		}while (validar_numero(clave1));
		istringstream(clave1)>>clave2;
	}while (validar_contra_consignacion(dato, clave2, tam, aux));
	return;
}

bool validar_dinero_envio (string & dinero){
	for (int i=0; i<dinero.size(); i++){
		if (dinero[i]<48 || dinero[i]>57 || dinero[i]==32){
			system ("cls");
			cout<<"ERRROR: DIGITE UNA OPCION NUMERICA\n";
			Beep (800, 100); Beep (800, 100);
			system ("pause");
			return true;
		}
	}
	return false;	
}

//============================================================================================================================================

//=======================================================APARTADO DE PROGRAMAS================================================================
void crear_cuenta (datos dato[],int tam){
	system ("cls");
	string validacion_cedula="x", validacion_numero, validacion_email, validacion_contra, aux1, nombre;
	int cedula=0, num=0, clave_escondida=0, aux2=0;
	
	string saludo="BIENVENIDO AL APARTADO DE CREACION DE CUENTA";
	
	int a=0,b=0,c=0;
	cout<<"|";	
	for (int a=0; a<saludo.size(); a++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
 	cout<<endl;
 	cout<<"|";
	for (int b=0; b<saludo.size(); b++){
		cout<<saludo[b]; Sleep (30);
	}
	cout<<"|";
	cout<<endl;
	cout<<"|";
	for (int c=0; c<saludo.size(); c++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
	cout<<endl;
	system ("pause");
	
	
	for (int i=0; num<1; i++){	//Info. de Usuario
		aux2=i;
		fflush (stdin);
		if (dato[i].cedula==0){
		
		do{
		system ("cls");
		cout<<"DIGITE SU NOMBRE COMPLETO---> ";
		getline (cin, nombre);
		}while(validar_nombre(nombre));
		dato[i].nombre=nombre;
		
		do{						//Cedula
			do{
				system ("cls");
				cout<<"DIGITE SU NUMERO DE CEDULA---> ";
				fflush (stdin);
				getline (cin, aux1);
			}while (validar_cedula_numeros(aux1));
			istringstream(aux1)>>cedula;
		}while(validar_cedula_repetida(dato, cedula, tam));
		dato[i].cedula=cedula;
	
		do {					//Email
			system ("cls");
			cout<<"DIGITE SU CORREO ELECTRONICO---> ";
			fflush (stdin);
			getline (cin, validacion_email);
		}while (validar_email(validacion_email));
		validacion_email=dato[i].email;
		
		do{						//Telefono
			system ("cls");
			cout<<"DIGITE SU NUMERO TELEFONICO---> ";
			getline (cin,validacion_numero);
		}while (validar_numero(validacion_numero));
		istringstream (validacion_numero)>>dato[i].telefono;
	
		esconder_clave_cuenta(dato, aux2);
				
		system ("cls");
		cout<<"-------------------------------------------------------\n";
		cout<<"RECUERDE!: SU NUMERO DE CEDULA SERA SU NUMERO DE CUENTA\n";
		cout<<"-------------------------------------------------------\n";
		num++;
		}
	}
}//Cierre Void

void consignacion (datos dato[], int tam){

	system ("cls");
	string validacion_cedula, validacion_contra;
	int numerico=0, aux1=0, aux2=0, valor_final=0, activador=0;
//
	int cedula=0, cantidad_num, cont=0;
	string cantidad_str, remitente;
//	
	string saludo="BIENVENIDO AL APARTADO DE CONSIGNACIONES";
	int a=0,b=0,c=0;
	cout<<"|";	
	for (int a=0; a<saludo.size(); a++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
 	cout<<endl;
 	cout<<"|";
	for (int b=0; b<saludo.size(); b++){
		cout<<saludo[b]; Sleep (30);
	}
	cout<<"|";
	cout<<endl;
	cout<<"|";
	for (int c=0; c<saludo.size(); c++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
	cout<<endl;
	system ("pause");
	
	do {
		do {
			numerico=0;
			system ("cls");
			cout<<"INGRESE SU NUMERO DE CEDULA---> ";
			getline (cin, validacion_cedula);
		}while (validar_numero (validacion_cedula));
			istringstream(validacion_cedula)>>numerico;
			
			for (int i=0; i<tam; i++){		
				if (dato[i].cedula==numerico){
					aux1=i;
					system ("cls");
					cout<<"CEDULA ENCONTRADA!\n";
					system ("pause");
					activador=1;
				}
			}
	}while (activador!=1);
	activador=0;

	system ("cls");
	cout<<"NOMBRE DE LA PERSONA O EMPRESA QUE REALIZA LA CONSIGNACION---> ";
	fflush(stdin);
	getline(cin, remitente);
	
	do{
		system ("cls");	
		cout<<"CANTIDAD QUE DESEA ENVIAR---> ";
		getline(cin, cantidad_str);
	}while (validar_dinero_envio (cantidad_str));
	istringstream(cantidad_str)>>valor_final;
	
		dato[aux1].saldo=dato[aux1].saldo+valor_final-(valor_final*4)/1000;
		
	system("cls");
	cout<<"ENVIADO CORRECTAMENTE!\n";
	
	aux1=0;
 	return;
}//Cierre Void

void consultar_saldo(datos dato[], int tam){
	int numerico=0, aux=0, activador=0;
	string validacion_cedula;
///	
	string saludo="BIENVENIDO AL APARTADO DE CONSULTA DE SALDO";
	
	system("cls");
	int a=0,b=0,c=0;
	cout<<"|";	
	for (int a=0; a<saludo.size(); a++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
 	cout<<endl;
 	cout<<"|";
	for (int b=0; b<saludo.size(); b++){
		cout<<saludo[b]; Sleep (30);
	}
	cout<<"|";
	cout<<endl;
	cout<<"|";
	for (int c=0; c<saludo.size(); c++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
	cout<<endl;
	system ("pause");
	cout<<"LA OPERACION DE RETIRO DE DINERO TIENE UN COSTO DE 2000 EL CUAL SERA RETIRADO DE SU SALDO"<<endl;
	
		do {
			do {
				numerico=0;
				system ("cls");
				cout<<"INGRESE SU NUMERO DE CEDULA---> ";
				getline (cin, validacion_cedula);
			}while (validar_numero (validacion_cedula));
				istringstream(validacion_cedula)>>numerico;
				for (int i=0; i<tam; i++){		
					if (dato[i].cedula==numerico){
						aux=i;
						system ("cls");
						cout<<"CEDULA ENCONTRADA!\n";
						system ("pause");
						activador=1;
					}
				}
		}while (activador=0);
		activador=0;
		
	system ("cls");
 	esconder_clave_consignacion(dato, tam, aux);
	
	if(dato[aux].saldo<1500){
		system ("cls");
		cout<<"ERROR: SU SALDO ES INSUFICIENTE PARA REALIZAR LA CONSULTA!";
		Beep (800, 100); Beep (800, 100);
		system ("pause");
	}
	else{
		system ("cls");
		dato[aux].saldo=dato[aux].saldo-1500;
		cout<<"TIENES UN SALDO DE--> "<<dato[aux].saldo<<endl;	
		Beep (500, 100); Beep (500, 100);
	}
	return;
}//void

void retiro (datos dato[], int tam){
	long ca=0;
	string vu;
	double re=0;
	int numerico=0, aux1=0, valor_final=0, activador=0;
	string validacion_cedula;
///
	string saludo="BIENVENIDO AL APARTADO DE RETIROS";
	
	int a=0,b=0,c=0;
	cout<<"|";	
	for (int a=0; a<saludo.size(); a++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
 	cout<<endl;
 	cout<<"|";
	for (int b=0; b<saludo.size(); b++){
		cout<<saludo[b]; Sleep (30);
	}
	cout<<"|";
	cout<<endl;
	cout<<"|";
	for (int c=0; c<saludo.size(); c++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
	cout<<endl;
	system ("pause");
	cout<<"LA OPERACION DE RETIRO DE DINERO TIENE UN COSTO DE 2000 EL CUAL SERA RETIRADO DE SU SALDO"<<endl;
	
		do {
			do {
				numerico=0;
				system ("cls");
				cout<<"INGRESE SU NUMERO DE CEDULA---> ";
				getline (cin, validacion_cedula);
			}while (validar_numero (validacion_cedula));
				istringstream(validacion_cedula)>>numerico;
				for (int i=0; i<tam; i++){		
					if (dato[i].cedula==numerico){
						aux1=i;
						system ("cls");
						cout<<"CEDULA ENCONTRADA!\n";
						system ("pause");
						activador=1;
					}
				}
		}while (activador=0);
		activador=0;
	
	system ("cls");
	esconder_clave_consignacion(dato, tam, aux1);
	system("cls");
	
	cout<<"CUANTO DESEA RETIRAR---> ";
	cin>>re;
	system("cls");
	
		if (re<=dato[aux1].saldo && dato[aux1].saldo>2000){
			dato[aux1].saldo=dato[aux1].saldo-re-2000;
			cout<<"SE HAN RETIRADO "<<re<<" EXITOSAMENTE SU DINERO Y 2000 POR SERVICIO DE RETIRO"<<endl;
		}
		else{
			cout<<"SALDO INSUFICIENTE"<<endl;
		}
}//Cierre void

void inscribir (datos dato[], int tam){
	int pago, pos;
	string validacion_cedula;
	int numerico=0, aux=0, activador;
//	
	string saludo="BIENVENIDO AL APARTADO DE CREACION DE CUENTA";
	
	int a=0,b=0,c=0;
	cout<<"|";	
	for (int a=0; a<saludo.size(); a++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
 	cout<<endl;
 	cout<<"|";
	for (int b=0; b<saludo.size(); b++){
		cout<<saludo[b]; Sleep (30);
	}
	cout<<"|";
	cout<<endl;
	cout<<"|";
	for (int c=0; c<saludo.size(); c++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
	cout<<endl;
	system ("pause");
	do {
		do {
			numerico=0;
			system ("cls");
			cout<<"INGRESE SU NUMERO DE CUENTA---> ";
			getline (cin, validacion_cedula);
		}while (validar_numero (validacion_cedula));
			istringstream(validacion_cedula)>>numerico;
			
			for (int i=0; i<tam; i++){		
				if (dato[i].cedula==numerico){
					aux=i;
					system ("cls");
					cout<<"NUMERO DE CUENTA ENCONTRADA!\n";
					system ("pause");
					activador=1;
				}
			}
	}while (activador=0);
	activador=0;
	
	system ("cls");
 	esconder_clave_consignacion(dato, tam, aux);
	
	system ("cls");
	cout<<"DESIGNE UN NUMERO PARA EL PAGO---> ";
	cin>>pago;
	
	for (int j=0; j<10; j++){
				if (dato[aux].inscripciones[j]==pago){
					system ("cls");
					cout<<"ESTE NUMERO YA ESTA REGISTRADA"<<endl;
					system ("pause");
					break;
				}
				if (dato[aux].inscripciones[j]==0){
					dato[aux].inscripciones[j]=pago;
					system ("cls");
					cout<<"DIGITE EL VALOR DEL PAGO--->";
					cin>>dato[aux].pagar[j];
					system ("cls");
					cout<<"EL PAGO SE HA INSCRITO CORRECTAMENTE!"<<endl;
					break;
				}
	}
}//Cierre Void

void pagos (datos dato[], int tam){
	int u=0,p=0,a=0;
		string validacion_cedula;
	int numerico=0, aux=0, activador;
//	
	string saludo="BIENVENIDO AL APARTADO DE CREACION DE CUENTA";
	
	int e=0,b=0,c=0;
	cout<<"|";	
	for (int e=0; e<saludo.size(); e++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
 	cout<<endl;
 	cout<<"|";
	for (int b=0; b<saludo.size(); b++){
		cout<<saludo[b]; Sleep (30);
	}
	cout<<"|";
	cout<<endl;
	cout<<"|";
	for (int c=0; c<saludo.size(); c++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
	cout<<endl;
	system ("pause");
	
	do {
		do {
			numerico=0;
			system ("cls");
			cout<<"INGRESE SU NUMERO DE CUENTA---> ";
			getline (cin, validacion_cedula);
		}while (validar_numero (validacion_cedula));
			istringstream(validacion_cedula)>>numerico;
			
			for (int i=0; i<tam; i++){		
				if (dato[i].cedula==numerico){
					aux=i;
					system ("cls");
					cout<<"NUMERO DE CUENTA ENCONTRADA!\n";
					system ("pause");
					activador=1;
				}
			}
	}while (activador=0);
	activador=0;
	
	system ("cls");
 	esconder_clave_consignacion(dato, tam, aux);
	
	system ("cls");
	cout<<"DIGITE EL NUMERO PAGO A PAGAR"<<endl;
	cin>>u;
	
			system("cls");
			
			for(int i=0; i<10; i++){
				if(dato[aux].inscripciones[i]>0){
					cout<<dato[aux].inscripciones[i]<<"\tCosto: "<<dato[aux].pagar[i]<<endl;
				}
				else {
					cout<<"."<<endl;
				}
			}
			
			cout<<"DIJITE EL PAGO QUE DESEA REALIZAR"<<endl;
			cin>>u;
			
			for(int j=0; j<10; j++){
				if(dato[aux].inscripciones[j]==u){
					if(dato[aux].saldo>dato[aux].pagar[j]){
						dato[aux].saldo= dato[aux].saldo-dato[aux].pagar[j];
						cout<<"SU PAGO SE REALIZO EXITOSAMENTE"<<endl;
						dato[aux].inscripciones[j]=0;
					}
					else if (dato[aux].saldo<dato[aux].pagar[j]){
						cout<<"SU SALDO ES INSUFICIENTE"<<endl;
					}
				}
			}
	return;	
}//Cierre Void

void cancelacion(datos dato[], int tam){
	int clave=0;
	string acc="";
	int numerico=0, aux=0, valor_final=0, activador=0;
	string validacion_cedula;
///
		string saludo="BIENVENIDO AL APARTADO DE CREACION DE CUENTA";
	
	int a=0,b=0,c=0;
	cout<<"|";	
	for (int a=0; a<saludo.size(); a++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
 	cout<<endl;
 	cout<<"|";
	for (int b=0; b<saludo.size(); b++){
		cout<<saludo[b]; Sleep (30);
	}
	cout<<"|";
	cout<<endl;
	cout<<"|";
	for (int c=0; c<saludo.size(); c++){
		cout<<"*"; Sleep (10);
 	}
 	cout<<"|";
	cout<<endl;
	system ("pause");	
	
	do {
		do {
			numerico=0;
			system ("cls");
			cout<<"INGRESE SU NUMERO DE CUENTA---> ";
			getline (cin, validacion_cedula);
		}while (validar_numero (validacion_cedula));
		
			istringstream(validacion_cedula)>>numerico;
			
			for (int i=0; i<tam; i++){		
				if (dato[i].cedula==numerico){
					aux=i;
					system ("cls");
					cout<<"NUMERO DE CUENTA ENCONTRADA!\n";
					system ("pause");
					activador=1;
				}
			}
	}while (activador=0);
	
	system ("cls");
 	esconder_clave_consignacion(dato, tam, aux);
	
		if(dato[aux].saldo<0){
			system("cls");
			cout<<"POSEE UNA DEUDA DE "<<dato[aux].saldo<<", CONSIGNE PARA QUEDAR A PAZ Y SALVO";
			system ("pause");
			return;
		}
		else if(dato[aux].saldo>=0){
			system("cls");
			dato[aux].saldo=0;
			cout<<"SE SACO EL DINERO DE LA CUENTA"<<endl;
			system ("pause");
			system("cls");
			cout<<"ESTAMOS BORRANDO SU CUENTA...\n";
			system ("pause");
		
			dato[aux].cedula=0;
			dato[aux].email="";
			dato[aux].telefono=0;
			dato[aux].contra=0;
			dato[aux].saldo=0;
		system ("cls");
		cout<<"SU CUENTA HA SIDO ELIMINADA";					
	return;			
	}		

	return;
}//for
	
//============================================================================================================================================

//=======================================================FUNCION PRINCIPAL====================================================================
int main(){
	int tam=10;
	datos dato[tam];
	int opcion=0;
	string validacion_numero;
	
	for(int i=0; i<tam; i++){
        dato[i].cedula=0;
        dato[i].email="";
        dato[i].telefono=0;
        dato[i].contra=0;
        dato[i].saldo=0;
        for (int j=0; j<10; j++){
        dato[i].inscripciones[j]=0;
		}
    }
	
	do{
		do {
			opcion=0;
			system("cls");
			system ("color F0");
			cout<< "------CAJERO AUTOMATICO------"<<endl;
			cout<<"1. CREACION DE UNA CUENTA"<<endl;
			cout<<"2. CONSIGNACIONES"<<endl;
			cout<<"3. CONSULTAS DE SALDO"<<endl;
			cout<<"4. RETIROS"<<endl;
			cout<<"5. INSCRIBIR PAGOS"<<endl;
			cout<<"6. PAGOS"<<endl;
			cout<<"7. CANCELACION DE UNA CUENTA"<<endl;
			cout<<"8. SALIDA"<<endl;
		
			cout<<"----------------------------------\n";
			fflush (stdin);
			cout<<"DIGITE UNA OPCION----------> ";
			getline (cin, validacion_numero);

		}while(validar_numero(validacion_numero));
		
		istringstream (validacion_numero)>>opcion;

		switch(opcion){
			case 1:{
				crear_cuenta(dato, tam);
				system ("pause");
			break;
			}//case 1

			case 2:{	
    			consignacion(dato, tam);
				system ("pause");
			break;
			}//case 2

			case 3:{
				consultar_saldo(dato, tam);
				system ("pause");
			break;
			}//case 3

			case 4:{
				retiro(dato, tam);
				system ("pause");	
			break;
			}//case 4
	
			case 5:{
    			inscribir(dato,tam);
				system ("pause");	
			break;
			}//case 5

			case 6:{
    			pagos(dato,tam);
				system ("pause");	
			break;
			}//case 6

			case 7:{
    			cancelacion(dato, tam);
				system ("pause");	
			break;
			}//case 7

			case 8:{
				system ("cls");
    			cout<<"BYE :D\n";
			break;
			}//case 8
	
			default:{
				system ("cls");
				cout<<"ERROR: DIGITE UNA DE LAS 8 OPCIONES\n";
				system ("pause");
				break;
			}
		}//SWITCH

	}while(opcion!=8);
	
return 0;
}//MAIN Grupo Natalia,Nicolas Y Samuel


#include<iostream>
#include<mysql.h>
#include<mysql_error.h>
#include<locale.h>

//-----------------------------------------------------------------------------------------------------------------------------------

using namespace std;
	class conne{
		
		public:
		MYSQL *obj;
		
		char* conectar(char *server, char *user, char *pw, char *database){
			
				if(!(obj=mysql_init(0)))
					{
						return "Error Create Objeto";
					}
					if(!mysql_real_connect(obj,server,user,pw,database,3306,NULL,0))
					{
						return (char*)mysql_error(obj);
					}else
					{
						return "++++++++ Base de Datos en Uso ++++++++";
					}
		}
		
		void desconectar(){
			mysql_close(obj);
		}
	};
	
	conne conexion;
	
	struct stagenda,stbaneada{
	char id[11];
	char nombre[20];
	char apellido[20];
	char telefono[12];
	char email[25];
	}agend,ban;
	
	class clagenda{
		public:
			char *resultado;
			void insertar(struct stagenda x){
				try{
				conexion.conectar("localhost","root","","crud_c++");
				char *consulta;
				char sentencia[]="INSERT INTO AGENDA (ID,NOMBRE,APELLIDO,TELEFONO,EMAIL) VALUES (\'%s\',\'%s\',\'%s\')";
				consulta=new char[strlen(sentencia)+sizeof(stagenda)]-sizeof(int);
				sprintf(consulta,sentencia,agend.id,agend.nombre,agend.apellido,agend.telefono,agend.telefono,agend.email))));
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro Ingresado Correctamente\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void modificar(struct stagenda x){
				try{
				conexion.conectar("localhost","root","","crud_c++");
				char *consulta;
				char sentencia[]="UPDATE AGENDA SET NOMBRE=\'%s\',APELLIDO=\'%s\',TELEFONO=\'%s\',EMAIL=\'%s\' wHERE ID=\'%s\'";
				consulta=new char[strlen(sentencia)+sizeof(stagenda)]-sizeof(int);
				sprintf(consulta,sentencia, agend.nombre, agend.apellido, agend.telefono, agend.email, agend.id);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro Modificado\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void eliminar(struct stagenda x){
				try{
				conexion.conectar("localhost","root","","crud_c++");
				char *consulta;
				char sentencia[]="DELETE from AGENDA WHERE ID=\'%s\'";
				consulta=new char[strlen(sentencia)+sizeof(stagenda)]-sizeof(int);
				sprintf(consulta,sentencia,agend.id);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro ELiminado Correctamente\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void eliminarBanear(struct stbaneada x){
				try{
				conexion.conectar("localhost","root","","crud_c++");
				char *consulta;
				char sentencia[]="DELETE from BANEADA WHERE ID=\'%s\'";
				consulta=new char[strlen(sentencia)+sizeof(stbaneada)]-sizeof(int); // crear stbaneo
				sprintf(consulta,sentencia,ban.id);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro ELiminado Correctamente\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}

			void banear(struct stbaneada x){
				try{
				conexion.conectar("localhost","root","","crud_c++");
				char *consulta;
				char sentencia[]="INSERT INTO BANEDA (ID,NOMBRE,APELLIDO,TELEFONO,EMAIL) VALUES (\'%s\',\'%s\',\'%s\')";
				consulta=new char[strlen(sentencia)+sizeof(stbaneada)]-sizeof(int);
				sprintf(consulta,sentencia,baneada.id);
				int aux=mysql_query(conexion.obj,consulta);
				if(!aux==0){
					throw mysql_error(conexion.obj);
				}
				resultado="Registro Baneado Correctamente\n";
				}catch(const char* msg){
					cout<<msg;
					conexion.desconectar();
				}
			}
			
			void mostrar(){
				   MYSQL           *objDatos;
				   MYSQL_RES       *res;
				   MYSQL_ROW        row;
				   MYSQL_FIELD     *columna;
				   int              i, j, k, l;
				   unsigned long   *lon;
				   MYSQL_ROW_OFFSET pos;
				   if(!(objDatos = mysql_init(0))) {
				      cout<<"Error Objeto"<<endl;
				      rewind(stdin);
				      getchar();	      
					}
				   if(!mysql_real_connect(objDatos,"localhost", "root", "", "crud_c++", 3306, NULL, 0)) {
				      cout<<"Error BD"<<MYSQL_PORT<<" Error: "<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				   if(mysql_select_db(objDatos, "crud_c++")) {
				      cout<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				   if(mysql_query(objDatos, "SELECT * FROM AGENDA")) {
				      cout<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				if((res=mysql_store_result(objDatos))){
					i=(int)mysql_num_rows(res);
					j=(int)mysql_num_fields(res);
					cout<<endl<<"		Datos de Todos Las Agendas"<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(res);
						lon=mysql_fetch_lengths(res);
						cout<<endl;
						for(k=0;k<j;k++){
						cout<<"	"<<((row[k]==NULL)?"NULL":row[k])<<"	";
					}
				}cout<<endl;
			    mysql_free_result(res);
			   }
			   mysql_close(objDatos);
			   rewind(stdin);
			   cout<<endl;
			} 
			
			void mostrarBaneo(){
				   MYSQL           *objDatos;
				   MYSQL_RES       *res;
				   MYSQL_ROW        row;
				   MYSQL_FIELD     *columna;
				   int              i, j, k, l;
				   unsigned long   *lon;
				   MYSQL_ROW_OFFSET pos;
				   if(!(objDatos = mysql_init(0))) {
				      cout<<"Error Objeto"<<endl;
				      rewind(stdin);
				      getchar();	      
					}
				   if(!mysql_real_connect(objDatos,"localhost", "root", "", "crud_c++", 3306, NULL, 0)) {
				      cout<<"Error BD"<<MYSQL_PORT<<" Error: "<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				   if(mysql_select_db(objDatos, "crud_c++")) {
				      cout<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				   if(mysql_query(objDatos, "SELECT * FROM BANEADA")) {
				      cout<<mysql_error(objDatos)<<endl;
				      mysql_close(objDatos);
				      rewind(stdin);
				      getchar();
				   }
				if((res=mysql_store_result(objDatos))){
					i=(int)mysql_num_rows(res);
					j=(int)mysql_num_fields(res);
					cout<<endl<<"		Datos de Todos Las Agendas Baneadas"<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(res);
						lon=mysql_fetch_lengths(res);
						cout<<endl;
						for(k=0;k<j;k++){
						cout<<"	"<<((row[k]==NULL)?"NULL":row[k])<<"	";
					}
				}cout<<endl;
			    mysql_free_result(res);
			   }
			   mysql_close(objDatos);
			   rewind(stdin);
			   cout<<endl;
			} 		
	}; 
	
	void salir(){
		cout<<"Programa Finalizado\n";
	}
	
	void menu(){
		int opcion;
		clagenda op;
		cout<<"Agenda consola en c++ \n";
		do{
		cout<<"*************************************************************\n";
		cout<<"                  +------------------------+"<<endl;
		cout<<"                  |          Menu          |"<<endl;
		cout<<"                  +------------------------+"<<endl;
		cout<<"                  | Seleccione una Opci?n  |"<<endl;
		cout<<"                  | 1.- Crear Registros    |"<<endl;
		cout<<"                  | 2.- Eliminar Registros |"<<endl;
		cout<<"                  | 3.- Modificar Registros|"<<endl;
		cout<<"                  | 4.- Banear Registro    |"<<endl;		
		cout<<"                  | 5.- Ver Registos       |"<<endl;
		cout<<"                  | 6.- Salir              |"<<endl;
		cout<<"                  +------------------------+"<<endl;
		cout<<"*************************************************************"<<endl;
		
		clagenda x;
		cin>>opcion; 

		switch(opcion){
				case 1:		
					cout<<"Ingrese Datos de Contacto \n";
					cout<<"Ingrese ID : ";
					cin>>agend.id;
					cout<<"Ingrese Nombre: ";
					cin>>agend.nombre;
					cout<<"Ingrese Apellido apellido: ";
					cin>>agend.apellido;
					cout<<"Ingrese Telefono telefono: ";
					cin>>agend.telefono;
					cout<<"Ingrese Email email: ";
					cin>>agend.email;
					op.insertar(agend);
					cout<<op.resultado;
				break;
				
				case 2:	
					switch(opcion){
						cout<<"Agenda consola en c++ \n";
						do{
							cout<<"*************************************************************\n";
							cout<<"                  +------------------------+"<<endl;
							cout<<"                  |   ELIMINAR REGISTROS   |"<<endl;
							cout<<"                  +------------------------+"<<endl;
							cout<<"                  | Seleccione una Opci?n  |"<<endl;
							cout<<"                  | 1.- Agenda             |"<<endl;
							cout<<"                  | 2.- Agenda Baneada     |"<<endl;
							cout<<"                  +------------------------+"<<endl;
							cout<<"*************************************************************"<<endl;
						case 1: 
							clagenda op;
							cout<<"Ingrese C?digo de Agenda para Eliminar: ";
							cin>>agend.id;
							op.eliminar(agend);
							cout<<op.resultado;
						break;
						case 2: 
							clagenda op;
							cout<<"Ingrese C?digo de Agenda para Eliminar: ";
							cin>>baneada.id;
							op.eliminarBanear(ban);
							cout<<op.resultado;
						break;	
					}		
				break;
			
				case 3: // modificAR
				
					switch(opcion){
						cout<<"Agenda consola en c++ \n";
						do{
							cout<<"*************************************************************\n";
							cout<<"                  +------------------------+"<<endl;
							cout<<"                  |  MODIFICAR  REGISTROS  |"<<endl;
							cout<<"                  +------------------------+"<<endl;
							cout<<"                  | Seleccione una Opci?n  |"<<endl;
							cout<<"                  | 1.- Agenda             |"<<endl;
							cout<<"                  | 2.- Agenda Baneada     |"<<endl;
							cout<<"                  +------------------------+"<<endl;
							cout<<"*************************************************************"<<endl;
						case 1:
							cout<<"Modificar Datos de la Agenda\n";
							cout<<"Ingrese ID : ";
							cin>>agend.id;
							cout<<"\nModificar? Registros de la agenda con ID "<<agend.id<<endl;
							cout<<"\nIngrese Nuevo Nombre: ";
							cin>>agend.nombre;
							cout<<"Ingrese Nuevo Apellido apellido: ";
							cin>>agend.apellido;
							cout<<"Ingrese Nuevo Telefono telefono: ";
							cin>>agend.telefono;
							cout<<"Ingrese Nuevo Email email: ";
							cin>>agend.email;
							op.modificar(agend);
							cout<<op.resultado;
						break;
						
						case 2:
							cout<<"Modificar Datos de la Agendas Baneadas\n";
							cout<<"Ingrese ID : ";
							cin>>ban.id;
							cout<<"\nModificar? Registros de la agenda con ID "<<ban.id<<endl;
							cout<<"\nIngrese Nuevo Nombre: ";
							cin>>ban.nombre;
							cout<<"Ingrese Nuevo Apellido apellido: ";
							cin>>ban.apellido;
							cout<<"Ingrese Nuevo Telefono telefono: ";
							cin>>ban.telefono;
							cout<<"Ingrese Nuevo Email email: ";
							cin>>ban.email;
							op.modificar(ban);
							cout<<op.resultado;
						break;
					}
				break;
	
				case 4:
					clagenda op;
					cout<<"Ingrese C?digo de Agenda para Banear: ";
					cin>>agend.id;
					op.banear(ban);
					cout<<op.resultado;
				break;
				
				case 5: 
				cout<<"Agenda consola en c++ \n";
						do{
							cout<<"*************************************************************\n";
							cout<<"                  +------------------------+"<<endl;
							cout<<"                  |      VER REGISTROS     |"<<endl;
							cout<<"                  +------------------------+"<<endl;
							cout<<"                  | Seleccione una Opci?n  |"<<endl;
							cout<<"                  | 1.- Agendas            |"<<endl;
							cout<<"                  | 2.- Agendas Baneadas   |"<<endl;
							cout<<"                  +------------------------+"<<endl;
							cout<<"*************************************************************"<<endl;
					switch(opcion){
						case 1:
							op.mostrar();
						break;
						case 2:
							op.mostrarBaneo();
						break;
					}
				break;
				
				case 6: salir();
				break;
				default:
				cout<<"Opci?n Incorrecta\n";	
		}
	}while(opcion!=6);
	}
	
int main() {
	setlocale(LC_CTYPE,"Spanish");
	menu();
	return 0;
}

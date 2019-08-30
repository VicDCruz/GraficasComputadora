// Tarea1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Employee {
	char ine[8];
	char name[80];
	int children;
	float salary;
	struct Employee* pointer;
};

int countLetters(char letters[]) {
	int output = 0;
	for (int i = 0; i < strlen(letters); i++)
	{
		int ascii = (int) letters[i];
		if ((65 <= ascii && ascii <= 90) || (97 <= ascii && ascii <= 122))
			output++;
	}
	return output;
}

struct Employee* addEmployee(Employee e, struct Employee* main, struct Employee* left, struct Employee* right) {
	struct Employee* pointer;
	if (right == NULL) {
		pointer = (struct Employee*) malloc(sizeof(struct Employee));
		memcpy(pointer->name, e.name, strlen(e.name));
		pointer->name[countLetters(e.name) + 1] = '\0';
		strcpy_s(pointer->ine, e.ine);
		pointer->children = e.children;
		pointer->salary = e.salary;
		pointer->pointer = e.pointer;
		if (left == NULL) {
			return pointer;
		}
		left->pointer = pointer;
		return main;
	}
	else {
		bool resultRight = strcmp(right->ine, e.ine) <= 0;
		if (resultRight)
			pointer = addEmployee(e, main, right, right->pointer);
		else {
			pointer = (struct Employee*) malloc(sizeof(struct Employee));
			memcpy(pointer->name, e.name, strlen(e.name));
			pointer->name[countLetters(e.name) + 1] = '\0';
			strcpy_s(pointer->ine, e.ine);
			pointer->children = e.children;
			pointer->salary = e.salary;
			pointer->pointer = right;
			if (left != NULL) {
				left->pointer = pointer;
				pointer = main;
			}
		}
		return pointer;
	}
}

int countEmployees(struct Employee* actual) {
	if (actual == NULL)
		return 0;
	return 1 + countEmployees(actual->pointer);
}

void showEmployees(struct Employee* actual) {
	if (actual != NULL) {
		cout << "INE: "<< actual->ine << endl;
		cout << "NOMBRE: " << actual->name << endl;
		cout << "TOTAL DE HIJOS: " << actual->children << endl;
		cout << "SALARIO: " << actual->salary << endl;
		showEmployees(actual->pointer);
	}
}

struct Employee* createList(struct Employee* latest) {
	string line;
	ifstream file("knowledgeBase.txt");
	string delimiter = ",";
	if (file.is_open()) {
		while (getline(file, line)) {
			size_t pos = 0;
			string token;
			int count = 0;
			Employee emp;
			while ((pos = line.find(delimiter)) != string::npos) {
				token = line.substr(0, pos);
				switch (count)
				{
				case 0:
					copy(token.begin(), token.end(), emp.ine);
					break;
				case 1:
					copy(token.begin(), token.end(), emp.name);
					break;
				case 2:
					emp.children = atoi(token.c_str());
					break;
				default:
					break;
				}
				emp.ine[7] = '\0';
				line.erase(0, pos + delimiter.length());
				count++;
			}
			emp.salary = atof(line.c_str());
			emp.pointer = NULL;
			if ((latest = addEmployee(emp, latest, NULL, latest)) != NULL)
				cout << "Empleado ficticio agregado: " << countEmployees(latest) << endl;
			else
				cout << "Error al agregar Empleado ficticio: " << countEmployees(latest) << endl;
		}
		file.close();
	}
	else
		cout << "Error al leer el archivo";
	return latest;
}

struct Employee* getEmployee(struct Employee* latest) {
	Employee emp;
	char name[40];
	char surname[40];
	cout << "INGRESAR # INE (7 Digitos): ";
	cin >> emp.ine;
	cout << "INGRESAR Nombre: ";
	cin >> name;
	cout << "INGRESAR Apellido: ";
	cin >> surname;
	cout << "INGRESAR # Hijos: ";
	cin >> emp.children;
	cout << "INGRESAR Salario: ";
	string salaryString;
	cin >> salaryString;
	emp.salary = atof(salaryString.c_str());
	emp.pointer = NULL;
	int sizeName = strlen(name);
	for (int i = 0; i < sizeName; i++) {
		emp.name[i] = name[i];
	}
	emp.name[sizeName + 1] = '_';
	for (int i = 0; i < strlen(surname); i++) {
		emp.name[sizeName + 1 + i] = surname[i];
	}
	return addEmployee(emp, latest, NULL, latest);
}

struct Employee* deleteEmployee(struct Employee* actual, struct Employee* main) {
	Employee emp;
	cout << "ELIMINAR # INE (7 Digitos): ";
	cin >> emp.ine;
	struct Employee* right = NULL;
	struct Employee* left = actual;
	while (left != NULL) {
		if (strcmp(left->ine, emp.ine) == 0) {
			if (left == main) {
				Employee* newHead = left->pointer;
				free(main);
				return newHead;
			}
			else {
				right->pointer = left->pointer;
				free(left);
				return main;
			}
		}
		right = left;
		left = left->pointer;
	}
	return main;
}

int main() {
	struct Employee* head = NULL;
	int option = -1;
	while (option != 0)
	{
		cout << "==============================" << endl;
		cout << "Selecciona una opcion" << endl;
		cout << "Cargar lista: 1" << endl;
		cout << "Crear empleado: 2" << endl;
		cout << "Imprimir todos los datos: 3" << endl;
		cout << "Total de empleados: 4" << endl;
		cout << "Eliminar empleado: 5" << endl;
		cout << "Salir: 0" << endl;
		cout << "==============================" << endl;
		cin >> option;
		if (option == 1)
			head = createList(head);
		else if (option == 2)
			head = getEmployee(head);
		else if (option == 3)
			showEmployees(head);
		else if (option == 4)
			cout << "Total de Empleados: " << countEmployees(head) << endl;
		else if(option == 5)
			head = deleteEmployee(head, head);
	}
	return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

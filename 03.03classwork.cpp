#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct child {
	char name[256];
	bool gen;
	int age;
	int height;
};

void printMenu() {
	cout << "1. Enter a new child.\n";
	cout << "2. Delete a child by index.\n";
	cout << "3. Edit data for a child.\n";
	cout << "4. Print average height.\n";
	cout << "5. Print average age.\n";
	cout << "6. Print all children.\n";
	cout << "7. Print child by index.\n";
	cout << "8. Exit.\n";
}
void printChild(child c) {
	cout << "Name: " << c.name << endl << "Gender: "
			<< (c.gen ? "male" : "female") << endl << "Height is " << c.height
			<< endl << "Age is " << c.age << endl;
}
void printAllChildren(child *c, int size) {
	for (int i = 0; i < size; i++) {
		cout << (i + 1) << ". ";
		printChild(c[i]);
		cout << endl;
	}
}
child createChild() {
	child c;
	cout << "Enter name:";
	cin.getline(c.name, 256);
	cout << "Enter gender (0 for female, 1 for male):";
	cin >> c.gen;
	cout << "Enter height:";
	cin >> c.height;
	cout << "Enter age:";
	cin >> c.age;
	return c;
}

child* addChild(child *c, int size) {
	child *n_c = new child[size + 1];
	for (int i = 0; i < size; i++)
		n_c[i] = c[i];
	n_c[size] = createChild();
	delete[] c;
	return n_c;
}

child* deleteChild(child *c, int size, int index) {
	child *n_c = new child[size - 1];
	child *ptr = c;
	for (int i = 0; i < index; i++, ptr++)
		n_c[i] = *ptr;
	ptr++;
	for (int i = index; i < size - 1; i++, ptr++)
		n_c[i] = *ptr;
	delete[] c;
	return n_c;
}

void editChild(child &c) {
	int choice { };
	printChild(c);
	cout << "Which parameter of " << c.name << " you want to change?" << endl;
	cout << "1. Name" << endl;
	cout << "2. Gender" << endl;
	cout << "3. Age" << endl;
	cout << "4. Height" << endl;
	cin >> choice;
	cin.clear();
	cin.ignore(32767, '\n');
	switch (choice) {
	case 1:
		cout << "Enter new name: ";
		cin.getline(c.name, 256);
		break;
	case 2:
		cout << "Enter new gender (0 for female, 1 for male): ";
		cin >> c.gen;
		break;
	case 3:
		cout << "Enter new age: ";
		cin >> c.age;
		break;
	case 4:
		cout << "Enter new height: ";
		cin >> c.height;
		break;
	default:
		cout << "Wrong command!";
	}
}

double averageHeight(child *c, int size) {
	double a { };
	for (int i = 0; i < size; i++) {
		a += c[i].height;
	}
	return (double) a / size;
}

double averageAge(child *c, int size) {
	double a { };
	for (int i = 0; i < size; i++) {
		a += c[i].age;
	}
	return (double) a / size;
}

struct mylist {
	int n;
	mylist *next;
};

mylist* getLastElement(mylist *l) {
	while (l->next)
		l = l->next;
	return l;
}

mylist* findElement(mylist *l, int k) {
	while (l->n != k && l->next)
		l = l->next;
	return l;
}

void insertAfter(mylist *l, int k, int el) {
	mylist *key = findElement(l, k);
	mylist *after=key->next;
	key->next=new mylist { el, after };
}

void createList(mylist *iter, int count) {
	for (int i = 0; i < count; i++) {
		iter->next = new mylist { i + 1, nullptr };
		iter = iter->next;
	}
}

void appendElement(mylist *l, int el) {
	mylist *last = getLastElement(l);
	last->next = new mylist { el, nullptr };
}

void printList(mylist *l) {
	while (l) {
		cout << l->n << " ";
		l = l->next;
	}
	cout << endl;
}

int main() {
	mylist *head1 = new mylist { 0, nullptr };
	createList(head1, 9);
	printList(head1);
	appendElement(head1, 1);
	printList(head1);
	appendElement(head1, 11);
	printList(head1);
	appendElement(head1, 113);
	printList(head1);
	insertAfter(head1, 5, 111);
	printList(head1);
	/*int choice;
	 child *children = nullptr;
	 int c_size = 0;

	 while (true) {
	 cout << "Currently there are " << c_size << " children in the database"
	 << endl;
	 printMenu();
	 cout << "Enter your choice:";
	 cin >> choice;
	 cin.clear();
	 cin.ignore(32767, '\n');
	 switch (choice) {
	 case 1:
	 children = addChild(children, c_size);
	 c_size++;
	 break;
	 case 2:
	 cout << "Enter the number of child you want to delete: ";
	 cin >> choice;
	 cin.clear();
	 cin.ignore(32767, '\n');
	 if (choice < 1 || choice > c_size) {
	 cout << "wrong number!" << endl;
	 break;
	 }
	 children = deleteChild(children, c_size, choice - 1);
	 c_size--;
	 break;
	 case 3:
	 cout << "Enter the number of child you want to edit: ";
	 cin >> choice;
	 cin.clear();
	 if (choice < 1 || choice > c_size) {
	 cout << "wrong number!" << endl;
	 break;
	 }
	 editChild(children[choice - 1]);
	 break;
	 case 4:
	 cout << "Average height is " << averageHeight(children, c_size)
	 << endl;
	 break;
	 case 5:
	 cout << "Average age is " << averageAge(children, c_size) << endl;
	 break;
	 case 6:
	 printAllChildren(children, c_size);
	 break;
	 case 7:
	 cout << "Enter index: ";
	 int ind;
	 cin >> ind;
	 if (ind > 0 && ind < c_size + 1)
	 printChild(children[ind - 1]);
	 else
	 cout << "Wrong number\n";
	 break;
	 }
	 if (choice == 8)
	 break;
	 }*/
	return 0;
}


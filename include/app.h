//
// Created by elvis on 4/4/19.
//

#ifndef STUDENTMANAGER_APP_H
#define STUDENTMANAGER_APP_H




#include <gtk/gtk.h>
#include <mysql.h>
#include <stdlib.h>
#include <glib.h>
#include <gmodule.h>
#include "filepath.h"


//datastructures and variables
typedef struct {
    GtkWidget *username;
    GtkWidget *password;
}LOGIN_FORM;

//.................................................................

//General Functions
void fileRenamer();
void Connector();
void addRecord();
void searchRecord();
void filterRecord();
void viewRecord();
void deleteRecord();
void editRecord();
void parseJson();





#endif //STUDENTMANAGER_APP_H

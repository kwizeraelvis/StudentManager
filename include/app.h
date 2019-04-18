//
// Created by elvis on 4/4/19.
//

#ifndef STUDENTMANAGER_APP_H
#define STUDENTMANAGER_APP_H




#include <gtk/gtk.h>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include <json-c/json.h>
#include "filepath.h"
#include "callback.h"

//datastructures and variables
typedef struct {
    GtkWidget *username;
    GtkWidget *password;
}LOGIN_FORM;

typedef struct{
    gchar *user_cred;
    gchar *passwd_cred;
}USER_INFO;


FILE *fp;


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
void mainwindow();
USER_INFO parseJson();





#endif //STUDENTMANAGER_APP_H

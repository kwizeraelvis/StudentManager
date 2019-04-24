//
// Created by elvis on 4/4/19.
//

#include "../include/app.h"




USER_INFO parseJson() {
    USER_INFO user;
    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *username;
    struct json_object *password;

    fp = fopen(USER_LOGON_INFO_PATH, "r");
    fread(buffer, 1024, 1, fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "user", &username);
    json_object_object_get_ex(parsed_json, "password", &password);
    user.user_cred = json_object_get_string(username);
    user.passwd_cred = json_object_get_string(password);
    return user;

}



void getRecord() {

}

void listRecord() {

}

void addRecord() {

}

void editRecord() {

}

void deleteRecord() {

}

void sortRecord() {

}

void filterRecord() {

}

void fileRenamer() {

}

void Connector() {

}
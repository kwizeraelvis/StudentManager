#include "include/app.h"

GtkWidget *window;


int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    LOGIN_FORM *logon = g_slice_new(LOGIN_FORM);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, LOGIN_UI_FILE_PATH, NULL);


    window = GTK_WIDGET(gtk_builder_get_object(builder, "login_main"));
    logon->username = GTK_WIDGET(gtk_builder_get_object(builder, "txt_username"));
    logon->password = GTK_WIDGET(gtk_builder_get_object(builder, "txt_password"));

    gtk_builder_connect_signals(builder, logon);
    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    g_slice_free(LOGIN_FORM, logon);

    return 0;
}

G_MODULE_EXPORT void on_login_btn_clicked(GtkButton *button, LOGIN_FORM *login)
{
    USER_INFO userinfo;
    userinfo = parseJson();


    const gchar *user_cred = userinfo.user_cred;
    const gchar *pass_cred = userinfo.passwd_cred;

    printf("Username is %s and Password is %s from json\n", user_cred, pass_cred);

    const gchar *username = gtk_entry_get_text(GTK_ENTRY(login->username));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(login->password));

    printf("Username is %s and Password is %s from gtk\n",username, password);

    if((g_strcmp0(user_cred, username) == 0) && (g_strcmp0(pass_cred, password) == 0)) {


            GtkWidget *dashboard;
            GtkWidget *add;
            GtkWidget *edit;
            GtkWidget *list;
            GtkWidget *search;
            GtkWidget *delete;
            GtkBuilder *builder;

            builder = gtk_builder_new();
            gtk_builder_add_from_file(builder, USER_DASH_FILE_PATH, NULL);

            dashboard = GTK_WIDGET(gtk_builder_get_object(builder, "dashboard"));
            g_signal_connect(dashboard, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

            add = GTK_WIDGET(gtk_builder_get_object(builder, "add"));
            g_signal_connect(add, "clicked", G_CALLBACK(on_add_clicked), NULL);

            edit = GTK_WIDGET(gtk_builder_get_object(builder, "edit"));
            g_signal_connect(edit, "clicked", G_CALLBACK(on_edit_clicked),NULL);

            list = GTK_WIDGET(gtk_builder_get_object(builder, "list"));
            g_signal_connect(list, "clicked", G_CALLBACK(on_list_clicked), NULL);

            search = GTK_WIDGET(gtk_builder_get_object(builder, "search"));
            g_signal_connect(search, "clicked", G_CALLBACK(on_search_clicked), NULL);

            delete = GTK_WIDGET(gtk_builder_get_object(builder, "delete"));
            g_signal_connect(delete, "clicked", G_CALLBACK(on_delete_clicked), NULL);

            gtk_widget_destroy(window);
            gtk_widget_show(dashboard);


    } else {

    GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
    GtkWidget *fail_dialog;
    fail_dialog = gtk_message_dialog_new(window,flags,GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,"Login Error");
    gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(fail_dialog), "Failed to login please check username or password");
    gtk_dialog_run(fail_dialog);
    gtk_widget_destroy(fail_dialog);

    }
}







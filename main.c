#include "include/app.h"


int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkBuilder *builder;
    LOGIN_FORM *logon = g_slice_new(LOGIN_FORM);

    gtk_init(&argc, &argv);

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

static void on_login_btn_clicked(GtkButton *button, LOGIN_FORM *login)
{
    const gchar *username = gtk_entry_get_text(GTK_ENTRY(login->username));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(login->password));


}
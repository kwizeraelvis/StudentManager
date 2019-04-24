#include "../include/dashboard.h"
#include "../include/app.h"


void on_add_clicked() {
    GtkWidget *add_window;
    GtkBuilder *builder;
    STUDENT_DATA *student = g_slice_new(STUDENT_DATA);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, USER_ADD_FILE_PATH, NULL);

    add_window = GTK_WIDGET(gtk_builder_get_object(builder, "add_new"));
    g_signal_connect(add_window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    student->firstname = GTK_WIDGET(gtk_builder_get_object(builder, "firstname"));
    student->lastname  = GTK_WIDGET(gtk_builder_get_object(builder, "lastname"));
    student->id = GTK_WIDGET(gtk_builder_get_object(builder, "id"));
    student->age =  GTK_WIDGET(gtk_builder_get_object(builder, "age"));
    student->male = GTK_WIDGET(gtk_builder_get_object(builder, "male"));
    student->female = GTK_WIDGET(gtk_builder_get_object(builder, "female"));

    gtk_builder_connect_signals(builder, student);

    g_object_unref(builder);

    gtk_widget_show(add_window);

}

void on_edit_clicked() {
    printf("edit callback is in working Condition");
}

void on_search_clicked() {
    printf("search callback is in working Condition");
}

void on_list_clicked() {
    printf("list callback is in working Condition");
}

void on_delete_clicked() {
    printf("delete callback is in working Condition");
}




G_MODULE_EXPORT void on_submit_clicked(GtkButton *button,STUDENT_DATA *std) {
           STUDENT_INFO *studentInfo;
           GENDER gender;
           guint32 age = 0;

           studentInfo->firstname = gtk_entry_get_text(GTK_ENTRY(std->firstname));
           studentInfo->lastname = gtk_entry_get_text(GTK_ENTRY(std->lastname));
           studentInfo->id = gtk_entry_get_text(GTK_ENTRY(std->id));
           if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(std->male))) {
               gender = MALE;
               studentInfo->gender = gender;
               printf("\nGender: %s\n" studentInfo->gender);
           } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(std->female))) {
               gender = FEMALE;
               studentInfo->gender = gender;
               printf("Gender: %s" studentInfo->gender);
           }

}

G_MODULE_EXPORT void on_cancel_clicked() {
    printf("\nCancel Button callback is working");
}
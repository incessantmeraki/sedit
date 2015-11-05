#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *vbox;

  //Definitions

  //Contains Menubar, Menu and menuitems inside it in an iterative way
  GtkWidget *menubar; 
  GtkWidget *fileMenu;
  GtkWidget *editMenu;
  GtkWidget *optionsMenu;
  GtkWidget *helpMenu;
  GtkWidget *fileMi;
  GtkWidget *newMi;
  GtkWidget *openMi;
  GtkWidget *saveMi;
  GtkWidget *quitMi;
  GtkWidget *editMi;
  GtkWidget *cutMi;
  GtkWidget *copyMi;
  GtkWidget *pasteMi;
  GtkWidget *optionsMi;
  GtkWidget *searchMi;
  GtkWidget *fontMi;
  GtkWidget *helpMi;
  GtkWidget *aboutMi;

  //Contains statusBar definition
  GtkWidget *statusbar;

  //Miscellaneous declaration
  GtkAccelGroup *accel_group = NULL;


  //initialize our gtk engine
  gtk_init(&argc, &argv);

  //properties for the main window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  gtk_window_set_title(GTK_WINDOW(window), "Phase 1");

  //Layout to align menu items vertically
  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  //initilize accel group which enables shortcut(accelerator) keys
  accel_group = gtk_accel_group_new();
  gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

  //initialize menu bar
  menubar = gtk_menu_bar_new();

  // Setting File Menu //

  //initialize file menu and define file items in it
  fileMenu = gtk_menu_new();
  fileMi = gtk_menu_item_new_with_mnemonic("_File");
  newMi  = gtk_menu_item_new_with_label("New");
  openMi  = gtk_menu_item_new_with_label("Open");
  saveMi  = gtk_menu_item_new_with_label("Save");
  quitMi  = gtk_menu_item_new_with_label("Quit");

  //linking menu and its respective menu items
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), newMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), saveMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);

  //Defining shortcut keys for menu items
  gtk_widget_add_accelerator(newMi, "activate", accel_group, 
      GDK_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
    gtk_widget_add_accelerator(openMi, "activate", accel_group, 
      GDK_o, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
  gtk_widget_add_accelerator(saveMi, "activate", accel_group, 
      GDK_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
  gtk_widget_add_accelerator(quitMi, "activate", accel_group, 
      GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 

  //attaching FileMenu to menubar
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi); 

  
  //Setting Edit Menu //

  //initialize edit menu and define file items in it
  editMenu = gtk_menu_new();
  editMi = gtk_menu_item_new_with_mnemonic("_Edit");
  cutMi  = gtk_menu_item_new_with_label("Cut");
  copyMi  = gtk_menu_item_new_with_label("Copy");
  pasteMi  = gtk_menu_item_new_with_label("Paste");

  //linking edit menu and its respective menu items
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(editMi), editMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(editMenu), cutMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(editMenu), copyMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(editMenu), pasteMi);

  //Defining shortcut keys for edit menu items
  gtk_widget_add_accelerator(cutMi, "activate", accel_group, 
      GDK_x, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
    gtk_widget_add_accelerator(copyMi, "activate", accel_group, 
      GDK_c, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
  gtk_widget_add_accelerator(pasteMi, "activate", accel_group, 
      GDK_v, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 

  //attaching EditMenu to menubar
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), editMi); 


  //Setting Options Menu //
  
  //initialize options menu and define file items in it
  optionsMenu = gtk_menu_new();
  optionsMi = gtk_menu_item_new_with_mnemonic("_Options");
  searchMi  = gtk_menu_item_new_with_label("Search");
  fontMi  = gtk_menu_item_new_with_label("Font");

  //linking options menu and its respective menu items
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(optionsMi), optionsMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(optionsMenu), searchMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(optionsMenu), fontMi);

  //Defining shortcut keys for edit menu items
  gtk_widget_add_accelerator(searchMi, "activate", accel_group, 
      GDK_f, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 

  //attaching optionsMenu to menubar
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), optionsMi); 

  //Setting Help Menu //
  
  //initialize help menu and define file items in it
  helpMenu = gtk_menu_new();
  helpMi = gtk_menu_item_new_with_mnemonic("_Help");
  aboutMi  = gtk_menu_item_new_with_label("About");

  //linking help menu and its respective menu items
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(helpMi), helpMenu);
  gtk_menu_shell_append(GTK_MENU_SHELL(helpMenu), aboutMi);

  //attaching helpMenu to menubar
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), helpMi); 


  //connecting layout of verticalbox to menubar
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

  //Initializing statusbar and displaying it.
  statusbar = gtk_statusbar_new();
  gtk_box_pack_end(GTK_BOX(vbox), statusbar, FALSE, TRUE, 0);
  
  //connect functions to events that is signalled by gtk
  g_signal_connect(G_OBJECT(window), "destroy",
    G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(quitMi), "activate",
    G_CALLBACK(gtk_main_quit), NULL);

  // display all the windows and enter into event loop
  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
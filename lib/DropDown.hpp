#pragma once


#include <gtkmm/window.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>

class DropDown : public Gtk::Window
{
    public:
        DropDown();
        virtual ~DropDown();

    protected:  
        //Signal handlers:
        virtual void on_combo_changed();

    //Tree model columns:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
        public:

            ModelColumns()
            { add(m_col_id); add(m_col_name); }

            Gtk::TreeModelColumn<int> m_col_id;
            Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumns m_Columns;

    //Child widgets:
    Gtk::ComboBox m_Combo;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
};
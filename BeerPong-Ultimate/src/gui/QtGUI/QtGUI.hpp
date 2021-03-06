#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGUI.h"

#include <QColor>
#include <vector>

#include "../../glasses/GlassGroupIDManager.hpp"
#include "../../gui/CustomWidgets/QColorButton.hpp"


struct ColoredPlayer {
   Player player;
   QColor color;
};

struct ColoredPoints {
   Points points;
   QColor color;
};

class QtGUI : public QMainWindow
{
   Q_OBJECT

public:
   QtGUI(QWidget *parent = Q_NULLPTR);

   std::vector<ColoredPlayer> get_players();
   std::vector<ColoredPoints> get_points();

   std::string get_gamemode() { return _ui.gm_selection->currentText().toStdString(); }

private slots:
   void on_b_settings_clicked() { /* TODO; */ }

   void on_gm_selection_currentIndexChanged(int index);

   void on_name_text_edit_textChanged();

   void on_b_add_player_clicked();
   void on_b_add_points_clicked();
   void on_b_play_clicked() { /* TODO; */ }

   void on_b_custom_color_player_toggled(bool checked) { /* TODO; */ }

   void on_b_custom_color_points_toggled(bool checked) { /* TODO; */ }

   void remove_player_line(QWidget* to_be_removed);
   void remove_points_line(QWidget* to_be_removed);

   void _select_player_color(bool checked);
   void _select_points_color(bool checked);

private:
   class ColorButtonsManager {
   public:
      ColorButtonsManager() = default;

      void add_button(QtGUI* gui, QColor& color);

      const std::vector<const QColorButton*> get_color_buttons() const;

      QColor get_color(int ind) const { _player_color_buttons[ind]->get_color(); }
      const QIcon* get_icon(int ind) const { _player_color_buttons[ind]->icon(); }
      int get_ind(const QColorButton* button) const;

      void set_visible(int ind, bool is_visible);

      void set_checked(int ind, bool is_checked) {
         _player_color_buttons[ind]->setChecked(is_checked);
         _points_color_buttons[ind]->setChecked(is_checked);
      }

   private:
      void _assert_same_size() const { assert(_player_color_buttons.size() == _points_color_buttons.size()
                                       && "Both vectors must be of same size."); }

      std::vector<QColorButton*> _player_color_buttons;
      std::vector<QColorButton*> _points_color_buttons;
   };

   friend void ColorButtonsManager::add_button(QtGUI* gui, QColor& color);

   void _select_color(const QObject* sender, bool checked);

   void _enable_or_disable_b_add_player();
   void _enable_or_disable_b_add_points();
   
   Ui::QtGUIClass _ui;
   ColorButtonsManager _color_button_manager;

   static const std::vector<QColor> _default_colors;

   int _selected_color_button_ind;

   std::vector<QColor> _players_lines_color;
   std::vector<QColor> _points_lines_color;
};


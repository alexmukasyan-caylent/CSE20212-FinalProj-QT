
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QPlainTextEdit>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QMenuBar>
#include <QString>
#include <QMessageBox>
#include <QStatusBar>
#include <QFileDialog>
#include <QCloseEvent>
#include <QTextCursor>
#include <QLayout>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTreeWidget>
#include <QActionGroup>
#include <QLabel>
#include <QDir>
#include <QLineEdit>
#include <QPushButton>
#include <QListView>
#include "codeeditor.h"
#include "syntaxhighlighter.h"
#include "ui_codeeditor.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

//private:
    //SyntaxHighlighter *highlighter;
    //CodeEditor *editor;
    //Ui::codeeditor *ui;
//private slots:
//   void on_actionOpen_triggered();
//   void on_actionCopy_triggered();
//   void on_actionQuit_triggered();
//   void on_actionCut_triggered();
//   void on_actionPaste_triggered();
//   void on_actionUndo_triggered();
//   void on_actionRedo_triggered();
//   void on_actionSelectAll_triggered();
};


#endif // MAINWINDOW_H

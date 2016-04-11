
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

private:
    SyntaxHighlighter *highlighter;
    CodeEditor *editor;
    Ui::codeeditor *ui;
private slots:
   void openDialog();
};


#endif // MAINWINDOW_H

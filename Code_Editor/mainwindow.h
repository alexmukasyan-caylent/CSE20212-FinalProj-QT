
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
#include "finddialog.h"
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
    //FindDialog *find;
    bool fileIsOpened;
    QString filePath;
    QString editorName;
    QString windowTitle;
private slots:
   void newFile();
   void openDialog();
   void saveDialog();
   void saveAsDialog();
   void ifstate();
   void ifelsestate();
   void forstate();
   void whilestate();
   void dowhilestate();
   void checkParen();
   //void findReplace();
   //void searchDown(QString, Qt::CaseSensitivity); // searches for a word going down the page
   //void searchUp(QString, Qt::CaseSensitivity); // searches for a word goign up the page
   //void replaceWord(QString); // repl
};


#endif // MAINWINDOW_H

#include <QtWidgets>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QLabel>
#include "codeeditor.h"
#include "syntaxhighlighter.h"
#include "mainwindow.h"
#include "ui_codeeditor.h"

int main(int argv, char **args){ 
    QApplication app(argv, args);
    MainWindow m;
//    QMainWindow *window = new QMainWindow;
//    CodeEditor editor(window);
//    SyntaxHighlighter highlighter(editor.document());
//    Ui::codeeditor ui;
//    ui.setupUi(window);
//    window -> setCentralWidget(&editor);
//    ui.actionQuit -> connect(ui.actionQuit, SIGNAL(triggered()), window, SLOT(close()));
//    ui.actionCopy -> connect(ui.actionCopy, SIGNAL(triggered()), &editor, SLOT(copy()));
//    ui.actionCut -> connect(ui.actionCut, SIGNAL(triggered()), &editor, SLOT(cut()));
//    ui.actionPaste -> connect(ui.actionPaste, SIGNAL(triggered()), &editor, SLOT(paste()));
    //ui.actionQuit -> connect(ui.actionQuit, SIGNAL(triggered()), &editor, SLOT(selectAll()));
//    ui.actionUndo -> connect(ui.actionUndo, SIGNAL(triggered()), &editor, SLOT(undo()));
//    ui.actionRedo -> QObject::connect(ui.actionRedo, SIGNAL(triggered()), &editor, SLOT(redo()));
    //ui->actionOpen -> connect(ui->actionOpen, SIGNAL(triggered()), &editor, SLOT(open(CodeEditor &editor,Ui::codeeditor &ui )));

    //editor.setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
   // window -> setWindowTitle(QObject::tr("Galeanthropy"));
//    window -> show();

    return app.exec();
}

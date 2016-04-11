#include <QtWidgets/QWidget>
#include "mainwindow.h"
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QTextStream>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QMenuBar>
#include <QString>
#include <QMessageBox>
#include <QStatusBar>
#include <QFileDialog>
#include <QCloseEvent>
#include <QTextStream>
#include <QFile>
#include <QApplication>
#include <QTextCursor>
#include <QSettings>
#include <QTextCharFormat>
#include <QDockWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QTreeWidget>
#include <QSplitter>
#include <iostream>
#include <QAbstractItemView>
#include <QPalette>
#include <QColor>
#include <QtDebug>
#include <QDir>
#include <QIcon>
#include <QInputDialog>

using namespace std;

MainWindow::MainWindow(): QMainWindow(){
    ui = new Ui::codeeditor;
    ui -> setupUi(this);
    editor = new CodeEditor(this);
    highlighter = new SyntaxHighlighter(editor->document());

    ui->actionQuit  -> connect(ui->actionQuit,  SIGNAL(triggered()), this,   SLOT(close()));
    ui->actionCopy  -> connect(ui->actionCopy,  SIGNAL(triggered()), editor, SLOT(copy()));
    ui->actionCut   -> connect(ui->actionCut,   SIGNAL(triggered()), editor, SLOT(cut()));
    ui->actionPaste -> connect(ui->actionPaste, SIGNAL(triggered()), editor, SLOT(paste()));
    ui->actionQuit  -> connect(ui->actionQuit,  SIGNAL(triggered()), editor, SLOT(selectAll()));
    ui->actionUndo  -> connect(ui->actionUndo,  SIGNAL(triggered()), editor, SLOT(undo()));
    ui->actionRedo  -> connect(ui->actionRedo,  SIGNAL(triggered()), editor, SLOT(redo()));
    ui->actionOpen  -> connect(ui->actionOpen,  SIGNAL(triggered()), this,   SLOT(openDialog()));
    ui->actionSave_As  -> connect(ui->actionSave_As,SIGNAL(triggered()), this, SLOT(saveAsDialog()));
    this -> setCentralWidget(editor);
    this -> setWindowTitle(QObject::tr("Galeanthropy"));
    this -> show();

//    dialog = new FindDialog(this);

//    ui-> actionFind_and_Replace -> connect(dialog, SIGNAL(findPrevious(QString, Qt::CaseSensitivity)), this, SLOT(findup(QString, Qt::CaseSensitivity)));
//    ui-> actionFind_and_Replace -> connect(dialog, SIGNAL(findNext(QString, Qt::CaseSensitivity)), this, SLOT(finddown(QString, Qt::CaseSensitivity)));
//    ui-> actionFind_and_Replace -> connect(dialog, SIGNAL(replace(QString)), this, SLOT(replacetext(QString)));

}

MainWindow::~MainWindow(){
    delete highlighter;
    delete editor;
    delete ui;
}

void MainWindow::openDialog() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"));
    if (!filePath.isEmpty()) editor->openFile(filePath);
}

void MainWindow::saveAsDialog(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",tr("File Type (*.txt);;C++ File (*.cpp *.h)"));
    //if(!fileName = '' ){
    editor->saveFile(fileName);
   // }
}

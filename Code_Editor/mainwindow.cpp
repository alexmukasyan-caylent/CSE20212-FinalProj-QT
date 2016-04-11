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
    //find = new FindDialog(editor->document());
    fileIsOpened = false;
    editorName = QString("Galeanthropy");

    ui->actionQuit     -> connect(ui->actionQuit,    SIGNAL(triggered()), this,   SLOT(close()));
    ui->actionCopy     -> connect(ui->actionCopy,    SIGNAL(triggered()), editor, SLOT(copy()));
    ui->actionCut      -> connect(ui->actionCut,     SIGNAL(triggered()), editor, SLOT(cut()));
    ui->actionPaste    -> connect(ui->actionPaste,   SIGNAL(triggered()), editor, SLOT(paste()));
    ui->actionQuit     -> connect(ui->actionQuit,    SIGNAL(triggered()), editor, SLOT(selectAll()));
    ui->actionUndo     -> connect(ui->actionUndo,    SIGNAL(triggered()), editor, SLOT(undo()));
    ui->actionRedo     -> connect(ui->actionRedo,    SIGNAL(triggered()), editor, SLOT(redo()));
    ui->actionOpen     -> connect(ui->actionOpen,    SIGNAL(triggered()), this,   SLOT(openDialog()));
    ui->actionSave_As  -> connect(ui->actionSave_As, SIGNAL(triggered()), this,   SLOT(saveAsDialog()));
    ui->actionSave     -> connect(ui->actionSave,    SIGNAL(triggered()), this,   SLOT(saveDialog()));
    ui->actionIf       -> connect(ui->actionIf,      SIGNAL(triggered()), this,   SLOT(ifstate()));
    ui->actionIf_Else  -> connect(ui->actionIf_Else, SIGNAL(triggered()), this,   SLOT(ifelsestate()));
    ui->actionFor      -> connect(ui->actionFor,     SIGNAL(triggered()), this,   SLOT(forstate()));
    ui->actionWhile    -> connect(ui->actionWhile,   SIGNAL(triggered()), this,   SLOT(whilestate()));
    ui->actionDo_While -> connect(ui->actionDo_While,SIGNAL(triggered()), this,   SLOT(dowhilestate()));
    //ui->actionFind_and_Replace -> connect(ui->actionFind_and_Replace, SIGNAL(triggered()), this, SLOT(findReplace()));
    setCentralWidget(editor);
    setWindowTitle(QString("%1 | %2").arg(editorName).arg(tr("untitled")));
    show();
}

MainWindow::~MainWindow(){
    delete highlighter;
    delete editor;
    delete ui;
}

void MainWindow::openDialog() {
    QString tmpFilePath = QFileDialog::getOpenFileName(this, tr("Open File"));
    if (!tmpFilePath.isEmpty()) {
        filePath = tmpFilePath;
        setWindowTitle(QString("%1 | %2").arg(editorName).arg(filePath.section('/',-1)));
        fileIsOpened = true;
        editor->openFile(filePath);
    }
}
void MainWindow::saveDialog() {
    if (fileIsOpened) {
        editor->saveFile(filePath);
    } else {
        saveAsDialog();
    }
}

void MainWindow::saveAsDialog(){
    QString tmpFilePath = QFileDialog::getSaveFileName(this, tr("Save File"), "",tr("File Type (*.txt);;C++ File (*.cpp *.h)"));
    if (!tmpFilePath.isEmpty()){
        filePath = tmpFilePath;
        setWindowTitle(QString("%1 | %2").arg(editorName).arg(filePath.section('/',-1)));
        fileIsOpened = true;
        editor->saveFile(filePath);
    }
}

void MainWindow::ifstate(){
    editor->ifstate();
}

void MainWindow::ifelsestate(){
    editor->ifelsestate();
}

void MainWindow::forstate(){
    editor->forstate();
}

void MainWindow::whilestate(){
    editor->whilestate();
}

void MainWindow::dowhilestate(){
    editor->dowhilestate();
}

//void MainWindow::searchUp(QString text, Qt::CaseSensitivity cs) //finds text movign downward
//{
//    if (!text.isEmpty())
//    {
//        if (!(editor->textCursor().atStart()))
//            editor->moveCursor(QTextCursor::NextWord);

//        editor->moveCursor(QTextCursor::StartOfWord);

//        bool sens;
//        if(cs == Qt::CaseSensitive)
//            sens = editor->find(text, QTextDocument::FindWholeWords | QTextDocument::FindCaseSensitively);
//        else
//            sens = editor->find(text, QTextDocument::FindWholeWords);

//        if (sens)
//        {
//            QTextCursor cursor = editor->textCursor();
//            cursor.select(QTextCursor::WordUnderCursor);
//        }
//        else if (editor->textCursor().atStart())
//        {
//            QMessageBox notFound;
//            notFound.setText("Keyword not found.");
//            notFound.exec();
//        }
//        else
//        {
//            editor->moveCursor(QTextCursor::Start);
//        }
//    }
//}

//void MainWindow::searchDown(QString text, Qt::CaseSensitivity cs)// finds text moving upward
//{
//    if (!text.isEmpty())
//    {
//        if (!(editor->textCursor().atEnd()))
//            editor->moveCursor(QTextCursor::PreviousWord);

//        bool sens;
//        if(cs == Qt::CaseSensitive)
//            sens = editor->find(text, QTextDocument::FindWholeWords | QTextDocument::FindBackward | QTextDocument::FindCaseSensitively);
//        else
//            sens = editor->find(text, QTextDocument::FindWholeWords | QTextDocument::FindBackward);

//        if (sens)
//        {
//            QTextCursor cursor = editor->textCursor();
//            cursor.select(QTextCursor::WordUnderCursor);
//        }
//        else if (editor->textCursor().atEnd())
//        {
//            QMessageBox notFound;
//            notFound.setText("Keyword not found.");
//            notFound.exec();
//        }
//        else
//        {
//            editor->moveCursor(QTextCursor::End);
//        }
//    }
//}

//void MainWindow::replaceWord(QString text) //replaces selected text
//{
//    if (!text.isEmpty())
//    {
//        if (editor->textCursor().hasSelection())
//        {
//            editor->textCursor().removeSelectedText();
//            editor->textCursor().insertText(text);
//        }
//        else
//        {
//            QMessageBox notFound;
//            notFound.setText("No text selected.");
//            notFound.exec();
//        }
//    }
//}

/********************************************************************************
** Form generated from reading UI file 'codeeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEEDITOR_H
#define UI_CODEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_codeeditor
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionQuit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFind_and_Replace;
    QAction *actionIf;
    QAction *actionIf_Else;
    QAction *actionFor;
    QAction *actionWhile;
    QAction *actionDo_While;
    QAction *actionDeclaration_Wizard;
    QAction *actionCustom;
    QAction *actionModify_Type_Declarations;
    QAction *actionModify_Active_Syntax_Rules;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuEdit;
    QMenu *menuTemplates;
    QMenu *menuSyntax_Validation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *codeeditor)
    {
        if (codeeditor->objectName().isEmpty())
            codeeditor->setObjectName(QStringLiteral("codeeditor"));
        codeeditor->resize(427, 423);
        actionNew = new QAction(codeeditor);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(codeeditor);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(codeeditor);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(codeeditor);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionQuit = new QAction(codeeditor);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionUndo = new QAction(codeeditor);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(codeeditor);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionCut = new QAction(codeeditor);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(codeeditor);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(codeeditor);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionFind_and_Replace = new QAction(codeeditor);
        actionFind_and_Replace->setObjectName(QStringLiteral("actionFind_and_Replace"));
        actionIf = new QAction(codeeditor);
        actionIf->setObjectName(QStringLiteral("actionIf"));
        actionIf_Else = new QAction(codeeditor);
        actionIf_Else->setObjectName(QStringLiteral("actionIf_Else"));
        actionFor = new QAction(codeeditor);
        actionFor->setObjectName(QStringLiteral("actionFor"));
        actionWhile = new QAction(codeeditor);
        actionWhile->setObjectName(QStringLiteral("actionWhile"));
        actionDo_While = new QAction(codeeditor);
        actionDo_While->setObjectName(QStringLiteral("actionDo_While"));
        actionDeclaration_Wizard = new QAction(codeeditor);
        actionDeclaration_Wizard->setObjectName(QStringLiteral("actionDeclaration_Wizard"));
        actionCustom = new QAction(codeeditor);
        actionCustom->setObjectName(QStringLiteral("actionCustom"));
        actionModify_Type_Declarations = new QAction(codeeditor);
        actionModify_Type_Declarations->setObjectName(QStringLiteral("actionModify_Type_Declarations"));
        actionModify_Active_Syntax_Rules = new QAction(codeeditor);
        actionModify_Active_Syntax_Rules->setObjectName(QStringLiteral("actionModify_Active_Syntax_Rules"));
        centralWidget = new QWidget(codeeditor);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        codeeditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(codeeditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 427, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTemplates = new QMenu(menuBar);
        menuTemplates->setObjectName(QStringLiteral("menuTemplates"));
        menuSyntax_Validation = new QMenu(menuBar);
        menuSyntax_Validation->setObjectName(QStringLiteral("menuSyntax_Validation"));
        codeeditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(codeeditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        codeeditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(codeeditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        codeeditor->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTemplates->menuAction());
        menuBar->addAction(menuSyntax_Validation->menuAction());
        menu_File->addAction(actionNew);
        menu_File->addAction(actionOpen);
        menu_File->addSeparator();
        menu_File->addAction(actionSave);
        menu_File->addAction(actionSave_As);
        menu_File->addSeparator();
        menu_File->addAction(actionQuit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind_and_Replace);
        menuTemplates->addAction(actionIf);
        menuTemplates->addAction(actionIf_Else);
        menuTemplates->addAction(actionFor);
        menuTemplates->addAction(actionWhile);
        menuTemplates->addAction(actionDo_While);
        menuTemplates->addAction(actionDeclaration_Wizard);
        menuTemplates->addSeparator();
        menuTemplates->addAction(actionCustom);
        menuSyntax_Validation->addAction(actionModify_Type_Declarations);
        menuSyntax_Validation->addAction(actionModify_Active_Syntax_Rules);

        retranslateUi(codeeditor);

        QMetaObject::connectSlotsByName(codeeditor);
    } // setupUi

    void retranslateUi(QMainWindow *codeeditor)
    {
        codeeditor->setWindowTitle(QApplication::translate("codeeditor", "codeeditor", 0));
        actionNew->setText(QApplication::translate("codeeditor", "New", 0));
        actionOpen->setText(QApplication::translate("codeeditor", "Open", 0));
        actionSave->setText(QApplication::translate("codeeditor", "Save", 0));
        actionSave_As->setText(QApplication::translate("codeeditor", "Save As", 0));
        actionQuit->setText(QApplication::translate("codeeditor", "Quit", 0));
        actionUndo->setText(QApplication::translate("codeeditor", "Undo", 0));
        actionRedo->setText(QApplication::translate("codeeditor", "Redo", 0));
        actionCut->setText(QApplication::translate("codeeditor", "Cut", 0));
        actionCopy->setText(QApplication::translate("codeeditor", "Copy", 0));
        actionPaste->setText(QApplication::translate("codeeditor", "Paste", 0));
        actionFind_and_Replace->setText(QApplication::translate("codeeditor", "Find and Replace", 0));
        actionIf->setText(QApplication::translate("codeeditor", "If () {}", 0));
        actionIf_Else->setText(QApplication::translate("codeeditor", "If (){} Else {}", 0));
        actionFor->setText(QApplication::translate("codeeditor", "For (){}", 0));
        actionWhile->setText(QApplication::translate("codeeditor", "While (){}", 0));
        actionDo_While->setText(QApplication::translate("codeeditor", "Do{} While ()", 0));
        actionDeclaration_Wizard->setText(QApplication::translate("codeeditor", "Declaration Wizard", 0));
        actionCustom->setText(QApplication::translate("codeeditor", "Custom", 0));
        actionModify_Type_Declarations->setText(QApplication::translate("codeeditor", "Modify Type Declarations", 0));
        actionModify_Active_Syntax_Rules->setText(QApplication::translate("codeeditor", "Modify Active Syntax Rules", 0));
        menu_File->setTitle(QApplication::translate("codeeditor", "&File", 0));
        menuEdit->setTitle(QApplication::translate("codeeditor", "Edit", 0));
        menuTemplates->setTitle(QApplication::translate("codeeditor", "Templates", 0));
        menuSyntax_Validation->setTitle(QApplication::translate("codeeditor", "Syntax Validation", 0));
    } // retranslateUi

};

namespace Ui {
    class codeeditor: public Ui_codeeditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEEDITOR_H

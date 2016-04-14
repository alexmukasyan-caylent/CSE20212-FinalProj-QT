
#include <QtWidgets>
#include "codeeditor.h"
#include "ui_codeeditor.h"
#include <QLineEdit>
#include <QKeyEvent>
#include <Qt>


//![constructor]

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);
    //find = new FindDialog(this);
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
//    connect(find, SIGNAL(findPrevious(QString, Qt::CaseSensitivity)), this, SLOT(searchDown(QString, Qt::CaseSensitivity)));
//    connect(find, SIGNAL(findNext(QString, Qt::CaseSensitivity)), this, SLOT(searchUp(QString, Qt::CaseSensitivity)));
//    connect(find, SIGNAL(replace(QString)), this, SLOT(replaceWord(QString)));
    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}

//![constructor]
#include <QtGui>
void CodeEditor::checkParen(){
    int currentIndex = 0;
    int openparen = 0;
    QRegExp rx(".*\x0028"); //match unicode left paren
    QRegExp rx2(".*\x0029");//match unicode right paren
    QRegExp rx3(".*\x007B");//match unicode left curly
    QRegExp rx4(".*\x007D");//match unicode right curly
    currentIndex++;
    QString plainTextEditContents = this->toPlainText();
    QStringList lines = plainTextEditContents.split("\n");
    QString currentLine = lines[currentIndex];
    if(rx.exactMatch(currentLine)){
        openparen++;
    }
    QMessageBox::StandardButton parencheck;
    if(openparen == 1){
        parencheck = QMessageBox::question(this,"Paren Check","This document has 1 paren",QMessageBox::Ignore|QMessageBox::Cancel );
    }
}

void CodeEditor::ifstate(){
    this->insertPlainText("if([condition){}");
}

void CodeEditor::ifelsestate(){
    this->insertPlainText("if([condition]){}else{[action];}");
}

void CodeEditor::forstate(){
    this->insertPlainText("for([incremented var];[var limit];[var increment]){}");
}

void CodeEditor::whilestate(){
    this->insertPlainText("while([condition]{actions}");

}

void CodeEditor::dowhilestate(){
    this->insertPlainText("do{actions}while([condition);");
}

void CodeEditor::openFile(QString filePath) {
    QFile file(filePath);
    if (file.open(QFile::ReadWrite | QFile::Text)) {
       this->document()->setPlainText(file.readAll());
    } else {
        // alert could not open file
    }
}

void CodeEditor::saveFile(QString fileName){
    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite)) {
       QTextStream stream(&file);
       stream << this->document()->toPlainText();
       file.flush();
       file.close();
    }
}

//![extraAreaWidth]

void CodeEditor::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_BraceLeft){
        this->insertPlainText("{}");
        QEvent *movePress= new QKeyEvent(QEvent::KeyPress, Qt::Key_Left,   Qt::NoModifier);
        QApplication::sendEvent(focusWidget(), movePress);
        QEvent *moveRelease= new QKeyEvent(QEvent::KeyRelease,  Qt::Key_Left,  Qt::NoModifier);
        QApplication::sendEvent(focusWidget(),moveRelease);
    }else if(e->key() == Qt::Key_ParenLeft){
        this->insertPlainText("()");
        QEvent *movePress= new QKeyEvent(QEvent::KeyPress, Qt::Key_Left,   Qt::NoModifier);
        QApplication::sendEvent(focusWidget(), movePress);
        QEvent *moveRelease= new QKeyEvent(QEvent::KeyRelease,  Qt::Key_Left,  Qt::NoModifier);
        QApplication::sendEvent(focusWidget(),moveRelease);
    }else{QPlainTextEdit::keyPressEvent(e);}

}

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

//![extraAreaWidth]

//![slotUpdateExtraAreaWidth]

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

//![slotUpdateExtraAreaWidth]

//![slotUpdateRequest]

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

//![slotUpdateRequest]

//![resizeEvent]

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);
    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

//![resizeEvent]

//![cursorPositionChanged]

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

//![cursorPositionChanged]

//![extraAreaPaintEvent_0]

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);

//![extraAreaPaintEvent_0]

//![extraAreaPaintEvent_1]
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
//![extraAreaPaintEvent_1]

//![extraAreaPaintEvent_2]
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
//![extraAreaPaintEvent_2]
//void CodeEditor::searchUp(QString text, Qt::CaseSensitivity cs) //finds text movign downward
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

//void CodeEditor::searchDown(QString text, Qt::CaseSensitivity cs)// finds text moving upward
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

//void CodeEditor::replaceWord(QString text) //replaces selected text
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



#include <QtWidgets>
#include "codeeditor.h"
#include "ui_codeeditor.h"
#include <QLineEdit>
#include <QKeyEvent>
#include <Qt>
#include <QPlainTextEdit>


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
    QString plainTextEditContents = this->toPlainText();
    int openParen = plainTextEditContents.count("(");
    int closeParen = plainTextEditContents.count(")");
    int openCurly = plainTextEditContents.count("{");
    int closeCurly = plainTextEditContents.count("}");
    int openBrack = plainTextEditContents.count("[");
    int closeBrack = plainTextEditContents.count("]");
    QString message;
    bool missing = false;
    message = "You are missing a:\n";
    if( openParen != closeParen){
        message += "parenthesis\n";
        missing = true;
    }
    if( openCurly != closeCurly){
        message += "curly brace\n";
        missing = true;
    }
    if( openBrack != closeBrack){
        message += "bracket\n";
        missing = true;
    }
    if(missing){
        QMessageBox::StandardButton parencheck;
        parencheck = QMessageBox::question(this,"Parenthesis Match Check",message,QMessageBox::Ignore|QMessageBox::Cancel );
    }
}

void CodeEditor::findString(QString text, Qt::CaseSensitivity cs) {
    if (toPlainText().count(text,cs) > 0) setTextCursor(document()->find(text, textCursor()));
}

void CodeEditor::findReplace(QString before, QString after, Qt::CaseSensitivity cs) {

    QString documentText = this->toPlainText();
    documentText.replace(before,after,cs);
    setPlainText(documentText);

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

QString CodeEditor::getLineIndent() {
    int location = textCursor().position();
    QString indent;
    moveCursor(QTextCursor::StartOfLine);
    while (textCursor().position() < location && QRegExp("\\s*").exactMatch(textCursor().selectedText())) {
        moveCursor(QTextCursor::Right,QTextCursor::KeepAnchor);
    }
    if (QRegExp("\\s*").exactMatch(textCursor().selectedText().right(1))) {
        indent = textCursor().selectedText();
    } else {
        moveCursor(QTextCursor::Left,QTextCursor::KeepAnchor);
        indent = textCursor().selectedText();
    }
    while (textCursor().position() < location) {
        moveCursor(QTextCursor::Right);
    }
    return indent;
}

void CodeEditor::keyPressEvent(QKeyEvent *e){
    switch(e->key()) {
      case Qt::Key_Backspace:
        {
            if (placedDoubleCharacter) {
                moveCursor(QTextCursor::Right);
                QPlainTextEdit::keyPressEvent(e);
                QPlainTextEdit::keyPressEvent(e);
            } else {
                QPlainTextEdit::keyPressEvent(e);
            }
        }
        break;
      case Qt::Key_BraceRight:
      case Qt::Key_BracketRight:
      case Qt::Key_ParenRight:
      case Qt::Key_Greater:
        {
          if (!placedDoubleCharacter) {
                placedDoubleCharacter = false;
                QPlainTextEdit::keyPressEvent(e);
          } else {
                moveCursor(QTextCursor::Right);
          }
        }
        break;
      case Qt::Key_BraceLeft:
        {
            textCursor().beginEditBlock();
            placedDoubleCharacter = true;
            insertPlainText("{}");
            moveCursor(QTextCursor::Left);
            textCursor().endEditBlock();
        }
        break;
      case Qt::Key_ParenLeft:
        {
            textCursor().beginEditBlock();
            placedDoubleCharacter = true;
            insertPlainText("()");
            moveCursor(QTextCursor::Left);
            textCursor().endEditBlock();
        }
        break;
      case Qt::Key_BracketLeft:
        {
            textCursor().beginEditBlock();
            placedDoubleCharacter = true;
            insertPlainText("[]");
            moveCursor(QTextCursor::Left);
            textCursor().endEditBlock();
        }
        break;
      case Qt::Key_Less:
        {
            textCursor().beginEditBlock();
            placedDoubleCharacter = true;
            insertPlainText("<>");
            moveCursor(QTextCursor::Left);
            textCursor().endEditBlock();
        }
        break;
      case Qt::Key_Apostrophe:
        {
            if (!placedDoubleCharacter) {
                textCursor().beginEditBlock();
                placedDoubleCharacter = true;
                insertPlainText("''");
                moveCursor(QTextCursor::Left);
                textCursor().endEditBlock();
            }
        }
        break;
      case Qt::Key_QuoteDbl:
        {
            if (!placedDoubleCharacter) {
                textCursor().beginEditBlock();
                placedDoubleCharacter = true;
                insertPlainText("\"\"");
                moveCursor(QTextCursor::Left);
                textCursor().endEditBlock();
            }
        }
        break;
      case Qt::Key_Return:
        {
            textCursor().beginEditBlock();
            QString indent = getLineIndent();
            QPlainTextEdit::keyPressEvent(e);
            insertPlainText(indent);
            if (placedDoubleCharacter) {
                insertPlainText("\t");
                QPlainTextEdit::keyPressEvent(e);
                insertPlainText(indent);
                moveCursor(QTextCursor::Up);
                moveCursor(QTextCursor::EndOfLine);
            }
            placedDoubleCharacter = false;
            textCursor().endEditBlock();
        }
        break;
      default:
        placedDoubleCharacter = false;
        QPlainTextEdit::keyPressEvent(e);
        break;
    }
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

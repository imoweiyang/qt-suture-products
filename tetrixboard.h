#ifndef TETRIXBOARD_H
#define TETRIXBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>

#include "tetrixpiece.h"

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE


class TetrixBoard : public QFrame
{
    Q_OBJECT
public:
    TetrixBoard(QWidget *parent = 0);

    void setNextPieceLabel(QLabel *label);
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;

public slots:
    void start();
    void pause();

signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;



private:
    enum { BoardWidth = 10, BoardHeight = 22 };

    TetrixShape &shapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }
    int timeoutTime() { return 1000 / (1 + level); }
    int squareWidth() { return contentsRect().width() / BoardWidth; }
    int squareHeight() { return contentsRect().height() / BoardHeight; }
    void clearBoard();
    void dropDown();
    void oneLineDown();
    void pieceDropped(int dropHeight);
    void removeFullLines();
    void newPiece();
    void showNextPiece();
    bool tryMove(const TetrixPiece &newPiece, int newX, int newY);
    void drawSquare(QPainter &painter, int x, int y, TetrixShape shape);

    QBasicTimer timer;
    QPointer<QLabel> nextPieceLabel;
    bool isStarted;
    bool isPaused;
    bool isWaitingAfterLine;
    TetrixPiece curPiece;
    TetrixPiece nextPiece;
    int curX;
    int curY;
    int numLinesRemoved;
    int numPiecesDropped;
    int score;
    int level;
    TetrixShape board[BoardWidth * BoardHeight];
};

#endif // TETRIXBOARD_H

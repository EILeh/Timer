#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Normally this member should be in private part of the
    // class, but due to the automated tests it must be more
    // accessible.
    QTimer* timer;

private slots:

    void startTimer();
    void stopTimer();
    void resetTimer();
    void closeTimer();
    void updateLcd();

private:
    Ui::MainWindow *ui;

    int time_ = 0;


};

#endif // MAINWINDOW_HH

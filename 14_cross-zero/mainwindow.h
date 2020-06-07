#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   void moveII ();
    int getFreeCell ();
    void dialog(const int &x);
    bool testEnd(const int &x);
    bool testDraw ();
    void choiceDialog (const int &x);

private slots:


    void on_pB_1_clicked();
    void on_pB_2_clicked();
    void on_pB_3_clicked();
    void on_pB_4_clicked();
    void on_pB_5_clicked();
    void on_pB_6_clicked();
    void on_pB_7_clicked();
    void on_pB_8_clicked();
    void on_pB_9_clicked();


    void on_pB_beginGame_clicked();

private:
    Ui::MainWindow *ui;
    QString m_nameUser;
    QVector <int> m_space;
    bool move; // ход (1 - игрок, 0 - ИИ)

};

#endif // MAINWINDOW_H

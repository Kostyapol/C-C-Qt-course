#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "QTime"
#include "qmath.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


   ui->setupUi(this);
    m_space = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    ui->gB_space->setVisible(false);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::getFreeCell () // случайная свободная клетка
{
    int freeCell;
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    do
    {
        freeCell = 1 + qrand()%9;
    } while (m_space.at(freeCell-1) != 2);
   // qDebug() << freeCell ;
    return freeCell;
}


void MainWindow::moveII ()
{
    int n = getFreeCell ();
    m_space[n-1] = 0;
    switch (n) {
    case 1:
        ui->pB_1->setDisabled(true);
        ui->pB_1->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        break;
    case 2:
        ui->pB_2->setDisabled(true);
        ui->pB_2->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        testEnd(2);
        break;
    case 3:
        ui->pB_3->setDisabled(true);
        ui->pB_3->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        testEnd(2);
        break;
    case 4:
        ui->pB_4->setDisabled(true);
        ui->pB_4->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        break;
    case 5:
        ui->pB_5->setDisabled(true);
        ui->pB_5->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        break;
    case 6:
        ui->pB_6->setDisabled(true);
        ui->pB_6->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        break;
    case 7:
        ui->pB_7->setDisabled(true);
        ui->pB_7->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        break;
    case 8:
        ui->pB_8->setDisabled(true);
        ui->pB_8->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        break;
    case 9:
        ui->pB_9->setDisabled(true);
        ui->pB_9->setStyleSheet("background:transparent;border-image:url(:/Resurs/Null.png) 0 0 0 0 0 stretch stretch;");
        break;
    }
    choiceDialog (0);

}


bool MainWindow::testDraw () // проверка на ничью
{
    int n = 0; //количество элементов не равных 2 (заполненных крестиком или  ноликом)
    for ( int i = 0; i < 9; ++i)
    {
        if (m_space.at(i) != 2)
        {
            n++;
        }
    qDebug () << n;
    }
    if (n == 9)
    {
    return true;
    } else return false;
}




bool MainWindow::testEnd (const int &x)  // проверка победы (x=1 - игрок, x=0 - ИИ)
{
    if ((m_space.at(0) == x && m_space.at(1) == x && m_space.at(2) == x) || // по горизонталям
        (m_space.at(3) == x && m_space.at(4) == x && m_space.at(5) == x) ||
        (m_space.at(6) == x && m_space.at(7) == x && m_space.at(8) == x) ||
        (m_space.at(0) == x && m_space.at(3) == x && m_space.at(6) == x) || // по вертикалям
        (m_space.at(1) == x && m_space.at(4) == x && m_space.at(7) == x) ||
        (m_space.at(2) == x && m_space.at(5) == x && m_space.at(8) == x) ||
        (m_space.at(0) == x && m_space.at(4) == x && m_space.at(8) == x) || // по диагоналям
        (m_space.at(2) == x && m_space.at(4) == x && m_space.at(6) == x))
    {
        return true;
    } else
        {
            return false;
        }

}

void MainWindow::choiceDialog (const int &x) // определение победа или ничья и вызов диалога
{
    if (testEnd(x))
    {
        dialog(x);
    } else if (testDraw())
    {
    dialog(3);
    }
}



void MainWindow::dialog (const int &x)
{
    QString message = m_nameUser;
    if (x == 1)
    {
        message.append("! Вы победили могущественный\n искусственный интеллект!");
    } else if (x == 0)
    {
        message.append("! Вы проиграли\n тупой машине!");
    } else if (x == 3)
    {
        message = "Ничья!";
    }

    QMessageBox* pmbx = new QMessageBox (QMessageBox::Information,
                                         "Окончание",
                                         message,
                                         QMessageBox::Ok);
    int n = pmbx->exec();
    delete pmbx;
    if (n == QMessageBox::Ok)
    {
    exit(0);
    }
}



void MainWindow::on_pB_1_clicked()
{
    ui->pB_1->setDisabled(true);
    ui->pB_1->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [0] = 1;
    choiceDialog (1);
    qDebug() << m_space;
    moveII ();
    qDebug() << m_space;
   
}


void MainWindow::on_pB_2_clicked()
{
    ui->pB_2->setDisabled(true);
    ui->pB_2->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [1] = 1;
    choiceDialog (1);
    qDebug() << m_space;
    moveII ();
    qDebug() << m_space;

}

void MainWindow::on_pB_3_clicked()
{
    ui->pB_3->setDisabled(true);
    ui->pB_3->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [2] = 1;
    choiceDialog (1);
    qDebug() << m_space;
    moveII ();
    qDebug() << m_space;

}

void MainWindow::on_pB_4_clicked()
{
    ui->pB_4->setDisabled(true);
    ui->pB_4->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [3] = 1;
    choiceDialog (1);
    qDebug() << m_space;
    moveII ();
    qDebug() << m_space;

}

void MainWindow::on_pB_5_clicked()
{
    ui->pB_5->setDisabled(true);
    ui->pB_5->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [4] = 1;
    choiceDialog (1);
    qDebug() << m_space;
    moveII ();
    qDebug() << m_space;

}

void MainWindow::on_pB_6_clicked()
{
    ui->pB_6->setDisabled(true);
    ui->pB_6->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [5] = 1;
    choiceDialog (1);
    qDebug() << m_space;
    moveII ();
    qDebug() << m_space;

}


void MainWindow::on_pB_7_clicked()
{
    ui->pB_7->setDisabled(true);
    ui->pB_7->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [6] = 1;
    choiceDialog (1);
    qDebug() << m_space;
    moveII ();
    qDebug() << m_space;

}

void MainWindow::on_pB_8_clicked()
{
    ui->pB_8->setDisabled(true);
    ui->pB_8->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [7] = 1;
    choiceDialog (1);
    qDebug() << m_space;
    moveII ();
    qDebug() << m_space;

}

void MainWindow::on_pB_9_clicked()
{
    ui->pB_9->setDisabled(true);
    ui->pB_9->setStyleSheet("background:transparent;border-image:url(:/Resurs/dagger.png) 0 0 0 0 0 stretch stretch;");
    m_space [8] = 1;
    qDebug() << m_space;
    choiceDialog (1);
    moveII ();
    qDebug() << m_space;

}


void MainWindow::on_pB_beginGame_clicked()
{
   m_nameUser = ui->lineEdit->text();
   ui->gB_space->setVisible(true);
   ui->lineEdit->setVisible(false);
   ui->label->setText(m_nameUser+" против икуствееного интеллекта");
   ui->pB_beginGame->setVisible(false);

}

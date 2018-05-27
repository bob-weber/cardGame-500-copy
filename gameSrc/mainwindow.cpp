#include <QWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	m_gameView = new view_500;
	m_gameLogic = new logic_500(this);
	QWidget *tableWidget = m_gameView->setupCardTable();
	setCentralWidget(tableWidget);

}

MainWindow::~MainWindow()
{
	delete ui;
}

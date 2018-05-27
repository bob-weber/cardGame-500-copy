#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logic/logic_500.h"
#include "view/view_500.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:
		Ui::MainWindow *ui;
		view_500 *m_gameView;
		logic_500 *m_gameLogic;
};

#endif // MAINWINDOW_H

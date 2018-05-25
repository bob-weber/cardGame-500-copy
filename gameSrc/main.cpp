#include "mainwindow.h"
#include <QApplication>
#include "data/card.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	Card * testCard = new Card();

	return a.exec();

}

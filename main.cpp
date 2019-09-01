#include "mainwindow.h"
#include "graphwidget.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    MainWindow mainWindow;
    GraphWidget* graphWidget = new GraphWidget();

    mainWindow.setCentralWidget(graphWidget);
    mainWindow.show();

    return application.exec();
}
